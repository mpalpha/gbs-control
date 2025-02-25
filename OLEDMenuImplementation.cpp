#define OSD_TIMEOUT 8000

#include <ESP8266WiFi.h>
#include "OLEDMenuImplementation.h"
#include "options.h"
#include "tv5725.h"
#include "slot.h"
#include "src/WebSockets.h"
#include "src/WebSocketsServer.h"
#include "fonts.h"
#include "OSDManager.h"

// Function declaration
uint16_t calculateResolutionFromRegisters(uint16_t *h_display, uint16_t *v_display);

typedef TV5725<GBS_ADDR> GBS;
extern void applyPresets(uint8_t videoMode);
extern void setOutModeHdBypass(bool bypass);
extern void saveUserPrefs();
extern float getOutputFrameRate();
extern void loadDefaultUserOptions();
extern uint8_t getVideoMode();
extern runTimeOptions *rto;
extern userOptions *uopt;
extern const char *ap_ssid;
extern const char *ap_password;
extern const char *device_hostname_full;
extern WebSocketsServer webSocket;
extern OLEDMenuManager oledMenu;
extern OSDManager osdManager;
unsigned long oledMenuFreezeStartTime;
unsigned long oledMenuFreezeTimeoutInMS;

// Standard video timing definitions
struct VideoTiming {
    uint16_t h_total;
    uint16_t v_total;
    uint16_t h_active;
    uint16_t v_active;
    const char* name;
    uint16_t tolerance;  // Tolerance for timing matching
};

const VideoTiming standardTimings[] = {
    // name        h_total  v_total  h_active  v_active  tolerance
    {1650,    750,    1280,     720,    "720p",      20},    // 720p
    {2200,    1125,   1920,    1080,    "1080p",     30},    // 1080p
    {1688,    1066,   1280,    1024,    "SXGA",      20},    // 1280x1024
    {1344,    806,    1024,    768,     "XGA",       20},    // 1280x960
    {858,     525,    720,     480,     "480p",      10},    // 480p
    {864,     625,    768,     576,     "576p",      10},    // 576p
    {1800,    1000,   1280,    960,     "1280x960",  25},    // 1280x960 - adjusted timing
};

// Helper function to match timings against standards
const VideoTiming* matchStandardTiming(uint16_t h_total, uint16_t v_total) {
    for (const auto& timing : standardTimings) {
        bool h_match = abs((int)h_total - (int)timing.h_total) <= timing.tolerance;
        bool v_match = abs((int)v_total - (int)timing.v_total) <= timing.tolerance;

        if (h_match && v_match) {
            return &timing;
        }
    }
    return nullptr;
}

bool resolutionMenuHandler(OLEDMenuManager *manager, OLEDMenuItem *item, OLEDMenuNav, bool isFirstTime)
{
    if (!isFirstTime) {
        if (millis() - oledMenuFreezeStartTime >= oledMenuFreezeTimeoutInMS) {
            manager->unfreeze();
        }
        return false;
    }
    oledMenuFreezeTimeoutInMS = 1000; // freeze for 1s
    oledMenuFreezeStartTime = millis();
    OLEDDisplay *display = manager->getDisplay();
    display->clear();
    display->setColor(OLEDDISPLAY_COLOR::WHITE);
    display->setFont(ArialMT_Plain_16);
    display->setTextAlignment(OLEDDISPLAY_TEXT_ALIGNMENT::TEXT_ALIGN_CENTER);
    display->drawString(OLED_MENU_WIDTH / 2, 16, item->str);
    display->drawXbm((OLED_MENU_WIDTH - TEXT_LOADED_WIDTH) / 2, OLED_MENU_HEIGHT / 2, IMAGE_ITEM(TEXT_LOADED));
    display->display();
    uint8_t videoMode = getVideoMode();
    PresetPreference preset = PresetPreference::Output1080P;
    switch (item->tag) {
        case MT_1280x960:
            preset = PresetPreference::Output960P;
            break;
        case MT1280x1024:
            preset = PresetPreference::Output1024P;
            break;
        case MT1280x720:
            preset = PresetPreference::Output720P;
            break;
        case MT1920x1080:
            preset = PresetPreference::Output1080P;
            break;
        case MT_480s576:
            preset = PresetPreference::Output480P;
            break;
        case MT_DOWNSCALE:
            preset = PresetPreference::OutputDownscale;
            break;
        case MT_BYPASS:
            preset = PresetPreference::OutputCustomized;
            break;
        default:
            break;
    }
    if (videoMode == 0 && GBS::STATUS_SYNC_PROC_HSACT::read()) {
        videoMode = rto->videoStandardInput;
    }
    if (item->tag != MT_BYPASS) {
        uopt->presetPreference = preset;
        rto->useHdmiSyncFix = 1;
        if (rto->videoStandardInput == 14) {
            rto->videoStandardInput = 15;
        } else {
            applyPresets(videoMode);
        }
    } else {
        setOutModeHdBypass(false);
        uopt->presetPreference = preset;
        if (rto->videoStandardInput != 15) {
            rto->autoBestHtotalEnabled = 0;
            if (rto->applyPresetDoneStage == 11) {
                rto->applyPresetDoneStage = 1;
            } else {
                rto->applyPresetDoneStage = 10;
            }
        } else {
            rto->applyPresetDoneStage = 1;
        }
    }
    saveUserPrefs();
    manager->freeze();
    return false;
}
bool presetSelectionMenuHandler(OLEDMenuManager *manager, OLEDMenuItem *item, OLEDMenuNav, bool isFirstTime)
{
    if (!isFirstTime) {
        if (millis() - oledMenuFreezeStartTime >= oledMenuFreezeTimeoutInMS) {
            manager->unfreeze();
        }
        return false;
    }
    OLEDDisplay *display = manager->getDisplay();
    display->clear();
    display->setColor(OLEDDISPLAY_COLOR::WHITE);
    display->setFont(ArialMT_Plain_16);
    display->setTextAlignment(OLEDDISPLAY_TEXT_ALIGNMENT::TEXT_ALIGN_CENTER);
    display->drawString(OLED_MENU_WIDTH / 2, 16, item->str);
    display->drawXbm((OLED_MENU_WIDTH - TEXT_LOADED_WIDTH) / 2, OLED_MENU_HEIGHT / 2, IMAGE_ITEM(TEXT_LOADED));
    display->display();
    uopt->presetSlot = 'A' + item->tag; // ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-._~()!*:,
    uopt->presetPreference = PresetPreference::OutputCustomized;
    saveUserPrefs();
    if (rto->videoStandardInput == 14) {
        // vga upscale path: let synwatcher handle it
        rto->videoStandardInput = 15;
    } else {
        // normal path
        applyPresets(rto->videoStandardInput);
    }
    saveUserPrefs();
    manager->freeze();
    oledMenuFreezeTimeoutInMS = 2000;
    oledMenuFreezeStartTime = millis();

    return false;
}
bool presetsCreationMenuHandler(OLEDMenuManager *manager, OLEDMenuItem *item, OLEDMenuNav, bool)
{
    SlotMetaArray slotsObject;
    File slotsBinaryFileRead = SPIFFS.open(SLOTS_FILE, "r");
    manager->clearSubItems(item);
    int curNumSlot = 0;
    if (slotsBinaryFileRead) {
        slotsBinaryFileRead.read((byte *)&slotsObject, sizeof(slotsObject));
        slotsBinaryFileRead.close();
        for (int i = 0; i < SLOTS_TOTAL; ++i) {
            const SlotMeta &slot = slotsObject.slot[i];
            if (strcmp(EMPTY_SLOT_NAME, slot.name) == 0 || !strlen(slot.name)) {
                continue;
            }
            curNumSlot++;
            if (curNumSlot > OLED_MENU_MAX_SUBITEMS_NUM) {
                break;
            }
            manager->registerItem(item, slot.slot, slot.name, presetSelectionMenuHandler);
        }
    }

    if (curNumSlot > OLED_MENU_MAX_SUBITEMS_NUM) {
        manager->registerItem(item, 0, IMAGE_ITEM(TEXT_TOO_MANY_PRESETS));
    }

    if (!item->numSubItem) {
        manager->registerItem(item, 0, IMAGE_ITEM(TEXT_NO_PRESETS));
    }
    return true;
}
bool resetMenuHandler(OLEDMenuManager *manager, OLEDMenuItem *item, OLEDMenuNav, bool isFirstTime)
{
    if (!isFirstTime) {
        // not precise
        if (millis() - oledMenuFreezeStartTime >= oledMenuFreezeTimeoutInMS) {
            manager->unfreeze();
            ESP.reset();
            return false;
        }
        return false;
    }

    OLEDDisplay *display = manager->getDisplay();
    display->clear();
    display->setColor(OLEDDISPLAY_COLOR::WHITE);
    switch (item->tag) {
        case MT_RESET_GBS:
            display->drawXbm(CENTER_IMAGE(TEXT_RESETTING_GBS));
            break;
        case MT_RESTORE_FACTORY:
            display->drawXbm(CENTER_IMAGE(TEXT_RESTORING));
            break;
        case MT_RESET_WIFI:
            display->drawXbm(CENTER_IMAGE(TEXT_RESETTING_WIFI));
            break;
    }
    display->display();
    webSocket.close();
    delay(50);
    switch (item->tag) {
        case MT_RESET_WIFI:
            WiFi.disconnect();
            break;
        case MT_RESTORE_FACTORY:
            loadDefaultUserOptions();
            saveUserPrefs();
            break;
    }
    manager->freeze();
    oledMenuFreezeStartTime = millis();
    oledMenuFreezeTimeoutInMS = 2000; // freeze for 2 seconds
    return false;
}
bool currentSettingHandler(OLEDMenuManager *manager, OLEDMenuItem *, OLEDMenuNav nav, bool isFirstTime)
{
    static unsigned long lastUpdateTime = 0;
    if (isFirstTime) {
        lastUpdateTime = 0;
        oledMenuFreezeStartTime = millis();
        oledMenuFreezeTimeoutInMS = 2000; // freeze for 2 seconds if no input
        manager->freeze();
    } else if (nav != OLEDMenuNav::IDLE) {
        manager->unfreeze();
        return false;
    }
    if (millis() - lastUpdateTime <= 200) {
        return false;
    }
    OLEDDisplay &display = *manager->getDisplay();
    display.clear();
    display.setColor(OLEDDISPLAY_COLOR::WHITE);
    display.setFont(ArialMT_Plain_16);
    if (rto->sourceDisconnected || !rto->boardHasPower) {
        if (millis() - oledMenuFreezeStartTime >= oledMenuFreezeTimeoutInMS) {
            manager->unfreeze();
            return false;
        }
        display.setTextAlignment(OLEDDISPLAY_TEXT_ALIGNMENT::TEXT_ALIGN_CENTER);
        display.drawXbm(CENTER_IMAGE(TEXT_NO_INPUT));
    } else {
        // TODO translations
        boolean vsyncActive = 0;
        boolean hsyncActive = 0;
        float ofr = getOutputFrameRate();
        uint8_t currentInput = GBS::ADC_INPUT_SEL::read();
        rto->presetID = GBS::GBS_PRESET_ID::read();

        display.setFont(ArialMT_Plain_16);
        display.setTextAlignment(TEXT_ALIGN_LEFT);

        // Line 1: Mode Resolution with label
        display.drawString(0, 0, "Mode: ");
        if (rto->presetID == 0x01 || rto->presetID == 0x11) {
            display.drawString(45, 0, "1280x960");
        } else if (rto->presetID == 0x02 || rto->presetID == 0x12) {
            display.drawString(45, 0, "1280x1024");
        } else if (rto->presetID == 0x03 || rto->presetID == 0x13) {
            display.drawString(45, 0, "1280x720");
        } else if (rto->presetID == 0x05 || rto->presetID == 0x15) {
            display.drawString(45, 0, "1920x1080");
        } else if (rto->presetID == 0x06 || rto->presetID == 0x16) {
            display.drawString(45, 0, "Downscale");
        } else if (rto->presetID == 0x04) {
            display.drawString(45, 0, "720x480");
        } else if (rto->presetID == 0x14) {
            display.drawString(45, 0, "768x576");
        } else {
            display.drawString(45, 0, "bypass");
        }

        // Line 2: Input Type and Sync Status with label
        display.drawString(0, 14, "In:   ");
        if (currentInput == 1) {
            display.drawString(45, 14, "RGB");
            vsyncActive = GBS::STATUS_SYNC_PROC_VSACT::read();
            if (vsyncActive) {
                display.drawString(85, 14, "V");
                hsyncActive = GBS::STATUS_SYNC_PROC_HSACT::read();
                if (hsyncActive) {
                    display.drawString(70, 14, "H");
                }
            }
        } else {
            display.drawString(45, 14, "YpBpR");
        }

        // Line 3: Actual Resolution with label
        display.drawString(0, 28, "Out:  ");
        uint16_t h_display = 0;
        uint16_t v_display = 0;
        bool valid_resolution = calculateResolutionFromRegisters(&h_display, &v_display);

        if (valid_resolution) {
            char resolution[32];
            // Check for interlaced signal conditions
            uint16_t v_total = GBS::STATUS_SYNC_PROC_VTOTAL::read();
            uint16_t v_period = GBS::VPERIOD_IF::read();
            bool is_interlaced = (v_total > 570 && v_total < 580) && (v_period > 1100);

            if (is_interlaced) {
                sprintf(resolution, "%dx%di", h_display, v_display);
            } else {
                sprintf(resolution, "%dx%d", h_display, v_display);
            }
            display.drawString(45, 28, resolution);
        } else {
            display.drawString(45, 28, "unknown");
        }

        // Line 4: Refresh Rate with label
        display.drawString(0, 42, "Frq:  ");
        display.drawString(45, 42, String(ofr, 4) + "Hz");
    }
    display.display();
    lastUpdateTime = millis();

    return false;
}
bool wifiMenuHandler(OLEDMenuManager *manager, OLEDMenuItem *item, OLEDMenuNav, bool)
{
    static char ssid[64];
    static char ip[25];
    static char domain[25];
    WiFiMode_t wifiMode = WiFi.getMode();
    manager->clearSubItems(item);
    if (wifiMode == WIFI_STA) {
        sprintf(ssid, "SSID: %s", WiFi.SSID().c_str());
        manager->registerItem(item, 0, ssid);
        if (WiFi.isConnected()) {
            manager->registerItem(item, 0, IMAGE_ITEM(TEXT_WIFI_CONNECTED));
            manager->registerItem(item, 0, IMAGE_ITEM(TEXT_WIFI_URL));
            sprintf(ip, "http://%s", WiFi.localIP().toString().c_str());
            manager->registerItem(item, 0, ip);
            sprintf(domain, "http://%s", device_hostname_full);
            manager->registerItem(item, 0, domain);
        } else {
            // shouldn't happen?
            manager->registerItem(item, 0, IMAGE_ITEM(TEXT_WIFI_DISCONNECTED));
        }
    } else if (wifiMode == WIFI_AP) {
        manager->registerItem(item, 0, IMAGE_ITEM(TEXT_WIFI_CONNECT_TO));
        sprintf(ssid, "SSID: %s (%s)", ap_ssid, ap_password);
        manager->registerItem(item, 0, ssid);
        manager->registerItem(item, 0, IMAGE_ITEM(TEXT_WIFI_URL));
        manager->registerItem(item, 0, "http://192.168.4.1");
        sprintf(domain, "http://%s", device_hostname_full);
        manager->registerItem(item, 0, domain);
    } else {
        // shouldn't happen?
        manager->registerItem(item, 0, IMAGE_ITEM(TEXT_WIFI_DISCONNECTED));
    }
    return true;
}
bool osdMenuHanlder(OLEDMenuManager *manager, OLEDMenuItem *, OLEDMenuNav nav, bool isFirstTime)
{
    static unsigned long start;
    static long left;
    char buf[30];
    auto display = manager->getDisplay();

    if (isFirstTime) {
        left = OSD_TIMEOUT;
        start = millis();
        manager->freeze();
        osdManager.tick(OSDNav::ENTER);
    } else {
        display->clear();
        display->setColor(OLEDDISPLAY_COLOR::WHITE);
        display->setFont(ArialMT_Plain_16);
        display->setTextAlignment(OLEDDISPLAY_TEXT_ALIGNMENT::TEXT_ALIGN_CENTER);
        display->drawStringf(OLED_MENU_WIDTH / 2, 16, buf, "OSD (%ds)", left / 1000 + 1);
        display->display();
        if (REVERSE_ROTARY_ENCODER_FOR_OLED_MENU){
            // reverse nav back to normal
            if(nav == OLEDMenuNav::DOWN) {
                nav = OLEDMenuNav::UP;
            } else if(nav == OLEDMenuNav::UP) {
                nav = OLEDMenuNav::DOWN;
            }
        }
        switch (nav) {
            case OLEDMenuNav::ENTER:
                osdManager.tick(OSDNav::ENTER);
                start = millis();
                break;
            case OLEDMenuNav::DOWN:
                if(REVERSE_ROTARY_ENCODER_FOR_OSD) {
                    osdManager.tick(OSDNav::RIGHT);
                } else {
                    osdManager.tick(OSDNav::LEFT);
                }
                start = millis();
                break;
            case OLEDMenuNav::UP:
                if(REVERSE_ROTARY_ENCODER_FOR_OSD) {
                    osdManager.tick(OSDNav::LEFT);
                } else {
                    osdManager.tick(OSDNav::RIGHT);
                }
                start = millis();
                break;
            default:
                break;
        }
        left = OSD_TIMEOUT - (millis() - start);
        if (left <= 0) {
            manager->unfreeze();
            osdManager.menuOff();
        }
    }
    return true;
}

// Function to calculate resolution from status registers
uint16_t calculateResolutionFromRegisters(uint16_t *h_display, uint16_t *v_display) {
    // Read horizontal period and total from status registers
    uint16_t h_period = GBS::HPERIOD_IF::read();
    uint16_t v_period = GBS::VPERIOD_IF::read();
    uint16_t h_total = GBS::STATUS_SYNC_PROC_HTOTAL::read();
    uint16_t v_total = GBS::STATUS_SYNC_PROC_VTOTAL::read();

    // Debug print raw values
    Serial.printf("Raw values - H: %d, V: %d, HTotal: %d, VTotal: %d\n",
                 h_period, v_period, h_total, v_total);

    // In bypass mode, try to match against standard timings first
    if (rto->outModeHdBypass) {
        // Apply scaling factor to convert register values to actual pixel counts
        float h_scale = 1.8f;  // Base scaling for 1280x960 timing

        // Adjust scaling based on HTotal ranges and vertical resolution
        if (h_total > 2300 && h_total < 2400) {
            if (v_total > 570 && v_total < 580) {  // 1080i timing range
                h_scale = 1.22f;  // Specific scaling for 1080i (2345/1920)
            } else {
                h_scale = 1.83f;  // Keep previous scaling for 1280x960
            }
        } else if (v_total > 700 && v_total < 800) {  // 720p timing range
            h_scale = 1.65f;  // Specific scaling for 720p
        }

        uint16_t scaled_h_total = h_total / h_scale;
        uint16_t scaled_v_total = v_total;

        // Special handling for 1080i - check both v_total and v_period
        bool is_1080i = (v_total > 570 && v_total < 580) && (v_period > 1100);

        // Double v_total for interlaced signals
        if (v_total < 600 || is_1080i) {
            scaled_v_total *= 2;
            Serial.printf("Interlaced signal detected (v_total: %d, v_period: %d)\n",
                         v_total, v_period);
        }

        Serial.printf("Using scale factor: %.2f, Scaled H total: %d, V total: %d\n",
                     h_scale, scaled_h_total, scaled_v_total);

        const VideoTiming* timing = matchStandardTiming(scaled_h_total, scaled_v_total);
        if (timing) {
            *h_display = timing->h_active;
            *v_display = timing->v_active;
            Serial.printf("Matched standard timing: %s (%dx%d)\n",
                        timing->name, timing->h_active, timing->v_active);
            return 1;
        }

        // If no match found, calculate based on the scaled totals
        uint16_t h_active = (scaled_h_total * 85) / 100;  // Typical 85% active pixels
        uint16_t v_active = (scaled_v_total * 95) / 100;  // Typical 95% active lines

        // Special handling for 1080i/p modes and 720p
        if (is_1080i || (scaled_v_total > 1000 && scaled_v_total < 1200)) {
            h_active = 1920;
            v_active = 1080;
            Serial.printf("Forcing 1080 mode (is_1080i: %d)\n", is_1080i);
        } else if (v_total > 700 && v_total < 800) {  // 720p range
            h_active = 1280;
            v_active = 720;
            Serial.printf("Forcing 720p mode\n");
        } else {
            // Round to nearest standard resolution
            if (h_active >= 1100 && h_active <= 1400) {
                h_active = 1280;
            } else if (h_active > 1400) {
                h_active = 1920;
            } else if (h_active > 900) {
                h_active = 1024;
            }

            if (v_active >= 900 && v_active <= 1000) {
                v_active = 960;
            } else if (v_active > 700 && v_active <= 800) {
                v_active = 768;
            } else if (v_active > 500) {
                v_active = 600;
            }
        }

        *h_display = h_active;
        *v_display = v_active;

        Serial.printf("Calculated bypass resolution: %dx%d (from scaled %dx%d)\n",
                    h_active, v_active, scaled_h_total, scaled_v_total);
        return 1;
    }

    // If not in bypass mode or no standard timing match, proceed with normal calculation
    uint16_t h_blank_start = GBS::VDS_DIS_HB_ST::read() % h_total;
    uint16_t h_blank_stop = GBS::VDS_DIS_HB_SP::read() % h_total;
    uint16_t h_display_val;

    // Calculate blanking period with wraparound handling
    uint16_t h_blank_period;
    if (h_blank_start > h_blank_stop) {
        h_blank_period = h_blank_stop + (h_total - h_blank_start);
    } else {
        h_blank_period = h_blank_stop - h_blank_start;
    }

    // In bypass mode with no standard timing match, use typical blanking ratios
    if (rto->outModeHdBypass) {
        // Most video standards use ~20% horizontal blanking
        h_blank_period = h_total * 0.2;
    } else if (h_blank_period > h_total || h_blank_period == 0) {
        h_blank_period = h_total / 4; // Use default only if not in bypass
    }

    h_display_val = h_total - h_blank_period;

    // Calculate vertical active lines
    uint16_t v_blank_start = GBS::VDS_DIS_VB_ST::read() % v_total;
    uint16_t v_blank_stop = GBS::VDS_DIS_VB_SP::read() % v_total;
    uint16_t v_display_val;

    // Calculate vertical blanking period with wraparound handling
    uint16_t v_blank_period;
    if (v_blank_start > v_blank_stop) {
        v_blank_period = v_blank_stop + (v_total - v_blank_start);
    } else {
        v_blank_period = v_blank_stop - v_blank_start;
    }

    // In bypass mode with no standard timing match, use typical blanking ratios
    if (rto->outModeHdBypass) {
        // Most video standards use ~8% vertical blanking
        v_blank_period = v_total * 0.08;
    } else if (v_blank_period > v_total || v_blank_period == 0) {
        v_blank_period = v_total / 4; // Use default only if not in bypass
    }

    v_display_val = v_total - v_blank_period;

    // Apply reasonable limits to calculated values
    if (h_display_val > 1920) h_display_val = 1920;
    if (v_display_val > 1200) v_display_val = 1200;
    if (h_display_val < 640) h_display_val = 640;
    if (v_display_val < 480) v_display_val = 480;

    *h_display = h_display_val;
    *v_display = v_display_val;

    // Debug print calculated values
    Serial.printf("Calculated resolution: %dx%d\n", h_display_val, v_display_val);

    return 1;
}

void initOLEDMenu()
{
    OLEDMenuItem *root = oledMenu.rootItem;

    // OSD Menu
    oledMenu.registerItem(root, MT_NULL, IMAGE_ITEM(OM_OSD), osdMenuHanlder);

    // Resolutions
    OLEDMenuItem *resMenu = oledMenu.registerItem(root, MT_NULL, IMAGE_ITEM(OM_RESOLUTION));
    const char *resolutions[5] = {"1280x960", "1280x1024", "1280x720", "1920x1080", "480/576"};
    uint8_t tags[5] = {MT_1280x960, MT1280x1024, MT1280x720, MT1920x1080, MT_480s576};
    for (int i = 0; i < 5; ++i) {
        oledMenu.registerItem(resMenu, tags[i], resolutions[i], resolutionMenuHandler);
    }
    // downscale and passthrough
    oledMenu.registerItem(resMenu, MT_DOWNSCALE, IMAGE_ITEM(OM_DOWNSCALE), resolutionMenuHandler);
    oledMenu.registerItem(resMenu, MT_BYPASS, IMAGE_ITEM(OM_PASSTHROUGH), resolutionMenuHandler);

    // Presets
    oledMenu.registerItem(root, MT_NULL, IMAGE_ITEM(OM_PRESET), presetsCreationMenuHandler);

    // WiFi
    oledMenu.registerItem(root, MT_NULL, IMAGE_ITEM(OM_WIFI), wifiMenuHandler);

    // Current Settings
    oledMenu.registerItem(root, MT_NULL, IMAGE_ITEM(OM_CURRENT), currentSettingHandler);

    // Reset (Misc.)
    OLEDMenuItem *resetMenu = oledMenu.registerItem(root, MT_NULL, IMAGE_ITEM(OM_RESET_RESTORE));
    oledMenu.registerItem(resetMenu, MT_RESET_GBS, IMAGE_ITEM(OM_RESET_GBS), resetMenuHandler);
    oledMenu.registerItem(resetMenu, MT_RESTORE_FACTORY, IMAGE_ITEM(OM_RESTORE_FACTORY), resetMenuHandler);
    oledMenu.registerItem(resetMenu, MT_RESET_WIFI, IMAGE_ITEM(OM_RESET_WIFI), resetMenuHandler);
}
