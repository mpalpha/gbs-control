# TV5725 Registers Documentation

## Document Information
- Title: TV5725 Registers Definition
- Version: 1.1
- Last Updated: [Current Date]

## Table of Contents
1. [Status Registers](#status-registers)
   - [S0_00: Input Mode Status 00](#register-s0_00-input-mode-status-00-read-only)
   - [S0_01: Input Mode Status 01](#register-s0_01-input-mode-status-01-read-only)
   - [S0_02: Input Mode Status 02](#register-s0_02-input-mode-status-02-read-only)
   - [S0_03: Input Mode Status 03](#register-s0_03-input-mode-status-03-read-only)
   - [S0_04: Input Mode Status 04](#register-s0_04-input-mode-status-04-read-only)
   - [S0_05: Input Mode Status 05](#register-s0_05-input-mode-status-05-read-only)
   - [S0_06-S0_08: Input Size Status](#register-s0_06-input-size-status-00-read-only)
   - [S0_09-S0_0A: MISC Status](#register-s0_09-misc-status-00-read-only)
   - [S0_0B-S0_0D: Chip ID](#register-s0_0b-chip-id-00-read-only)
   - [S0_0E: GPIO Status](#register-s0_0e-gpio-status-00-read-only)
   - [S0_0F: Interrupt Status](#register-s0_0f-interrupt-status-00-read-only)
   - [S0_10-S0_12: Video Processor Status](#register-s0_10-video-processor-status-00-read-only)
   - [S0_13-S0_14: Memory FIFO Status](#register-s0_13-memory-fifo-status-00-read-only)

2. [Input Formatter Registers](#input-formatter-registers)
   - [S1_00-S1_03: Input Format Control](#register-s1_00-input-format-control-00)
   - [S1_04-S1_11: Input Format Timing](#register-s1_04-input-format-control-04)
   - [S1_12-S1_17: Input Format Scaling](#register-s1_12-input-format-scaling-00)
   - [S1_18-S1_2D: Input Format CSC](#register-s1_18-input-format-csc-00)

3. [Deinterlacer Registers](#deinterlacer-registers)
   - [S2_00-S2_03: Deinterlacer Control](#register-s2_00-deinterlacer-control-00)
   - [S2_04-S2_05: Film Mode Control](#register-s2_04-deinterlacer-film-mode-00)
   - [S2_06-S2_09: Motion Control](#register-s2_06-deinterlacer-motion-00)
   - [S2_0A-S2_0B: Processing Control](#register-s2_0a-deinterlacer-processing-00)
   - [S2_0C-S2_13: Film Pattern](#register-s2_0c-deinterlacer-film-pattern-00)
   - [S2_14-S2_17: Edge Control](#register-s2_14-deinterlacer-edge-00)
   - [S2_18-S2_1B: Advanced Control](#register-s2_18-deinterlacer-advanced-00)

4. [HD Bypass Registers](#hd-bypass-registers)
   - [S3_00-S3_02: HD Bypass Control](#register-s3_00-hd-bypass-control-00)
   - [S3_03-S3_0A: HD Bypass Timing](#register-s3_03-hd-bypass-timing-00)

5. [Miscellaneous Registers](#miscellaneous-registers)
   - [S4_00-S4_02: System Control](#register-s4_00-system-control-00)
   - [S4_03: System Status](#register-s4_03-system-status-00)
   - [S4_04-S4_06: GPIO Control](#register-s4_04-gpio-control-00)
   - [S4_07-S4_08: Interrupt Control](#register-s4_07-interrupt-control-00)

6. [Memory Registers](#memory-registers)
   - [S5_00-S5_02: Memory Control](#register-s5_00-memory-control-00)
   - [S5_03-S5_08: Memory Timing](#register-s5_03-memory-timing-00)

7. [Capture & Playback Registers](#capture--playback-registers)
   - [S6_00-S6_01: Capture Control](#register-s6_00-capture-control-00)
   - [S6_02: Playback Control](#register-s6_02-playback-control-00)
   - [S6_03-S6_06: Capture Size](#register-s6_03-capture-size-00)

8. [Write & Read FIFO Registers](#write--read-fifo-registers)
   - [S7_00-S7_03: Write FIFO Control](#register-s7_00-write-fifo-control-00)
   - [S7_04-S7_07: Read FIFO Control](#register-s7_04-read-fifo-control-00)

9. [Video Processor Registers](#video-processor-registers)
   - [S8_00-S8_07: Video Processor Control](#register-s8_00-video-processor-control-00)

10. [OSD Registers](#osd-registers)
    - [S0_90-S0_91: OSD Control](#register-s0_90-osd-control-00)
    - [S0_92-S0_93: OSD Color Control](#register-s0_92-osd-color-control-00)
    - [S0_94: OSD Format Control](#register-s0_94-osd-format-control)
    - [S0_95-S0_98: OSD Position & Bar Control](#register-s0_95-osd-position-control-00)

11. [Mode Detect Registers](#mode-detect-registers)
    - [S1_60-S1_61: Mode Detect Control](#register-s1_60-mode-detect-control-00)
    - [S1_63: Mode Detect Control 03](#register-s1_63-mode-detect-control-03)
    - [S1_65-S1_75: Mode Detect Format Control](#register-s1_65-mode-detect-vga-control)
    - [S1_7F: Mode Detect HD Control](#register-s1_7f-mode-detect-hd-control)

12. [ADC Registers](#adc-registers)
    - [S5_00: ADC Clock Control](#register-s5_00-adc-clock-control-00)
    - [S5_02: ADC SOG Control](#register-s5_02-adc-sog-control)
    - [S5_03: ADC Power Control](#register-s5_03-adc-power-control)
    - [S5_06-S5_08: ADC Offset Control](#register-s5_06-adc-red-offset-control)
    - [S5_09-S5_0B: ADC Gain Control](#register-s5_09-adc-red-gain-control)
    - [S5_0E-S5_0F: ADC Auto Offset](#register-s5_0e-adc-auto-offset-control)

13. [Sync Processor Registers](#sync-processor-registers)
    - [S5_20: Sync Processor Control](#register-s5_20-sync-processor-control-00)
    - [S5_21-S5_26: Sync Timing Control](#register-s5_21-sync-toggle-threshold)
    - [S5_2A-S5_34: Sync Detection Control](#register-s5_2a-period-equality)
    - [S5_3E: Sync Control](#register-s5_3e-sync-control)
    - [S5_41-S5_47: Sync Position Control](#register-s5_41-clamp-start)
    - [S5_55-S5_57: Sync Advanced Control](#register-s5_55-sync-polarity-control)

## Register Map

### Address Map Overview
| Address Range | Section                     |
| ------------- | --------------------------- |
| 00~0F         | Status Register (Read Only) |
| 10~2F         | Input Formatter             |
| 30~3F         | De-interlace                |
| 40~4F         | Video Processor             |
| 50~5F         | Memory                      |
| 60~6F         | ADC                         |
| 70~7F         | Sync Processor              |
| 80~8F         | OSD                         |
| 90~9F         | Mode Detect                 |
| A0~AF         | Reserved                    |
| B0~BF         | Reserved                    |
| C0~CF         | Reserved                    |
| D0~DF         | Reserved                    |
| E0~EF         | Reserved                    |
| F0            | Segment Register            |

### Chapter Overview
| Chapter | Description        | Section                    |
| ------- | ------------------ | -------------------------- |
| 00      | Status Registers   | Read-only status registers |
| 01      | Input Formatter    | Input signal formatting    |
| 02      | Deinterlacer       | Deinterlacing control      |
| 03      | HD Bypass          | HD signal bypass control   |
| 04      | Miscellaneous      | Various control registers  |
| 05      | Memory             | Memory control             |
| 06      | Capture & Playback | Video capture/playback     |
| 07      | Write & Read FIFO  | FIFO operations            |
| 08      | Video Processor    | Video processing           |
| 09      | OSD                | On-screen display          |
| 10      | Mode Detect        | Input mode detection       |
| 11      | ADC                | Analog-digital conversion  |
| 12      | Sync Processor     | Sync signal processing     |

## Status Registers

### Register S0_00: Input Mode Status 00 (Read Only)
| Bit | Name          | Function          | Description                                  |
| --- | ------------- | ----------------- | -------------------------------------------- |
| 0   | IF_STATUS_[0] | Vertical stable   | 1: Input vertical timing is stable           |
| 1   | IF_STATUS_[1] | Horizontal stable | 1: Input horizontal timing is stable         |
| 2   | IF_STATUS_[2] | H & V stable      | 1: Input H/V timing are both stable          |
| 3   | IF_STATUS_[3] | NTSC interlace    | 1: Input is NTSC interlace (480i) source     |
| 4   | IF_STATUS_[4] | NTSC progressive  | 1: Input is NTSC progressive (480P) source   |
| 5   | IF_STATUS_[5] | PAL interlace     | 1: Input is PAL interlace (576i) source      |
| 6   | IF_STATUS_[6] | PAL progressive   | 1: Input is PAL progressive (576P) source    |
| 7   | IF_STATUS_[7] | SD mode           | 1: Input is SD mode (480i, 480P, 576i, 576P) |

### Register S0_01: Input Mode Status 01 (Read Only)
| Bit | Name           | Function       | Description                                          |
| --- | -------------- | -------------- | ---------------------------------------------------- |
| 0   | IF_STATUS_[8]  | VGA 60Hz mode  | 1: Input is VGA (640x480) 60Hz mode                  |
| 1   | IF_STATUS_[9]  | VGA 75Hz mode  | 1: Input is VGA (640x480) 75Hz mode                  |
| 2   | IF_STATUS_[10] | VGA 85Hz mode  | 1: Input is VGA (640x480) 85Hz mode                  |
| 3   | IF_STATUS_[11] | VGA mode       | 1: Input is VGA (640x480) source (any refresh rate)  |
| 4   | IF_STATUS_[12] | SVGA 60Hz mode | 1: Input is SVGA (800x600) 60Hz mode                 |
| 5   | IF_STATUS_[13] | SVGA 75Hz mode | 1: Input is SVGA (800x600) 75Hz mode                 |
| 6   | IF_STATUS_[14] | SVGA 85Hz mode | 1: Input is SVGA (800x600) 85Hz mode                 |
| 7   | IF_STATUS_[15] | SVGA mode      | 1: Input is SVGA (800x600) source (any refresh rate) |

### Register S0_02: Input Mode Status 02 (Read Only)
| Bit | Name           | Function       | Description                                          |
| --- | -------------- | -------------- | ---------------------------------------------------- |
| 0   | IF_STATUS_[16] | XGA 60Hz mode  | 1: Input is XGA (1024x768) 60Hz mode                 |
| 1   | IF_STATUS_[17] | XGA 70Hz mode  | 1: Input is XGA (1024x768) 70Hz mode                 |
| 2   | IF_STATUS_[18] | XGA 75Hz mode  | 1: Input is XGA (1024x768) 75Hz mode                 |
| 3   | IF_STATUS_[19] | XGA 85Hz mode  | 1: Input is XGA (1024x768) 85Hz mode                 |
| 4   | IF_STATUS_[20] | XGA mode       | 1: Input is XGA (1024x768) source (any refresh rate) |
| 5   | IF_STATUS_[21] | SXGA 60Hz mode | 1: Input is SXGA (1280x1024) 60Hz mode               |
| 6   | IF_STATUS_[22] | SXGA 75Hz mode | 1: Input is SXGA (1280x1024) 75Hz mode               |
| 7   | IF_STATUS_[23] | SXGA 85Hz mode | 1: Input is SXGA (1280x1024) 85Hz mode               |

### Register S0_03: Input Mode Status 03 (Read Only)
| Bit | Name           | Function              | Description                                            |
| --- | -------------- | --------------------- | ------------------------------------------------------ |
| 0   | IF_STATUS_[24] | SXGA mode             | 1: Input is SXGA (1280x1024) source (any refresh rate) |
| 1   | IF_STATUS_[25] | Graphic mode          | 1: Input is graphic mode (VGA/SVGA/XGA/SXGA)           |
| 2   | IF_STATUS_[26] | HD720P 50Hz mode      | 1: Input is HD720P (1280x720) 50Hz mode                |
| 3   | IF_STATUS_[27] | HD720P 60Hz mode      | 1: Input is HD720P (1280x720) 60Hz mode                |
| 4   | IF_STATUS_[28] | HD720P mode           | 1: Input is HD720P source (50Hz/60Hz)                  |
| 5   | IF_STATUS_[29] | HD2200_1125 interlace | 1: Input is 2200x1125i mode                            |
| 6   | IF_STATUS_[30] | HD2376_1250 interlace | 1: Input is 2376x1250i mode                            |
| 7   | IF_STATUS_[31] | HD2640_1125 interlace | 1: Input is 2640x1125i mode                            |

### Register S0_04: Input Mode Status 04 (Read Only)
| Bit | Name           | Function          | Description                                                     |
| --- | -------------- | ----------------- | --------------------------------------------------------------- |
| 0   | IF_STATUS_[32] | HD1080i mode      | 1: Input is HD1080i source (2200x1125i, 2376x1250i, 2640x1125i) |
| 1   | IF_STATUS_[33] | HD2200_1125P      | 1: Input is HD 2200x1125P mode                                  |
| 2   | IF_STATUS_[34] | HD2376_1250P      | 1: Input is HD 2376x1250P mode                                  |
| 3   | IF_STATUS_[35] | HD2640_1125P      | 1: Input is HD 2640x1125P mode                                  |
| 4   | IF_STATUS_[36] | HD1080P mode      | 1: Input is HD1080P source (2200x1250P, 2376x1125P)             |
| 5   | IF_STATUS_[37] | HD mode           | 1: Input is HD source (720P, 1080i, 1080P)                      |
| 6   | IF_STATUS_[38] | Interlace video   | 1: Input is interlace video (480i, 576i, 1080i)                 |
| 7   | IF_STATUS_[39] | Progressive video | 1: Input is progressive video (480P, 576P, 720P, 1080P)         |

### Register S0_05: Input Mode Status 05 (Read Only)
| Bit | Name           | Function         | Description                              |
| --- | -------------- | ---------------- | ---------------------------------------- |
| 0   | IF_STATUS_[40] | User define mode | 1: Input matches user-defined resolution |
| 1   | IF_STATUS_[41] | No sync          | 1: Input has no sync timing              |
| 2   | IF_STATUS_[42] | H unstable       | 1: Input H sync is not stable            |
| 3   | IF_STATUS_[43] | V unstable       | 1: Input V sync is not stable            |
| 4   | IF_STATUS_[44] | Mode switch      | 1: Input source has switched mode        |
| 7:5 | RESERVED       | Reserved         | Reserved                                 |

### Register S0_06: Input Size Status 00 (Read Only)
| Bit | Name             | Function            | Description                     |
| --- | ---------------- | ------------------- | ------------------------------- |
| 7:0 | IF_HPERIOD_[7:0] | H total measurement | Input source H total pixels / 4 |

### Register S0_07: Input Size Status 01 (Read Only)
| Bit | Name             | Function            | Description                            |
| --- | ---------------- | ------------------- | -------------------------------------- |
| 0   | IF_HPERIOD_[8]   | H total MSB         | MSB of input source H total pixels / 4 |
| 7:1 | IF_VPERIOD_[6:0] | V total measurement | Input source V total lines             |

### Register S0_08: Input Size Status 02 (Read Only)
| Bit | Name              | Function    | Description                       |
| --- | ----------------- | ----------- | --------------------------------- |
| 3:0 | IF_VPERIOD_[10:7] | V total MSB | MSB of input source V total lines |
| 7:4 | RESERVED          | Reserved    | Reserved                          |

### Register S0_09: MISC Status 00 (Read Only)
| Bit | Name              | Function    | Description           |
| --- | ----------------- | ----------- | --------------------- |
| 5:0 | MISC_STATUS_[5:0] | Reserved    | Reserved              |
| 6   | MISC_STATUS_[6]   | PLL648 LOCK | PLL648 lock indicator |
| 7   | MISC_STATUS_[7]   | PLLAD LOCK  | PLLAD lock indicator  |

### Register S0_0A: MISC Status 01 (Read Only)
| Bit | Name             | Function        | Description                                    |
| --- | ---------------- | --------------- | ---------------------------------------------- |
| 0   | MISC_STATUS_[8]  | PIP V Enable    | 1: Sub picture's vertical period in PIP mode   |
| 1   | MISC_STATUS_[9]  | PIP H Enable    | 1: Sub picture's horizontal period in PIP mode |
| 2   | MISC_STATUS_[10] | Reserved        | Reserved                                       |
| 3   | MISC_STATUS_[11] | Reserved        | Reserved                                       |
| 4   | MISC_STATUS_[12] | Display V Blank | 1: In display vertical blanking                |
| 5   | MISC_STATUS_[13] | Display H Blank | 1: In display horizontal blanking              |
| 6   | MISC_STATUS_[14] | Display V Sync  | 1: In display vertical sync (high active)      |
| 7   | MISC_STATUS_[15] | Display H Sync  | 1: In display horizontal sync (high active)    |

### Register S0_0B: CHIP ID 00 (Read Only)
| Bit | Name          | Function   | Description            |
| --- | ------------- | ---------- | ---------------------- |
| 7:0 | CHIP_ID_[7:0] | Foundry ID | Foundry identification |

### Register S0_0C: CHIP ID 01 (Read Only)
| Bit | Name           | Function   | Description            |
| --- | -------------- | ---------- | ---------------------- |
| 7:0 | CHIP_ID_[15:8] | Product ID | Product identification |

### Register S0_0D: CHIP ID 02 (Read Only)
| Bit | Name            | Function     | Description                  |
| --- | --------------- | ------------ | ---------------------------- |
| 7:0 | CHIP_ID_[23:16] | Chip Version | Chip revision identification |

### Register S0_0E: GPIO Status 00 (Read Only)
| Bit | Name            | Function  | Description                    |
| --- | --------------- | --------- | ------------------------------ |
| 0   | GPIO_STATUS_[0] | GPIO bit0 | GPIO bit0 (GPIO pin76) status  |
| 1   | GPIO_STATUS_[1] | GPIO bit1 | GPIO bit1 (HALF pin77) status  |
| 2   | GPIO_STATUS_[2] | GPIO bit2 | GPIO bit2 (SCLSA pin43) status |
| 3   | GPIO_STATUS_[3] | GPIO bit3 | GPIO bit3 (MBA pin107) status  |
| 4   | GPIO_STATUS_[4] | GPIO bit4 | GPIO bit4 (MCS1 pin109) status |
| 5   | GPIO_STATUS_[5] | GPIO bit5 | GPIO bit5 (HBOUT pin6) status  |
| 6   | GPIO_STATUS_[6] | GPIO bit6 | GPIO bit6 (VBOUT pin7) status  |
| 7   | GPIO_STATUS_[7] | GPIO bit7 | GPIO bit7 (CLKOUT pin4) status |

### Register S0_0F: Interrupt Status 00 (Read Only)
| Bit | Name           | Function      | Description                                      |
| --- | -------------- | ------------- | ------------------------------------------------ |
| 0   | INT_STATUS_[0] | SOG unstable  | 1: Input SOG source is unstable                  |
| 1   | INT_STATUS_[1] | SOG switch    | 1: Input SOG source switched mode                |
| 2   | INT_STATUS_[2] | SOG stable    | 1: Input SOG source is stable                    |
| 3   | INT_STATUS_[3] | Mode switch   | 1: Input source switched mode                    |
| 4   | INT_STATUS_[4] | No sync       | 1: Input source has no H-sync                    |
| 5   | INT_STATUS_[5] | H-sync change | 1: H-sync status changed between stable/unstable |
| 6   | INT_STATUS_[6] | V-sync change | 1: V-sync status changed between stable/unstable |
| 7   | INT_STATUS_[7] | H-sync status | 1: H-sync status changed between stable/unstable |

### Register Access Notes
1. All registers marked with "RO" are read-only.
2. All registers (except chapter 01 status registers) have default value "0x00" after power up.
3. All registers require segment for access. Segment is defined in address F0.

Example:
```
S1_46 means F0 must be set to 1 before accessing 46
S1_46=8D equals following operation:
F0 = 01
46 = 8D
```

### Register S0_10: Video Processor Status 00 (Read Only)
| Bit | Name             | Function      | Description                   |
| --- | ---------------- | ------------- | ----------------------------- |
| 3:0 | VDS_STATUS_[3:0] | Frame number  | Current frame number          |
| 4   | VDS_STATUS_[4]   | Output V Sync | Output vertical sync status   |
| 5   | VDS_STATUS_[5]   | Output H Sync | Output horizontal sync status |
| 7:6 | VDS_STATUS_[7:6] | Reserved      | Reserved                      |

### Register S0_11: Video Processor Status 01 (Read Only)
| Bit | Name               | Function        | Description                                          |
| --- | ------------------ | --------------- | ---------------------------------------------------- |
| 0   | VDS_STATUS_[8]     | Field Index     | 0: Display top field, 1: Display bottom field        |
| 1   | VDS_STATUS_[9]     | Composite Blank | 0: Display active period, 1: Display blanking period |
| 3:2 | VDS_STATUS_[11:10] | Reserved        | Reserved                                             |
| 7:4 | VDS_STATUS_[15:12] | V Counter       | Vertical counter value (line number in display)      |

### Register S0_12: Video Processor Status 02 (Read Only)
| Bit | Name               | Function      | Description                                         |
| --- | ------------------ | ------------- | --------------------------------------------------- |
| 6:0 | VDS_STATUS_[22:16] | V Counter MSB | Vertical counter value MSB (line number in display) |
| 7   | VDS_STATUS_[23]    | Reserved      | Reserved                                            |

### Register S0_13: Memory FIFO Status 00 (Read Only)
| Bit | Name              | Function       | Description               |
| --- | ----------------- | -------------- | ------------------------- |
| 0   | MEM_FF_STATUS_[0] | WFF Full       | 1: Write FIFO is full     |
| 1   | MEM_FF_STATUS_[1] | WFF Empty      | 1: Write FIFO is empty    |
| 2   | MEM_FF_STATUS_[2] | RFF Full       | 1: Read FIFO is full      |
| 3   | MEM_FF_STATUS_[3] | RFF Empty      | 1: Read FIFO is empty     |
| 4   | MEM_FF_STATUS_[4] | Capture Full   | 1: Capture FIFO is full   |
| 5   | MEM_FF_STATUS_[5] | Capture Empty  | 1: Capture FIFO is empty  |
| 6   | MEM_FF_STATUS_[6] | Playback Full  | 1: Playback FIFO is full  |
| 7   | MEM_FF_STATUS_[7] | Playback Empty | 1: Playback FIFO is empty |

### Register S0_14: Memory FIFO Status 01 (Read Only)
| Bit | Name              | Function        | Description                  |
| --- | ----------------- | --------------- | ---------------------------- |
| 0   | MEM_FF_STATUS_[8] | WFF Almost Full | 1: Write FIFO is almost full |
| 1   | MEM_FF_STATUS_[9] | RFF Almost Full | 1: Read FIFO is almost full  |
| 7:2 | RESERVED          | Reserved        | Reserved                     |

### Register S0_15: Deinterlacer Status 00 (Read Only)
| Bit | Name             | Function          | Description                         |
| --- | ---------------- | ----------------- | ----------------------------------- |
| 0   | DEINT_STATUS_[0] | Film Mode         | 1: Film mode detected               |
| 1   | DEINT_STATUS_[1] | Film Phase        | Current film phase                  |
| 2   | DEINT_STATUS_[2] | Motion            | 1: Motion detected in current field |
| 3   | DEINT_STATUS_[3] | Field Index       | 0: Top field, 1: Bottom field       |
| 4   | DEINT_STATUS_[4] | Film Lock         | 1: Film sequence locked             |
| 5   | DEINT_STATUS_[5] | Film Unlock Count | Film unlock counter value           |
| 6   | DEINT_STATUS_[6] | Film Mode Type    | 0: 3:2 pulldown, 1: 2:2 pulldown    |
| 7   | DEINT_STATUS_[7] | Reserved          | Reserved                            |

### Register S0_16: Sync Processor Status 00 (Read Only)
| Bit | Name              | Function        | Description                    |
| --- | ----------------- | --------------- | ------------------------------ |
| 0   | SYNC_STATUS_[0]   | H Sync Polarity | 1: H sync is positive polarity |
| 1   | SYNC_STATUS_[1]   | V Sync Polarity | 1: V sync is positive polarity |
| 2   | SYNC_STATUS_[2]   | SOG Level       | Current SOG level              |
| 3   | SYNC_STATUS_[3]   | H Sync Present  | 1: H sync signal is present    |
| 4   | SYNC_STATUS_[4]   | V Sync Present  | 1: V sync signal is present    |
| 5   | SYNC_STATUS_[5]   | Sync Source     | 0: Separate sync, 1: SOG       |
| 7:6 | SYNC_STATUS_[7:6] | Reserved        | Reserved                       |

### Register S0_17: Sync Processor Status 01 (Read Only)
| Bit | Name               | Function     | Description                     |
| --- | ------------------ | ------------ | ------------------------------- |
| 7:0 | SYNC_STATUS_[15:8] | H Period LSB | H sync period measurement (LSB) |

### Register S0_18: Sync Processor Status 02 (Read Only)
| Bit | Name                | Function     | Description                     |
| --- | ------------------- | ------------ | ------------------------------- |
| 7:0 | SYNC_STATUS_[23:16] | H Period MSB | H sync period measurement (MSB) |

### Register S0_19: Sync Processor Status 03 (Read Only)
| Bit | Name                | Function     | Description                     |
| --- | ------------------- | ------------ | ------------------------------- |
| 7:0 | SYNC_STATUS_[31:24] | V Period LSB | V sync period measurement (LSB) |

### Register S0_1A: Sync Processor Status 04 (Read Only)
| Bit | Name                | Function     | Description                     |
| --- | ------------------- | ------------ | ------------------------------- |
| 7:0 | SYNC_STATUS_[39:32] | V Period MSB | V sync period measurement (MSB) |

### Register S0_1B: Sync Processor Status 05 (Read Only)
| Bit | Name                | Function    | Description                    |
| --- | ------------------- | ----------- | ------------------------------ |
| 7:0 | SYNC_STATUS_[47:40] | H Width LSB | H sync width measurement (LSB) |

### Register S0_1C: Sync Processor Status 06 (Read Only)
| Bit | Name                | Function    | Description                    |
| --- | ------------------- | ----------- | ------------------------------ |
| 7:0 | SYNC_STATUS_[55:48] | H Width MSB | H sync width measurement (MSB) |

### Register S0_1D: Sync Processor Status 07 (Read Only)
| Bit | Name                | Function    | Description                    |
| --- | ------------------- | ----------- | ------------------------------ |
| 7:0 | SYNC_STATUS_[63:56] | V Width LSB | V sync width measurement (LSB) |

### Register S0_1E: Sync Processor Status 08 (Read Only)
| Bit | Name                | Function    | Description                    |
| --- | ------------------- | ----------- | ------------------------------ |
| 7:0 | SYNC_STATUS_[71:64] | V Width MSB | V sync width measurement (MSB) |

### Register S0_1F: Test Bus Status 00 (Read Only)
| Bit | Name              | Function     | Description          |
| --- | ----------------- | ------------ | -------------------- |
| 7:0 | TEST_STATUS_[7:0] | Test Bus LSB | Test bus value [7:0] |

### Register S0_20: Test FIFO Status 00 (Read Only)
| Bit | Name                 | Function       | Description           |
| --- | -------------------- | -------------- | --------------------- |
| 7:0 | TEST_FF_STATUS_[7:0] | Test FIFO Data | Test FIFO data output |

### Register S0_21: Test FIFO Status 01 (Read Only)
| Bit | Name                  | Function          | Description              |
| --- | --------------------- | ----------------- | ------------------------ |
| 7:0 | TEST_FF_STATUS_[15:8] | Test FIFO Control | Test FIFO control status |

### Register S0_22: CRC RFF Status 00 (Read Only)
| Bit | Name                 | Function          | Description               |
| --- | -------------------- | ----------------- | ------------------------- |
| 7:0 | CRC_RFF_STATUS_[7:0] | CRC RFF Value LSB | CRC Read FIFO value [7:0] |

### Register S0_23: CRC PB Status 00 (Read Only)
| Bit | Name                | Function         | Description              |
| --- | ------------------- | ---------------- | ------------------------ |
| 7:0 | CRC_PB_STATUS_[7:0] | CRC PB Value LSB | CRC Playback value [7:0] |

### Register S0_24: CRC Result Status 00 (Read Only)
| Bit | Name             | Function       | Description                  |
| --- | ---------------- | -------------- | ---------------------------- |
| 7:0 | CRC_RESULT_[7:0] | CRC Result LSB | CRC calculation result [7:0] |

### Register S0_25: CRC Result Status 01 (Read Only)
| Bit | Name              | Function   | Description                   |
| --- | ----------------- | ---------- | ----------------------------- |
| 7:0 | CRC_RESULT_[15:8] | CRC Result | CRC calculation result [15:8] |

### Register S0_26: CRC Result Status 02 (Read Only)
| Bit | Name               | Function   | Description                    |
| --- | ------------------ | ---------- | ------------------------------ |
| 7:0 | CRC_RESULT_[23:16] | CRC Result | CRC calculation result [23:16] |

### Register S0_27: CRC Result Status 03 (Read Only)
| Bit | Name               | Function   | Description                    |
| --- | ------------------ | ---------- | ------------------------------ |
| 7:0 | CRC_RESULT_[31:24] | CRC Result | CRC calculation result [31:24] |

### Register S0_28: CRC Result Status 04 (Read Only)
| Bit | Name               | Function   | Description                    |
| --- | ------------------ | ---------- | ------------------------------ |
| 7:0 | CRC_RESULT_[39:32] | CRC Result | CRC calculation result [39:32] |

### Register S0_29: CRC Result Status 05 (Read Only)
| Bit | Name               | Function   | Description                    |
| --- | ------------------ | ---------- | ------------------------------ |
| 7:0 | CRC_RESULT_[47:40] | CRC Result | CRC calculation result [47:40] |

### Register S0_2A: CRC Result Status 06 (Read Only)
| Bit | Name               | Function   | Description                    |
| --- | ------------------ | ---------- | ------------------------------ |
| 7:0 | CRC_RESULT_[55:48] | CRC Result | CRC calculation result [55:48] |

### Register S0_2B: CRC Result Status 07 (Read Only)
| Bit | Name               | Function   | Description                    |
| --- | ------------------ | ---------- | ------------------------------ |
| 7:0 | CRC_RESULT_[63:56] | CRC Result | CRC calculation result [63:56] |

### Register S0_2C: CRC Result Status 08 (Read Only)
| Bit | Name               | Function   | Description                    |
| --- | ------------------ | ---------- | ------------------------------ |
| 7:0 | CRC_RESULT_[71:64] | CRC Result | CRC calculation result [71:64] |

### Register S0_2D: CRC Result Status 09 (Read Only)
| Bit | Name               | Function   | Description                    |
| --- | ------------------ | ---------- | ------------------------------ |
| 7:0 | CRC_RESULT_[79:72] | CRC Result | CRC calculation result [79:72] |

### Register S0_2E: Test Bus Status 01 (Read Only)
| Bit | Name               | Function     | Description           |
| --- | ------------------ | ------------ | --------------------- |
| 7:0 | TEST_STATUS_[15:8] | Test Bus MSB | Test bus value [15:8] |

### Register S0_2F: Test Bus Status 02 (Read Only)
| Bit | Name                | Function          | Description            |
| --- | ------------------- | ----------------- | ---------------------- |
| 7:0 | TEST_STATUS_[23:16] | Test Bus Extended | Test bus value [23:16] |

## Input Formatter Registers

The Input Formatter section (Chapter 01) controls how input video signals are processed and formatted. These registers configure input timing, sync detection, and signal processing parameters.

### Register S1_00: Input Format Control 00
| Bit | Name        | Function           | Description                                         |
| --- | ----------- | ------------------ | --------------------------------------------------- |
| 0   | IF_CTRL_[0] | Input Enable       | 1: Enable input formatter                           |
| 1   | IF_CTRL_[1] | Input Invert       | 1: Invert input data polarity                       |
| 2   | IF_CTRL_[2] | Input Swap         | 1: Swap input data MSB/LSB                          |
| 3   | IF_CTRL_[3] | Input Clock Edge   | 0: Sample at rising edge, 1: Sample at falling edge |
| 4   | IF_CTRL_[4] | Input Clock Delay  | 1: Enable input clock delay                         |
| 5   | IF_CTRL_[5] | Input Clock Phase  | 1: Invert input clock phase                         |
| 6   | IF_CTRL_[6] | Input Clock Mode   | 0: Single edge, 1: Double edge sampling             |
| 7   | IF_CTRL_[7] | Input Clock Source | 0: External clock, 1: Internal PLL clock            |

### Register S1_01: Input Format Control 01
| Bit | Name            | Function           | Description                                        |
| --- | --------------- | ------------------ | -------------------------------------------------- |
| 1:0 | IF_CTRL_[9:8]   | Input Format       | 00: YCbCr422, 01: RGB888, 10: YCbCr444, 11: RGB565 |
| 3:2 | IF_CTRL_[11:10] | Input Color Space  | 00: RGB, 01: YCbCr601, 10: YCbCr709, 11: Reserved  |
| 4   | IF_CTRL_[12]    | Input Range        | 0: Full range (0-255), 1: Limited range (16-235)   |
| 5   | IF_CTRL_[13]    | Input Field Order  | 0: Even field first, 1: Odd field first            |
| 6   | IF_CTRL_[14]    | Input Interlace    | 0: Progressive, 1: Interlaced                      |
| 7   | IF_CTRL_[15]    | Input Field Toggle | 1: Toggle field every frame                        |

### Register S1_02: Input Format Control 02
| Bit | Name         | Function        | Description                   |
| --- | ------------ | --------------- | ----------------------------- |
| 0   | IF_CTRL_[16] | H-Sync Polarity | 0: Active low, 1: Active high |
| 1   | IF_CTRL_[17] | V-Sync Polarity | 0: Active low, 1: Active high |
| 2   | IF_CTRL_[18] | DE Polarity     | 0: Active low, 1: Active high |
| 3   | IF_CTRL_[19] | Field Polarity  | 0: Active low, 1: Active high |
| 4   | IF_CTRL_[20] | SOG Enable      | 1: Enable Sync-On-Green       |
| 5   | IF_CTRL_[21] | Coast Enable    | 1: Enable coast function      |
| 6   | IF_CTRL_[22] | Clamp Enable    | 1: Enable clamp function      |
| 7   | IF_CTRL_[23] | ADC Sync Source | 0: External sync, 1: SOG sync |

### Register S1_03: Input Format Control 03
| Bit | Name         | Function       | Description                           |
| --- | ------------ | -------------- | ------------------------------------- |
| 0   | IF_CTRL_[24] | H-Sync Input   | 1: Enable H-Sync input                |
| 1   | IF_CTRL_[25] | V-Sync Input   | 1: Enable V-Sync input                |
| 2   | IF_CTRL_[26] | DE Input       | 1: Enable DE (Data Enable) input      |
| 3   | IF_CTRL_[27] | Field Input    | 1: Enable Field input                 |
| 4   | IF_CTRL_[28] | Auto Detection | 1: Enable input format auto detection |
| 5   | IF_CTRL_[29] | Mode Lock      | 1: Lock current detected mode         |
| 6   | IF_CTRL_[30] | Coast Lock     | 1: Lock coast timing                  |
| 7   | IF_CTRL_[31] | Clamp Lock     | 1: Lock clamp timing                  |

### Register S1_04: Input Format Control 04
| Bit | Name            | Function        | Description                                  |
| --- | --------------- | --------------- | -------------------------------------------- |
| 7:0 | IF_CTRL_[39:32] | H-Sync Duration | Minimum H-Sync pulse width (in pixel clocks) |

### Register S1_05: Input Format Control 05
| Bit | Name            | Function        | Description                                 |
| --- | --------------- | --------------- | ------------------------------------------- |
| 7:0 | IF_CTRL_[47:40] | V-Sync Duration | Minimum V-Sync pulse width (in line counts) |

### Register S1_06: Input Format Timing 00
| Bit | Name            | Function    | Description                            |
| --- | --------------- | ----------- | -------------------------------------- |
| 7:0 | IF_TIMING_[7:0] | H-Total Low | Horizontal total pixels (lower 8 bits) |

### Register S1_07: Input Format Timing 01
| Bit | Name              | Function           | Description                                     |
| --- | ----------------- | ------------------ | ----------------------------------------------- |
| 3:0 | IF_TIMING_[11:8]  | H-Total High       | Horizontal total pixels (upper 4 bits)          |
| 7:4 | IF_TIMING_[15:12] | H-Active Start Low | Horizontal active start position (lower 4 bits) |

### Register S1_08: Input Format Timing 02
| Bit | Name              | Function            | Description                                     |
| --- | ----------------- | ------------------- | ----------------------------------------------- |
| 7:0 | IF_TIMING_[23:16] | H-Active Start High | Horizontal active start position (upper 8 bits) |

### Register S1_09: Input Format Timing 03
| Bit | Name              | Function           | Description                            |
| --- | ----------------- | ------------------ | -------------------------------------- |
| 3:0 | IF_TIMING_[27:24] | H-Active Width Low | Horizontal active width (lower 4 bits) |
| 7:4 | IF_TIMING_[31:28] | Reserved           | Reserved                               |

### Register S1_0A: Input Format Timing 04
| Bit | Name              | Function            | Description                            |
| --- | ----------------- | ------------------- | -------------------------------------- |
| 7:0 | IF_TIMING_[39:32] | H-Active Width High | Horizontal active width (upper 8 bits) |

### Register S1_0B: Input Format Timing 05
| Bit | Name              | Function    | Description                         |
| --- | ----------------- | ----------- | ----------------------------------- |
| 7:0 | IF_TIMING_[47:40] | V-Total Low | Vertical total lines (lower 8 bits) |

### Register S1_0C: Input Format Timing 06
| Bit | Name              | Function           | Description                               |
| --- | ----------------- | ------------------ | ----------------------------------------- |
| 3:0 | IF_TIMING_[51:48] | V-Total High       | Vertical total lines (upper 4 bits)       |
| 7:4 | IF_TIMING_[55:52] | V-Active Start Low | Vertical active start line (lower 4 bits) |

### Register S1_0D: Input Format Timing 07
| Bit | Name              | Function            | Description                               |
| --- | ----------------- | ------------------- | ----------------------------------------- |
| 7:0 | IF_TIMING_[63:56] | V-Active Start High | Vertical active start line (upper 8 bits) |

### Register S1_0E: Input Format Timing 08
| Bit | Name              | Function            | Description                           |
| --- | ----------------- | ------------------- | ------------------------------------- |
| 3:0 | IF_TIMING_[67:64] | V-Active Height Low | Vertical active height (lower 4 bits) |
| 7:4 | IF_TIMING_[71:68] | Reserved            | Reserved                              |

### Register S1_0F: Input Format Timing 09
| Bit | Name              | Function             | Description                           |
| --- | ----------------- | -------------------- | ------------------------------------- |
| 7:0 | IF_TIMING_[79:72] | V-Active Height High | Vertical active height (upper 8 bits) |

### Register S1_10: Input Format Timing 10
| Bit | Name              | Function       | Description                                    |
| --- | ----------------- | -------------- | ---------------------------------------------- |
| 7:0 | IF_TIMING_[87:80] | Field 2 Offset | Second field vertical offset (interlaced mode) |

### Register S1_11: Input Format Timing 11
| Bit | Name              | Function     | Description                      |
| --- | ----------------- | ------------ | -------------------------------- |
| 7:0 | IF_TIMING_[95:88] | Field Length | Field length for interlaced mode |

### Register S1_12: Input Format Scaling 00
| Bit | Name         | Function        | Description                      |
| --- | ------------ | --------------- | -------------------------------- |
| 0   | IF_SCALE_[0] | H-Scale Enable  | 1: Enable horizontal scaling     |
| 1   | IF_SCALE_[1] | V-Scale Enable  | 1: Enable vertical scaling       |
| 2   | IF_SCALE_[2] | H-Scale Mode    | 0: Linear, 1: Non-linear         |
| 3   | IF_SCALE_[3] | V-Scale Mode    | 0: Linear, 1: Non-linear         |
| 4   | IF_SCALE_[4] | H-Filter Enable | 1: Enable horizontal filter      |
| 5   | IF_SCALE_[5] | V-Filter Enable | 1: Enable vertical filter        |
| 6   | IF_SCALE_[6] | Filter Mode     | 0: 2-tap filter, 1: 4-tap filter |
| 7   | IF_SCALE_[7] | Scale Lock      | 1: Lock scaling parameters       |

### Register S1_13: Input Format Scaling 01
| Bit | Name            | Function          | Description                             |
| --- | --------------- | ----------------- | --------------------------------------- |
| 7:0 | IF_SCALE_[15:8] | H-Scale Ratio Low | Horizontal scaling ratio (lower 8 bits) |

### Register S1_14: Input Format Scaling 02
| Bit | Name             | Function           | Description                             |
| --- | ---------------- | ------------------ | --------------------------------------- |
| 3:0 | IF_SCALE_[19:16] | H-Scale Ratio High | Horizontal scaling ratio (upper 4 bits) |
| 7:4 | IF_SCALE_[23:20] | H-Scale Init Phase | Horizontal scaling initial phase        |

### Register S1_15: Input Format Scaling 03
| Bit | Name             | Function          | Description                           |
| --- | ---------------- | ----------------- | ------------------------------------- |
| 7:0 | IF_SCALE_[31:24] | V-Scale Ratio Low | Vertical scaling ratio (lower 8 bits) |

### Register S1_16: Input Format Scaling 04
| Bit | Name             | Function           | Description                           |
| --- | ---------------- | ------------------ | ------------------------------------- |
| 3:0 | IF_SCALE_[35:32] | V-Scale Ratio High | Vertical scaling ratio (upper 4 bits) |
| 7:4 | IF_SCALE_[39:36] | V-Scale Init Phase | Vertical scaling initial phase        |

### Register S1_17: Input Format Scaling 05
| Bit | Name             | Function             | Description                          |
| --- | ---------------- | -------------------- | ------------------------------------ |
| 1:0 | IF_SCALE_[41:40] | H-Filter Coefficient | Horizontal filter coefficient select |
| 3:2 | IF_SCALE_[43:42] | V-Filter Coefficient | Vertical filter coefficient select   |
| 5:4 | IF_SCALE_[45:44] | H-Scale Mode Select  | Horizontal scaling algorithm select  |
| 7:6 | IF_SCALE_[47:46] | V-Scale Mode Select  | Vertical scaling algorithm select    |

### Register Access Notes for Scaling
1. Scaling ratios are in 12.4 fixed-point format
2. For downscaling ratio N:M (N>M), value = (N-M)/M × 4096
3. For upscaling ratio N:M (N<M), value = (M-N)/N × 4096
4. Filter coefficients:
   - 00: Nearest neighbor (no filtering)
   - 01: Bilinear
   - 10: Bicubic
   - 11: Reserved
5. Scaling mode select:
   - 00: Simple (nearest neighbor)
   - 01: Bilinear
   - 10: Polyphase
   - 11: Reserved
6. Initial phase values range from 0 to 15
7. Changes to scaling registers take effect at the start of the next frame

### Register S1_18: Input Format CSC 00
| Bit | Name         | Function     | Description                                      |
| --- | ------------ | ------------ | ------------------------------------------------ |
| 0   | IF_CSC_[0]   | CSC Enable   | 1: Enable color space conversion                 |
| 1   | IF_CSC_[1]   | CSC Mode     | 0: RGB to YCbCr, 1: YCbCr to RGB                 |
| 2   | IF_CSC_[2]   | CSC Format   | 0: 601, 1: 709                                   |
| 3   | IF_CSC_[3]   | CSC Range    | 0: Full range (0-255), 1: Limited range (16-235) |
| 4   | IF_CSC_[4]   | Clip Enable  | 1: Enable output clipping                        |
| 5   | IF_CSC_[5]   | Round Enable | 1: Enable coefficient rounding                   |
| 7:6 | IF_CSC_[7:6] | Reserved     | Reserved                                         |

### Register S1_19: Input Format CSC 01
| Bit | Name          | Function | Description                        |
| --- | ------------- | -------- | ---------------------------------- |
| 7:0 | IF_CSC_[15:8] | K11 Low  | CSC coefficient K11 (lower 8 bits) |

### Register S1_1A: Input Format CSC 02
| Bit | Name           | Function | Description                        |
| --- | -------------- | -------- | ---------------------------------- |
| 5:0 | IF_CSC_[21:16] | K11 High | CSC coefficient K11 (upper 6 bits) |
| 7:6 | IF_CSC_[23:22] | Reserved | Reserved                           |

### Register S1_1B: Input Format CSC 03
| Bit | Name           | Function | Description                        |
| --- | -------------- | -------- | ---------------------------------- |
| 7:0 | IF_CSC_[31:24] | K12 Low  | CSC coefficient K12 (lower 8 bits) |

### Register S1_1C: Input Format CSC 04
| Bit | Name           | Function | Description                        |
| --- | -------------- | -------- | ---------------------------------- |
| 5:0 | IF_CSC_[37:32] | K12 High | CSC coefficient K12 (upper 6 bits) |
| 7:6 | IF_CSC_[39:38] | Reserved | Reserved                           |

### Register S1_1D: Input Format CSC 05
| Bit | Name           | Function | Description                        |
| --- | -------------- | -------- | ---------------------------------- |
| 7:0 | IF_CSC_[47:40] | K13 Low  | CSC coefficient K13 (lower 8 bits) |

### Register S1_1E: Input Format CSC 06
| Bit | Name           | Function | Description                        |
| --- | -------------- | -------- | ---------------------------------- |
| 5:0 | IF_CSC_[53:48] | K13 High | CSC coefficient K13 (upper 6 bits) |
| 7:6 | IF_CSC_[55:54] | Reserved | Reserved                           |

### Register S1_1F: Input Format CSC 07
| Bit | Name           | Function | Description                        |
| --- | -------------- | -------- | ---------------------------------- |
| 7:0 | IF_CSC_[63:56] | K21 Low  | CSC coefficient K21 (lower 8 bits) |

### Register Access Notes for Color Space Conversion
1. CSC coefficients are in 2.8 fixed-point format
2. Default coefficients for RGB to YCbCr 601:
   - K11 = 0.299, K12 = 0.587, K13 = 0.114 (Y)
   - K21 = -0.169, K22 = -0.331, K23 = 0.500 (Cb)
   - K31 = 0.500, K32 = -0.419, K33 = -0.081 (Cr)
3. Default coefficients for RGB to YCbCr 709:
   - K11 = 0.213, K12 = 0.715, K13 = 0.072 (Y)
   - K21 = -0.115, K22 = -0.385, K23 = 0.500 (Cb)
   - K31 = 0.500, K32 = -0.454, K33 = -0.046 (Cr)
4. For YCbCr to RGB conversion, the inverse matrices are used
5. Changes to CSC registers take effect immediately

### Register S1_20: Input Format CSC 08
| Bit | Name           | Function | Description                        |
| --- | -------------- | -------- | ---------------------------------- |
| 5:0 | IF_CSC_[69:64] | K21 High | CSC coefficient K21 (upper 6 bits) |
| 7:6 | IF_CSC_[71:70] | Reserved | Reserved                           |

### Register S1_21: Input Format CSC 09
| Bit | Name           | Function | Description                        |
| --- | -------------- | -------- | ---------------------------------- |
| 7:0 | IF_CSC_[79:72] | K22 Low  | CSC coefficient K22 (lower 8 bits) |

### Register S1_22: Input Format CSC 10
| Bit | Name           | Function | Description                        |
| --- | -------------- | -------- | ---------------------------------- |
| 5:0 | IF_CSC_[85:80] | K22 High | CSC coefficient K22 (upper 6 bits) |
| 7:6 | IF_CSC_[87:86] | Reserved | Reserved                           |

### Register S1_23: Input Format CSC 11
| Bit | Name           | Function | Description                        |
| --- | -------------- | -------- | ---------------------------------- |
| 7:0 | IF_CSC_[95:88] | K23 Low  | CSC coefficient K23 (lower 8 bits) |

### Register S1_24: Input Format CSC 12
| Bit | Name             | Function | Description                        |
| --- | ---------------- | -------- | ---------------------------------- |
| 5:0 | IF_CSC_[101:96]  | K23 High | CSC coefficient K23 (upper 6 bits) |
| 7:6 | IF_CSC_[103:102] | Reserved | Reserved                           |

### Register S1_25: Input Format CSC 13
| Bit | Name             | Function | Description                        |
| --- | ---------------- | -------- | ---------------------------------- |
| 7:0 | IF_CSC_[111:104] | K31 Low  | CSC coefficient K31 (lower 8 bits) |

### Register S1_26: Input Format CSC 14
| Bit | Name             | Function | Description                        |
| --- | ---------------- | -------- | ---------------------------------- |
| 5:0 | IF_CSC_[117:112] | K31 High | CSC coefficient K31 (upper 6 bits) |
| 7:6 | IF_CSC_[119:118] | Reserved | Reserved                           |

### Register S1_27: Input Format CSC 15
| Bit | Name             | Function | Description                        |
| --- | ---------------- | -------- | ---------------------------------- |
| 7:0 | IF_CSC_[127:120] | K32 Low  | CSC coefficient K32 (lower 8 bits) |

### Register S1_28: Input Format CSC 16
| Bit | Name             | Function | Description                        |
| --- | ---------------- | -------- | ---------------------------------- |
| 5:0 | IF_CSC_[133:128] | K32 High | CSC coefficient K32 (upper 6 bits) |
| 7:6 | IF_CSC_[135:134] | Reserved | Reserved                           |

### Register S1_29: Input Format CSC 17
| Bit | Name             | Function | Description                        |
| --- | ---------------- | -------- | ---------------------------------- |
| 7:0 | IF_CSC_[143:136] | K33 Low  | CSC coefficient K33 (lower 8 bits) |

### Register S1_2A: Input Format CSC 18
| Bit | Name             | Function | Description                        |
| --- | ---------------- | -------- | ---------------------------------- |
| 5:0 | IF_CSC_[149:144] | K33 High | CSC coefficient K33 (upper 6 bits) |
| 7:6 | IF_CSC_[151:150] | Reserved | Reserved                           |

### Register S1_2B: Input Format CSC Offset 00
| Bit | Name             | Function | Description      |
| --- | ---------------- | -------- | ---------------- |
| 7:0 | IF_CSC_[159:152] | Y Offset | Y/R offset value |

### Register S1_2C: Input Format CSC Offset 01
| Bit | Name             | Function  | Description       |
| --- | ---------------- | --------- | ----------------- |
| 7:0 | IF_CSC_[167:160] | Cb Offset | Cb/G offset value |

### Register S1_2D: Input Format CSC Offset 02
| Bit | Name             | Function  | Description       |
| --- | ---------------- | --------- | ----------------- |
| 7:0 | IF_CSC_[175:168] | Cr Offset | Cr/B offset value |

### Register S1_2E: Input Format Reserved
| Bit | Name     | Function | Description             |
| --- | -------- | -------- | ----------------------- |
| 7:0 | Reserved | Reserved | Reserved for future use |

### Register S1_2F: Input Format Reserved
| Bit | Name     | Function | Description             |
| --- | -------- | -------- | ----------------------- |
| 7:0 | Reserved | Reserved | Reserved for future use |

### Additional Notes for Color Space Conversion
1. Offset values are used for level shifting in color space conversion:
   - For RGB to YCbCr: Y offset = 16, Cb/Cr offset = 128 (limited range)
   - For YCbCr to RGB: All offsets = 0
2. When using full range (0-255):
   - RGB to YCbCr: Y offset = 0, Cb/Cr offset = 128
   - YCbCr to RGB: R/G/B offset = 0
3. The CSC matrix operation is:
   ```
   Y/R  = (K11×R + K12×G + K13×B) + Y_offset
   Cb/G = (K21×R + K22×G + K23×B) + Cb_offset
   Cr/B = (K31×R + K32×G + K33×B) + Cr_offset
   ```
4. All coefficients and calculations maintain 14-bit precision internally

## Deinterlacer Registers

The Deinterlacer section (Chapter 02) controls the deinterlacing process for converting interlaced video signals to progressive scan. These registers configure motion detection, film mode detection, and various deinterlacing algorithms.

### Register S2_00: Deinterlacer Control 00
| Bit | Name           | Function           | Description                                  |
| --- | -------------- | ------------------ | -------------------------------------------- |
| 0   | DEINT_CTRL_[0] | Deinterlace Enable | 1: Enable deinterlacing                      |
| 1   | DEINT_CTRL_[1] | Film Mode Enable   | 1: Enable film mode detection                |
| 2   | DEINT_CTRL_[2] | Motion Enable      | 1: Enable motion adaptive processing         |
| 3   | DEINT_CTRL_[3] | Field Repeat       | 1: Enable field repeat mode                  |
| 4   | DEINT_CTRL_[4] | Vertical Filter    | 1: Enable vertical filtering                 |
| 5   | DEINT_CTRL_[5] | Edge Detection     | 1: Enable edge-based processing              |
| 6   | DEINT_CTRL_[6] | Auto Film Mode     | 1: Enable automatic film mode detection      |
| 7   | DEINT_CTRL_[7] | Force Film Mode    | 1: Force film mode (override auto detection) |

### Register S2_01: Deinterlacer Control 01
| Bit | Name               | Function           | Description                                      |
| --- | ------------------ | ------------------ | ------------------------------------------------ |
| 1:0 | DEINT_CTRL_[9:8]   | Film Mode Type     | 00: 3:2, 01: 2:2, 10: Custom, 11: Reserved       |
| 3:2 | DEINT_CTRL_[11:10] | Motion Sensitivity | 00: Low, 01: Medium, 10: High, 11: Custom        |
| 5:4 | DEINT_CTRL_[13:12] | Edge Sensitivity   | 00: Low, 01: Medium, 10: High, 11: Custom        |
| 7:6 | DEINT_CTRL_[15:14] | Field Polarity     | 00: Auto, 01: Normal, 10: Inverted, 11: Reserved |

### Register S2_02: Deinterlacer Control 02
| Bit | Name               | Function         | Description                      |
| --- | ------------------ | ---------------- | -------------------------------- |
| 7:0 | DEINT_CTRL_[23:16] | Motion Threshold | Motion detection threshold value |

### Register S2_03: Deinterlacer Control 03
| Bit | Name               | Function       | Description                    |
| --- | ------------------ | -------------- | ------------------------------ |
| 7:0 | DEINT_CTRL_[31:24] | Edge Threshold | Edge detection threshold value |

### Register S2_04: Deinterlacer Film Mode 00
| Bit | Name             | Function        | Description                                     |
| --- | ---------------- | --------------- | ----------------------------------------------- |
| 7:0 | DEINT_FILM_[7:0] | Film Lock Count | Number of frames to confirm film mode detection |

### Register S2_05: Deinterlacer Film Mode 01
| Bit | Name              | Function          | Description                                 |
| --- | ----------------- | ----------------- | ------------------------------------------- |
| 7:0 | DEINT_FILM_[15:8] | Film Unlock Count | Number of frames before disabling film mode |

### Register Access Notes for Deinterlacer Control
1. All Deinterlacer registers require segment 2 (F0 = 02) for access
2. Motion and edge thresholds are 8-bit values (0-255)
3. Higher threshold values make detection more conservative
4. Film mode detection requires stable input timing
5. Changes to control registers take effect at the start of the next frame

### Register S2_06: Deinterlacer Motion 00
| Bit | Name               | Function     | Description                         |
| --- | ------------------ | ------------ | ----------------------------------- |
| 7:0 | DEINT_MOTION_[7:0] | Motion Alpha | Motion blending coefficient (0-255) |

### Register S2_07: Deinterlacer Motion 01
| Bit | Name                | Function    | Description                          |
| --- | ------------------- | ----------- | ------------------------------------ |
| 7:0 | DEINT_MOTION_[15:8] | Motion Beta | Secondary motion coefficient (0-255) |

### Register S2_08: Deinterlacer Motion 02
| Bit | Name                 | Function          | Description                          |
| --- | -------------------- | ----------------- | ------------------------------------ |
| 3:0 | DEINT_MOTION_[19:16] | Min Motion Width  | Minimum motion region width (pixels) |
| 7:4 | DEINT_MOTION_[23:20] | Min Motion Height | Minimum motion region height (lines) |

### Register S2_09: Deinterlacer Motion 03
| Bit | Name                 | Function           | Description                        |
| --- | -------------------- | ------------------ | ---------------------------------- |
| 3:0 | DEINT_MOTION_[27:24] | Motion Filter Mode | 0000: None through 1111: Strongest |
| 7:4 | DEINT_MOTION_[31:28] | Motion Smooth      | Motion smoothing strength (0-15)   |

### Register S2_0A: Deinterlacer Processing 00
| Bit | Name             | Function           | Description                                        |
| --- | ---------------- | ------------------ | -------------------------------------------------- |
| 1:0 | DEINT_PROC_[1:0] | Interpolation Mode | 00: BOB, 01: Motion Adaptive, 10: Field, 11: Frame |
| 3:2 | DEINT_PROC_[3:2] | Edge Mode          | 00: None, 01: Simple, 10: Advanced, 11: Reserved   |
| 5:4 | DEINT_PROC_[5:4] | Vertical Filter    | 00: None, 01: 2-tap, 10: 4-tap, 11: 6-tap          |
| 7:6 | DEINT_PROC_[7:6] | Field Selection    | 00: Auto, 01: Previous, 10: Current, 11: Next      |

### Register S2_0B: Deinterlacer Processing 01
| Bit | Name               | Function      | Description                    |
| --- | ------------------ | ------------- | ------------------------------ |
| 3:0 | DEINT_PROC_[11:8]  | Blend Factor  | Field blending factor (0-15)   |
| 7:4 | DEINT_PROC_[15:12] | Smooth Factor | Output smoothing factor (0-15) |

### Register Access Notes for Motion Processing
1. Motion coefficients control the blending between fields:
   - Alpha: Primary motion detection sensitivity
   - Beta: Secondary motion refinement
2. Motion region size constraints help eliminate noise:
   - Width and height in pixels/lines
   - Values of 0 disable size constraints
3. Processing modes affect output quality and latency:
   - BOB: Lowest latency, basic quality
   - Motion Adaptive: Best quality, higher latency
   - Field/Frame: Special cases for specific content
4. Filter modes provide different quality/performance tradeoffs:
   - More taps = better quality but higher latency
   - Stronger filtering can help reduce flicker

### Register S2_0C: Deinterlacer Film Pattern 00
| Bit | Name               | Function       | Description                                    |
| --- | ------------------ | -------------- | ---------------------------------------------- |
| 7:0 | DEINT_FILM_[23:16] | Pattern Length | Number of fields in custom film pattern (2-32) |

### Register S2_0D: Deinterlacer Film Pattern 01
| Bit | Name               | Function         | Description                    |
| --- | ------------------ | ---------------- | ------------------------------ |
| 7:0 | DEINT_FILM_[31:24] | Pattern Data Low | Custom film pattern bits [7:0] |

### Register S2_0E: Deinterlacer Film Pattern 02
| Bit | Name               | Function         | Description                     |
| --- | ------------------ | ---------------- | ------------------------------- |
| 7:0 | DEINT_FILM_[39:32] | Pattern Data Mid | Custom film pattern bits [15:8] |

### Register S2_0F: Deinterlacer Film Pattern 03
| Bit | Name               | Function          | Description                      |
| --- | ------------------ | ----------------- | -------------------------------- |
| 7:0 | DEINT_FILM_[47:40] | Pattern Data High | Custom film pattern bits [23:16] |

### Register S2_10: Deinterlacer Film Pattern 04
| Bit | Name               | Function         | Description                      |
| --- | ------------------ | ---------------- | -------------------------------- |
| 7:0 | DEINT_FILM_[55:48] | Pattern Data Top | Custom film pattern bits [31:24] |

### Register S2_11: Deinterlacer Film Detection 00
| Bit | Name               | Function        | Description                        |
| --- | ------------------ | --------------- | ---------------------------------- |
| 7:0 | DEINT_FILM_[63:56] | Match Threshold | Pattern matching threshold (0-255) |

### Register S2_12: Deinterlacer Film Detection 01
| Bit | Name               | Function           | Description                                       |
| --- | ------------------ | ------------------ | ------------------------------------------------- |
| 3:0 | DEINT_FILM_[67:64] | Bad Edit Tolerance | Number of mismatches allowed before unlock (0-15) |
| 7:4 | DEINT_FILM_[71:68] | Lock Speed         | Lock acquisition speed (0: Slow to 15: Fast)      |

### Register S2_13: Deinterlacer Film Detection 02
| Bit | Name               | Function       | Description                                        |
| --- | ------------------ | -------------- | -------------------------------------------------- |
| 3:0 | DEINT_FILM_[75:72] | Pattern Offset | Starting offset in pattern (0 to pattern length-1) |
| 7:4 | DEINT_FILM_[79:76] | Reserved       | Reserved for future use                            |

### Register Access Notes for Film Mode
1. Custom film pattern format:
   - Each bit represents one field
   - 1 = display field, 0 = skip field
   - Pattern repeats after specified length
2. Common film patterns:
   - 3:2 Pulldown: 32-bit pattern "10100101010010101010010101001010"
   - 2:2 Pulldown: 4-bit pattern "1010"
3. Pattern matching considerations:
   - Higher threshold = stricter matching
   - Bad edit tolerance helps handle scene changes
   - Lock speed affects detection responsiveness
4. Pattern offset allows synchronization:
   - Typically auto-detected
   - Can be manually set for specific cases
5. Changes to film mode registers take effect at next field

### Register S2_14: Deinterlacer Edge 00
| Bit | Name             | Function           | Description                    |
| --- | ---------------- | ------------------ | ------------------------------ |
| 7:0 | DEINT_EDGE_[7:0] | Edge Threshold Low | Lower edge detection threshold |

### Register S2_15: Deinterlacer Edge 01
| Bit | Name              | Function            | Description                    |
| --- | ----------------- | ------------------- | ------------------------------ |
| 7:0 | DEINT_EDGE_[15:8] | Edge Threshold High | Upper edge detection threshold |

### Register S2_16: Deinterlacer Edge 02
| Bit | Name               | Function         | Description                       |
| --- | ------------------ | ---------------- | --------------------------------- |
| 3:0 | DEINT_EDGE_[19:16] | Min Edge Length  | Minimum edge length in pixels     |
| 7:4 | DEINT_EDGE_[23:20] | Edge Sensitivity | Edge detection sensitivity (0-15) |

### Register S2_17: Deinterlacer Edge 03
| Bit | Name               | Function       | Description                           |
| --- | ------------------ | -------------- | ------------------------------------- |
| 3:0 | DEINT_EDGE_[27:24] | Edge Direction | 0000: All through 1111: 157.5 degrees |
| 7:4 | DEINT_EDGE_[31:28] | Edge Smoothing | Edge smoothing strength (0-15)        |

### Register S2_18: Deinterlacer Advanced 00
| Bit | Name            | Function        | Description                      |
| --- | --------------- | --------------- | -------------------------------- |
| 0   | DEINT_ADV_[0]   | Diagonal Enable | 1: Enable diagonal interpolation |
| 1   | DEINT_ADV_[1]   | Vertical Enable | 1: Enable vertical interpolation |
| 2   | DEINT_ADV_[2]   | Temporal Enable | 1: Enable temporal interpolation |
| 3   | DEINT_ADV_[3]   | Spatial Enable  | 1: Enable spatial interpolation  |
| 4   | DEINT_ADV_[4]   | Median Enable   | 1: Enable median filtering       |
| 5   | DEINT_ADV_[5]   | Comb Enable     | 1: Enable comb filtering         |
| 7:6 | DEINT_ADV_[7:6] | Reserved        | Reserved for future use          |

### Register S2_19: Deinterlacer Advanced 01
| Bit | Name              | Function          | Description                            |
| --- | ----------------- | ----------------- | -------------------------------------- |
| 3:0 | DEINT_ADV_[11:8]  | Diagonal Strength | Diagonal interpolation strength (0-15) |
| 7:4 | DEINT_ADV_[15:12] | Vertical Strength | Vertical interpolation strength (0-15) |

### Register S2_1A: Deinterlacer Advanced 02
| Bit | Name              | Function          | Description                            |
| --- | ----------------- | ----------------- | -------------------------------------- |
| 3:0 | DEINT_ADV_[19:16] | Temporal Strength | Temporal interpolation strength (0-15) |
| 7:4 | DEINT_ADV_[23:20] | Spatial Strength  | Spatial interpolation strength (0-15)  |

### Register S2_1B: Deinterlacer Advanced 03
| Bit | Name              | Function         | Description                    |
| --- | ----------------- | ---------------- | ------------------------------ |
| 3:0 | DEINT_ADV_[27:24] | Median Threshold | Median filter threshold (0-15) |
| 7:4 | DEINT_ADV_[31:28] | Comb Threshold   | Comb filter threshold (0-15)   |

### Register S2_1C through S2_1F: Reserved
| Bit | Name     | Function | Description             |
| --- | -------- | -------- | ----------------------- |
| 7:0 | Reserved | Reserved | Reserved for future use |

### Register Access Notes for Advanced Processing
1. Edge processing parameters:
   - Lower/upper thresholds define edge detection range
   - Edge length helps eliminate noise
   - Direction allows angle-specific processing
2. Advanced interpolation modes:
   - Diagonal: Best for diagonal edges
   - Vertical: Best for vertical detail
   - Temporal: Best for static areas
   - Spatial: Best for moving areas
3. Filter strengths:
   - Higher values = stronger effect
   - May increase processing artifacts
   - Balance based on content type
4. Recommended settings:
   - Film content: Temporal > Spatial
   - Sports: Spatial > Temporal
   - Text: Edge > Motion
   - Animation: Motion > Edge

## HD Bypass Registers

The HD Bypass section (Chapter 03) controls the direct passthrough of HD video signals. These registers configure bypass modes, timing parameters, and signal processing options for high-definition content.

### Register S3_00: HD Bypass Control 00
| Bit | Name        | Function       | Description                          |
| --- | ----------- | -------------- | ------------------------------------ |
| 0   | HD_CTRL_[0] | Bypass Enable  | 1: Enable HD bypass mode             |
| 1   | HD_CTRL_[1] | Clock Select   | 0: Use input clock, 1: Use PLL clock |
| 2   | HD_CTRL_[2] | Sync Select    | 0: Use input sync, 1: Generate sync  |
| 3   | HD_CTRL_[3] | Data Format    | 0: YCbCr, 1: RGB                     |
| 4   | HD_CTRL_[4] | Color Range    | 0: Full range, 1: Limited range      |
| 5   | HD_CTRL_[5] | Sync Polarity  | 0: Normal, 1: Inverted               |
| 6   | HD_CTRL_[6] | Clock Polarity | 0: Normal, 1: Inverted               |
| 7   | HD_CTRL_[7] | Auto Detection | 1: Enable automatic format detection |

### Register S3_01: HD Bypass Control 01
| Bit | Name            | Function          | Description                                        |
| --- | --------------- | ----------------- | -------------------------------------------------- |
| 1:0 | HD_CTRL_[9:8]   | Input Resolution  | 00: 720p, 01: 1080i, 10: 1080p, 11: Custom         |
| 3:2 | HD_CTRL_[11:10] | Output Resolution | 00: Same as input, 01: 720p, 10: 1080p, 11: Custom |
| 5:4 | HD_CTRL_[13:12] | Frame Rate        | 00: 50Hz, 01: 59.94Hz, 10: 60Hz, 11: Custom        |
| 7:6 | HD_CTRL_[15:14] | Aspect Ratio      | 00: Same as input, 01: 4:3, 10: 16:9, 11: Custom   |

### Register S3_02: HD Bypass Control 02
| Bit | Name            | Function      | Description                           |
| --- | --------------- | ------------- | ------------------------------------- |
| 0   | HD_CTRL_[16]    | HDCP Enable   | 1: Enable HDCP processing             |
| 1   | HD_CTRL_[17]    | Audio Enable  | 1: Enable audio passthrough           |
| 2   | HD_CTRL_[18]    | Deep Color    | 1: Enable deep color mode (30/36-bit) |
| 3   | HD_CTRL_[19]    | Pixel Repeat  | 1: Enable pixel repetition            |
| 4   | HD_CTRL_[20]    | CSC Enable    | 1: Enable color space conversion      |
| 5   | HD_CTRL_[21]    | Dither Enable | 1: Enable output dithering            |
| 7:6 | HD_CTRL_[23:22] | Reserved      | Reserved for future use               |

### Register S3_03: HD Bypass Timing 00
| Bit | Name            | Function    | Description                            |
| --- | --------------- | ----------- | -------------------------------------- |
| 7:0 | HD_TIMING_[7:0] | H-Total Low | Horizontal total pixels (lower 8 bits) |

### Register S3_04: HD Bypass Timing 01
| Bit | Name             | Function     | Description                            |
| --- | ---------------- | ------------ | -------------------------------------- |
| 7:0 | HD_TIMING_[15:8] | H-Total High | Horizontal total pixels (upper 8 bits) |

### Register S3_05: HD Bypass Timing 02
| Bit | Name              | Function       | Description                                  |
| --- | ----------------- | -------------- | -------------------------------------------- |
| 7:0 | HD_TIMING_[23:16] | H-Active Start | Horizontal active start position (in pixels) |

### Register S3_06: HD Bypass Timing 03
| Bit | Name              | Function       | Description                         |
| --- | ----------------- | -------------- | ----------------------------------- |
| 7:0 | HD_TIMING_[31:24] | H-Active Width | Horizontal active width (in pixels) |

### Register S3_08: HD Bypass Timing 05
| Bit | Name              | Function     | Description                         |
| --- | ----------------- | ------------ | ----------------------------------- |
| 7:0 | HD_TIMING_[47:40] | V-Total High | Vertical total lines (upper 8 bits) |

### Register S3_09: HD Bypass Timing 06
| Bit | Name              | Function       | Description                           |
| --- | ----------------- | -------------- | ------------------------------------- |
| 7:0 | HD_TIMING_[55:48] | V-Active Start | Vertical active start line (in lines) |

### Register S3_0A: HD Bypass Timing 07
| Bit | Name              | Function        | Description                       |
| --- | ----------------- | --------------- | --------------------------------- |
| 7:0 | HD_TIMING_[63:56] | V-Active Height | Vertical active height (in lines) |

### Register Access Notes for HD Bypass
1. All HD Bypass registers require segment 3 (F0 = 03) for access
2. Timing parameters must match input signal specifications
3. Changes to control registers take effect at the next frame
4. Resolution and frame rate changes require PLL reconfiguration
5. HDCP and audio features require additional hardware support

### Common HD Formats and Settings

#### 720p (1280x720)
- H-Total: 1650 pixels
- V-Total: 750 lines
- Frame Rates: 50Hz, 59.94Hz, 60Hz
- Recommended settings:
  ```
  S3_00 = 0x01 (Bypass Enable)
  S3_01 = 0x00 (720p, native)
  S3_02 = 0x00 (Basic mode)
  ```

#### 1080i (1920x1080)
- H-Total: 2200 pixels
- V-Total: 1125 lines
- Field Rates: 50Hz, 59.94Hz, 60Hz
- Recommended settings:
  ```
  S3_00 = 0x01 (Bypass Enable)
  S3_01 = 0x01 (1080i)
  S3_02 = 0x00 (Basic mode)
  ```

#### 1080p (1920x1080)
- H-Total: 2200 pixels
- V-Total: 1125 lines
- Frame Rates: 24Hz, 25Hz, 30Hz, 50Hz, 60Hz
- Recommended settings:
  ```
  S3_00 = 0x01 (Bypass Enable)
  S3_01 = 0x02 (1080p)
  S3_02 = 0x00 (Basic mode)
  ```

### Configuration Examples

1. Basic HD Bypass (720p60)
```
S3_00 = 0x01    // Enable bypass
S3_01 = 0x00    // 720p input/output
S3_02 = 0x00    // Basic mode
S3_03 = 0x72    // H-Total low (1650 & 0xFF)
S3_04 = 0x06    // H-Total high (1650 >> 8)
S3_07 = 0xEE    // V-Total low (750 & 0xFF)
S3_08 = 0x02    // V-Total high (750 >> 8)
```

2. 1080p with Color Space Conversion
```
S3_00 = 0x09    // Enable bypass, RGB mode
S3_01 = 0x02    // 1080p input/output
S3_02 = 0x10    // Enable CSC
S3_03 = 0x98    // H-Total low (2200 & 0xFF)
S3_04 = 0x08    // H-Total high (2200 >> 8)
S3_07 = 0x65    // V-Total low (1125 & 0xFF)
S3_08 = 0x04    // V-Total high (1125 >> 8)
```

3. Custom Timing with Deep Color
```
S3_00 = 0x01    // Enable bypass
S3_01 = 0x03    // Custom resolution
S3_02 = 0x04    // Enable deep color
```

### Register S3_0B through S3_0F: Reserved
| Bit | Name     | Function | Description             |
| --- | -------- | -------- | ----------------------- |
| 7:0 | Reserved | Reserved | Reserved for future use |

## Miscellaneous Registers

The Miscellaneous section (Chapter 04) contains various control registers for system-wide configuration, power management, and special features. These registers provide essential control over the TV5725's general operation.

### Register S4_00: System Control 00
| Bit | Name         | Function          | Description                             |
| --- | ------------ | ----------------- | --------------------------------------- |
| 0   | SYS_CTRL_[0] | Chip Enable       | 1: Enable chip operation                |
| 1   | SYS_CTRL_[1] | Soft Reset        | 1: Trigger soft reset (self-clearing)   |
| 2   | SYS_CTRL_[2] | Power Down        | 1: Enter power-down mode                |
| 3   | SYS_CTRL_[3] | Clock Gate        | 1: Enable clock gating for power saving |
| 4   | SYS_CTRL_[4] | PLL Power Down    | 1: Power down all PLLs                  |
| 5   | SYS_CTRL_[5] | ADC Power Down    | 1: Power down ADC                       |
| 6   | SYS_CTRL_[6] | DAC Power Down    | 1: Power down DAC                       |
| 7   | SYS_CTRL_[7] | Memory Power Down | 1: Power down memory subsystem          |

### Register S4_01: System Control 01
| Bit | Name          | Function         | Description                               |
| --- | ------------- | ---------------- | ----------------------------------------- |
| 0   | SYS_CTRL_[8]  | Test Mode        | 1: Enable test mode                       |
| 1   | SYS_CTRL_[9]  | Debug Mode       | 1: Enable debug mode                      |
| 2   | SYS_CTRL_[10] | Boundary Scan    | 1: Enable boundary scan mode              |
| 3   | SYS_CTRL_[11] | Memory BIST      | 1: Enable memory built-in self test       |
| 4   | SYS_CTRL_[12] | Clock Monitor    | 1: Enable clock monitoring                |
| 5   | SYS_CTRL_[13] | Watchdog Enable  | 1: Enable watchdog timer                  |
| 6   | SYS_CTRL_[14] | Interrupt Enable | 1: Enable interrupt generation            |
| 7   | SYS_CTRL_[15] | GPIO Mode        | 1: Enable GPIO mode for configurable pins |

### Register S4_02: System Control 02
| Bit | Name             | Function      | Description                                      |
| --- | ---------------- | ------------- | ------------------------------------------------ |
| 1:0 | SYS_CTRL_[17:16] | Clock Source  | 00: Crystal, 01: PLL, 10: External, 11: Reserved |
| 3:2 | SYS_CTRL_[19:18] | Clock Divider | System clock divider ratio (0-3)                 |
| 5:4 | SYS_CTRL_[21:20] | Memory Clock  | Memory subsystem clock divider (0-3)             |
| 7:6 | SYS_CTRL_[23:22] | Core Clock    | Core logic clock divider (0-3)                   |

### Register S4_03: System Status 00
| Bit | Name           | Function        | Description                |
| --- | -------------- | --------------- | -------------------------- |
| 0   | SYS_STATUS_[0] | Reset Active    | 1: Reset in progress       |
| 1   | SYS_STATUS_[1] | PLL Lock        | 1: All PLLs locked         |
| 2   | SYS_STATUS_[2] | Power State     | 1: Chip in power-down mode |
| 3   | SYS_STATUS_[3] | Clock Status    | 1: All clocks stable       |
| 4   | SYS_STATUS_[4] | Memory Ready    | 1: Memory subsystem ready  |
| 5   | SYS_STATUS_[5] | Test Status     | 1: Test mode active        |
| 6   | SYS_STATUS_[6] | Watchdog Status | 1: Watchdog timer expired  |
| 7   | SYS_STATUS_[7] | Error Status    | 1: System error detected   |

### Register S4_04: GPIO Control 00
| Bit | Name          | Function     | Description              |
| --- | ------------- | ------------ | ------------------------ |
| 0   | GPIO_CTRL_[0] | GPIO0 Enable | 1: Enable GPIO0 function |
| 1   | GPIO_CTRL_[1] | GPIO1 Enable | 1: Enable GPIO1 function |
| 2   | GPIO_CTRL_[2] | GPIO2 Enable | 1: Enable GPIO2 function |
| 3   | GPIO_CTRL_[3] | GPIO3 Enable | 1: Enable GPIO3 function |
| 4   | GPIO_CTRL_[4] | GPIO4 Enable | 1: Enable GPIO4 function |
| 5   | GPIO_CTRL_[5] | GPIO5 Enable | 1: Enable GPIO5 function |
| 6   | GPIO_CTRL_[6] | GPIO6 Enable | 1: Enable GPIO6 function |
| 7   | GPIO_CTRL_[7] | GPIO7 Enable | 1: Enable GPIO7 function |

### Register S4_05: GPIO Control 01
| Bit | Name           | Function        | Description         |
| --- | -------------- | --------------- | ------------------- |
| 0   | GPIO_CTRL_[8]  | GPIO0 Direction | 0: Input, 1: Output |
| 1   | GPIO_CTRL_[9]  | GPIO1 Direction | 0: Input, 1: Output |
| 2   | GPIO_CTRL_[10] | GPIO2 Direction | 0: Input, 1: Output |
| 3   | GPIO_CTRL_[11] | GPIO3 Direction | 0: Input, 1: Output |
| 4   | GPIO_CTRL_[12] | GPIO4 Direction | 0: Input, 1: Output |
| 5   | GPIO_CTRL_[13] | GPIO5 Direction | 0: Input, 1: Output |
| 6   | GPIO_CTRL_[14] | GPIO6 Direction | 0: Input, 1: Output |
| 7   | GPIO_CTRL_[15] | GPIO7 Direction | 0: Input, 1: Output |

### Register S4_06: GPIO Data 00
| Bit | Name          | Function   | Description             |
| --- | ------------- | ---------- | ----------------------- |
| 0   | GPIO_DATA_[0] | GPIO0 Data | GPIO0 input/output data |
| 1   | GPIO_DATA_[1] | GPIO1 Data | GPIO1 input/output data |
| 2   | GPIO_DATA_[2] | GPIO2 Data | GPIO2 input/output data |
| 3   | GPIO_DATA_[3] | GPIO3 Data | GPIO3 input/output data |
| 4   | GPIO_DATA_[4] | GPIO4 Data | GPIO4 input/output data |
| 5   | GPIO_DATA_[5] | GPIO5 Data | GPIO5 input/output data |
| 6   | GPIO_DATA_[6] | GPIO6 Data | GPIO6 input/output data |
| 7   | GPIO_DATA_[7] | GPIO7 Data | GPIO7 input/output data |

### Register S4_07: Interrupt Control 00
| Bit | Name         | Function            | Description                          |
| --- | ------------ | ------------------- | ------------------------------------ |
| 0   | INT_CTRL_[0] | SOG Int Enable      | 1: Enable SOG change interrupt       |
| 1   | INT_CTRL_[1] | Mode Int Enable     | 1: Enable mode change interrupt      |
| 2   | INT_CTRL_[2] | Sync Int Enable     | 1: Enable sync loss interrupt        |
| 3   | INT_CTRL_[3] | FIFO Int Enable     | 1: Enable FIFO overflow interrupt    |
| 4   | INT_CTRL_[4] | Error Int Enable    | 1: Enable error condition interrupt  |
| 5   | INT_CTRL_[5] | GPIO Int Enable     | 1: Enable GPIO change interrupt      |
| 6   | INT_CTRL_[6] | Watchdog Int Enable | 1: Enable watchdog timeout interrupt |
| 7   | INT_CTRL_[7] | Global Int Enable   | 1: Enable all interrupts             |

### Register S4_08: Interrupt Mask 00
| Bit | Name         | Function       | Description                        |
| --- | ------------ | -------------- | ---------------------------------- |
| 0   | INT_MASK_[0] | SOG Int Mask   | 1: Mask SOG change interrupt       |
| 1   | INT_MASK_[1] | Mode Int Mask  | 1: Mask mode change interrupt      |
| 2   | INT_MASK_[2] | Sync Int Mask  | 1: Mask sync loss interrupt        |
| 3   | INT_MASK_[3] | FIFO Int Mask  | 1: Mask FIFO overflow interrupt    |
| 4   | INT_MASK_[4] | Error Int Mask | 1: Mask error condition interrupt  |
| 5   | INT_MASK_[5] | GPIO Int Mask  | 1: Mask GPIO change interrupt      |
| 6   | INT_MASK_[6] | WD Int Mask    | 1: Mask watchdog timeout interrupt |
| 7   | INT_MASK_[7] | Reserved       | Reserved for future use            |

### Register Access Notes for System Control
1. All Miscellaneous registers require segment 4 (F0 = 04) for access
2. Soft reset (S4_00[1]) automatically clears after reset completes
3. Power-down mode disables all non-essential functions
4. Clock gating affects system performance but saves power
5. Changes to clock settings require careful timing

### Configuration Examples

1. Basic System Initialization
```
S4_00 = 0x01    // Enable chip, normal power mode
S4_01 = 0x40    // Enable interrupts
S4_02 = 0x00    // Use crystal oscillator, default clocks
```

2. Power Saving Mode
```
S4_00 = 0x0C    // Enable clock gating and power-down mode
S4_02 = 0x2A    // Reduce clock speeds
```

3. GPIO Configuration
```
S4_04 = 0x03    // Enable GPIO0 and GPIO1
S4_05 = 0x01    // GPIO0 output, GPIO1 input
S4_06 = 0x01    // Set GPIO0 high
```

4. Interrupt Setup
```
S4_07 = 0x87    // Enable global, SOG, and sync interrupts
S4_08 = 0x78    // Mask unused interrupts
```

### Register S4_09 through S4_0F: Reserved
| Bit | Name     | Function | Description             |
| --- | -------- | -------- | ----------------------- |
| 7:0 | Reserved | Reserved | Reserved for future use |

## Memory Registers

The Memory section (Chapter 05) controls the DDR memory interface and timing parameters. These registers configure memory access, refresh timing, and various memory-related operations.

### Register S5_00: Memory Control 00
| Bit | Name         | Function        | Description                                |
| --- | ------------ | --------------- | ------------------------------------------ |
| 0   | MEM_CTRL_[0] | Memory Enable   | 1: Enable memory subsystem                 |
| 1   | MEM_CTRL_[1] | Memory Reset    | 1: Reset memory controller (self-clearing) |
| 2   | MEM_CTRL_[2] | Auto Refresh    | 1: Enable auto refresh                     |
| 3   | MEM_CTRL_[3] | Power Down      | 1: Enter memory power-down mode            |
| 4   | MEM_CTRL_[4] | Self Refresh    | 1: Enter self-refresh mode                 |
| 5   | MEM_CTRL_[5] | Clock Stop      | 1: Stop memory clock                       |
| 6   | MEM_CTRL_[6] | Bank Interleave | 1: Enable bank interleaving                |
| 7   | MEM_CTRL_[7] | Burst Mode      | 1: Enable burst mode                       |

### Register S5_01: Memory Control 01
| Bit | Name             | Function     | Description                                     |
| --- | ---------------- | ------------ | ----------------------------------------------- |
| 1:0 | MEM_CTRL_[9:8]   | Memory Type  | 00: DDR, 01: DDR2, 10: DDR3, 11: Reserved       |
| 3:2 | MEM_CTRL_[11:10] | Memory Size  | 00: 64MB, 01: 128MB, 10: 256MB, 11: Reserved    |
| 5:4 | MEM_CTRL_[13:12] | Memory Width | 00: 8-bit, 01: 16-bit, 10: 32-bit, 11: Reserved |
| 7:6 | MEM_CTRL_[15:14] | Memory Speed | 00: 200MHz, 01: 266MHz, 10: 333MHz, 11: 400MHz  |

### Register S5_02: Memory Control 02
| Bit | Name             | Function      | Description                |
| --- | ---------------- | ------------- | -------------------------- |
| 3:0 | MEM_CTRL_[19:16] | CAS Latency   | CAS latency value (2-15)   |
| 7:4 | MEM_CTRL_[23:20] | Write Latency | Write latency value (2-15) |

### Register S5_03: Memory Timing 00
| Bit | Name           | Function | Description                               |
| --- | -------------- | -------- | ----------------------------------------- |
| 7:0 | MEM_TIME_[7:0] | tRCD     | RAS to CAS delay (in memory clock cycles) |

### Register S5_04: Memory Timing 01
| Bit | Name            | Function | Description                                 |
| --- | --------------- | -------- | ------------------------------------------- |
| 7:0 | MEM_TIME_[15:8] | tRP      | Row precharge time (in memory clock cycles) |

### Register S5_05: Memory Timing 02
| Bit | Name             | Function | Description                              |
| --- | ---------------- | -------- | ---------------------------------------- |
| 7:0 | MEM_TIME_[23:16] | tRAS     | Row active time (in memory clock cycles) |

### Register S5_06: Memory Timing 03
| Bit | Name             | Function | Description                             |
| --- | ---------------- | -------- | --------------------------------------- |
| 7:0 | MEM_TIME_[31:24] | tRC      | Row cycle time (in memory clock cycles) |

### Register S5_07: Memory Timing 04
| Bit | Name             | Function | Description                                 |
| --- | ---------------- | -------- | ------------------------------------------- |
| 7:0 | MEM_TIME_[39:32] | tRFC     | Refresh cycle time (in memory clock cycles) |

### Register S5_08: Memory Timing 05
| Bit | Name             | Function | Description                                  |
| --- | ---------------- | -------- | -------------------------------------------- |
| 7:0 | MEM_TIME_[47:40] | tWR      | Write recovery time (in memory clock cycles) |

### Register Access Notes for Memory Control
1. All Memory registers require segment 5 (F0 = 05) for access
2. Memory reset (S5_00[1]) automatically clears after reset completes
3. Memory timing parameters must match DDR device specifications
4. Changes to memory settings require careful sequencing
5. Some timing parameters are device-specific

### Memory Timing Parameters
1. tRCD (RAS to CAS Delay)
   - Minimum time between row activation and column access
   - Typical values: DDR (20ns), DDR2 (15ns), DDR3 (13.5ns)

2. tRP (Row Precharge)
   - Minimum time required to precharge a row
   - Typical values: DDR (20ns), DDR2 (15ns), DDR3 (13.5ns)

3. tRAS (Row Active Time)
   - Minimum time row must remain active
   - Typical values: DDR (45ns), DDR2 (40ns), DDR3 (36ns)

4. tRC (Row Cycle Time)
   - Minimum time between row activations
   - Calculated as tRAS + tRP

5. tRFC (Refresh Cycle Time)
   - Time required for auto-refresh operation
   - Varies by memory density and technology

6. tWR (Write Recovery)
   - Time between write command and precharge
   - Critical for data integrity

### Configuration Examples

1. DDR Memory (200MHz)
```
// Basic DDR Configuration
S5_00 = 0x85    // Enable memory, auto refresh, burst mode
S5_01 = 0x01    // DDR memory, 64MB, 16-bit width
S5_02 = 0x23    // CAS=2, WL=3
S5_03 = 0x04    // tRCD=4 cycles (20ns @ 200MHz)
S5_04 = 0x04    // tRP=4 cycles
S5_05 = 0x09    // tRAS=9 cycles
S5_06 = 0x0D    // tRC=13 cycles
S5_07 = 0x12    // tRFC=18 cycles
S5_08 = 0x03    // tWR=3 cycles
```

2. DDR2 Memory (333MHz)
```
// High-Performance DDR2
S5_00 = 0xC5    // Enable memory, auto refresh, burst, bank interleave
S5_01 = 0x15    // DDR2 memory, 128MB, 16-bit, 333MHz
S5_02 = 0x45    // CAS=4, WL=5
S5_03 = 0x05    // tRCD=5 cycles (15ns @ 333MHz)
S5_04 = 0x05    // tRP=5 cycles
S5_05 = 0x0E    // tRAS=14 cycles
S5_06 = 0x13    // tRC=19 cycles
S5_07 = 0x28    // tRFC=40 cycles
S5_08 = 0x06    // tWR=6 cycles
```

3. Power-Saving Configuration
```
// Low-Power Mode
S5_00 = 0x1C    // Enable memory, power-down, clock stop
S5_01 = 0x00    // Lowest speed setting
S5_02 = 0x22    // Minimal latency
```

### Memory Initialization Sequence
1. Power-up sequence:
   ```
   S5_00 = 0x02    // Assert memory reset
   // Wait 200μs
   S5_00 = 0x00    // Clear reset
   S5_01 = 0x--    // Configure memory type/size
   S5_02 = 0x--    // Set latency values
   // Configure timing parameters
   S5_00 = 0x85    // Enable memory and refresh
   ```

2. Power-down sequence:
   ```
   S5_00 = 0x08    // Enter power-down mode
   S5_00 = 0x28    // Stop memory clock
   ```

### Register S5_09 through S5_0F: Reserved
| Bit | Name     | Function | Description             |
| --- | -------- | -------- | ----------------------- |
| 7:0 | Reserved | Reserved | Reserved for future use |

## Capture & Playback Registers

The Capture & Playback section (Chapter 06) controls video capture and playback operations. These registers configure frame buffering, capture timing, and playback parameters.

### Register S6_00: Capture Control 00
| Bit | Name         | Function        | Description                        |
| --- | ------------ | --------------- | ---------------------------------- |
| 0   | CAP_CTRL_[0] | Capture Enable  | 1: Enable video capture            |
| 1   | CAP_CTRL_[1] | Continuous Mode | 1: Enable continuous capture       |
| 2   | CAP_CTRL_[2] | Single Frame    | 1: Capture single frame            |
| 3   | CAP_CTRL_[3] | Field Mode      | 0: Frame capture, 1: Field capture |
| 4   | CAP_CTRL_[4] | Memory Select   | 0: Memory bank 0, 1: Memory bank 1 |
| 5   | CAP_CTRL_[5] | Double Buffer   | 1: Enable double buffering         |
| 6   | CAP_CTRL_[6] | Capture Format  | 0: YCbCr, 1: RGB                   |
| 7   | CAP_CTRL_[7] | Capture Sync    | 0: Internal sync, 1: External sync |

### Register S6_01: Capture Control 01
| Bit | Name             | Function           | Description                                               |
| --- | ---------------- | ------------------ | --------------------------------------------------------- |
| 1:0 | CAP_CTRL_[9:8]   | Capture Resolution | 00: Full, 01: Half, 10: Quarter, 11: Custom               |
| 3:2 | CAP_CTRL_[11:10] | Memory Format      | 00: 8-bit, 01: 16-bit, 10: 32-bit, 11: Reserved           |
| 5:4 | CAP_CTRL_[13:12] | Trigger Source     | 00: Free run, 01: External, 10: Software, 11: VSYNC       |
| 7:6 | CAP_CTRL_[15:14] | Capture Mode       | 00: Progressive, 01: Interlaced, 10: Custom, 11: Reserved |

### Register S6_02: Playback Control 00
| Bit | Name        | Function        | Description                          |
| --- | ----------- | --------------- | ------------------------------------ |
| 0   | PB_CTRL_[0] | Playback Enable | 1: Enable video playback             |
| 1   | PB_CTRL_[1] | Continuous Mode | 1: Enable continuous playback        |
| 2   | PB_CTRL_[2] | Single Frame    | 1: Play single frame                 |
| 3   | PB_CTRL_[3] | Field Mode      | 0: Frame playback, 1: Field playback |
| 4   | PB_CTRL_[4] | Memory Select   | 0: Memory bank 0, 1: Memory bank 1   |
| 5   | PB_CTRL_[5] | Double Buffer   | 1: Enable double buffering           |
| 6   | PB_CTRL_[6] | Playback Format | 0: YCbCr, 1: RGB                     |
| 7   | PB_CTRL_[7] | Sync Generation | 1: Generate sync signals             |

### Register S6_03: Capture Size 00
| Bit | Name           | Function  | Description                  |
| --- | -------------- | --------- | ---------------------------- |
| 7:0 | CAP_SIZE_[7:0] | Width Low | Capture width (lower 8 bits) |

### Register S6_04: Capture Size 01
| Bit | Name            | Function   | Description                  |
| --- | --------------- | ---------- | ---------------------------- |
| 7:0 | CAP_SIZE_[15:8] | Width High | Capture width (upper 8 bits) |

### Register S6_05: Capture Size 02
| Bit | Name             | Function   | Description                   |
| --- | ---------------- | ---------- | ----------------------------- |
| 7:0 | CAP_SIZE_[23:16] | Height Low | Capture height (lower 8 bits) |

### Register S6_06: Capture Size 03
| Bit | Name             | Function    | Description                   |
| --- | ---------------- | ----------- | ----------------------------- |
| 7:0 | CAP_SIZE_[31:24] | Height High | Capture height (upper 8 bits) |

### Register Access Notes for Capture & Playback
1. All Capture & Playback registers require segment 6 (F0 = 06) for access
2. Capture and playback operations require proper memory configuration
3. Double buffering prevents tearing but requires twice the memory
4. Resolution changes require memory reallocation
5. Sync generation affects output timing

### Configuration Examples

1. Basic Frame Capture
```
S6_00 = 0x01    // Enable capture
S6_01 = 0x00    // Full resolution, 8-bit
S6_03 = 0x80    // Width = 1920 (lower byte)
S6_04 = 0x07    // Width = 1920 (upper byte)
S6_05 = 0x38    // Height = 1080 (lower byte)
S6_06 = 0x04    // Height = 1080 (upper byte)
```

2. Continuous Playback with Double Buffering
```
S6_02 = 0x23    // Enable playback, continuous mode, double buffer
```

### Register S6_07 through S6_0F: Reserved
| Bit | Name     | Function | Description             |
| --- | -------- | -------- | ----------------------- |
| 7:0 | Reserved | Reserved | Reserved for future use |

## Write & Read FIFO Registers

The Write & Read FIFO section (Chapter 07) controls data buffering and transfer operations. These registers manage FIFO buffers for writing data to and reading data from memory.

### Register S7_00: Write FIFO Control 00
| Bit | Name         | Function       | Description                          |
| --- | ------------ | -------------- | ------------------------------------ |
| 0   | WFF_CTRL_[0] | Write Enable   | 1: Enable write FIFO                 |
| 1   | WFF_CTRL_[1] | Reset FIFO     | 1: Reset write FIFO (self-clearing)  |
| 2   | WFF_CTRL_[2] | Burst Mode     | 1: Enable burst write mode           |
| 3   | WFF_CTRL_[3] | Auto Flush     | 1: Enable automatic FIFO flush       |
| 4   | WFF_CTRL_[4] | Threshold Mode | 1: Enable threshold-based operation  |
| 5   | WFF_CTRL_[5] | Interrupt Mode | 1: Enable FIFO level interrupts      |
| 6   | WFF_CTRL_[6] | Data Format    | 0: 8-bit mode, 1: 16-bit mode        |
| 7   | WFF_CTRL_[7] | Address Mode   | 0: Linear addressing, 1: Ring buffer |

### Register S7_01: Write FIFO Control 01
| Bit | Name             | Function         | Description                                    |
| --- | ---------------- | ---------------- | ---------------------------------------------- |
| 1:0 | WFF_CTRL_[9:8]   | Buffer Select    | 00: Buffer 0, 01: Buffer 1, 10: Both, 11: Auto |
| 3:2 | WFF_CTRL_[11:10] | Priority Level   | 00: Low to 11: Highest                         |
| 5:4 | WFF_CTRL_[13:12] | Burst Size       | 00: 8 bytes to 11: 64 bytes                    |
| 7:6 | WFF_CTRL_[15:14] | Threshold Select | 00: 25%, 01: 50%, 10: 75%, 11: Custom          |

### Register S7_02: Write FIFO Threshold 00
| Bit | Name             | Function          | Description                        |
| --- | ---------------- | ----------------- | ---------------------------------- |
| 7:0 | WFF_THRESH_[7:0] | Almost Full Level | FIFO almost full threshold (bytes) |

### Register S7_03: Write FIFO Threshold 01
| Bit | Name              | Function           | Description                         |
| --- | ----------------- | ------------------ | ----------------------------------- |
| 7:0 | WFF_THRESH_[15:8] | Almost Empty Level | FIFO almost empty threshold (bytes) |

### Register S7_04: Read FIFO Control 00
| Bit | Name         | Function       | Description                          |
| --- | ------------ | -------------- | ------------------------------------ |
| 0   | RFF_CTRL_[0] | Read Enable    | 1: Enable read FIFO                  |
| 1   | RFF_CTRL_[1] | Reset FIFO     | 1: Reset read FIFO (self-clearing)   |
| 2   | RFF_CTRL_[2] | Burst Mode     | 1: Enable burst read mode            |
| 3   | RFF_CTRL_[3] | Auto Prefetch  | 1: Enable automatic data prefetch    |
| 4   | RFF_CTRL_[4] | Threshold Mode | 1: Enable threshold-based operation  |
| 5   | RFF_CTRL_[5] | Interrupt Mode | 1: Enable FIFO level interrupts      |
| 6   | RFF_CTRL_[6] | Data Format    | 0: 8-bit mode, 1: 16-bit mode        |
| 7   | RFF_CTRL_[7] | Address Mode   | 0: Linear addressing, 1: Ring buffer |

### Register S7_05: Read FIFO Control 01
| Bit | Name             | Function         | Description                                    |
| --- | ---------------- | ---------------- | ---------------------------------------------- |
| 1:0 | RFF_CTRL_[9:8]   | Buffer Select    | 00: Buffer 0, 01: Buffer 1, 10: Both, 11: Auto |
| 3:2 | RFF_CTRL_[11:10] | Priority Level   | 00: Low to 11: Highest                         |
| 5:4 | RFF_CTRL_[13:12] | Burst Size       | 00: 8 bytes to 11: 64 bytes                    |
| 7:6 | RFF_CTRL_[15:14] | Threshold Select | 00: 25%, 01: 50%, 10: 75%, 11: Custom          |

### Register S7_06: Read FIFO Threshold 00
| Bit | Name             | Function          | Description                        |
| --- | ---------------- | ----------------- | ---------------------------------- |
| 7:0 | RFF_THRESH_[7:0] | Almost Full Level | FIFO almost full threshold (bytes) |

### Register S7_07: Read FIFO Threshold 01
| Bit | Name              | Function           | Description                         |
| --- | ----------------- | ------------------ | ----------------------------------- |
| 7:0 | RFF_THRESH_[15:8] | Almost Empty Level | FIFO almost empty threshold (bytes) |

### Register Access Notes for FIFO Control
1. All Write & Read FIFO registers require segment 7 (F0 = 07) for access
2. FIFO resets (S7_00[1], S7_04[1]) automatically clear after reset completes
3. Threshold values determine interrupt generation and flow control
4. Burst modes improve memory bandwidth utilization
5. Buffer selection affects memory organization and access patterns

### Configuration Examples

1. Basic Write FIFO Setup
```
S7_00 = 0x01    // Enable write FIFO
S7_01 = 0x20    // 32-byte bursts, normal priority
S7_02 = 0xC0    // Almost full at 192 bytes
S7_03 = 0x40    // Almost empty at 64 bytes
```

2. High-Performance Read FIFO
```
S7_04 = 0x0F    // Enable read FIFO, burst mode, prefetch
S7_05 = 0x2C    // 32-byte bursts, high priority
S7_06 = 0xE0    // Almost full at 224 bytes
S7_07 = 0x20    // Almost empty at 32 bytes
```

3. Double-Buffered Operation
```
S7_00 = 0x03    // Enable write FIFO with reset
S7_01 = 0x02    // Use both buffers
S7_04 = 0x03    // Enable read FIFO with reset
S7_05 = 0x02    // Use both buffers
```

### Register S7_08 through S7_0F: Reserved
| Bit | Name     | Function | Description             |
| --- | -------- | -------- | ----------------------- |
| 7:0 | Reserved | Reserved | Reserved for future use |

## Video Processor Registers

The Video Processor section (Chapter 08) controls video processing operations. These registers configure video scaling, color space conversion, and various processing parameters.

### Register S8_00: Video Processor Control 00
| Bit | Name        | Function           | Description                                      |
| --- | ----------- | ------------------ | ------------------------------------------------ |
| 0   | VP_CTRL_[0] | Video Enable       | 1: Enable video processing                       |
| 1   | VP_CTRL_[1] | Input Format       | 0: YCbCr, 1: RGB                                 |
| 2   | VP_CTRL_[2] | Output Format      | 0: YCbCr, 1: RGB                                 |
| 3   | VP_CTRL_[3] | Color Space        | 0: YCbCr, 1: RGB                                 |
| 4   | VP_CTRL_[4] | Input Range        | 0: Full range (0-255), 1: Limited range (16-235) |
| 5   | VP_CTRL_[5] | Output Range       | 0: Full range (0-255), 1: Limited range (16-235) |
| 6   | VP_CTRL_[6] | Input Color Space  | 0: YCbCr, 1: RGB                                 |
| 7   | VP_CTRL_[7] | Output Color Space | 0: YCbCr, 1: RGB                                 |

### Register S8_01: Video Processor Control 01
| Bit | Name            | Function          | Description                                                   |
| --- | --------------- | ----------------- | ------------------------------------------------------------- |
| 1:0 | VP_CTRL_[9:8]   | Scaling Mode      | 00: None, 01: Bilinear, 10: Bicubic, 11: Reserved             |
| 3:2 | VP_CTRL_[11:10] | Scaling Algorithm | 00: Nearest Neighbor, 01: Bilinear, 10: Bicubic, 11: Reserved |
| 5:4 | VP_CTRL_[13:12] | Scaling Ratio     | 00: 1:1, 01: 2:1, 10: 3:1, 11: Reserved                       |
| 7:6 | VP_CTRL_[15:14] | Scaling Filter    | 00: None, 01: 2-tap, 10: 4-tap, 11: 6-tap                     |

### Register S8_02: Video Processor Control 02
| Bit | Name            | Function           | Description                                        |
| --- | --------------- | ------------------ | -------------------------------------------------- |
| 1:0 | VP_CTRL_[17:16] | Color Space Mode   | 00: YCbCr, 01: RGB, 10: YCbCr to RGB, 11: Reserved |
| 3:2 | VP_CTRL_[19:18] | Color Space Format | 00: 601, 01: 709, 10: 444, 11: Reserved            |
| 5:4 | VP_CTRL_[21:20] | Color Space Range  | 00: Full range (0-255), 1: Limited range (16-235)  |
| 7:6 | VP_CTRL_[23:22] | Color Space Range  | 00: Full range (0-255), 1: Limited range (16-235)  |

### Register S8_03: Video Processor Control 03
| Bit | Name            | Function           | Description                    |
| --- | --------------- | ------------------ | ------------------------------ |
| 1:0 | VP_CTRL_[25:24] | Color Space Offset | 00: 0, 01: 128, 10: 16, 11: 24 |
| 3:2 | VP_CTRL_[27:26] | Color Space Offset | 00: 0, 01: 128, 10: 16, 11: 24 |
| 5:4 | VP_CTRL_[29:28] | Color Space Offset | 00: 0, 01: 128, 10: 16, 11: 24 |
| 7:6 | VP_CTRL_[31:30] | Color Space Offset | 00: 0, 01: 128, 10: 16, 11: 24 |

### Register S8_04: Video Processor Control 04
| Bit | Name            | Function           | Description                    |
| --- | --------------- | ------------------ | ------------------------------ |
| 1:0 | VP_CTRL_[33:32] | Color Space Offset | 00: 0, 01: 128, 10: 16, 11: 24 |
| 3:2 | VP_CTRL_[35:34] | Color Space Offset | 00: 0, 01: 128, 10: 16, 11: 24 |
| 5:4 | VP_CTRL_[37:36] | Color Space Offset | 00: 0, 01: 128, 10: 16, 11: 24 |
| 7:6 | VP_CTRL_[39:38] | Color Space Offset | 00: 0, 01: 128, 10: 16, 11: 24 |

### Register S8_05: Video Processor Control 05
| Bit | Name            | Function           | Description                    |
| --- | --------------- | ------------------ | ------------------------------ |
| 1:0 | VP_CTRL_[41:40] | Color Space Offset | 00: 0, 01: 128, 10: 16, 11: 24 |
| 3:2 | VP_CTRL_[43:42] | Color Space Offset | 00: 0, 01: 128, 10: 16, 11: 24 |
| 5:4 | VP_CTRL_[45:44] | Color Space Offset | 00: 0, 01: 128, 10: 16, 11: 24 |
| 7:6 | VP_CTRL_[47:46] | Color Space Offset | 00: 0, 01: 128, 10: 16, 11: 24 |

### Register S8_06: Video Processor Control 06
| Bit | Name            | Function           | Description                    |
| --- | --------------- | ------------------ | ------------------------------ |
| 1:0 | VP_CTRL_[49:48] | Color Space Offset | 00: 0, 01: 128, 10: 16, 11: 24 |
| 3:2 | VP_CTRL_[51:50] | Color Space Offset | 00: 0, 01: 128, 10: 16, 11: 24 |
| 5:4 | VP_CTRL_[53:52] | Color Space Offset | 00: 0, 01: 128, 10: 16, 11: 24 |
| 7:6 | VP_CTRL_[55:54] | Color Space Offset | 00: 0, 01: 128, 10: 16, 11: 24 |

### Register S8_07: Video Processor Control 07
| Bit | Name | Function | Description |
| --- | ---- | -------- | ----------- |

## OSD Registers

The OSD (On-Screen Display) section (Chapter 09) controls the display of on-screen menus and information. These registers configure menu appearance, position, colors, and various OSD-related features.

### Register S0_90: OSD Control 00
| Bit | Name                | Function        | Description                             |
| --- | ------------------- | --------------- | --------------------------------------- |
| 0   | OSD_SW_RESET        | Software Reset  | 1: Reset OSD controller (self-clearing) |
| 3:1 | OSD_HORIZONTAL_ZOOM | Horizontal Zoom | 000: 1x to 111: 8x zoom                 |
| 6:4 | OSD_VERTICAL_ZOOM   | Vertical Zoom   | 000: 1x to 111: 8x zoom                 |
| 7   | OSD_MENU_EN         | Menu Enable     | 1: Enable OSD menu display              |

### Register S0_91: OSD Control 01
| Bit | Name              | Function       | Description                      |
| --- | ----------------- | -------------- | -------------------------------- |
| 3:0 | OSD_MENU_ICON_SEL | Icon Selection | 0000: None through 1111: Icon 15 |
| 7:4 | OSD_MENU_MOD_SEL  | Mode Selection | Menu mode selection              |

### Register S0_92: OSD Color Control 00
| Bit | Name                     | Function        | Description                 |
| --- | ------------------------ | --------------- | --------------------------- |
| 2:0 | OSD_MENU_BAR_FONT_FORCOR | Font Foreground | Font foreground color (0-7) |
| 5:3 | OSD_MENU_BAR_FONT_BGCOR  | Font Background | Font background color (0-7) |
| 7:6 | OSD_MENU_BAR_BORD_COR    | Border Color    | Menu border color (0-3)     |

### Register S0_93: OSD Color Control 01
| Bit | Name                | Function             | Description                    |
| --- | ------------------- | -------------------- | ------------------------------ |
| 2:0 | OSD_MENU_SEL_FORCOR | Selection Foreground | Selected item foreground color |
| 5:3 | OSD_MENU_SEL_BGCOR  | Selection Background | Selected item background color |
| 7   | OSD_COMMAND_FINISH  | Command Complete     | 1: OSD command completed       |

### Register S0_94: OSD Format Control
| Bit | Name                 | Function        | Description                |
| --- | -------------------- | --------------- | -------------------------- |
| 0   | OSD_MENU_DISP_STYLE  | Display Style   | 0: Vertical, 1: Horizontal |
| 2   | OSD_YCBCR_RGB_FORMAT | Color Format    | 0: RGB, 1: YCbCr           |
| 3   | OSD_INT_NG_LAT       | Interrupt Latch | Interrupt control          |
| 7:4 | OSD_TEST_SEL         | Test Mode       | OSD test mode selection    |

### Register S0_95: OSD Position Control 00
| Bit | Name                | Function         | Description                    |
| --- | ------------------- | ---------------- | ------------------------------ |
| 7:0 | OSD_MENU_HORI_START | Horizontal Start | Menu horizontal start position |

### Register S0_96: OSD Position Control 01
| Bit | Name               | Function       | Description                  |
| --- | ------------------ | -------------- | ---------------------------- |
| 7:0 | OSD_MENU_VER_START | Vertical Start | Menu vertical start position |

### Register S0_97: OSD Bar Control 00
| Bit | Name           | Function   | Description           |
| --- | -------------- | ---------- | --------------------- |
| 7:0 | OSD_BAR_LENGTH | Bar Length | Menu bar total length |

### Register S0_98: OSD Bar Control 01
| Bit | Name                     | Function  | Description               |
| --- | ------------------------ | --------- | ------------------------- |
| 7:0 | OSD_BAR_FOREGROUND_VALUE | Bar Value | Menu bar foreground value |

### Register Access Notes
1. All OSD registers require segment 0 (F0 = 00) for access
2. Color values follow standard RGB/YCbCr color coding:
   - 000: Black
   - 001: Blue
   - 010: Green
   - 011: Cyan
   - 100: Red
   - 101: Magenta
   - 110: Yellow
   - 111: White
3. Position values are in units of 8 pixels
4. Changes to control registers take effect immediately

### Configuration Examples

1. Basic OSD Setup
```
S0_90 = 0x00    // Reset OSD controller
S0_92 = 0x27    // White text on blue background
S0_94 = 0x00    // RGB format, vertical style
S0_95 = 0x3C    // Horizontal position
S0_96 = 0x28    // Vertical position
S0_90 = 0x80    // Enable OSD menu
```

2. Menu Bar Configuration
```
S0_97 = 0x20    // Set bar length to 32 units
S0_98 = 0x10    // Set bar value to 16 units
```

3. High Visibility Setup
```
S0_90 = 0x4C    // 4x zoom
S0_92 = 0x37    // White text on red background
S0_93 = 0x1C    // Blue selection highlight
```

### OSD Icons
The TV5725 supports various predefined icons for common menu functions:
- 0x01: Brightness
- 0x02: Contrast
- 0x03: Hue
- 0x04: Sound/Volume
- 0x08: Up/Down Navigation
- 0x09: Left/Right Navigation
- 0x0A: Vertical Size
- 0x0B: Horizontal Size

## Mode Detect Registers

The Mode Detect section (Chapter 10) controls the automatic detection and classification of input video signals. These registers configure timing detection, mode recognition, and various format-specific parameters.

### Register S1_60: Mode Detect Control 00
| Bit | Name                  | Function      | Description                      |
| --- | --------------------- | ------------- | -------------------------------- |
| 4:0 | MD_HPERIOD_LOCK_VALUE | H Period Lock | Horizontal period lock threshold |
| 7:5 | Reserved              | Reserved      | Reserved for future use          |

### Register S1_61: Mode Detect Control 01
| Bit | Name                    | Function        | Description                      |
| --- | ----------------------- | --------------- | -------------------------------- |
| 4:0 | MD_VPERIOD_LOCK_VALUE   | V Period Lock   | Vertical period lock threshold   |
| 7:5 | MD_VPERIOD_UNLOCK_VALUE | V Period Unlock | Vertical period unlock threshold |

### Register S1_63: Mode Detect Control 03
| Bit | Name       | Function    | Description               |
| --- | ---------- | ----------- | ------------------------- |
| 6   | MD_HS_FLIP | H Sync Flip | 1: Invert H sync polarity |
| 7   | MD_VS_FLIP | V Sync Flip | 1: Invert V sync polarity |

### Register S1_65: Mode Detect VGA Control
| Bit | Name         | Function        | Description                |
| --- | ------------ | --------------- | -------------------------- |
| 6:0 | MD_VGA_CNTRL | VGA Control     | VGA mode detection control |
| 7   | MD_SEL_VGA60 | VGA 60Hz Select | 1: Force VGA 60Hz mode     |

### Register S1_66: Mode Detect VGA 75Hz Control
| Bit | Name              | Function         | Description                        |
| --- | ----------------- | ---------------- | ---------------------------------- |
| 7:0 | MD_VGA_75HZ_CNTRL | VGA 75Hz Control | VGA 75Hz mode detection parameters |

### Register S1_67: Mode Detect VGA 85Hz Control
| Bit | Name              | Function         | Description                        |
| --- | ----------------- | ---------------- | ---------------------------------- |
| 7:0 | MD_VGA_85HZ_CNTRL | VGA 85Hz Control | VGA 85Hz mode detection parameters |

### Register S1_6A: Mode Detect SVGA 60Hz Control
| Bit | Name               | Function          | Description                         |
| --- | ------------------ | ----------------- | ----------------------------------- |
| 7:0 | MD_SVGA_60HZ_CNTRL | SVGA 60Hz Control | SVGA 60Hz mode detection parameters |

### Register S1_6B: Mode Detect SVGA 75Hz Control
| Bit | Name               | Function          | Description                         |
| --- | ------------------ | ----------------- | ----------------------------------- |
| 7:0 | MD_SVGA_75HZ_CNTRL | SVGA 75Hz Control | SVGA 75Hz mode detection parameters |

### Register S1_6C: Mode Detect SVGA 85Hz Control
| Bit | Name               | Function          | Description                         |
| --- | ------------------ | ----------------- | ----------------------------------- |
| 7:0 | MD_SVGA_85HZ_CNTRL | SVGA 85Hz Control | SVGA 85Hz mode detection parameters |

### Register S1_6E: Mode Detect XGA 60Hz Control
| Bit | Name              | Function         | Description                        |
| --- | ----------------- | ---------------- | ---------------------------------- |
| 7:0 | MD_XGA_60HZ_CNTRL | XGA 60Hz Control | XGA 60Hz mode detection parameters |

### Register S1_6F: Mode Detect XGA 70Hz Control
| Bit | Name              | Function         | Description                        |
| --- | ----------------- | ---------------- | ---------------------------------- |
| 6:0 | MD_XGA_70HZ_CNTRL | XGA 70Hz Control | XGA 70Hz mode detection parameters |
| 7   | Reserved          | Reserved         | Reserved for future use            |

### Register S1_70: Mode Detect XGA 75Hz Control
| Bit | Name              | Function         | Description                        |
| --- | ----------------- | ---------------- | ---------------------------------- |
| 6:0 | MD_XGA_75HZ_CNTRL | XGA 75Hz Control | XGA 75Hz mode detection parameters |
| 7   | Reserved          | Reserved         | Reserved for future use            |

### Register S1_71: Mode Detect XGA 85Hz Control
| Bit | Name              | Function         | Description                        |
| --- | ----------------- | ---------------- | ---------------------------------- |
| 6:0 | MD_XGA_85HZ_CNTRL | XGA 85Hz Control | XGA 85Hz mode detection parameters |
| 7   | Reserved          | Reserved         | Reserved for future use            |

### Register S1_73: Mode Detect SXGA 60Hz Control
| Bit | Name               | Function          | Description                         |
| --- | ------------------ | ----------------- | ----------------------------------- |
| 6:0 | MD_SXGA_60HZ_CNTRL | SXGA 60Hz Control | SXGA 60Hz mode detection parameters |
| 7   | Reserved           | Reserved          | Reserved for future use             |

### Register S1_74: Mode Detect SXGA 75Hz Control
| Bit | Name               | Function          | Description                         |
| --- | ------------------ | ----------------- | ----------------------------------- |
| 6:0 | MD_SXGA_75HZ_CNTRL | SXGA 75Hz Control | SXGA 75Hz mode detection parameters |
| 7   | Reserved           | Reserved          | Reserved for future use             |

### Register S1_75: Mode Detect SXGA 85Hz Control
| Bit | Name               | Function          | Description                         |
| --- | ------------------ | ----------------- | ----------------------------------- |
| 6:0 | MD_SXGA_85HZ_CNTRL | SXGA 85Hz Control | SXGA 85Hz mode detection parameters |
| 7   | Reserved           | Reserved          | Reserved for future use             |

### Register S1_7F: Mode Detect HD Control
| Bit | Name             | Function   | Description                          |
| --- | ---------------- | ---------- | ------------------------------------ |
| 6:0 | MD_HD1250P_CNTRL | HD Control | HD mode detection parameters (24kHz) |
| 7   | Reserved         | Reserved   | Reserved for future use              |

### Register Access Notes
1. All Mode Detect registers require segment 1 (F0 = 01) for access
2. Lock/unlock thresholds control mode detection stability:
   - Higher lock values require more stable signals
   - Higher unlock values allow more timing variation
3. Mode-specific control registers configure detection parameters for:
   - VGA modes (640x480)
   - SVGA modes (800x600)
   - XGA modes (1024x768)
   - SXGA modes (1280x1024)
4. Changes to control registers take effect immediately

### Configuration Examples

1. Basic Mode Detection Setup
```
S1_60 = 0xB6    // H period lock/unlock thresholds
S1_61 = 0x84    // V period lock/unlock thresholds
S1_63 = 0x26    // Normal sync polarity
S1_65 = 0x3E    // Enable VGA detection
```

2. High Stability Configuration
```
S1_60 = 0xDC    // Stricter H lock threshold
S1_61 = 0xA5    // Stricter V lock threshold
S1_83 = 0x0C    // Higher unstable lock value
```

3. Custom Mode Detection
```
S1_80 = 0xFF    // Custom horizontal parameters
S1_81 = 0xFF    // Custom vertical parameters
S1_82 = 0x05    // Custom detection control
```

### Supported Video Modes
The Mode Detect unit can automatically detect and classify:
1. Standard Definition:
   - NTSC (480i)
   - PAL (576i)
   - EDTV 480p/576p
2. PC Modes:
   - VGA: 640x480 @ 60/75/85Hz
   - SVGA: 800x600 @ 60/75/85Hz
   - XGA: 1024x768 @ 60/70/75/85Hz
   - SXGA: 1280x1024 @ 60/75/85Hz
3. HD Formats:
   - 720p (1280x720)
   - 1080i (1920x1080)
   - 1080p (1920x1080)
   - Custom HD modes

## ADC Registers

The ADC (Analog-to-Digital Converter) section (Chapter 11) controls the analog input processing and digitization. These registers configure ADC operation, clocking, gain/offset control, and SOG (Sync-On-Green) processing.

### Register S5_00: ADC Clock Control 00
| Bit | Name           | Function     | Description                 |
| --- | -------------- | ------------ | --------------------------- |
| 2:0 | ADC_CLK_PA     | Phase Adjust | ADC clock phase adjustment  |
| 3   | ADC_CLK_ICLK2X | Clock 2X     | 1: Enable 2x internal clock |
| 4   | ADC_CLK_ICLK1X | Clock 1X     | 1: Enable 1x internal clock |
| 7:5 | Reserved       | Reserved     | Reserved for future use     |

### Register S5_02: ADC SOG Control
| Bit | Name          | Function     | Description                        |
| --- | ------------- | ------------ | ---------------------------------- |
| 0   | ADC_SOGEN     | SOG Enable   | 1: Enable Sync-On-Green processing |
| 5:1 | ADC_SOGCTRL   | SOG Control  | Sync slice level (10mV per step)   |
| 7:6 | ADC_INPUT_SEL | Input Select | Input channel selection            |

### Register S5_03: ADC Power Control
| Bit | Name        | Function    | Description                                    |
| --- | ----------- | ----------- | ---------------------------------------------- |
| 0   | ADC_POWDZ   | Power Down  | 0: Power down ADC, 1: Normal operation         |
| 1   | ADC_RYSEL_R | Red Clamp   | 1: Midlevel clamp, 0: Ground clamp             |
| 2   | ADC_RYSEL_G | Green Clamp | 1: Midlevel clamp, 0: Ground clamp             |
| 3   | ADC_RYSEL_B | Blue Clamp  | 1: Midlevel clamp, 0: Ground clamp             |
| 5:4 | ADC_FLTR    | Filter      | ADC bandwidth filter (00: 150MHz to 11: 40MHz) |
| 7:6 | Reserved    | Reserved    | Reserved for future use                        |

### Register S5_06: ADC Red Offset Control
| Bit | Name        | Function   | Description                      |
| --- | ----------- | ---------- | -------------------------------- |
| 7:0 | ADC_ROFCTRL | Red Offset | Red channel DC offset adjustment |

### Register S5_07: ADC Green Offset Control
| Bit | Name        | Function     | Description                        |
| --- | ----------- | ------------ | ---------------------------------- |
| 7:0 | ADC_GOFCTRL | Green Offset | Green channel DC offset adjustment |

### Register S5_08: ADC Blue Offset Control
| Bit | Name        | Function    | Description                       |
| --- | ----------- | ----------- | --------------------------------- |
| 7:0 | ADC_BOFCTRL | Blue Offset | Blue channel DC offset adjustment |

### Register S5_09: ADC Red Gain Control
| Bit | Name       | Function | Description                 |
| --- | ---------- | -------- | --------------------------- |
| 7:0 | ADC_RGCTRL | Red Gain | Red channel gain adjustment |

### Register S5_0A: ADC Green Gain Control
| Bit | Name       | Function   | Description                   |
| --- | ---------- | ---------- | ----------------------------- |
| 7:0 | ADC_GGCTRL | Green Gain | Green channel gain adjustment |

### Register S5_0B: ADC Blue Gain Control
| Bit | Name       | Function  | Description                  |
| --- | ---------- | --------- | ---------------------------- |
| 7:0 | ADC_BGCTRL | Blue Gain | Blue channel gain adjustment |

### Register S5_0E: ADC Auto Offset Control
| Bit | Name                | Function           | Description                           |
| --- | ------------------- | ------------------ | ------------------------------------- |
| 0   | ADC_AUTO_OFST_EN    | Auto Offset Enable | 1: Enable automatic offset adjustment |
| 1   | ADC_AUTO_OFST_PRD   | Update Period      | 0: Line-based, 1: Frame-based         |
| 3:2 | ADC_AUTO_OFST_DELAY | Delay              | Delay before offset measurement       |
| 5:4 | ADC_AUTO_OFST_STEP  | Step Size          | Adjustment step size                  |
| 6   | Reserved            | Reserved           | Reserved for future use               |
| 7   | ADC_AUTO_OFST_TEST  | Test Mode          | 1: Enable test mode                   |

### Register S5_0F: ADC Auto Offset Range
| Bit | Name                    | Function | Description                  |
| --- | ----------------------- | -------- | ---------------------------- |
| 7:0 | ADC_AUTO_OFST_RANGE_REG | Range    | Auto offset adjustment range |

### Register Access Notes
1. All ADC registers require segment 5 (F0 = 05) for access
2. ADC gain and offset values take effect immediately
3. SOG control affects sync separation quality
4. Filter settings trade bandwidth for noise reduction
5. Auto offset should be used carefully with proper delay settings

### Configuration Examples

1. Basic ADC Setup
```
S5_00 = 0x00    // Normal clock operation
S5_02 = 0x21    // Enable SOG, mid-range slice level
S5_03 = 0x0F    // Power up ADC, all channels midlevel clamp
```

2. RGB Input Configuration
```
S5_03 = 0x0E    // Ground clamp for green, midlevel for R/B
S5_09 = 0x80    // Unity gain for red
S5_0A = 0x80    // Unity gain for green
S5_0B = 0x80    // Unity gain for blue
```

3. Auto Offset Setup
```
S5_0E = 0x13    // Enable auto offset, line-based, medium step
S5_0F = 0x20    // Medium adjustment range
```

### ADC Operating Modes

1. Normal Mode
- Full power operation
- All features available
- Maximum bandwidth

2. Power-Saving Mode
- Reduced bandwidth
- Lower power consumption
- Suitable for standard-definition inputs

3. SOG Processing
- Sync separation from green channel
- Adjustable slice level
- Critical for component video inputs

### Initialization Sequence
1. Power-up sequence:
   ```
   S5_03 = 0x00    // Power down ADC
   // Wait 100μs
   S5_03 = 0x0F    // Power up ADC, configure clamps
   S5_00 = 0x00    // Configure clocking
   // Configure gain/offset
   S5_02 = 0x21    // Enable SOG if needed
   ```

2. Power-down sequence:
   ```
   S5_02 = 0x00    // Disable SOG
   S5_03 = 0x00    // Power down ADC
   ```

## Sync Processor Registers

The Sync Processor section (Chapter 12) controls the synchronization signal processing and timing recovery. These registers configure sync detection, polarity control, timing measurements, and various sync processing parameters.

### Register S5_20: Sync Processor Control 00
| Bit | Name            | Function          | Description                            |
| --- | --------------- | ----------------- | -------------------------------------- |
| 0   | SP_SOG_SRC_SEL  | SOG Source Select | 1: Select SOG as sync source           |
| 1   | SP_SOG_P_ATO    | SOG Auto Polarity | 1: Enable automatic polarity detection |
| 2   | SP_SOG_P_INV    | SOG Polarity      | 1: Invert SOG polarity                 |
| 3   | SP_EXT_SYNC_SEL | External Sync     | 1: Use external sync                   |
| 4   | SP_JITTER_SYNC  | Jitter Reduction  | 1: Enable sync jitter reduction        |
| 7:5 | Reserved        | Reserved          | Reserved for future use                |

### Register S5_21: Sync Toggle Threshold
| Bit | Name            | Function         | Description                  |
| --- | --------------- | ---------------- | ---------------------------- |
| 7:0 | SP_SYNC_TGL_THD | Toggle Threshold | H Sync toggle time threshold |

### Register S5_22: Sync Width Difference
| Bit | Name         | Function    | Description                           |
| --- | ------------ | ----------- | ------------------------------------- |
| 7:0 | SP_L_DLT_REG | Width Delta | Sync pulse width difference threshold |

### Register S5_24: H Total Difference
| Bit | Name         | Function    | Description                        |
| --- | ------------ | ----------- | ---------------------------------- |
| 7:0 | SP_T_DLT_REG | Total Delta | H total width difference threshold |

### Register S5_26: Sync Pulse Width
| Bit  | Name           | Function    | Description                  |
| ---- | -------------- | ----------- | ---------------------------- |
| 11:0 | SP_SYNC_PD_THD | Pulse Width | H sync pulse width threshold |

### Register S5_2A: Period Equality
| Bit | Name          | Function     | Description                          |
| --- | ------------- | ------------ | ------------------------------------ |
| 7:0 | SP_PRD_EQ_THD | Period Match | Number of legal lines for validation |

### Register S5_33: H Timer Value
| Bit | Name           | Function    | Description                      |
| --- | -------------- | ----------- | -------------------------------- |
| 7:0 | SP_H_TIMER_VAL | Timer Value | H timer value for sync detection |

### Register S5_34: V Timer Value
| Bit | Name           | Function    | Description                      |
| --- | -------------- | ----------- | -------------------------------- |
| 7:0 | SP_V_TIMER_VAL | Timer Value | V timer value for sync detection |

### Register S5_3E: Sync Control
| Bit | Name             | Function      | Description                     |
| --- | ---------------- | ------------- | ------------------------------- |
| 0   | SP_CS_P_SWAP     | Polarity Swap | 1: Swap sync polarity           |
| 1   | SP_HD_MODE       | HD Mode       | 1: Enable HD sync processing    |
| 2   | SP_H_COAST       | H Coast       | 1: Enable horizontal coast      |
| 4   | SP_H_PROTECT     | H Protect     | 1: Enable horizontal protection |
| 5   | SP_DIS_SUB_COAST | Disable Coast | 1: Disable subsequent coast     |
| 7:6 | Reserved         | Reserved      | Reserved for future use         |

### Register S5_41: Clamp Start
| Bit  | Name         | Function    | Description                      |
| ---- | ------------ | ----------- | -------------------------------- |
| 11:0 | SP_CS_CLP_ST | Clamp Start | Clamp start position (in pixels) |

### Register S5_43: Clamp Stop
| Bit  | Name         | Function   | Description                     |
| ---- | ------------ | ---------- | ------------------------------- |
| 11:0 | SP_CS_CLP_SP | Clamp Stop | Clamp stop position (in pixels) |

### Register S5_45: H Sync Start
| Bit  | Name        | Function     | Description                       |
| ---- | ----------- | ------------ | --------------------------------- |
| 11:0 | SP_CS_HS_ST | H Sync Start | H sync start position (in pixels) |

### Register S5_47: H Sync Stop
| Bit  | Name        | Function    | Description                      |
| ---- | ----------- | ----------- | -------------------------------- |
| 11:0 | SP_CS_HS_SP | H Sync Stop | H sync stop position (in pixels) |

### Register S5_55: Sync Polarity Control
| Bit | Name          | Function        | Description                    |
| --- | ------------- | --------------- | ------------------------------ |
| 4   | SP_HS_POL_ATO | H Sync Auto Pol | 1: Enable H sync auto polarity |
| 6   | SP_VS_POL_ATO | V Sync Auto Pol | 1: Enable V sync auto polarity |

### Register S5_56: PLL Control
| Bit | Name               | Function           | Description                 |
| --- | ------------------ | ------------------ | --------------------------- |
| 0   | SP_HS2PLL_INV_REG  | H Sync PLL Invert  | 1: Invert H sync to PLL     |
| 5   | SP_HS_PROC_INV_REG | H Sync Proc Invert | 1: Invert H sync to decoder |

### Register S5_57: Loop Control
| Bit | Name           | Function    | Description                        |
| --- | -------------- | ----------- | ---------------------------------- |
| 6   | SP_HS_LOOP_SEL | Loop Select | 0: Full SP sync, 1: Bypass SP sync |

### Register Access Notes
1. All Sync Processor registers require segment 5 (F0 = 05) for access
2. Timing parameters are in pixel clock cycles
3. Polarity settings affect sync detection reliability
4. Coast and protection features help maintain sync during noise
5. Changes to control registers take effect at next sync event

### Configuration Examples

1. Basic Sync Setup
```
S5_20 = 0x00    // Normal sync operation
S5_21 = 0x18    // H sync toggle threshold
S5_22 = 0x0F    // Sync width difference threshold
S5_26 = 0x04    // H sync pulse width threshold
```

2. HD Sync Processing
```
S5_3E = 0x02    // Enable HD mode
S5_56 = 0x00    // Normal PLL operation
S5_57 = 0x00    // Use full SP sync processing
```

3. Clamp Configuration
```
// ... existing code ...

