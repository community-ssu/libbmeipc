/*
NOKIA                                                             CONFIDENTIAL
Copenhagen
TP/WP/CoreSW
EM Team Leader



                  EM ISI Server Message Include File
                  --------------------------------
                  SW Include Document - ANSI C/C++



Continuus Ref:
--------------
database:        ou1gif

project path:    global_interface/ISI/Core

name:            em_isi.h

version:         008.028

type:            incl

instance:        -


ISI header file for Energy Management Server

Current   ISI Version : 008.028
Supported ISI Versions: 007.000, 007.001, 007.002, 007.003, 007.004, 007.005,
                        007.006, 007.007, 007.008, 007.009, 007.010, 007.011,
                        007.012, 007.013, 007.014, 007.015, 008.000, 008.001,
                        008.002, 008.003, 008.004, 008.005, 008.006, 008.007,
                        008.008, 008.009, 008.010, 008.011, 008.012, 008.020,
                        008.021, 008.022, 008.023, 008.024, 008.025, 008.026,
                        008.027, 008.028

Generated with autogen version 09_w47 on 02-Dec-2009 12:01:04
DO NOT EDIT - changes will be lost at next autogeneration

Copyright (c) Nokia Corporation. All rights reserved.


ISI version change history

Version     : 008.028    APPROVED    02-Dec-2009    Ronny Hansen
Reason      : Change for Maemo
Reference   : SWAM CR: TF09102739348, CM Synergy task id: co1core2#
Description : Added Subblock EM_CONTROL_BACKUP_BATTERY_CHARGING_DATA to EM_CONTROL_WRITE_REQ
              Added Subblock EM_CONTROL_BACKUP_BATTERY_CHARGING_DATA
              Added Constant table EM_CONTROL_BACKUP_BATTERY_CHARGING_ACTION
              Added new subblock EM_CONTROL_BACKUP_BATTERY_CHARGING_DATA.

Version     : 008.027    APPROVED    16-Oct-2008    Emanuele Zattin
Reason      : SCO: 006-8509: Battery charging percentage.
Reference   : RM-RIM: 006-8509, SWAM CR: EZ08101651735, SWAM Inspection:
              EZ08102937344, CM Synergy task id: co1core2#34578
Description : Added Subblock EM_MONITORING_BATT_PERC_DATA to EM_MONITORING_INFO_RESP
              Added Subblock EM_MONITORING_BATT_PERC_DATA
              Added new subblock EM_MONITORING_BATT_PERC_DATA to
              EM_MONITORING_INFO_RESP.

Version     : 008.026    APPROVED    08-Oct-2008    Aske Olsson
Reason      : SCO: 417-2595: Charger (change) indication.
Reference   : RM-RIM: 417-2595, SWAM CR: AO08090543618 , SWAM Inspection:
              AO08100837484, CM Synergy task id: co1core2#29647
Description : Added Entry EM_CHARGER_USB_DEDICATED_CHARGER to EM_CHARGER_TYPE_INFO
              Added Entry EM_CHARGER_USB_HOST_HUB_CHARGER_FULL to EM_CHARGER_TYPE_INFO
              Added Entry EM_CHARGER_USB_HOST_HUB_CHARGER_HIGH to EM_CHARGER_TYPE_INFO
              Added Entry EM_CHARGER_USB_HOST_HUB_HIGH to EM_CHARGER_TYPE_INFO
              Added Entry EM_CHARGER_USB_HOST_HUB_LOW to EM_CHARGER_TYPE_INFO
              Added new constants to EM_CHARGER_TYPE_INFO for USB chargers.

Version     : 008.025    APPROVED    15-Jul-2008    Michael Bjerking
Reason      : SCO: 408-3933 : Enable field test display support for
              point-based battery monitor
Reference   : RM-RIM: 408-2412, SWAM CR: None SWAM Inspection: MB08071558296,
              CM Synergy task id: co1core2#26225
Description : Added new FTD fields: EM_SB_FTD_REMAIN_PROMILLE,
              EM_SB_FTD_DELTA_CAPACITY, EM_SB_FTD_REMAIN_CAPACITY

Version     : 008.024    APPROVED    03-Jul-2008    Michael Bjerking
Reason      : SCO: 408-5415 : BCOM EB3: Chipset API: Energy Management API
              Implementation (Phase 2 EM server)
Reference   : RM-RIM: 417-7622, SWAM CR: MB08050538512, SWAM Inspection:
              None, CM Synergy task id: co1core2#22663
Description : Added Message EM_ADC_CHIPSET_CAL_CALCULATE_REQ
              Added Message EM_ADC_CHIPSET_CAL_CALCULATE_RESP
              Added Message EM_ADC_CHIPSET_CAL_READ_REQ
              Added Message EM_ADC_CHIPSET_CAL_READ_RESP
              Added Message EM_ADC_CHIPSET_CAL_STORE_REQ
              Added Message EM_ADC_CHIPSET_CAL_STORE_RESP
              Added Subblock EM_ADC_CHIPSET_CAL_CALCULATE_REQ_DATA
              Added Subblock EM_ADC_CHIPSET_CAL_READ_REQ_DATA
              Added Subblock EM_ADC_CHIPSET_CAL_READ_RESP_DATA
              Added Constant table EM_CHIPSET_CAL_STORE
              Added Constant table EM_CHIPSET_CAL_TYPE
              Added Bitmask table EM_CHIPSET_OPT_CAL
              Added new req/resp EM_ADC_CHIPSET_CAL_CALCULATE_REQ,
              EM_ADC_CHIPSET_CAL_READ_REQ, EM_ADC_CHIPSET_CAL_STORE_REQ

Version     : 008.023    APPROVED    16-Jun-2008    Aske Olsson
Reason      : SCO 408-3608: Dedicated charger detection production testing
              with ISP1704/7.
Reference   : RM-RIM: 408-3608, SWAM CR: AO08051644192, SWAM Inspection:
              AO08061352466, CM Synergy task id: co1core2#19597
Description : Added Subblock EM_CONTROL_USB_CHARGER_TYPE to EM_CONTROL_READ_RESP
              Added Subblock EM_CONTROL_USB_CHARGER_TYPE
              Added Entry EM_CONTROL_USB_CHARGER_ACTION_GET_CHARGER_TYPE to EM_CONTROL_USB_CHARGER_ACTION
              Added Constant table EM_CONTROL_USB_CHARGER_HOST_CURRENT
              Added Constant table EM_CONTROL_USB_CHARGER_TYPE_INFO
              Added new subblock EM_CONTROL_USB_CHARGER_TYPE.

Version     : 008.022    APPROVED    03-Jun-2008    Frank Joergensen
Reason      : SCO
Reference   : RM-RIM: 408-2986, SWAM CR: FJ08042552190, CM Synergy task id
              (headers): co1core2#15174, CM Synergy task id (spec):
              co1core2#15175
Description : Added Entry EM_ADC_SCALE1_CAL to EM_ADC_CHANNEL_INFO
              Added Entry EM_ADC_SCALE2_CAL to EM_ADC_CHANNEL_INFO
              Added Entry EM_ADC_SCALE3_CAL to EM_ADC_CHANNEL_INFO
              Added Entry EM_ADC_SCALE4_CAL to EM_ADC_CHANNEL_INFO
              Added Entry EM_ADC_SCALE5_CAL to EM_ADC_CHANNEL_INFO
              Added Entry EM_ADC_TESTNET1_VCHAR_ADC to EM_ADC_CHANNEL_INFO
              Added Entry EM_ADC_TESTNET2_BSI to EM_ADC_CHANNEL_INFO
              Added Entry EM_ADC_TESTNET3_VBAT_VANA to EM_ADC_CHANNEL_INFO
              Added 5 new logical (pseudo) ADC channels EM_ADC_SCALE1_CAL -
              EM_ADC_SCALE5_CAL, which can be used for handling ADC scaling
              buffer calibration in Gazoo & Pearl Mixed-Signal ASIC's.Added
              EM_ADC_TESTNET1_VCHAR_ADC, EM_ADC_TESTNET2_BSI,
              EM_ADC_TESTNET3_VBAT_VANA used for measuring internal signals
              via reaspective testnet channel.

Version     : 008.021    APPROVED    22-Feb-2008    Aske Olsson
Reason      : SCO 408-1779: Extend the notification EM_MEASUREMENT_NTF to
              include battery voltage.
Reference   : RM-RIM: 408-1779, SWAM CR: AO08022552302, SWAM Inspection:
              AO08042547746, CM Synergy task id: co1core2#13942
Description : Added Entry EM_MEASUREMENT_TYPE_VOLTAGE to EM_MEASUREMENT_VALUE
              Added new value type to EM_MEASUREMENT_VALUE, renewed
              description of EM_MEASUREMENT_REQ.

Version     : 008.020    APPROVED    15-Dec-2007    Frank Joergensen
Reason      : SCO, LitePlus Support
Reference   : RM-RIM: 408-2173 & 408-2670SWAM CR: FJ08010463793, CM Synergy
              task id (ISI C-files): co1core#90465, CM Synergy task id (ISI
              Spec): co1core#92192
Description : Added Subblock EM_ADC_CAL_STORED_MEAS_DATA to EM_ADC_CAL_READ_RESP
              Added Sequence EM_ADC_CAL_RAW_MEAS_RESULT_SEQ_ENTRY
              Added Subblock EM_ADC_CAL_STORED_MEAS_DATA
              Added Entry EM_ADC_STORED_MEAS_FLAG to EM_ADC_ACTION_INFO
              Re-introduced Entry EM_ADC_TESTNET1 in EM_ADC_CHANNEL_INFO
              Re-introduced Entry EM_ADC_TESTNET2 in EM_ADC_CHANNEL_INFO
              Re-introduced Entry EM_ADC_TESTNET3 in EM_ADC_CHANNEL_INFO
              Jump to version 008.020 to reserve 008.013 to 008.019 for
              changes to old branches

Version     : 008.012    APPROVED    15-Oct-2007    Martin Steen
Reason      : SCO
Reference   : RM-RIM: SCO: 006-16370, 408-2046,SWAM CR: MS07100142816, SWAM
              Inspection: MS07101650548, CM Synergy task id: co1core#84462
Description : Changed Message EM_CONTROL_READ_REQ
              Added Subblock EM_CONTROL_USB_CHARGER_DATA to EM_CONTROL_READ_RESP
              Discontinued Entry EM_ADC_TESTNET1 in EM_ADC_CHANNEL_INFO
              Discontinued Entry EM_ADC_TESTNET2 in EM_ADC_CHANNEL_INFO
              Discontinued Entry EM_ADC_TESTNET3 in EM_ADC_CHANNEL_INFO
              Added Entry EM_CONTROL_USB_CHARGER_ACTION_GET_500_100_DETECT_PIN_STATUS to EM_CONTROL_USB_CHARGER_ACTION
              Added Entry EM_CONTROL_USB_CHARGER_ACTION_GET_MSASIC_VBUSDET_STATUS to EM_CONTROL_USB_CHARGER_ACTION
              Added Entry EM_CONTROL_USB_CHARGER_ACTION_MSASIC_USB_CHARGING to EM_CONTROL_USB_CHARGER_ACTION
              Added Entry EM_CONTROL_USB_CHARGER_ACTION_OUTPUT_CURRENT to EM_CONTROL_USB_CHARGER_ACTION

Version     : 008.011    APPROVED    23-May-2007    Martin Steen
Reason      : SCO
Reference   : RM-RIM: SCO: 404-492, SWAM CR: MS07052332726, SWAM Inspection:
              MS07083047343, CM Synergy task id: co1core#75676
Description : Added Entry EM_CONTROL_USB_CHARGER_ACTION_FLOAT_VOLTAGE to EM_CONTROL_USB_CHARGER_ACTION
              Added Entry EM_CONTROL_USB_CHARGER_ACTION_INPUT_CURRENT to EM_CONTROL_USB_CHARGER_ACTION

Version     : 008.010    APPROVED    16-Feb-2007    Robin Hansen
Reason      : SCO
Reference   : RM-RIM: SCO: 006-14685, SWAM CR: RH07090250880, SWAM
              Inspection: RH07030537867, CM Synergy task id: co1core#69220
Description : Added Entry EM_ADC_IDDET to EM_ADC_CHANNEL_INFO
              Added Entry EM_ADC_TESTNET1 to EM_ADC_CHANNEL_INFO
              Added Entry EM_ADC_TESTNET2 to EM_ADC_CHANNEL_INFO
              Added Entry EM_ADC_TESTNET3 to EM_ADC_CHANNEL_INFO
              Added Entry EM_ADC_VBAT_SAMPLED to EM_ADC_CHANNEL_INFO
              Added Entry EM_ADC_VBUS to EM_ADC_CHANNEL_INFO
              Added new symbolic names for Gazoo ADC Channels.

Version     : 008.009    APPROVED    05-Jan-2007    Michael Bjerking
Reason      : SCO
Reference   : RM-RIM: SCO: 006-15266, CR: MB07011252222, ActionDB for SWAM:
              MB07012247812, CM Synergy task id: co1core#67139
Description : Added Message EM_ME_STATE_REQ
              Added Message EM_ME_STATE_RESP
              Added Constant table EM_ME_STATE_ACTION
              Added Constant table EM_ME_STATE_RESULT
              Added new request EM_ME_STATE_REQ/RESPThis new request id to
              enable/disable em measurement (production).

Version     : 008.008    APPROVED    08-Sep-2006    Ronny Hansen
Reason      : SCO
Reference   : RM-RIM: SCO: 006-13026, CR: RH06090848162, ActionDB for SWAM:
              RH06091357937, CM Synergy task id: co1core#60472
Description : Added Subblock EM_CONTROL_USB_CHARGER_DATA to EM_CONTROL_WRITE_REQ
              Added Subblock EM_CONTROL_USB_CHARGER_DATA
              Added Constant table EM_CONTROL_USB_CHARGER_ACTION
              Added new subblock (EM_CONTROL_USB_CHARGER_DATA) to
              EM_CONTROL_WRITE_REQ.This new subblock allows for external
              control of the USB charging chip.

Version     : 008.007    APPROVED    17-Aug-2006    Ronny Hansen
Reason      : PCP
Reference   : PCP Error: RH06081542680, CR: RH06081834277, ActionDB for SWAM:
              RH06082234515, CM Synergy task id: co1core#59009
Description : Added Message EM_SELFTEST_REQ
              Added Message EM_SELFTEST_RESP
              Added Constant table EM_SELFTEST_ID
              Added Constant table EM_SELFTEST_RESULT
              Added messages to support selftest server executing tests

Version     : 008.006    APPROVED    07-Jun-2006    Michael Bjerking
Reason      : SCO
Reference   : RM-RIM: 006-8980, CR: FJ06050258515, ActionDB for SWAM:
              RH06051753834, CM Synergy task id: co1core#52098
Description : Added Message EM_MEASUREMENT_NTF
              Added Message EM_MEASUREMENT_REQ
              Added Message EM_MEASUREMENT_RESP
              Added Subblock EM_MEASUREMENT
              Added Subblock EM_MEASUREMENT_TYPE
              Added Constant table EM_MEASUREMENT_ACTION
              Added Constant table EM_MEASUREMENT_PERIOD
              Added Constant table EM_MEASUREMENT_RESULT
              Added Constant table EM_MEASUREMENT_VALUE
              Added new messages, subblocks and types to suppport real-time
              EM measuring.

Version     : 008.005    APPROVED    07-Apr-2006    Hongyan Sun
Reason      : SCO
Reference   : RM-RIM 006-5989, ActionDB for SWAM: HS06032835542, CM Synergy
              task id: co1core#49821 and co1core#49405
Description : Added Entry EM_PSM_EXT_LIGHTS to EM_PSM_EXTERNAL_DEVICE_INFO
              Added external device id for lights.

Version     : 008.004    APPROVED    31-May-2005    Bjarne Glerup
Reason      : UMA and BUB added.
Reference   : ActionDB for SWAM: BG05041450145, RM-RIM 006-7490, Continuus
              task id: co1core#33209 and co1core#33271.
Description : Added Entry EM_CONTROL_BUB_NO_SUPPORT to EM_CONTROL_BACKUP_BATTERY_INFO
              Added Entry EM_PSM_CS_PROTOCOL_UMA to EM_PSM_CS_ACTIVE_PROTOCOL_INFO
              Added UMA protocol and BUB no support. In addition updata
              according to findings in inspection are done.

Version     : 008.003    APPROVED    21-Jan-2005    Knud Poulsen
Reason      : Assorted updates, comments, bugfixes.
Reference   : ActionDB for SWAM: KP05010639844, Inspection in SWAM:
              KP05012136979, Continuus task id: co1core#25258 and
              co1core#25260.
Description : Added Entry BATTERY_GENERATION_TABBY_BSI to EM_BATTERY_GEN_INFO
              Added Entry EM_CHARGING_OVV_RECOVERY to EM_CHARGING_MODE_INFO
              Added Entry EM_CHARGING_SPECIAL_WAIT to EM_CHARGING_MODE_INFO
              Fixed autogen compiler warnings and some comments.

Version     : 008.002    APPROVED    13-Jul-2004    Knud Poulsen
Reason      : RM-RIM id 006-3127.
Reference   : ActionDB for SWAM: KP04042753279, Inspection in SWAM:
              KP04061442320, Continuus task id: co1core#13857 and
              co1core#13865.
Description : Added Entry EM_CHARGER_SPECIAL to EM_CHARGER_TYPE_INFO
              Added Entry EM_CHARGING_SPECIAL_CHARGE to EM_CHARGING_MODE_INFO
              Added Entry EM_CHARGING_STATE_CONTINUE to EM_CHARGING_STATE_INFO
              Added EM_CHARGING_STATE_CONTINUE to EM_CHARGING_STATE_INFO.
              Added EM_CHARGER_SPECIAL to EM_CHARGER_TYPE_INFO. Added
              EM_CHARGING_SPECIAL_CHARGE to EM_CHARGING_MODE_INFO. Added Spe
              (Special Charger) and SpC (Special Charging) to FTD comments.
              Added comment to EM_CHARGER_INFO_RESP. Elaborated comments
              regarding EM_ADC_IBAT_AVG & IBAT_AVG. Updated
              EM_SB_FTD_CONF_BAT_FOOTPRINT with 3 new batteries.

Version     : 008.001    APPROVED    01-Apr-2003    Frank Joergensen
Reason      : RM-RIM id 006-2315.
Reference   : ActionDB for SWAM: FJ04032451620, Continuus task id:
              co_core#26823 and co_core#26824.
Description : Added Subblock EM_ADC_CAL_ALG_DATA to EM_ADC_CAL_READ_RESP
              Added Subblock EM_ADC_CAL_ALG_DATA
              Added Entry EM_ADC_ALG_FLAG to EM_ADC_ACTION_INFO
              Added Constant table EM_ADC_ALG_ID_INFO
              Added new Action EM_ADC_ALG_FLAG to EM_ADC_ACTION_INFO. Added
              SubBlock EM_ADC_CAL_ALG_DATA to EM_ADC_CAL_READ_RESP. Added
              typedef for tEMADCCalAlgDataAdded comment to
              EM_ADC_CAL_WRITE_REQ

Version     : 008.000    APPROVED    10-Feb-2003    Soeren Chr. Bisgaard
Reason      : PCP Error: JN03112943738.
Reference   : ActionDB for SWAM: SB04011239570, Continuus task id:
              co_core#24496 and co_core#24582. Continuus task id:
              co_core#24685 and co_core#24709.
Description : Changed Subblock EM_ADC_CAL_TUNE_RESP_DATA
              Added a status field to the SubBlock: -
              EM_ADC_CAL_TUNE_RESP_DATA Updated references to EM SW
              documents. Inspection:  - Old version of
              EM_ADC_CAL_TUNE_RESP_DATA is obsolete from version 008.000 not
              from version 007.015.  - Remove EM_INFO_NOT_SUPPORTED as a
              valid value in EM_ADC_CAL_TUNE_RESP_DATA. Added typedefs for
              the 16 bit header file.

Version     : 007.015    APPROVED    19-Nov-2003    Soeren Chr. Bisgaard
Reason      : Removal of USB interface for Symbian-OS.
Reference   : ISA RM id: 010-1509, ISA RM id: 006-2435, ISA RM id: 006-2863,
              ActionDB for SWAM: SB03103141983, Continuus task id:
              co_core#22755.
Description : Added Message EM_POWER_REQ
              Added Message EM_POWER_RESP
              Added Message EM_SOS_EVENT_NTF
              Added Message EM_SOS_EVENT_REQ
              Added Message EM_SOS_EVENT_RESP
              Added Subblock EM_SOS_TIMER_EVENT_DATA
              Added Constant table EM_POWER_CONSUMER_INFO
              Added Constant table EM_POWER_STATE_INFO
              Added Constant table EM_SOS_EVENT_INFO
              Removed the following messages: - EM_SOS_REGISTER_WRITE_REQ -
              EM_SOS_REGISTER_WRITE_RESP - EM_SOS_REGISTER_READ_REQ -
              EM_SOS_REGISTER_READ_RESP including sub-blocks and symbols.
              Also removed the sub-block and symbols used for USB events.
              Changed Continuus location.

Version     : 007.014    APPROVED    17-Oct-2003    Soeren Chr. Bisgaard
Reason      : New interface for PM and Symbian OS.
Reference   : ISA RM id: 010-1509, ISA RM id: 006-1614, ISA RM id: 006-2435,
              ActionDB for SWAM: SB03092927902, Continuus task id:
              co_core#21351.
Description : New messages for Power Management and Symbian OS interface -
              EM_POWER_REQ - EM_POWER_RESP - EM_SOS_REGISTER_WRITE_REQ -
              EM_SOS_REGISTER_WRITE_RESP - EM_SOS_REGISTER_READ_REQ -
              EM_SOS_REGISTER_READ_RESP - EM_SOS_EVENT_REQ -
              EM_SOS_EVENT_RESP - EM_SOS_EVENT_NTF including sub-blocks and
              symbols. Added missing filler to EM_PSM_EXTERNAL_WRITE_REQ.
              Removed 47K footprint from FTD's and corrected a name from
              BL_5C to BL_6C.

Version     : 007.013    APPROVED    18-Sep-2003    Frank Joergensen
Reason      : New transfer function and Sensor changed.
Reference   : ISA RM id: 006-2259, ISA RM id: 006-1962, ActionDB for SWAM:
              FJ03090443402, Continuus task id: co_core#21316.
Description : Added Entry EM_ADC_PARALLEL_NTC_FLAG to EM_ADC_TRANSFER_FUNCTION_INFO
              Added Entry EM_PSM_SENSORS_ACTIVE to EM_PSM_ACTIVITY_INFO
              Added Entry EM_PSM_EXT_SENSORS to EM_PSM_EXTERNAL_DEVICE_INFO
              Sensors changed to enternal power consumer. Is still backwards
              compatible. Transfer function id EM_ADC_PARALLEL_NTC_FLAG added
              to EM_ADC_TRANSFER_FUNCTION_INFO.

Version     : 007.012    APPROVED    15-Jul-2003    Emil Froeding
Reason      : Changes in EM interface for BB5 implementation and internal
              Compass feature.
Reference   : ISA RM id: 006-1962, ISA RM id: 006-1878, ActionDB for SWAM:
              EF03070749492, Continuus task id: co_core#20031.
Description : Changed Message EM_ADC_READ_REQ
              Changed Message EM_ADC_UNIT_REQ
              Added Entry EM_ADC_LS_TEMP to EM_ADC_CHANNEL_INFO
              Added Entry EM_ADC_RETU_TEMP to EM_ADC_CHANNEL_INFO
              Added Entry EM_ADC_RF_MEAS to EM_ADC_CHANNEL_INFO
              Added Entry EM_ADC_WB_TX_DET to EM_ADC_CHANNEL_INFO
              Sensors added as an internal power consumer. Additional
              changes: Footprints added in FTD descriptions. EM_ADC_READ_REQ
              and EM_ADC_UNIT_REQ updated to use the EM_ADC_CHANNEL_INFO
              instead of pure text. Table in Chapter 4.10 changed

Version     : 007.011    APPROVED    8-Nov-2002     Carsten Hauge
Reason      : Touchpad current consumption support.
Reference   : ISA RM id: 009-1134, ActionDB for SWAM: CH02110843061,
              Continuus task id: co_core#14098.
Description : Added Case EM_PSM_INT_TOUCHPAD to EM_PSM_INTERNAL_WRITE_REQ
              Added Entry EM_PSM_TOUCHPAD_ACTIVE to EM_PSM_ACTIVITY_INFO
              Added Entry EM_PSM_INT_TOUCHPAD to EM_PSM_INTERNAL_DEVICE_INFO
              Touchpad added as an internal power consumer. Additional
              changes: Footprints and usb added in FTD descriptions.
              EM_ADC_CAL_TUNE_RESP_DATA ITEM_LIMITS changed. Example added in
              EM_ADC_CAL_TUNE_REQ_DATA. Reference to FTD spec added.

Version     : 007.010    APPROVED    10-Oct-2002    Carsten Hauge
Reason      : USB MM and Thermometer support and inspection of Calibration
              optimization in production line.
Reference   : ISA RM id: 8247 & 9449, ActionDB for SWAM: CH02101042545,
              Continuus task id: co_core#13339, Inspection minutes in SWAM:
              CH02100254109.
Description : Added Case EM_PSM_INT_USB to EM_PSM_INTERNAL_WRITE_REQ
              Added Message EM_TEMPERATURE_CHANGED_IND
              Added Message EM_TEMPERATURE_QUERY_REQ
              Added Message EM_TEMPERATURE_QUERY_RESP
              Added Entry EM_PSM_USB_ACTIVE to EM_PSM_ACTIVITY_INFO
              Added Entry EM_PSM_INT_USB to EM_PSM_INTERNAL_DEVICE_INFO
              Added Constant table EM_TEMPERATURE_INFO
              EM_TEMPERATURE_QUERY_REQ, EM_TEMPERATURE_QUERY_RESP
              EM_TEMPERATURE_CHANGED_IND message added. EM_PSM_INT_USB,
              EM_PSM_USB_ACTIVE, EM_TEMPERATURE_OK and EM_TEMPERATURE_FAIL
              defines added. Spelling error in state_transition_timer_value.

Version     : 007.009    APPROVED    18-Sep-2002    Carsten Hauge
Reason      : Calibration optimization in production.
Reference   : ISA RM id: 9128, ActionDB for SWAM: CH02091830634, Continuus
              task id: co_core#12701
Description : Added Message EM_ADC_CAL_TUNE_REQ
              Added Message EM_ADC_CAL_TUNE_RESP
              Added Subblock EM_ADC_CAL_TUNE_REQ_DATA
              Added Subblock EM_ADC_CAL_TUNE_RESP_DATA
              Message EM_ADC_CAL_TUNE_REQ and EM_ADC_CAL_TUNE_RESP added.
              Subblock EM_ADC_CAL_TUNE_REQ_DATA and EM_ADC_CAL_TUNE_RESP_DATA
              added.

Version     : 007.008    APPROVED    5-Sep-2002     Carsten Hauge
Reason      : UEME & UEMC support.
Reference   : ISA RM id: 6342 & 4604, Continuus task id: co_core#12106,
              co_core#12178
Description : Added Entry EM_ADC_ALCO to EM_ADC_CHANNEL_INFO
              Added Entry EM_ADC_AUXDET to EM_ADC_CHANNEL_INFO
              Added Entry EM_ADC_HEADINT2 to EM_ADC_CHANNEL_INFO
              Added Entry EM_ADC_VBACK to EM_ADC_CHANNEL_INFO
              Added Entry EM_CONTROL_BUB_DISCHARGING to EM_CONTROL_BACKUP_BATTERY_INFO
              Changed EM_ADC_UEME_HEADINT2 to EM_ADC_HEADINT2,
              EM_ADC_UEME_ALCO to EM_ADC_ALCO, EM_ADC_UEME_AUXDET to
              EM_ADC_AUXDET and EM_ADC_UEME_VBACK to EM_ADC_VBACK. Ftd for
              EM_SB_FTD_BUB_CHARGING description changed.
              EM_ADC_CAL_WRITE_REQ description changed.
              EM_CONTROL_BACKUP_BATTERY_INFO description changed.

Version     : 007.007    APPROVED    11-Jul-2002    Carsten Hauge
Reason      : Flashlight support and use of new message macro's.
Reference   : ActionDB for SWAM: CH02071137963, ISA RM id: 5520, Continuus
              task id: co_core#9438.
Description : Added Case EM_PSM_INT_FLASHLIGHT to EM_PSM_INTERNAL_WRITE_REQ
              Added Entry EM_PSM_FLASHLIGHT_ACTIVE to EM_PSM_ACTIVITY_INFO
              Added Entry EM_PSM_INT_FLASHLIGHT to EM_PSM_INTERNAL_DEVICE_INFO
              Added description for: EM_PSM_INT_FLASHLIGHT &
              EM_PSM_FLASHLIGHT_ACTIVE. This new version of the message macro
              file supports automatic generation of em_isi.h.

Version     : 007.006    APPROVED    30-Apr-2002    Carsten Hauge
Reason      : New FTD's and Midi support.
Reference   : ActionDB for SWAM: CH02043046082 ActionDB for TEC:
              PP02040364886 (Midi) ActionDB for TEC: ? (FTD. See link in
              ActionDB for SWAM) Continuus task id: co_core#8073.
Description : Added Case EM_PSM_INT_MIDI to EM_PSM_INTERNAL_WRITE_REQ
              Added Entry EM_PSM_MIDI_ACTIVE to EM_PSM_ACTIVITY_INFO
              Added Entry EM_PSM_INT_MIDI to EM_PSM_INTERNAL_DEVICE_INFO
              Added FTD data EM_SB_FTD_STRING1 to FTD table
              Added FTD data EM_SB_FTD_STRING2 to FTD table
              Added FTD data EM_SB_FTD_STRING3 to FTD table
              Added FTD data EM_SB_FTD_STRING4 to FTD table
              Added FTD data EM_SB_FTD_STRING5 to FTD table
              Added FTD data EM_SB_FTD_STRING6 to FTD table
              Added FTD data EM_SB_FTD_STRING7 to FTD table
              Added FTD data EM_SB_FTD_STRING8 to FTD table
              Added description for: EM_PSM_INT_MIDI & EM_PSM_MIDI_ACTIVE.
              Added description for: EM_SB_FTD_STRING1, EM_SB_FTD_STRING2,
              EM_SB_FTD_STRING3, EM_SB_FTD_STRING4, EM_SB_FTD_STRING5,
              EM_SB_FTD_STRING6, EM_SB_FTD_STRING7, EM_SB_FTD_STRING8.

Version     : 007.005    APPROVED    25-Mar-2002    Carsten Hauge
Reason      : Lynx battery support.
Reference   : ActionDB for SWAM: CH02032245662 ActionDB for TEC:
              PP02012047922 Continuus task id: co_core#7285.
Description : Added Message EM_ADC_UNIT_LOCK_REQ
              Added Message EM_ADC_UNIT_LOCK_RESP
              Added Constant table EM_ADC_LOCK_INFO
              Discontinued Entry BATTERY_GENERATION_DCT4_DBI in EM_BATTERY_GEN_INFO
              Added Entry BATTERY_GENERATION_LYNX_BSI to EM_BATTERY_GEN_INFO
              BATTERY_GENERATION_LYNX_BSI added. Message
              EM_ADC_UNIT_LOCK_REQ, EM_ADC_UNIT_LOCK_RESP added.
              EM_ADC_LOCK_RESET_ALL, EM_ADC_LOCK_RESET and EM_ADC_LOCK_SET
              added.

Version     : 007.004    APPROVED    6-Mar-2002     Carsten Hauge
Reason      : Battery Audio Bars interface.
Reference   : ActionDB for SWAM: CH02030642364 ActionDB for TEC:
              PP02022043835 Continuus task id: co_core#6921.
Description : Added Subblock EM_MONITORING_BATTAUDIOBARS_DATA to EM_MONITORING_INFO_RESP
              Added Subblock EM_MONITORING_BATTAUDIOBARS_DATA
              Added Entry EM_MONITORING_BATT_AUDIO_BARS to EM_MONITORING_INFO
              Added Constant EM_INFO_NO_SUPPORT
              EM_MONITORING_BATTAUDIOBARS_DATA and
              EM_MONITORING_BATT_AUDIO_BARS added. EM_MONITORING_VOLTAGE_IND
              description changed.

Version     : 007.003    APPROVED    19-Feb-2002    Carsten Hauge
Reason      : Redesign of EM_INFO_IND and EM_INDICATION_INFO comment added
              for EM_BATTERY_STATE_CHANGE.
Reference   : ActionDB for SWAM: CH02012443643 ActionDB for TEC:
              SH02012436608 Continuus task id: co_core#6062.
Description : Changed Message EM_INFO_IND
              Changed Message EM_MONITORING_VOLTAGE_IND
              -

Version     : 007.002    APPROVED    18-Jan-2002    Carsten Hauge
Reason      : ADSP current consumption support added.
Reference   : ActionDB for SWAM: CH02011637397 ActionDB for TEC:
              PP02010428130 Continuus task id: co_core#5404.
Description : Added Case EM_PSM_INT_ADSP to EM_PSM_INTERNAL_WRITE_REQ
              Added Entry EM_PSM_ADSP_ACTIVE to EM_PSM_ACTIVITY_INFO
              Added Entry EM_PSM_INT_ADSP to EM_PSM_INTERNAL_DEVICE_INFO
              -

Version     : 007.001    APPROVED    20-Dec-2001    Carsten Hauge
Reason      : ADC calibration for Cover Type Indicator (CTI).
Reference   : ActionDB for TP Software: PP01111437534. ActionDB for SWAM:
              CH01120338054. Continuus task id: co_core#4386, co_core#4910.
Description : Added Message EM_ADC_CAL_READ_REQ
              Added Message EM_ADC_CAL_READ_RESP
              Added Message EM_ADC_CAL_WRITE_REQ
              Added Message EM_ADC_CAL_WRITE_RESP
              Added Subblock EM_ADC_CAL_GEN_DATA
              Added Subblock EM_ADC_CAL_LOG_DATA
              Added Constant table EM_ADC_ACTION_INFO
              Added Constant table EM_ADC_CHANNEL_INFO
              Added Constant table EM_ADC_TRANSFER_FUNCTION_INFO
              4 new messages added: EM_ADC_CAL_WRITE_REQ,
              EM_ADC_CAL_WRITE_RESP, EM_ADC_CAL_READ_REQ,
              EM_ADC_CAL_WRITE_RESP. 2 new subblocks added:
              tEM_Sb2Byte2DwordData, tEM_Sb2Byte4WordData. Several new
              symbols added.

Version     : 007.000    APPROVED    22-Nov-2001    Carsten Hauge
Reason      : Production line need a way to tell if the sample hold circuit
              is defective. Backward combability to version 006.002 is
              removed, since it is no longer used. Tomahawk connector needs a
              way to tell that the DC Out uses current.
Reference   : ActionDB for TP Software: PH01101258963. ActionDB for SWAM:
              CH01112146479. Continuus task id: co_core#3922.
Description : The sample hold circuit check solution has added the following:
              EM_BATTERY_VOLTAGE_SH_CHK_DATA, EM_BATTERY_VOLTAGE_SH_CHK. For
              the tomahawk connector the following has been added:
              EM_PSM_INT_DC_OUT, EM_PSM_DC_OUT_ACTIVE.

------------------------------------------------------------------------------

Description

------------------------------------------------------------------------------
Questions concerning EM  SW:

Use the EM support email address "Support.ISA-EM-SW@nokia.com"
------------------------------------------------------------------------------

This document allso serves as a description of the features which the Energy
Management Server supports.

The protocol description for Energy Management Server can be found in
reference /7/.

*/

#ifndef _EM_ISI_H
#define _EM_ISI_H

#include <stdint.h>

#ifndef EM_ISI_VERSION
#define EM_ISI_VERSION
#define EM_ISI_VERSION_Z   8
#define EM_ISI_VERSION_Y  28
#endif

#define EM_ISI_MIN_VERSION(z,y) \
 ((EM_ISI_VERSION_Z == (z) && EM_ISI_VERSION_Y >= (y)) || \
  (EM_ISI_VERSION_Z > (z)))

#if !EM_ISI_MIN_VERSION(7,0)
#error The specified interface version is not supported by this header file
#elif EM_ISI_MIN_VERSION(8,29)
#error The specified interface version is not supported by this header file
#endif


/* ----------------------------------------------------------------------- */
/* Constants                                                               */
/* ----------------------------------------------------------------------- */

#define EM_INFO_NOT_KNOWN_YET                    0x00
#define EM_INFO_NOT_SUPPORTED                    0xFFFF
#define EM_INFO_NO_SUPPORT                       0xFF
/* constant for variable-length definitions */
#define EM_ANY_SIZE                              1
#define EM_PSM_INT_DEVICE_ON                     0x64
#define EM_PSM_INT_DEVICE_OFF                    0x00

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_CHIPSET_CAL_TYPE - Valid from version 008.024        */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_CHIPSET_CAL_TYPE_CONST;

/* Status
   Applied Voltage
*/
#define EM_ADC_CAL_APPLIED_VOLTAGE               0x01
/* Applied Current */
#define EM_ADC_CAL_APPLIED_CURRENT               0x02
#define EM_ADC_CAL_SENSOR                        0x03  /* Sensor */

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_CHIPSET_CAL_STORE - Valid from version 008.024       */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_CHIPSET_CAL_STORE_CONST;

/* Status
   Store
*/
#define EM_ADC_CAL_STORE                         0x01
#define EM_ADC_CAL_RESTORE                       0x02  /* Restore */
#define EM_ADC_CAL_CLEAR                         0x03  /* Clear */

/* ----------------------------------------------------------------------- */
/* Bitmask Table: EM_CHIPSET_OPT_CAL - Valid from version 008.024          */
/* ----------------------------------------------------------------------- */
typedef uint16_t EM_CHIPSET_OPT_CAL_CONST;

/* Store calibration in PMM */
#define EM_CAL_STORE_PMM                         0x0001  /* ---------------1 */
/* Return calibration values */
#define EM_CAL_RETURN_DATA                       0x0002  /* --------------1- */

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_STATUS - Valid from version 007.000                  */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_STATUS_CONST;

/* #define EM_INFO_NOT_KNOWN_YET                 0x00 (already defined) */
#define EM_INFO_OK                               0x01  /* OK */
#define EM_INFO_FAIL                             0x02  /* Fail */

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_CHARGER_STATUS_INFO - Valid from version 007.000     */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_CHARGER_STATUS_INFO_CONST;

/* Charger is disconnected */
#define EM_CHARGER_DISCONNECTED                  0x00
/* Charger is connected */
#define EM_CHARGER_CONNECTED                     0x01
/* Charger is rejected */
#define EM_CHARGER_CONNECTION_ERROR              0x02

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_CHARGER_TYPE_INFO - Valid from version 007.000       */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_CHARGER_TYPE_INFO_CONST;

/* #define EM_INFO_NOT_KNOWN_YET                 0x00 (already defined) */
/* Unsupported charger is connected */
#define EM_CHARGER_TYPE_ERROR                    0x01
/* ACP7 type of charger is connected */
#define EM_CHARGER_ACP7                          0x02
/* 2-wire charger is connected */
#define EM_CHARGER_TWO_WIRES                     0x03
/* 3-wire charger is connected */
#define EM_CHARGER_THREE_WIRES                   0x04
/* There is a charger voltage error */
#define EM_CHARGER_VOLTAGE_ERROR                 0x05
/* There is a charger current error */
#define EM_CHARGER_CURRENT_ERROR                 0x06
/* Special type charger is connected */
#define EM_CHARGER_SPECIAL                       0x07
/* USB host/hub with low charging current is connected */
#define EM_CHARGER_USB_HOST_HUB_LOW              0x08
/* USB host/hub with high charging current is connected */
#define EM_CHARGER_USB_HOST_HUB_HIGH             0x09
/* USB dedicated is connected */
#define EM_CHARGER_USB_DEDICATED_CHARGER         0x0A
/* USB host/hub charger at high speed connection */
#define EM_CHARGER_USB_HOST_HUB_CHARGER_HIGH     0x0B
/* USB host/hub charger at full speed connection */
#define EM_CHARGER_USB_HOST_HUB_CHARGER_FULL     0x0C

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_BATTERY_TYPE_INFO - Valid from version 007.000       */
/* ----------------------------------------------------------------------- */
typedef uint16_t EM_BATTERY_TYPE_INFO_CONST;

/* #define EM_INFO_NOT_KNOWN_YET                 0x00 (already defined) */
/* Battery is service or test battery */
#define EM_BATTERY_TYPE_SERVICE                  0x0001
/* Battery type is Nickel */
#define EM_BATTERY_TYPE_NICKEL                   0x0002
/* Battery type is 4.1V Lithium */
#define EM_BATTERY_TYPE_4V1_LITHIUM              0x0003
/* Battery type is 4.2V Lithium */
#define EM_BATTERY_TYPE_4V2_LITHIUM              0x0004
/* Error in battery type reading */
#define EM_BATTERY_TYPE_ERROR                    0xFFFF

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_BATTERY_GEN_INFO - Valid from version 007.000        */
/* ----------------------------------------------------------------------- */
typedef uint16_t EM_BATTERY_GEN_INFO_CONST;

/* Battery detection is based on the DCT3 BSI generation */
#define BATTERY_GENERATION_DCT3_BSI              0x0001
/* Battery detection is based on the DCT4 BSI generation */
#define BATTERY_GENERATION_DCT4_BSI              0x0002

#if EM_ISI_MIN_VERSION(7,0) && !EM_ISI_MIN_VERSION(7,5)
/* Battery detection is based on the DCT4 Digital Battery Interface
   generation
*/
#define BATTERY_GENERATION_DCT4_DBI              0x0003
#endif /* EM_ISI_MIN_VERSION(7,0) && !EM_ISI_MIN_VERSION(7,5) */

/* Battery detection is based on the Lynx BSI generation */
#define BATTERY_GENERATION_LYNX_BSI              0x0003
/* Battery detection is based on the Tabby BSI generation */
#define BATTERY_GENERATION_TABBY_BSI             0x0004

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_CHARGING_STATE_INFO - Valid from version 007.000     */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_CHARGING_STATE_INFO_CONST;

/* #define EM_INFO_NOT_KNOWN_YET                 0x00 (already defined) */
/* Charging is off */
#define EM_CHARGING_STATE_OFF                    0x01
#define EM_CHARGING_STATE_ON                     0x02  /* Charging is on */
/* Battery is almost fully charged */
#define EM_CHARGING_STATE_ALMOST_FULL            0x03
/* Battery is full and maintenance charging is active */
#define EM_CHARGING_STATE_FULL                   0x04
#define EM_CHARGING_STATE_ERROR                  0x05  /* Charging error */
/* Charging is continued */
#define EM_CHARGING_STATE_CONTINUE               0x06

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_CHARGING_MODE_INFO - Valid from version 007.000      */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_CHARGING_MODE_INFO_CONST;

/* #define EM_INFO_NOT_KNOWN_YET                 0x00 (already defined) */
/* No charger is connected */
#define EM_CHARGING_NOT_CHARGING                 0x01
/* Charger recognition is in progress */
#define EM_CHARGING_INITIALISATION               0x02
/* Battery temperature is outside the accepted limits for charging */
#define EM_CHARGING_TEMP_CHECKING                0x03
/* Charging is not possible because of a wrong battery type */
#define EM_CHARGING_BATTERY_ERROR                0x04
/* Charging is not possible because of a wrong type of charger or if an error
   is detected in the HW
*/
#define EM_CHARGING_CHARGE_DISABLED              0x05
/* Battery is in discharge mode */
#define EM_CHARGING_DISCHARGING                  0x06
/* Charger is disconnected. (After a few seconds the charging mode is changed
   to not charging)
*/
#define EM_CHARGING_CHARGER_DISCONNECTED         0x07
/* Power consuming charge algorithm is used */
#define EM_CHARGING_POWER_CONSUMING              0x08
/* Cold charge algorithm is used */
#define EM_CHARGING_COLD_CHARGE                  0x09
/* Hot charge algorithm is used */
#define EM_CHARGING_HOT_CHARGE                   0x0A
/* Maintenance charge algorithm is used */
#define EM_CHARGING_MAINTENANCE_CHARGE           0x0B
/* Lithium charge algorithm is used */
#define EM_CHARGING_LITHIUM_CHARGE               0x0C
/* Nickel charge algorithm is used */
#define EM_CHARGING_NICKEL_CHARGE                0x0D
/* Charging is paused by a client */
#define EM_CHARGING_ACTION_PAUSE                 0x0E
/* Charging is disabled by a client or the phone is in local or test mode */
#define EM_CHARGING_ACTION_DISABLE               0x0F
/* Special charger algorithm is used */
#define EM_CHARGING_SPECIAL_CHARGE               0x10
/* Over Voltage recovery is used */
#define EM_CHARGING_OVV_RECOVERY                 0x11
/* Special Waiting is used */
#define EM_CHARGING_SPECIAL_WAIT                 0x12

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_MON_BATT_POWER_INFO - Valid from version 007.000     */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_MON_BATT_POWER_INFO_CONST;

/* Battery power level is normal (ok) */
#define EM_MONITORING_BATT_OK                    0x01
/* Battery power level is low */
#define EM_MONITORING_BATT_LOW                   0x02
/* Battery power level is totally empty */
#define EM_MONITORING_BATT_EMPTY                 0x03
/* Battery power level is too low for booting up */
#define EM_MONITORING_BATT_LOW_FOR_BOOT          0x04

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_PSM_CS_ACTIVE_STATE_INFO - Valid from version 007.000 */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_PSM_CS_ACTIVE_STATE_INFO_CONST;

/* #define EM_INFO_NOT_KNOWN_YET                 0x00 (already defined) */
#define EM_PSM_CS_STATE_IDLE                     0x01  /* Idle state */
/* No service power save state (out of range) */
#define EM_PSM_CS_STATE_NSPS                     0x02
/* Scanning state (including cell info active) */
#define EM_PSM_CS_STATE_SCANNING                 0x03
/* Signaling state */
#define EM_PSM_CS_STATE_SIGNALING                0x04
#define EM_PSM_CS_STATE_CALL                     0x05  /* Call state */
/* Circuit switch Data State */
#define EM_PSM_CS_STATE_CSD                      0x06
/* High-speed circuit switch Data State */
#define EM_PSM_CS_STATE_HSCSD                    0x07
/* General packet radio Service State */
#define EM_PSM_CS_STATE_GPRS                     0x08
/* Enhanced Data rates for GSM Evolution */
#define EM_PSM_CS_STATE_EDGE                     0x09
/* Data call state other than CSD, HSCSD, GPRS and EDGE */
#define EM_PSM_CS_STATE_DATA                     0x0A

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_PSM_CS_ACTIVE_PROTOCOL_INFO - Valid from version 007.000 */
/* ----------------------------------------------------------------------- */
/* Note: EM_PSM_CS_PROTOCOL_RF_INACTIVE is not valid for
   EM_PSM_CS_PROTOCOL_WRITE_REQ, EM_PSM_PROTOCOL_RF_INACTIVE is only valid
   for EM_PSM_READ_RESP
*/
typedef uint8_t EM_PSM_CS_ACTIVE_PROTOCOL_INFO_CONST;

/* #define EM_INFO_NOT_KNOWN_YET                 0x00 (already defined) */
#define EM_PSM_CS_PROTOCOL_GSM                   0x01  /* GSM band */
#define EM_PSM_CS_PROTOCOL_TDMA                  0x02  /* TDMA band */
#define EM_PSM_CS_PROTOCOL_CDMA                  0x03  /* CDMA band */
#define EM_PSM_CS_PROTOCOL_AMPS                  0x04  /* AMPS band */
#define EM_PSM_CS_PROTOCOL_PDC                   0x05  /* PDC band */
#define EM_PSM_CS_PROTOCOL_WCDMA                 0x06  /* WCDMA band */
#define EM_PSM_CS_PROTOCOL_NMT                   0x07  /* NMT band */
#define EM_PSM_CS_PROTOCOL_TETRA                 0x08  /* TETRA band */
#define EM_PSM_CS_PROTOCOL_UMA                   0x09  /* UMA band */
#define EM_PSM_CS_PROTOCOL_RF_INACTIVE           0xFF  /* RF is inactive */

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_PSM_INTERNAL_DEVICE_INFO - Valid from version 007.000 */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_PSM_INTERNAL_DEVICE_INFO_CONST;

/* Display light intensity */
#define EM_PSM_INT_DISPLAY_LIGHT                 0x00
/* Keyboard light intensity */
#define EM_PSM_INT_KEYBOARD_LIGHT                0x01
/* Vibrator activity level */
#define EM_PSM_INT_VIBRA                         0x02
/* Buzzer activity level */
#define EM_PSM_INT_BUZZER                        0x03
/* IrDA activity level */
#define EM_PSM_INT_IRDA                          0x04
/* DC Out activity level */
#define EM_PSM_INT_DC_OUT                        0x05
/* FM radio activity level */
#define EM_PSM_INT_RADIO                         0x06
/* Video camera activity level */
#define EM_PSM_INT_VIDEO                         0x07
/* Global Position System activity level */
#define EM_PSM_INT_GPS                           0x08
/* MP3 player activity level */
#define EM_PSM_INT_MP3                           0x09
/* Integrated Hands Free activity level */
#define EM_PSM_INT_IHF                           0x0A
/* Voice Recording and Recognition activity level */
#define EM_PSM_INT_VRR                           0x0B
/* Application DSP activity level */
#define EM_PSM_INT_ADSP                          0x0C
/* MIDI activity level */
#define EM_PSM_INT_MIDI                          0x0D
/* Flashlight activity level */
#define EM_PSM_INT_FLASHLIGHT                    0x0E
/* USB activity level */
#define EM_PSM_INT_USB                           0x0F
/* Touchpad activity level */
#define EM_PSM_INT_TOUCHPAD                      0x10

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_PSM_EXTERNAL_DEVICE_INFO - Valid from version 007.000 */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_PSM_EXTERNAL_DEVICE_INFO_CONST;

/* DLR-3 data cable */
#define EM_PSM_EXT_DATA_CABLE                    0x00
#define EM_PSM_EXT_CAMERA                        0x01  /* Camera */
#define EM_PSM_EXT_COVER_POWER                   0x02  /* Cover */
#define EM_PSM_EXT_BLUETOOTH                     0x03  /* Bluetooth */
#define EM_PSM_EXT_SENSORS                       0x04  /* Sensors */
#define EM_PSM_EXT_LIGHTS                        0x05  /* Lights */

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_PSM_SW_FEATURE_STATUS - Valid from version 007.000   */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_PSM_SW_FEATURE_STATUS_CONST;

/* An application stops a power consuming feature */
#define EM_PSM_SW_FEATURE_INACTIVE               0x00
/* An application start a power consuming feature (increase the MCU load) */
#define EM_PSM_SW_FEATURE_ACTIVE                 0x01

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_CONTROL_DISABLE_CHARGING_INFO - Valid from version 007.000 */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_CONTROL_DISABLE_CHARGING_INFO_CONST;

/* Charging is enabled and controlled by the EM software */
#define EM_CONTROL_CHARGING_ENABLE               0x00
/* Charging is disabled during production test and calibration */
#define EM_CONTROL_CHARGING_DISABLE              0x01

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_CONTROL_PAUSE_CHARGING_INFO - Valid from version 007.000 */
/* ----------------------------------------------------------------------- */
/* Note: Pause charging is only possible when charging is enabled. */
typedef uint8_t EM_CONTROL_PAUSE_CHARGING_INFO_CONST;

/* Charging is resumed after accessory detection */
#define EM_CONTROL_CHARGING_RESUME               0x00
/* Charging is paused during accessory detection */
#define EM_CONTROL_CHARGING_PAUSE                0x01

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_CONTROL_HW_VOLT_LIMIT_INFO - Valid from version 007.000 */
/* ----------------------------------------------------------------------- */
/* Note: HW voltage limitation is only possible when charging is disabled */
typedef uint8_t EM_CONTROL_HW_VOLT_LIMIT_INFO_CONST;

/* VLIM_MINIMUM (VLIM1, ~3.6V) is activated */
#define EM_CONTROL_VLIM_MINIMUM                  0x00
/* VLIM_LITHIUM (VLIM2L, ~5.1V in DCT4, ~5.4V in BB5) is activated */
#define EM_CONTROL_VLIM_LITHIUM                  0x01
/* VLIM_NICKEL (VLIM2H, ~5.3V in DCT4, not in BB5) is activated */
#define EM_CONTROL_VLIM_NICKEL                   0x02

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_CONTROL_TX_VOLT_LIMIT_INFO - Valid from version 007.000 */
/* ----------------------------------------------------------------------- */
/* Note: TX voltage limitation, used by CS SW to protect the PA against to
   high battery voltage, is only active when Charging is enabled.
*/
typedef uint8_t EM_CONTROL_TX_VOLT_LIMIT_INFO_CONST;

/* Battery voltage limitation is activated. Used by CS software when PA is
   active.
*/
#define EM_CONTROL_TX_VLIM_ON                    0x00
/* Battery voltage limitation is deactivated. Used ny CS software when PA is
   inactive.
*/
#define EM_CONTROL_TX_VLIM_OFF                   0x01

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_CONTROL_BACKUP_BATTERY_INFO - Valid from version 007.000 */
/* ----------------------------------------------------------------------- */
/* Note: To check if the backup battery in UEME, UEMC or RETU is mounted
   incorrectly the following sequence has to be done:
   EM_ADC_READ_REQ->EM_CONTROL_BUB_DISCHARGING->EM_ADC_READ_REQ and compare
   the readings. If the voltage on the backup battery is lower, almost empty,
   then it can be assumed that the battery is not mounted correctly or not at
   all.
   Remember to set EM_CONTROL_BUB_CHARGING_SW_CTRL after using
   EM_CONTROL_BUB_CHARGING_ENABLE, EM_CONTROL_BUB_CHARGING_DISABLE and
   EM_CONTROL_BUB_DISCHARGING.
*/
typedef uint8_t EM_CONTROL_BACKUP_BATTERY_INFO_CONST;

/* Backup battery charging is controlled by the EM software */
#define EM_CONTROL_BUB_CHARGING_SW_CTRL          0x00
/* Backup battery charging is deactivated */
#define EM_CONTROL_BUB_CHARGING_DISABLE          0x01
/* Backup battery charging is activated */
#define EM_CONTROL_BUB_CHARGING_ENABLE           0x02
/* Backup battery discharging is activated with a pull down resistor active.
   (Only possible in UEME and UEMC)
*/
#define EM_CONTROL_BUB_DISCHARGING               0x03
/* No support for backup battery */
#define EM_CONTROL_BUB_NO_SUPPORT                0xFF

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_ADC_CHANNEL_INFO - Valid from version 007.001        */
/* ----------------------------------------------------------------------- */
/* Note: When using UEME the following channels returns the same. EM_ADC_ALCO
   = EM_ADC_LS, EM_ADC_AUXDET = EM_ADC_KEYB1, EM_ADC_VBACK = EM_ADC_KEYB2.
   Note: Please Check MS-ASIC specification regarding channel support
*/
typedef uint8_t EM_ADC_CHANNEL_INFO_CONST;

/* BATtery Voltage, DIVided */
#define EM_ADC_VBAT_DIV                          0x00
/* BATtery Voltage, SCALed */
#define EM_ADC_VBAT_SCAL                         0x01
/* CHARger Voltage */
#define EM_ADC_VCHAR                             0x02
/* CHARger current */
#define EM_ADC_ICHAR                             0x03
/* Battery Size Identification */
#define EM_ADC_BSI                               0x04
/* Battery TEMPerature */
#define EM_ADC_BTEMP                             0x05
/* HEADset INTerconnection (accessory detection) */
#define EM_ADC_HEADINT                           0x06
/* HOOK INTerconnection (accessory detection) */
#define EM_ADC_HOOKINT                           0x07
#define EM_ADC_LS                                0x08  /* Light Sensor */
/* Power Amplifier TEMPerature */
#define EM_ADC_PATEMP                            0x09
/* Voltage Controlled Oscillator TEMPerature */
#define EM_ADC_VCXOTEMP                          0x0A
/* resistive KEYBoard 1 */
#define EM_ADC_KEYB1                             0x0B
/* resistive KEYBoard 2 */
#define EM_ADC_KEYB2                             0x0C
/* initial battery voltage */
#define EM_ADC_VBAT_INIT                         0x0D
/* battery current (positive: current from battery to phone, negative:
   current running to the battery)
*/
#define EM_ADC_IBAT_AVG                          0x0E
/* only one averaging period */
#define EM_ADC_IBAT_FAST                         0x0F
/* HEADset INTerconnection 2 */
#define EM_ADC_HEADINT2                          0x10
/* Ambient Light COnverter */
#define EM_ADC_ALCO                              0x11
/* AUXillary DETection */
#define EM_ADC_AUXDET                            0x12
/* Backup battery voltage */
#define EM_ADC_VBACK                             0x13
/* Light Sensor TEMPerature */
#define EM_ADC_LS_TEMP                           0x14
#define EM_ADC_RF_MEAS                           0x15  /* RF MEASurement */
/* Wideband Transmit DETection */
#define EM_ADC_WB_TX_DET                         0x16
/* RETU TEMPerature) */
#define EM_ADC_RETU_TEMP                         0x17
/* BATtery Voltage, SAMPLED */
#define EM_ADC_VBAT_SAMPLED                      0x18
/* VBUS signal (USB) */
#define EM_ADC_VBUS                              0x19
#define EM_ADC_IDDET                             0x1A  /* IDDET signal */

#if EM_ISI_MIN_VERSION(8,10) && !EM_ISI_MIN_VERSION(8,12)
/* TESTNET1 signal */
#define EM_ADC_TESTNET1                          0x1B
#endif /* EM_ISI_MIN_VERSION(8,10) && !EM_ISI_MIN_VERSION(8,12) */

/* TESTNET1 signal. Note: Routed to EM_ADC_BTEMP ADC channel in case of
   LitePlus MS-ASIC
*/
#define EM_ADC_TESTNET1                          0x1B

#if EM_ISI_MIN_VERSION(8,10) && !EM_ISI_MIN_VERSION(8,12)
/* TESTNET2 signal */
#define EM_ADC_TESTNET2                          0x1C
#endif /* EM_ISI_MIN_VERSION(8,10) && !EM_ISI_MIN_VERSION(8,12) */

/* TESTNET2 signal. Note: Routed to ADC_VCXOTEMP ADC channel in case of
   LitePlus MS-ASIC
*/
#define EM_ADC_TESTNET2                          0x1C

#if EM_ISI_MIN_VERSION(8,10) && !EM_ISI_MIN_VERSION(8,12)
/* TESTNET3 signal */
#define EM_ADC_TESTNET3                          0x1D
#endif /* EM_ISI_MIN_VERSION(8,10) && !EM_ISI_MIN_VERSION(8,12) */

/* TESTNET2 signal. Note: Routed to EM_ADC_PATEMP ADC channel in case of
   LitePlus MS-ASIC
*/
#define EM_ADC_TESTNET3                          0x1D
/* Used for calibration of scaling circuit/buffer 1 */
#define EM_ADC_SCALE1_CAL                        0x1E
/* Used for calibration of scaling circuit/buffer 2 */
#define EM_ADC_SCALE2_CAL                        0x1F
/* Used for calibration of scaling circuit/buffer 3 */
#define EM_ADC_SCALE3_CAL                        0x20
/* Used for calibration of scaling circuit/buffer 4 */
#define EM_ADC_SCALE4_CAL                        0x21
/* Used for calibration of scaling circuit/buffer 5 */
#define EM_ADC_SCALE5_CAL                        0x22
/* Measuring internal VCharIn via TestNet1 */
#define EM_ADC_TESTNET1_VCHAR_ADC                0xDD
/* Measuring internal BSI via TestNet2 */
#define EM_ADC_TESTNET2_BSI                      0xDE
/* Measuring internal VBat via TestNet3 */
#define EM_ADC_TESTNET3_VBAT_VANA                0xDF
/* Return main ADC calibration data */
#define EM_ADC_MAIN_CAL                          0xFE
/* Return all available ADC calibration data */
#define EM_ADC_ALL_CAL                           0xFF

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_ADC_TRANSFER_FUNCTION_INFO - Valid from version 007.001 */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_ADC_TRANSFER_FUNCTION_INFO_CONST;

/* No Transfer function data */
#define EM_ADC_NON_FLAG                          0x00
#define EM_ADC_LIN_FLAG                          0x01  /* Linear data */
/* Hyperbolic data */
#define EM_ADC_HYP_FLAG                          0x02
/* Logarithmic data */
#define EM_ADC_LOG_FLAG                          0x03
/* Parallel NTC transfer function data */
#define EM_ADC_PARALLEL_NTC_FLAG                 0x04

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_ADC_ACTION_INFO - Valid from version 007.001         */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_ADC_ACTION_INFO_CONST;

/* Calibration data */
#define EM_ADC_CAL_FLAG                          0x00
/* Default calibration data */
#define EM_ADC_DEFAULT_FLAG                      0x01
/* ADC algorithm flag */
#define EM_ADC_ALG_FLAG                          0x02
/* Calibration measurements stored in ASIC (read-only) */
#define EM_ADC_STORED_MEAS_FLAG                  0x03

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_ADC_LOCK_INFO - Valid from version 007.005           */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_ADC_LOCK_INFO_CONST;

/* Reset all locked channels */
#define EM_ADC_LOCK_RESET_ALL                    0x00
/* Reset one locked channel */
#define EM_ADC_LOCK_RESET                        0x01
/* Set one channel to a locked value */
#define EM_ADC_LOCK_SET                          0x02

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_TEMPERATURE_INFO - Valid from version 007.010        */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_TEMPERATURE_INFO_CONST;

#define EM_TEMPERATURE_OK                        0x00  /* Temperature OK */
/* Temperature fail */
#define EM_TEMPERATURE_FAIL                      0x01

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_POWER_CONSUMER_INFO - Valid from version 007.015     */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_POWER_CONSUMER_INFO_CONST;

/* Power sources for the camera */
#define EM_POWER_CAMERA                          0x00
/* Power sources for the MMC */
#define EM_POWER_MMC                             0x01
/* Power sources for the Bluetooth device */
#define EM_POWER_BT                              0x02
/* Power sources for the display */
#define EM_POWER_DISPLAY                         0x03

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_POWER_STATE_INFO - Valid from version 007.015        */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_POWER_STATE_INFO_CONST;

/* Power OFF to the power consumer */
#define EM_POWER_OFF                             0x00
/* Power ON to the power consumer */
#define EM_POWER_ON                              0x01

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_SOS_EVENT_INFO - Valid from version 007.015          */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_SOS_EVENT_INFO_CONST;

/* A Timer event has occured */
#define EM_SOS_TIMER_EVENT                       0x00

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_ADC_ALG_ID_INFO - Valid from version 008.001         */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_ADC_ALG_ID_INFO_CONST;

/* No Transfer function data. */
#define EM_ADC_ALG_NONE                          0x00
/* General Linear algorithm with dependency to ADC calibration. */
#define EM_ADC_ALG_LIN_ADC_DEP                   0x01
/* General Hyperbolic algorithm with dependency to ADC calibration. */
#define EM_ADC_ALG_HYP_ADC_DEP                   0x02
/* General Logarithmic algorithm with dependency to ADC calibration. */
#define EM_ADC_ALG_LOG_ADC_DEP                   0x03
/* Special Parallel NTC specific algorithm (NTC in parallel with clamp
   resistor). Used for e.g. LS_TEMP in BB5.
*/
#define EM_ADC_ALG_PAR_NTC                       0x04
/* General Linear algotithm with no dependencies. Used for e.g. main ADC
   calibration.
*/
#define EM_ADC_ALG_LIN_BASIC                     0x05
/* General Linear algotithm with no dependencies. Support unit reading only
   (i.e. no raw reading). Used for e.g. IBAT in TAHVO.
*/
#define EM_ADC_ALG_LIN_BASIC_UNIT_ONLY           0x06
/* General Hyperbolic algorithm with variable reference voltage. In SubBlock
   EM_ADC_CAL_ALG_DATA parameter P1 = reference voltage [mV] (unsigned
   integer).
*/
#define EM_ADC_ALG_HYP_VAR_VREF                  0x07
/* Special ZOCUS-C specific linear algorithm for IBAT calibration. */
#define EM_ADC_ALG_LIN_IBAT_ZOCUSC               0x08

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_MEASUREMENT_ACTION - Valid from version 008.006      */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_MEASUREMENT_ACTION_CONST;

/* Start measuring. */
#define EM_MEASUREMENT_ACTION_START              0x00
/* Stop measuring. */
#define EM_MEASUREMENT_ACTION_STOP               0x01

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_MEASUREMENT_VALUE - Valid from version 008.006       */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_MEASUREMENT_VALUE_CONST;

/* Battery current (mA). */
#define EM_MEASUREMENT_TYPE_CURRENT              0x00
/* Battery voltage (mV). From 008.021 */
#define EM_MEASUREMENT_TYPE_VOLTAGE              0x01

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_MEASUREMENT_PERIOD - Valid from version 008.006      */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_MEASUREMENT_PERIOD_CONST;

/* Configurable sampling rate based on possible rates supported by hardware.
*/
#define EM_MEASUREMENT_PERIOD_CONF_HW_RATE       0x00
/* Once every 250m seconds. */
#define EM_MEASUREMENT_PERIOD_250MS              0x01
/* Once every seconds. */
#define EM_MEASUREMENT_PERIOD_1S                 0x02
/* Once every 5 seconds. */
#define EM_MEASUREMENT_PERIOD_5S                 0x03

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_MEASUREMENT_RESULT - Valid from version 008.006      */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_MEASUREMENT_RESULT_CONST;

#define EM_MEASUREMENT_RESULT_OK                 0x00  /* Result OK. */
#define EM_MEASUREMENT_RESULT_NOK                0x01  /* Result not OK. */
#define EM_MEASUREMENT_RESULT_NOT_SUPPORTED      0x02  /* Not supported. */

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_SELFTEST_ID - Valid from version 008.007             */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_SELFTEST_ID_CONST;

/* Executes selftest for USB charging */
#define EM_SELFTEST_USB_CHARGING                 0x01

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_SELFTEST_RESULT - Valid from version 008.007         */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_SELFTEST_RESULT_CONST;

#define EM_SELFTEST_RESULT_PASS                  0x00  /* Test passed. */
#define EM_SELFTEST_RESULT_FAIL                  0x01  /* Test failed. */
/* Test not supported. */
#define EM_SELFTEST_RESULT_NOT_SUPPORTED         0x02

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_CONTROL_BACKUP_BATTERY_CHARGING_ACTION - Valid from version 008.028 */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_CONTROL_BACKUP_BATTERY_CHARGING_ACTION_CONST;

#define EM_CONTROL_BACKUP_BATTERY_CHARGING_VOLTAGE_SET 0x00  /* Set voltage */
#define EM_CONTROL_BACKUP_BATTERY_CHARGING_CURRENT_SET 0x01  /* Set current */

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_CONTROL_USB_CHARGER_ACTION - Valid from version 008.008 */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_CONTROL_USB_CHARGER_ACTION_CONST;

/* Enable USB charging chip */
#define EM_CONTROL_USB_CHARGER_ACTION_ENABLE     0x00
/* Disable USB charging chip */
#define EM_CONTROL_USB_CHARGER_ACTION_DISABLE    0x01
/* Set charging current to 100mA */
#define EM_CONTROL_USB_CHARGER_ACTION_SET_CURRENT_100 0x02
/* Set charging current to 500mA */
#define EM_CONTROL_USB_CHARGER_ACTION_SET_CURRENT_500 0x03
/* Set charging current to a specific value, specify the value in the value
   field with unit milli ampere (mA)
*/
#define EM_CONTROL_USB_CHARGER_ACTION_SET_CURRENT 0x04
/* Releases control of the USB charging chip */
#define EM_CONTROL_USB_CHARGER_ACTION_CONTROL_RELEASE 0x05
/* Get/set charging float voltage. The value field holds the actual/desired
   floatvoltage with unit milli volt (mV)
*/
#define EM_CONTROL_USB_CHARGER_ACTION_FLOAT_VOLTAGE 0x06
/* Get/set maximum charging input current. The value field holds the
   actual/desired input current with unit milli ampere (mA). Value 100
   represents USB100 input current mode. Value 500 represents USB500 input
   current mode. All other values represents AC current input mode.
*/
#define EM_CONTROL_USB_CHARGER_ACTION_INPUT_CURRENT 0x07
/* Get/set maximum charging output current. The value field holds the
   actual/desired output current with unit milli ampere (mA).
*/
#define EM_CONTROL_USB_CHARGER_ACTION_OUTPUT_CURRENT 0x08
/* Get/Set Mixed signal ASIC USB Charging with 100mA.The value field holds
   the actual/desired state. A non-zero value represents that Mixed signal
   ASIC USB Charging with 100mA is enabled.
*/
#define EM_CONTROL_USB_CHARGER_ACTION_MSASIC_USB_CHARGING 0x09
/* Get the status of the USB5/1 or OTG input pinThe value field holds the
   actual state. A non-zero value represents a logical high.
*/
#define EM_CONTROL_USB_CHARGER_ACTION_GET_500_100_DETECT_PIN_STATUS 0x0A
/* Get the status of the Mixed signal ASIC VBUS detection input pinThe value
   field holds the actual state. A non-zero value represents a logical high.
*/
#define EM_CONTROL_USB_CHARGER_ACTION_GET_MSASIC_VBUSDET_STATUS 0x0B
/* Get the USB charger type. Response will be sent in an
   EM_CONTROL_USB_CHARGER_TYPE subblock.
*/
#define EM_CONTROL_USB_CHARGER_ACTION_GET_CHARGER_TYPE 0x0C
/* Set charging current to 900mA */
#define EM_CONTROL_USB_CHARGER_ACTION_SET_CURRENT_900 0x0D

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_ME_STATE_RESULT - Valid from version 008.009         */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_ME_STATE_RESULT_CONST;

#define EM_ME_STATE_RESULT_OK                    0x00  /* Request ok. */
/* Request failed. */
#define EM_ME_STATE_RESULT_NOK                   0x01

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_ME_STATE_ACTION - Valid from version 008.009         */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_ME_STATE_ACTION_CONST;

/* Disable EM measurement */
#define EM_ME_STATE_ACTION_OFF                   0x00
/* Enable EM measurement */
#define EM_ME_STATE_ACTION_ON                    0x01

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_CONTROL_USB_CHARGER_TYPE_INFO - Valid from version 008.023 */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_CONTROL_USB_CHARGER_TYPE_INFO_CONST;

/* No USB charger present */
#define EM_CONTROL_USB_CHARGER_NOT_PRESENT       0x00
/* Dedicated (wall) charger present */
#define EM_CONTROL_USB_CHARGER_DEDICATED_CHARGER 0x01
/* Host charger present */
#define EM_CONTROL_USB_CHARGER_HOST_CHARGER      0x02

/* ----------------------------------------------------------------------- */
/* Constant Table: EM_CONTROL_USB_CHARGER_HOST_CURRENT - Valid from version 008.023 */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_CONTROL_USB_CHARGER_HOST_CURRENT_CONST;

/* Charging current not avaliable. The charge current is only avaliable with
   host charger
*/
#define EM_CONTROL_USB_CHARGER_HOST_CURRENT_NA   0x00
/* 100 mA charging current */
#define EM_CONTROL_USB_CHARGER_HOST_CURRENT_100  0x01
/* 500 mA charging current */
#define EM_CONTROL_USB_CHARGER_HOST_CURRENT_500  0x02

/* ----------------------------------------------------------------------- */
/* Bitmask Table: EM_CHARGER_INFO - Valid from version 007.000             */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_CHARGER_INFO_CONST;

/* Charger status */
#define EM_CHARGER_STATUS                        0x01  /* -------1 */
/* Charger type */
#define EM_CHARGER_TYPE                          0x02  /* ------1- */
/* Charger voltage */
#define EM_CHARGER_VOLTAGE                       0x04  /* -----1-- */
/* Charger current */
#define EM_CHARGER_CURRENT                       0x08  /* ----1--- */

/* ----------------------------------------------------------------------- */
/* Bitmask Table: EM_CONTROL_INFO - Valid from version 007.000             */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_CONTROL_INFO_CONST;

/* Disabling charging */
#define EM_CONTROL_DISABLE_CHARGING              0x01  /* -------1 */
/* Pause charging during accessory detection */
#define EM_CONTROL_PAUSE_CHARGING                0x02  /* ------1- */
/* UEM voltage limit control */
#define EM_CONTROL_HW_VOLT_LIMIT                 0x04  /* -----1-- */
/* Battery voltage limitation during call */
#define EM_CONTROL_TX_VOLT_LIMIT                 0x08  /* ----1--- */
/* Backup battery charge control */
#define EM_CONTROL_BACKUP_BATTERY                0x10  /* ---1---- */
/* Charging PWM and charge switch control */
#define EM_CONTROL_PWM                           0x20  /* --1----- */
/* USB charger control */
#define EM_CONTROL_USB_CHARGER                   0x40  /* -1------ */

/* ----------------------------------------------------------------------- */
/* Bitmask Table: EM_BATTERY_INFO - Valid from version 007.000             */
/* ----------------------------------------------------------------------- */
typedef uint16_t EM_BATTERY_INFO_CONST;

/* Battery type */
#define EM_BATTERY_TYPE                          0x0001  /* ---------------1 */
/* Nominal battery capacity */
#define EM_BATTERY_NOMINAL_CAPA                  0x0002  /* --------------1- */
/* Battery temperature */
#define EM_BATTERY_TEMP                          0x0004  /* -------------1-- */
/* Battery voltage */
#define EM_BATTERY_VOLTAGE                       0x0008  /* ------------1--- */
/* TX on battery voltage */
#define EM_BATTERY_VOLTAGE_TX_ON                 0x0010  /* -----------1---- */
/* TX off battery voltage */
#define EM_BATTERY_VOLTAGE_TX_OFF                0x0020  /* ----------1----- */
/* PWM on battery voltage */
#define EM_BATTERY_VOLTAGE_PWM_ON                0x0040  /* ---------1------ */
/* PWM off battery voltage */
#define EM_BATTERY_VOLTAGE_PWM_OFF               0x0080  /* --------1------- */
/* Supported battery generation */
#define EM_BATTERY_GENERATION                    0x0100  /* -------1-------- */
/* Sample hold check voltage */
#define EM_BATTERY_VOLTAGE_SH_CHK                0x0200  /* ------1--------- */

/* ----------------------------------------------------------------------- */
/* Bitmask Table: EM_CHARGING_INFO - Valid from version 007.000            */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_CHARGING_INFO_CONST;

/* Charging state - low level charging information */
#define EM_CHARGING_STATE                        0x01  /* -------1 */
/* Charging mode - more detailed charging information */
#define EM_CHARGING_MODE                         0x02  /* ------1- */

/* ----------------------------------------------------------------------- */
/* Bitmask Table: EM_MONITORING_INFO - Valid from version 007.000          */
/* ----------------------------------------------------------------------- */
typedef uint8_t EM_MONITORING_INFO_CONST;

/* Battery power status */
#define EM_MONITORING_BATT_POWER                 0x01  /* -------1 */
/* Remaining battery bar level */
#define EM_MONITORING_BATT_BARS                  0x02  /* ------1- */
/* Remaining battery capacity */
#define EM_MONITORING_BATT_CAPA                  0x04  /* -----1-- */
/* Remaining battery stand by time */
#define EM_MONITORING_BATT_TIME                  0x08  /* ----1--- */
/* Remaining battery percentage */
#define EM_MONITORING_BATT_PERC                  0x20  /* --1----- */
/* Remaining battery bar level for audio use */
#define EM_MONITORING_BATT_AUDIO_BARS            0x10  /* ---1---- */

/* ----------------------------------------------------------------------- */
/* Bitmask Table: EM_PSM_INFO - Valid from version 007.000                 */
/* ----------------------------------------------------------------------- */
typedef uint16_t EM_PSM_INFO_CONST;

/* Battery current */
#define EM_PSM_BATTERY_CURRENT                   0x0001  /* ---------------1 */
/* Phone current */
#define EM_PSM_PHONE_CURRENT                     0x0002  /* --------------1- */
/* Discharge amount, since battery full */
#define EM_PSM_DISCHARGE_AMOUNT                  0x0004  /* -------------1-- */
/* Active CS State */
#define EM_PSM_CS_ACTIVE_STATE                   0x0008  /* ------------1--- */
/* Active CS protocol */
#define EM_PSM_CS_ACTIVE_PROTOCOL                0x0010  /* -----------1---- */
/* CS idle activity */
#define EM_PSM_CS_IDLE_ACTIVITY                  0x0020  /* ----------1----- */
/* Phone State used by batmon4 */
#define EM_PSM_BATMON4_PHONE_STATE               0x0040  /* ---------1------ */
/* Number of active software features */
#define EM_PSM_SW_FEATURE_COUNTER                0x0080  /* --------1------- */
/* Phone activity feature flags */
#define EM_PSM_ACTIVITY                          0x0100  /* -------1-------- */

/* ----------------------------------------------------------------------- */
/* Bitmask Table: EM_PSM_ACTIVITY_INFO - Valid from version 007.000        */
/* ----------------------------------------------------------------------- */
typedef uint32_t EM_PSM_ACTIVITY_INFO_CONST;

#define EM_PSM_DISPLAY_LIGHT_ACTIVE              0x00000001  /* -------------------------------1 */
#define EM_PSM_KEYBOARD_LIGHT_ACTIVE             0x00000002  /* ------------------------------1- */
#define EM_PSM_VIBRA_ACTIVE                      0x00000004  /* -----------------------------1-- */
#define EM_PSM_BUZZER_ACTIVE                     0x00000008  /* ----------------------------1--- */
#define EM_PSM_IRDA_ACTIVE                       0x00000010  /* ---------------------------1---- */
#define EM_PSM_DC_OUT_ACTIVE                     0x00000020  /* --------------------------1----- */
#define EM_PSM_RADIO_ACTIVE                      0x00000040  /* -------------------------1------ */
#define EM_PSM_VIDEO_ACTIVE                      0x00000080  /* ------------------------1------- */
#define EM_PSM_GPS_ACTIVE                        0x00000100  /* -----------------------1-------- */
#define EM_PSM_MP3_ACTIVE                        0x00000200  /* ----------------------1--------- */
#define EM_PSM_IHF_ACTIVE                        0x00000400  /* ---------------------1---------- */
#define EM_PSM_VRR_ACTIVE                        0x00000800  /* --------------------1----------- */
#define EM_PSM_ADSP_ACTIVE                       0x00001000  /* -------------------1------------ */
#define EM_PSM_MIDI_ACTIVE                       0x00002000  /* ------------------1------------- */
#define EM_PSM_FLASHLIGHT_ACTIVE                 0x00004000  /* -----------------1-------------- */
#define EM_PSM_USB_ACTIVE                        0x00008000  /* ----------------1--------------- */
#define EM_PSM_TOUCHPAD_ACTIVE                   0x00010000  /* ---------------1---------------- */
#define EM_PSM_SENSORS_ACTIVE                    0x08000000  /* ----1--------------------------- */
#define EM_PSM_BLUETOOTH_ACTIVE                  0x10000000  /* ---1---------------------------- */
#define EM_PSM_COVER_POWER_ACTIVE                0x20000000  /* --1----------------------------- */
#define EM_PSM_CAMERA_ACTIVE                     0x40000000  /* -1------------------------------ */
#define EM_PSM_DATA_CABLE_ACTIVE                 0x80000000  /* 1------------------------------- */

/* ----------------------------------------------------------------------- */
/* Bitmask Table: EM_INDICATION_INFO - Valid from version 007.000          */
/* ----------------------------------------------------------------------- */
typedef uint16_t EM_INDICATION_INFO_CONST;

/* Charger state change */
#define EM_CHARGER_STATE_CHANGE                  0x0001  /* ---------------1 */
/* Battery state change.(Is never set. DO NOT USE!) */
#define EM_BATTERY_STATE_CHANGE                  0x0002  /* --------------1- */
/* Charging state change */
#define EM_CHARGING_STATE_CHANGE                 0x0004  /* -------------1-- */
/* Monitoring state change */
#define EM_MONITORING_STATE_CHANGE               0x0008  /* ------------1--- */
/* Early battery empty warning */
#define EM_CS_BATTERY_EMPTY                      0x0010  /* -----------1---- */
#define EM_CS_BATTERY_TIME                       0x0020  /* ----------1----- */
#define EM_CS_BATTERY_FULL                       0x0040  /* ---------1------ */


/* ----------------------------------------------------------------------- */
/* FTD Data Table                                                          */
/* ----------------------------------------------------------------------- */
/* Battery monitor SW status
   ???
   Cha = Charging
   Mon = Monitoring
   Rst = Restart batmon4
   Set = Settle after charging
   Res = Reset batmon4
   Ser = Service
   Sto = Stopped
   Dis = Disable
*/
#define EM_SB_FTD_STATUS                         0x0100  /* String */
/* Battery type
   ???
   SB = Service battery
   Ni = Nickel battery
   Err = Error
   4L1 = 4.1 v lithium battery
   4L2 = 4.2 v lithium battery
*/
#define EM_SB_FTD_BAT_TYPE                       0x0101  /* String */
/* Current battery temperature in kelvin */
#define EM_SB_FTD_CURRENT_BAT_TEMP               0x0102  /* Word */
/* Instantaneous battery voltage */
#define EM_SB_FTD_INST_BAT_VOLT                  0x0103  /* Word */
/* Battery capacity */
#define EM_SB_FTD_BAT_CAPACITY                   0x0104  /* Word */
/* Number of battery bars (1 - 8) */
#define EM_SB_FTD_NUMBER_OF_BAT_BARS             0x0105  /* Byte */
/* Remaining standby time to battery low */
#define EM_SB_FTD_REMAIN_STBY_HOURS              0x0106  /* Word */
/* Elapsed model time */
#define EM_SB_FTD_ELAPSED_TIME                   0x0107  /* Dword */
/* DMF Double median filtered battery voltage */
#define EM_SB_FTD_DMF_BAT_VOLT                   0x0108  /* Word */
/* Remaining standby time to battery low */
#define EM_SB_FTD_REMAIN_STBY_MINUTES            0x0109  /* Dword */
/* Present Phi value */
#define EM_SB_FTD_PHI_VARIABLE                   0x010A  /* Word */
/* Voltage level at first battery low warning */
#define EM_SB_FTD_VOLT_AT_FIRST_BAT_LOW          0x010B  /* Word */
/* Present Delta Phi value */
#define EM_SB_FTD_DELTA_PHI_VARIABLE             0x010C  /* Word */
/* Number of battery low warnings */
#define EM_SB_FTD_NUMBER_BAT_LOW_WARN            0x010D  /* Word */
/* Parameter error bitmap */
#define EM_SB_FTD_PARAM_ERRORS                   0x010E  /* Word */
/* CS idle activity */
#define EM_SB_FTD_CS_IDLE_ACTIVITY               0x010F  /* Byte */
/* CS state
   ????
   Idle
   NSPS
   SCAN = Scanning
   SIGN = Signalling
   Call
   CSD
   HSCS = HSCSD
   GPRS
   Data
   EDGE
*/
#define EM_SB_FTD_CS_STATE                       0x0110  /* String */
/* CS protocol
   ?????
   GSM
   TDMA
   CDMA
   AMPS
   PDC
   WCDMA
   NMT
   TETRA
   UMA
   INACT
*/
#define EM_SB_FTD_CS_PROTOCOL                    0x0111  /* String */
/* Battery current */
#define EM_SB_FTD_BAT_CURRENT                    0x0112  /* Word */
/* Phone current */
#define EM_SB_FTD_PHONE_CURRENT                  0x0113  /* Word */
/* Feature current */
#define EM_SB_FTD_FEATURE_CURRENT                0x0114  /* Word */
/* Discharge amount */
#define EM_SB_FTD_DISCHARGE_AMOUNT               0x0115  /* Word */
/* BATMON4 state
   IDLE
   TALK
   FEAT
   DATA
   TRANS
   PACKD
*/
#define EM_SB_FTD_BATMON4_STATE                  0x0116  /* String */
/* Present charger type
   ???
   TEr = Type error
   2Wi = 2 wire charger
   3Wi = 3 wire charger
   AC7 = ACP7 type of charger
   Spe = Special type charger
   VEr = Voltage error
   CEr = Current error
*/
#define EM_SB_FTD_PRESENT_CHR_TYPE               0x0117  /* String */
/* Previous charger type
   ???
   TEr = Type error
   2Wi = 2 wire charger
   3Wi = 3 wire charger
   AC7 = ACP7 type of charger
   Spe = Special type charger
   VEr = Voltage error
   CEr = Current error
*/
#define EM_SB_FTD_PREVIOUS_CHR_TYPE              0x0118  /* String */
/* Average charging voltage */
#define EM_SB_FTD_AVERAGE_CHR_VOLT               0x0119  /* Word */
/* Calculated charging current */
#define EM_SB_FTD_CALC_CHR_CURRENT               0x011A  /* Word */
/* Charger recognition state
   ????
   NoCh = No charger connected
   ByCk = Battery type check
   BeCk = Battery temp check
   CkV7 = Check VCHAR for ACP7
   CkI7 = Check ICHAR from ACP7
   CkI8 = Check ICHAR from ACP8 or ACP9
   Ck3W = Check for 3 wire charger
   MxCk = Done maximum number of charger checks
   ChPa = Charger info paused
   ChDi = Charger info disabled
   ChOK= Charger OK
   ChNo = Charger not OK
*/
#define EM_SB_FTD_CHR_REC_STATE                  0x011B  /* String */
/* Number of charger checks (0 - 9) */
#define EM_SB_FTD_NUMBER_CHR_CHECKS              0x011C  /* Byte */
/* Present charging mode
   ???
   Not = Not charging
   Ini = Initialisation
   TCh = Temperature check
   LiC = Lithium charging
   Dis = Charge disabled
   Dch = Discharging
   Dco = Disconnectted
   Pow = Power consuming charge
   Col = Cold charging
   Hot = Hot charging
   Mai = Maintenance charging
   BEr = Battery error
   NiC = Nickel charging
   SpC = Special charging
   CPa = Control paused
   CDi = Control disabled
*/
#define EM_SB_FTD_PRESENT_CHA_MODE               0x011D  /* String */
/* Present charging mode
   ???
   Not = Not charging
   Ini = Initialisation
   TCh = Temperature check
   LiC = Lithium charging
   Dis = Charge disabled
   Dch = Discharging
   Dco = Disconnectted
   Pow = Power consuming charge
   Col = Cold charging
   Hot = Hot charging
   Mai = Maintenance charging
   BEr = Battery error
   NiC = Nickel charging
   SpC = Special charging
   CPa = Control paused
   CDi = Control disabled
*/
#define EM_SB_FTD_PREVIOUS_CHA_MODE              0x011E  /* String */
/* HW PWM frequency */
#define EM_SB_FTD_PWM_FREQ                       0x011F  /* Byte */
/* Charge time */
#define EM_SB_FTD_CHA_TIME                       0x0120  /* Word */
/* Instantaneous battery voltage */
#define EM_SB_FTD_CHA_INST_BAT_VOLT              0x0121  /* Word */
/* Open switch PWM battery voltage */
#define EM_SB_FTD_OS_PWM_BAT_VOLT                0x0122  /* Word */
/* Close switch PWM battery voltage */
#define EM_SB_FTD_CS_PWM_BAT_VOLT                0x0123  /* Word */
/* Instantaneous charger current */
#define EM_SB_FTD_INST_CHR_CURRENT               0x0124  /* Word */
/* Battery full flag (0 or 1) */
#define EM_SB_FTD_BAT_FULL_FLAG                  0x0125  /* Byte */
/* Charging mode (0 - 9) */
#define EM_SB_FTD_CHA_MODE                       0x0126  /* Byte */
/* Open switch -dv detect rule */
#define EM_SB_FTD_OS_DV_DETECT                   0x0127  /* Byte */
/* Slow -dv detect rule */
#define EM_SB_FTD_SLOW_DV_DETECT                 0x0128  /* Byte */
/* -dv over time detect rule */
#define EM_SB_FTD_DV_OVER_TIME_DETECT            0x0129  /* Byte */
/* Charge amount detect rule */
#define EM_SB_FTD_CHARGE_AMOUNT_DETECT           0x012A  /* Byte */
/* Battery voltage detect rule */
#define EM_SB_FTD_BAT_VOLT_DETECT                0x012B  /* Byte */
/* Battery temperature detect rule */
#define EM_SB_FTD_BAT_TEMP_DETECT                0x012C  /* Byte */
/* Fuzzy sum */
#define EM_SB_FTD_FUZZY_SUM                      0x012D  /* Word */
/* Maintenance charging time */
#define EM_SB_FTD_MAINTENANCE_CHA_TIME           0x012E  /* Word */
/* Open switch dv over time */
#define EM_SB_FTD_OS_DV_OVER_TIME                0x012F  /* Word */
/* Activity information LSB
   Bit0 = Display light active
   Bit1 = Keyboard light active
   Bit2 = Vibra active
   Bit3 = Buzzer active
   Bit4 = Irda active
   Bit5 = DC-out active
   Bit6 = Radio active
   Bit7 = Video active
*/
#define EM_SB_FTD_ACTIVITY_BYTE1                 0x0130  /* String */
/* Activity information 2nd LSB
   Bit8 = GPS active
   Bit9 = MP3 active
   Bit10 = IHF active
   Bit11 = VRR active
   Bit12 = ADSP active
   Bit13 = MIDI active
   Bit14 = Flashlight active
   Bit15 = USB active
*/
#define EM_SB_FTD_ACTIVITY_BYTE2                 0x0131  /* String */
/* Activity information 2nd MSB
   Bit16 = Touchpad active
   Bit17-Bit23 = not used
*/
#define EM_SB_FTD_ACTIVITY_BYTE3                 0x0132  /* String */
/* Activity information MSB
   Bit24-Bit26 = not used
   Bit27 = Sensors active
   Bit28 = Bluetooth active
   Bit29 = Cover active
   Bit30 = Camera active
   Bit31 = Data cable active
*/
#define EM_SB_FTD_ACTIVITY_BYTE4                 0x0133  /* String */
#define EM_SB_FTD_VERSIONNO                      0x0134  /* String */
/* Active sw features */
#define EM_SB_FTD_ACTIVE_SW_FEATURE              0x0135  /* Byte */
/* SW PWM value */
#define EM_SB_FTD_SW_PWM_VALUE                   0x0136  /* Byte */
/* Over voltage limit
   ???
   3v6 = 3.6 volt
   5v1 = 5.1 volt
   5v3 = 5.3 volt
*/
#define EM_SB_FTD_OVV_LIMIT                      0x0137  /* String */
/* Back-UP Bat charging
   0 = software control (Should not happen)
   1 = disabled
   2 = enabled
   3 = discharging
   BUB charging
*/
#define EM_SB_FTD_BUB_CHARGING                   0x0138  /* Byte */
/* Estimated Tx-Off battery voltage */
#define EM_SB_FTD_EST_TX_OFF                     0x0139  /* Word */
/* Measured Tx-On sync battery voltage */
#define EM_SB_FTD_MEAS_TX_ON                     0x013A  /* Word */
/* Mics. battery monitor flags */
#define EM_SB_FTD_MISC_MON_INT_FLAGS1            0x013B  /* Byte */
#define EM_SB_FTD_BAT_POW_IND                    0x013C  /* String */
/* Calculated voltage level */
#define EM_SB_FTD_CALC_VOLT_LEVEL                0x013D  /* Word */
/* Number of battery low warnings */
#define EM_SB_FTD_WARN_COUNT                     0x013E  /* Word */
/* Misc. batmon4 internal flags
   Fields (bit 0 = lsb):
   [0]    : First Correction flag
   [1]    : Model Valid flag
   [2-3]  : Settle Delay Mode
   Misc mon int flags2
*/
#define EM_SB_FTD_MISC_MON_INT_FLAGS2            0x013F  /* Byte */
/* Total phone current in 0.1 units by PSM */
#define EM_SB_FTD_CURRENT_MON_EST1               0x0140  /* Dword */
/* Batmon4 model voltage */
#define EM_SB_FTD_MON_VOLT                       0x0141  /* Word */
/* Misc. batmon4 internal flags
   Bitfields (bit 0 = lsb):
   [0]     : 0=Standby, 1=Non-Standby.
   [1-3]  : <Future - TBD>
   Misc mon int flags3
*/
#define EM_SB_FTD_MISC_MON_INT_FLAGS3            0x0142  /* Byte */
/* Total phone current in 0.1 units by batmon4 */
#define EM_SB_FTD_CURRENT_MON_EST2               0x0143  /* Dword */
/* Calculated time per battery bar */
#define EM_SB_FTD_CALC_BAT_BAR                   0x0144  /* Word */
/* Configured minimum standby current */
#define EM_SB_FTD_CONF_MIN_CURRENT               0x0145  /* Word */
/* Battery impedance */
#define EM_SB_FTD_BAT_IMP                        0x0146  /* Word */
/* Battery full voltage threshold */
#define EM_SB_FTD_BAT_FULL_THRES                 0x0147  /* Word */
/* Battery low voltage threshold */
#define EM_SB_FTD_BAT_LOW_THRES                  0x0148  /* Word */
/* Battery boot voltage */
#define EM_SB_FTD_BAT_BOOT_VOLT                  0x0149  /* Word */
/* Configured batmon battery low voltage (Safety level) */
#define EM_SB_FTD_CONF_BAT_SAFETY_LEVEL          0x014A  /* Word */
/* Configured batmon battery low voltage (Empty) */
#define EM_SB_FTD_CONF_BAT_EMPTY_LEVEL           0x014B  /* Word */
/* Batmon4 algorithm parameter adjustments */
#define EM_SB_FTD_MON_ALG_ADJ                    0x014C  /* Byte */
/* Battery footprint
   BxB = 1
   BxC = 2
   BxD = 3
   BxN = 4
   BL_4C = 11
   BL_5C = 12
   BP_5L = 13
   BR_5C = 14
   BL_5B = 15
   BL_6C = 16
   BL_8N = 17
   BS_5C = 18
   BP_6M = 19
   Bat footprint
*/
#define EM_SB_FTD_CONF_BAT_FOOTPRINT             0x014D  /* Word */
/* Configured battery bars */
#define EM_SB_FTD_CONF_BAT_BARS                  0x014E  /* Byte */
/* Charged amount */
#define EM_SB_FTD_CHARGED_AMOUNT                 0x014F  /* Word */
/* HW PWM value */
#define EM_SB_FTD_HW_PWM_VALUE                   0x0150  /* Byte */
/* Varying field test display 1 */
#define EM_SB_FTD_STRING1                        0x0151  /* String */
/* Varying field test display 2 */
#define EM_SB_FTD_STRING2                        0x0152  /* String */
/* Varying field test display 3 */
#define EM_SB_FTD_STRING3                        0x0153  /* String */
/* Varying field test display 4 */
#define EM_SB_FTD_STRING4                        0x0154  /* String */
/* Varying field test display 5 */
#define EM_SB_FTD_STRING5                        0x0155  /* String */
/* Varying field test display 6 */
#define EM_SB_FTD_STRING6                        0x0156  /* String */
/* Varying field test display 7 */
#define EM_SB_FTD_STRING7                        0x0157  /* String */
/* Varying field test display 8 */
#define EM_SB_FTD_STRING8                        0x0158  /* String */
/* Remaining standby capacity */
#define EM_SB_FTD_REMAIN_PROMILLE                0x0159  /* Word */
/* Last capacity change */
#define EM_SB_FTD_DELTA_CAPACITY                 0x015A  /* Dword */
/* Calculated time per battery bar */
#define EM_SB_FTD_REMAIN_CAPACITY                0x015B  /* Dword */

/* ----------------------------------------------------------------------- */
/* Message ID's                                                            */
/* ----------------------------------------------------------------------- */

/** @addtogroup bmeipc */
/*@{ */

/**
 * @name BME IPC request/responses IDs
 *
 * First 16-bit field type should be set to one of this values
 */

/*@{ */

#define EM_CHARGER_INFO_REQ                      0x00
#define EM_CHARGER_INFO_RESP                     0x01
#define EM_CONTROL_WRITE_REQ                     0x02
#define EM_CONTROL_WRITE_RESP                    0x03
#define EM_CONTROL_READ_REQ                      0x04
#define EM_CONTROL_READ_RESP                     0x05
#define EM_BATTERY_INFO_REQ                      0x06
#define EM_BATTERY_INFO_RESP                     0x07
#define EM_CHARGING_INFO_REQ                     0x08
#define EM_CHARGING_INFO_RESP                    0x09
#define EM_MONITORING_INFO_REQ                   0x0A
#define EM_MONITORING_INFO_RESP                  0x0B
#define EM_MONITORING_VOLTAGE_REQ                0x0C
#define EM_MONITORING_VOLTAGE_RESP               0x0D
#define EM_MONITORING_VOLTAGE_IND                0x0E
#define EM_ADC_READ_REQ                          0x0F
#define EM_ADC_READ_RESP                         0x10
#define EM_ADC_UNIT_REQ                          0x11
#define EM_ADC_UNIT_RESP                         0x12
#define EM_PSM_CS_STATE_WRITE_REQ                0x13
#define EM_PSM_CS_STATE_WRITE_RESP               0x14
#define EM_PSM_CS_PROTOCOL_WRITE_REQ             0x15
#define EM_PSM_CS_PROTOCOL_WRITE_RESP            0x16
#define EM_PSM_CS_IDLE_ACTIVITY_REQ              0x17
#define EM_PSM_CS_IDLE_ACTIVITY_RESP             0x18
#define EM_PSM_INTERNAL_WRITE_REQ                0x19
#define EM_PSM_INTERNAL_WRITE_RESP               0x1A
#define EM_PSM_EXTERNAL_WRITE_REQ                0x1B
#define EM_PSM_EXTERNAL_WRITE_RESP               0x1C
#define EM_PSM_SW_FEATURE_REQ                    0x1D
#define EM_PSM_SW_FEATURE_RESP                   0x1E
#define EM_PSM_READ_REQ                          0x1F
#define EM_PSM_READ_RESP                         0x20
#define EM_INFO_IND                              0x21
#define EM_ADC_CAL_WRITE_REQ                     0x22
#define EM_ADC_CAL_WRITE_RESP                    0x23
#define EM_ADC_CAL_READ_REQ                      0x24
#define EM_ADC_CAL_READ_RESP                     0x25
#define EM_ADC_UNIT_LOCK_REQ                     0x26
#define EM_ADC_UNIT_LOCK_RESP                    0x27
#define EM_ADC_CAL_TUNE_REQ                      0x28
#define EM_ADC_CAL_TUNE_RESP                     0x29
#define EM_TEMPERATURE_QUERY_REQ                 0x2A
#define EM_TEMPERATURE_QUERY_RESP                0x2B
#define EM_TEMPERATURE_CHANGED_IND               0x2C
#define EM_POWER_REQ                             0x2D
#define EM_POWER_RESP                            0x2E
#define EM_SOS_EVENT_REQ                         0x2F
#define EM_SOS_EVENT_RESP                        0x30
#define EM_SOS_EVENT_NTF                         0x31
#define EM_MEASUREMENT_REQ                       0x32
#define EM_MEASUREMENT_RESP                      0x33
#define EM_MEASUREMENT_NTF                       0x34
#define EM_SELFTEST_REQ                          0x35
#define EM_SELFTEST_RESP                         0x36
#define EM_ME_STATE_REQ                          0x37
#define EM_ME_STATE_RESP                         0x38
#define EM_ADC_CHIPSET_CAL_CALCULATE_REQ         0x39
#define EM_ADC_CHIPSET_CAL_CALCULATE_RESP        0x3A
#define EM_ADC_CHIPSET_CAL_READ_REQ              0x3B
#define EM_ADC_CHIPSET_CAL_READ_RESP             0x3C
#define EM_ADC_CHIPSET_CAL_STORE_REQ             0x3D
#define EM_ADC_CHIPSET_CAL_STORE_RESP            0x3E
#define EM_BATTERY_USETIME_REQ                   0x3F
/*@}*/
/*@}*/

/* ----------------------------------------------------------------------- */
/* Subblock ID's                                                           */
/* ----------------------------------------------------------------------- */

#define EM_CHARGER_STATUS_DATA                   0x00
#define EM_CHARGER_TYPE_DATA                     0x01
#define EM_CHARGER_VOLTAGE_DATA                  0x02
#define EM_CHARGER_CURRENT_DATA                  0x03
#define EM_CONTROL_DISABLE_CHARGING_DATA         0x04
#define EM_CONTROL_PAUSE_CHARGING_DATA           0x05
#define EM_CONTROL_HW_VOLT_LIMIT_DATA            0x06
#define EM_CONTROL_TX_VOLT_LIMIT_DATA            0x07
#define EM_CONTROL_BACKUP_BATTERY_DATA           0x08
#define EM_CONTROL_PWM_DATA                      0x09
#define EM_BATTERY_TYPE_DATA                     0x0A
#define EM_BATTERY_NOMINAL_CAPA_DATA             0x0B
#define EM_BATTERY_TEMP_DATA                     0x0C
#define EM_BATTERY_VOLTAGE_DATA                  0x0D
#define EM_BATTERY_VOLTAGE_TX_ON_DATA            0x0E
#define EM_BATTERY_VOLTAGE_TX_OFF_DATA           0x0F
#define EM_BATTERY_VOLTAGE_PWM_ON_DATA           0x10
#define EM_BATTERY_VOLTAGE_PWM_OFF_DATA          0x11
#define EM_BATTERY_GENERATION_DATA               0x12
#define EM_BATTERY_VOLTAGE_SH_CHK_DATA           0x22
#define EM_CHARGING_STATE_DATA                   0x13
#define EM_CHARGING_MODE_DATA                    0x14
#define EM_MONITORING_BATT_POWER_DATA            0x15
#define EM_MONITORING_BATT_BARS_DATA             0x16
#define EM_MONITORING_BATT_CAPA_DATA             0x17
#define EM_MONITORING_BATT_TIME_DATA             0x18
#define EM_MONITORING_BATTAUDIOBARS_DATA         0x25
#define EM_PSM_BATTERY_CURRENT_DATA              0x19
#define EM_PSM_PHONE_CURRENT_DATA                0x1A
#define EM_PSM_DISCHARGE_AMOUNT_DATA             0x1B
#define EM_PSM_CS_ACTIVE_STATE_DATA              0x1C
#define EM_PSM_CS_ACTIVE_PROTOCOL_DATA           0x1D
#define EM_PSM_CS_IDLE_ACTIVITY_DATA             0x1E
#define EM_PSM_BATMON4_PHONE_STATE_DATA          0x1F
#define EM_PSM_SW_FEATURE_COUNTER_DATA           0x20
#define EM_PSM_ACTIVITY_DATA                     0x21
#define EM_ADC_CAL_GEN_DATA                      0x23
#define EM_ADC_CAL_LOG_DATA                      0x24
#define EM_ADC_CAL_ALG_DATA                      0x29
#define EM_ADC_CAL_STORED_MEAS_DATA              0x2D
#define EM_ADC_CAL_TUNE_REQ_DATA                 0x26
#define EM_ADC_CAL_TUNE_RESP_DATA                0x27
#define EM_SOS_TIMER_EVENT_DATA                  0x28
#define EM_MEASUREMENT_TYPE                      0x2A
#define EM_MEASUREMENT                           0x2B
#define EM_CONTROL_USB_CHARGER_DATA              0x2C
#define EM_CONTROL_BACKUP_BATTERY_CHARGING_DATA  0x34
#define EM_CONTROL_USB_CHARGER_TYPE              0x2E
#define EM_ADC_CHIPSET_CAL_CALCULATE_REQ_DATA    0x2F
#define EM_ADC_CHIPSET_CAL_READ_REQ_DATA         0x31
#define EM_ADC_CHIPSET_CAL_READ_RESP_DATA        0x32
#define EM_MONITORING_BATT_PERC_DATA             0x33

/* ----------------------------------------------------------------------- */
/* Subblock: EM_CHARGER_STATUS_DATA - Valid from version 007.000           */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   sb_id;
    uint8_t   sb_size;
    /* Values from the constant table EM_CHARGER_STATUS_INFO */
    uint8_t   req_data;
    uint8_t   reserved1;
    } tEM_SbByteData;

#define EM_SB_BYTE_DATA_BASE_LEN   sizeof(tEM_SbByteData)


/* ----------------------------------------------------------------------- */
/* Subblock: EM_CHARGER_VOLTAGE_DATA - Valid from version 007.000          */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   sb_id;
    uint8_t   sb_size;
    uint16_t  req_data;
    } tEM_SbWordData;

#define EM_SB_WORD_DATA_BASE_LEN   sizeof(tEM_SbWordData)


/* ----------------------------------------------------------------------- */
/* Subblock: EM_CONTROL_PWM_DATA - Valid from version 007.000              */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   sb_id;
    uint8_t   sb_size;
    uint8_t   req_data0;
    uint8_t   req_data1;
    } tEM_Sb2ByteData;

#define EM_SB_2_BYTE_DATA_BASE_LEN   sizeof(tEM_Sb2ByteData)


/* ----------------------------------------------------------------------- */
/* Subblock: EM_PSM_ACTIVITY_DATA - Valid from version 007.000             */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   sb_id;
    uint8_t   sb_size;
    /* Contains the phone activity bit-field, when a feature is active then
       the corresponding bit is set.
    */
    uint8_t   reserved1;
    uint8_t   reserved2;
    /* Values from the bitmask table EM_PSM_ACTIVITY_INFO */
    uint32_t  req_data;
    } tEM_SbDwordData;

#define EM_SB_DWORD_DATA_BASE_LEN   sizeof(tEM_SbDwordData)


/* ----------------------------------------------------------------------- */
/* Subblock: EM_ADC_CAL_GEN_DATA - Valid from version 007.001              */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   sb_id;
    uint8_t   sb_size;
    /* Contains the Linear, hyberbolic and no transfer function data from the
       ADC library.
       Values from the constant table EM_ADC_CHANNEL_INFO
    */
    uint8_t   data0;
    /* Values from the constant table EM_ADC_TRANSFER_FUNCTION_INFO */
    uint8_t   data1;
    uint32_t  data2;
    uint32_t  data3;
    } tEM_Sb2Byte2DwordData;

#define EM_SB_2BYTE_2DWORD_DATA_BASE_LEN   sizeof(tEM_Sb2Byte2DwordData)


/* ----------------------------------------------------------------------- */
/* Subblock: EM_ADC_CAL_LOG_DATA - Valid from version 007.001              */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   sb_id;
    uint8_t   sb_size;
    /* Contains the Logarithmic data from the ADC library.
       Values from the constant table EM_ADC_CHANNEL_INFO
    */
    uint8_t   data0;
    /* Values from the constant table EM_ADC_TRANSFER_FUNCTION_INFO */
    uint8_t   data1;
    uint16_t  data2;
    uint16_t  data3;
    uint16_t  data4;
    uint16_t  data5;
    } tEM_Sb2Byte4WordData;

#define EM_SB_2BYTE_4WORD_DATA_BASE_LEN   sizeof(tEM_Sb2Byte4WordData)


/* ----------------------------------------------------------------------- */
/* Sequence: EM_ADC_CAL_RAW_MEAS_RESULT_SEQ_ENTRY - Valid from version 008.020 */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    /* Values from the constant table EM_ADC_CHANNEL_INFO */
    uint8_t   adc_channel;
    uint8_t   reserved1;
    /* Calibration reference (voltage/current/etc.) used for the measurement.
       Unit equals unit for the selected ADC channel
    */
    int16_t   meas_cal_ref;
    uint16_t  meas_raw_reading; /* ADC measurement result (raw reading) */
    uint16_t  reserved2;
    } tEM_Seq_ADCCalRawMeasResultEntry_Str;

#define SIZE_EM_ADC_CAL_RAW_MEAS_RESULT_SEQ_ENTRY_STR   \
        sizeof(tEM_Seq_ADCCalRawMeasResultEntry_Str)


/* ----------------------------------------------------------------------- */
/* Subblock: EM_ADC_CAL_STORED_MEAS_DATA - Valid from version 008.020      */
/* ----------------------------------------------------------------------- */
/* This SubBlock contains MS-ASIC ADC calibration measurements that has been
   recorded by ASIC vendor and stored in non-volatile memory in the ASIC. All
   measurements are raw ADC reading.
*/

typedef struct
    {
    uint8_t   sb_id;
    uint8_t   sb_size;
    uint8_t   num_of_meas;
    uint8_t   reserved1;
    tEM_Seq_ADCCalRawMeasResultEntry_Str measurement_table[30];
    } tEM_Sb_ADCCalStoredMeasDataStr;

#define SIZE_EM_ADC_CAL_STORED_MEAS_DATA_STR   (4*sizeof(uint8_t) + \
        30*sizeof(tEM_Seq_ADCCalRawMeasResultEntry_Str))


/* ----------------------------------------------------------------------- */
/* Subblock: EM_ADC_CAL_TUNE_REQ_DATA - Valid from version 007.009         */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   sb_id;
    uint8_t   sb_size;
    /* Note: It is not possible to measure the EM_ADC_ALL_CAL channel.
       EM_ADC_ALL_CAL is not a channel.
       Values from the constant table EM_ADC_CHANNEL_INFO
    */
    uint8_t   channel_id;
    /* Number passed to ADC library function adc_average_raw_read().
       When measuring EM_ADC_IBAT_AVG adc_average_unit_read() is used.
    */
    uint8_t   sample_amount;
    /* The trigger level is used as the measuring point when the state
       machine measures on a specific ADC channel. Measuring is made by
       adc_unit_read() or adc_raw_read(). When the level is positive the
       triggering happens on a rising edge. And on a falling edge when the
       trigger level is negative.
       Note: When measuring on EM_ADC_MAIN_CAL the value has to be raw data.
       Any other channel should be in units.
    */
    int16_t   trigger_level;
    uint8_t   data0;
    uint8_t   data1;
    } tEM_AdcCalTuneReqData;

#define EM_ADC_CAL_TUNE_REQ_DATA_LEN   sizeof(tEM_AdcCalTuneReqData)


/* ----------------------------------------------------------------------- */
/* Subblock: EM_ADC_CAL_TUNE_RESP_DATA - Versions 007.009 - 008.000        */
/* ----------------------------------------------------------------------- */

#if EM_ISI_MIN_VERSION(7,9) && !EM_ISI_MIN_VERSION(8,0)

typedef struct
    {
    uint8_t   sb_id;
    uint8_t   sb_size;
    /* Values from the constant table EM_ADC_CHANNEL_INFO */
    uint8_t   channel_id;
    uint8_t   data0;
    /* Measured value is read by adc library function adc_average_raw_read().
       But when EM_ADC_IBAT_AVG is read adc_average_unit_read() is used and
       therefore returned in units and the number is negative since current
       is put to the battery, not drained from the battery. See reference:
       /7/ for a more detailed description.
       Note: It can be that a timeout has occurred, then the subblock will
       include the data which has been measured until the timer ran out. The
       channel that was about to be read has EM_INFO_NOT_SUPPORTED in
       measured value.
    */
    int16_t   measured_value;
    uint8_t   data1;
    uint8_t   data2;
    } tEM_AdcCalTuneRespData;

#define EM_ADC_CAL_TUNE_RESP_DATA_LEN   sizeof(tEM_AdcCalTuneRespData)

#endif /* EM_ISI_MIN_VERSION(7,9) && !EM_ISI_MIN_VERSION(8,0) */


/* ----------------------------------------------------------------------- */
/* Subblock: EM_ADC_CAL_TUNE_RESP_DATA - Valid from version 008.000        */
/* ----------------------------------------------------------------------- */

#if EM_ISI_MIN_VERSION(8,0)

typedef struct
    {
    uint8_t   sb_id;
    uint8_t   sb_size;
    /* Values from the constant table EM_ADC_CHANNEL_INFO */
    uint8_t   channel_id;
    /* This field is initialised to EM_INFO_NOT_KNOWN_YET. When the channel
       has been measured the status changes to EM_INFO_OK, but should the
       measurement fail then the status changes to EM_INFO_FAIL.
       Values from the constant table EM_STATUS
    */
    uint8_t   status;
    /* Measured value is read by adc library function adc_average_raw_read().
       But when EM_ADC_IBAT_AVG is read adc_average_unit_read() is used and
       therefore returned in units and the number is negative since current
       is put to the battery, not drained from the battery. See reference:
       /7/ for a more detailed description.
       Note: It can be that a timeout occurs, then data will be included in
       the subblocks for the channels that have been measured correctly
       before the timer ran out. The channel that was about to be read has
       EM_INFO_FAIL in the status field.
    */
    int16_t   measured_value;
    uint8_t   data1;
    uint8_t   data2;
    } tEM_AdcCalTuneRespData;

#define EM_ADC_CAL_TUNE_RESP_DATA_LEN   sizeof(tEM_AdcCalTuneRespData)

#endif /* EM_ISI_MIN_VERSION(8,0) */


/* ----------------------------------------------------------------------- */
/* Subblock: EM_MEASUREMENT_TYPE - Valid from version 008.006              */
/* ----------------------------------------------------------------------- */
/* This SubBlock contains information of what to measure and how often. When
   used in a EM_MEASUREMENT_REQ only the first subblock is processed for
   sampling period, the following EM_MEASUREMENT_NTF will contain all
   measurement types
*/

typedef struct
    {
    uint8_t   sb_id;
    uint8_t   sb_size;
    uint8_t   type;   /* Values from the constant table EM_MEASUREMENT_VALUE */
    /* NB: Only the period in the first subblock is used
       Values from the constant table EM_MEASUREMENT_PERIOD
    */
    uint8_t   period;
    } tEM_SbMeasurement_Type;

#define EM_MEASUREMENT_TYPE_LEN   sizeof(tEM_SbMeasurement_Type)


/* ----------------------------------------------------------------------- */
/* Subblock: EM_MEASUREMENT - Valid from version 008.006                   */
/* ----------------------------------------------------------------------- */
/* This SubBlock contains a single measurement. */

typedef struct
    {
    uint8_t   sb_id;
    uint8_t   sb_size;
    uint8_t   type;   /* Values from the constant table EM_MEASUREMENT_VALUE */
    uint8_t   fill1;
    uint32_t  time;         /* MCU OS timestamp (32bit wraparound counter) */
    /* Measured value, type given in request (EM_MEASUREMENT_TYPE) */
    uint32_t  value;
    } tEM_SbMeasurement;

#define EM_MEASUREMENT_LEN   sizeof(tEM_SbMeasurement)


/* ----------------------------------------------------------------------- */
/* Subblock: EM_CONTROL_USB_CHARGER_DATA - Valid from version 008.008      */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   sb_id;
    uint8_t   sb_size;
    /* Values from the constant table EM_CONTROL_USB_CHARGER_ACTION */
    uint8_t   action;
    uint8_t   fill1;
    uint32_t  value;        /* Value field dependent on the action selected */
    } tEM_CONTROL_USB_CHARGER_DATA;

#define EM_CONTROL_USB_CHARGER_DATA_LEN   \
        sizeof(tEM_CONTROL_USB_CHARGER_DATA)


/* ----------------------------------------------------------------------- */
/* Subblock: EM_CONTROL_BACKUP_BATTERY_CHARGING_DATA - Valid from version 008.028 */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   sb_id;
    uint8_t   sb_size;
    /* Values from the constant table
       EM_CONTROL_BACKUP_BATTERY_CHARGING_ACTION
    */
    uint8_t   action;
    uint8_t   fill1;
    uint32_t  value;        /* Value field dependent on the action selected */
    } tEM_CONTROL_BACKUP_BATTERY_CHARGING_DATA;

#define EM_CONTROL_BACKUP_BATTERY_CHARGING_DATA_LEN   \
        sizeof(tEM_CONTROL_BACKUP_BATTERY_CHARGING_DATA)


/* ----------------------------------------------------------------------- */
/* Subblock: EM_CONTROL_USB_CHARGER_TYPE - Valid from version 008.023      */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   sb_id;
    uint8_t   sb_size;
    /* Values from the constant table EM_CONTROL_USB_CHARGER_TYPE_INFO */
    uint8_t   type;
    /* Only avaliable when charger type is a host charger.
       Values from the constant table EM_CONTROL_USB_CHARGER_HOST_CURRENT
    */
    uint8_t   current;
    } tEM_CONTROL_USB_CHARGER_TYPE;

#define EM_CONTROL_USB_CHARGER_TYPE_LEN   \
        sizeof(tEM_CONTROL_USB_CHARGER_TYPE)


/* ----------------------------------------------------------------------- */
/* Subblock: EM_ADC_CHIPSET_CAL_CALCULATE_REQ_DATA - Valid from version 008.024 */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   sb_id;
    uint8_t   sb_size;
    /* ADC channel
       Values from the constant table EM_ADC_CHANNEL_INFO
    */
    uint8_t   data0;
    /* Adc type of sensor, measurement voltage/current applied
       Values from the constant table EM_CHIPSET_CAL_TYPE
    */
    uint8_t   type;
    uint16_t  adc_raw_reading; /* ADC measurement raw reading */
    uint8_t   reserved1[2];
    int32_t   reference_value; /* ADC reference point, unit value */
    /* Identification of the PC (tool) doing the calibration */
    uint32_t  identification;
    } tEM_AdcChipsetCalCalculateReqData;

#define EM_SB_ADC_CHIPSET_CAL_CALCULATE_REQ_DATA_BASE_LEN   \
        sizeof(tEM_AdcChipsetCalCalculateReqData)


/* ----------------------------------------------------------------------- */
/* Subblock: EM_ADC_CHIPSET_CAL_READ_REQ_DATA - Valid from version 008.024 */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   sb_id;
    uint8_t   sb_size;
    /* Contains the adc channel for which calibration data shuld be
       returned(in chipset platform).
       Values from the constant table EM_ADC_CHANNEL_INFO
    */
    uint8_t   data0;
    uint8_t   reserved1;
    } tEM_AdcChipsetCalReadReqData;

#define EM_SB_ADC_CHIPSET_CAL_READ_REQ_DATA_BASE_LEN   \
        sizeof(tEM_AdcChipsetCalReadReqData)


/* ----------------------------------------------------------------------- */
/* Subblock: EM_ADC_CHIPSET_CAL_READ_RESP_DATA - Valid from version 008.024 */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   sb_id;
    uint8_t   sb_size;
    /* Contains the calibration data for given channel.The calibration
       parameters should somehow represent the calibration, so any
       significant change in calibration should result in a significant
       change in one or more of the parameters(in chipset platform).
       Values from the constant table EM_ADC_CHANNEL_INFO
    */
    uint8_t   data0;
    /* Identifier of the PC(tool) which did the calibration */
    uint8_t   reserved1;
    uint32_t  data2;
    uint32_t  data3;        /* Field containing calibration value (e.g gain) */
    uint32_t  data4;      /* Field containing calibration value (e.g offset) */
    uint32_t  data5;      /* Field containing calibration value (e.g method) */
    } tEM_AdcChipsetCalReadDataResp;

#define EM_SB_ADC_CHIPSET_CAL_READ_RESP_DATA_BASE_LEN   \
        sizeof(tEM_AdcChipsetCalReadDataResp)


/* ----------------------------------------------------------------------- */
/* Message: EM_CHARGER_INFO_REQ - Valid from version 007.000               */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   trans_id;
    uint8_t   message_id;
    uint8_t   req_info;     /* Values from the bitmask table EM_CHARGER_INFO */
    uint8_t   reserved1;
    } tEM_BasicInfoReq;

#define EM_BASIC_INFO_REQ_LEN   sizeof(tEM_BasicInfoReq)


/* ----------------------------------------------------------------------- */
/* Message: EM_CHARGER_INFO_RESP - Valid from version 007.000              */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   trans_id;
    uint8_t   message_id;
    uint8_t   status;       /* Values from the constant table EM_STATUS */
    uint8_t   sb_amount;
    /* Subblock list:
       EM_CHARGER_CURRENT_DATA
       EM_CHARGER_STATUS_DATA
       EM_CHARGER_TYPE_DATA
       EM_CHARGER_VOLTAGE_DATA
    */
    } tEM_BasicInfoResp;

#define EM_BASIC_INFO_RESP_BASE_LEN   (4*sizeof(uint8_t))


/* ----------------------------------------------------------------------- */
/* Message: EM_CONTROL_WRITE_REQ - Valid from version 007.000              */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   trans_id;
    uint8_t   message_id;
    uint8_t   write_req;    /* Values from the bitmask table EM_CONTROL_INFO */
    uint8_t   sb_amount;
    /* Subblock list:
       EM_CONTROL_BACKUP_BATTERY_CHARGING_DATA
       EM_CONTROL_BACKUP_BATTERY_DATA
       EM_CONTROL_DISABLE_CHARGING_DATA
       EM_CONTROL_HW_VOLT_LIMIT_DATA
       EM_CONTROL_PAUSE_CHARGING_DATA
       EM_CONTROL_PWM_DATA
       EM_CONTROL_TX_VOLT_LIMIT_DATA
       EM_CONTROL_USB_CHARGER_DATA
    */
    uint8_t   sub_blocks[EM_ANY_SIZE];
    } tEM_Write_Req;

#define EM_WRITE_REQ_LEN   (4*sizeof(uint8_t))

/* Only the header part is included in the message length. The sub_blocks
   array is only used for indexing into the sub-blocks, so sizeof
   (tEM_Write_Req) cannot be used for message memory allocation          */

/* ----------------------------------------------------------------------- */
/* Message: EM_CONTROL_WRITE_RESP - Valid from version 007.000             */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   trans_id;
    uint8_t   message_id;
    uint8_t   resp_status;  /* Values from the constant table EM_STATUS */
    uint8_t   reserved1;
    } tEM_BasicInfoOneResp;

#define EM_BASIC_INFO_ONE_RESP_LEN   sizeof(tEM_BasicInfoOneResp)


/* ----------------------------------------------------------------------- */
/* Message: EM_CONTROL_READ_REQ - Valid from version 008.012               */
/* ----------------------------------------------------------------------- */
/* Clients can use this feature, to control the charging SW and charging
   related HW. It is possible to read the control information from the EM
   server.
   This feature is also used for production and testing purposes. The
   EM_CONTROL_READ_REQ message is used for reading the control values. The
   read requests info is specified in a bit-field EM_CONTROL_INFO.
   If the EM_CONTROL_USB_CHARGER is set in bit-field, it is mandatory to send
   only one EM_CONTROL_USB_CHARGER_DATA subblock. In this subblock the
   requested usb read action can be specified. There is also a generic value
   field in EM_CONTROL_USB_CHARGER_DATA subblock which must be zero when this
   subblock is used in this request.
   This feature is mandatory.
*/

typedef struct
    {
    uint8_t   trans_id;
    uint8_t   message_id;
    uint8_t   req_info;     /* Values from the bitmask table EM_CONTROL_INFO */
    uint8_t   sb_amount;
    /* Subblock list:
       EM_CONTROL_USB_CHARGER_DATA
    */
    } tEMControlReadReq;

#define EM_CONTROL_READ_REQ_LEN   (4*sizeof(uint8_t))


/* ----------------------------------------------------------------------- */
/* Message: EM_MONITORING_VOLTAGE_REQ - Valid from version 007.000         */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   trans_id;
    uint8_t   message_id;
    uint16_t  req_info;
    } tEM_BasicInfoTwoReq;

#define EM_BASIC_INFO_TWO_REQ_LEN   sizeof(tEM_BasicInfoTwoReq)


/* ----------------------------------------------------------------------- */
/* Message: EM_ADC_READ_REQ - Versions 007.000 - 007.012                   */
/* ----------------------------------------------------------------------- */

#if EM_ISI_MIN_VERSION(7,0) && !EM_ISI_MIN_VERSION(7,12)

typedef struct
    {
    uint8_t   trans_id;
    uint8_t   message_id;
    /* Channel number passed to the ADC library function adc_average_raw_read
    */
    uint8_t   req_info0;
    /* Number of reading passed to the ADC library function
       adc_average_raw_read
    */
    uint8_t   req_info1;
    } tEM_BasicInfoTwoByteReq;

#define EM_BASIC_TWO_BYTE_INFO_REQ_LEN   sizeof(tEM_BasicInfoTwoByteReq)

#endif /* EM_ISI_MIN_VERSION(7,0) && !EM_ISI_MIN_VERSION(7,12) */


/* ----------------------------------------------------------------------- */
/* Message: EM_ADC_READ_REQ - Valid from version 007.012                   */
/* ----------------------------------------------------------------------- */

#if EM_ISI_MIN_VERSION(7,12)

typedef struct
    {
    uint8_t   trans_id;
    uint8_t   message_id;
    /* Values from the constant table EM_ADC_CHANNEL_INFO */
    uint8_t   req_info0;
    /* Number of reading passed to the ADC library function
       adc_average_raw_read
    */
    uint8_t   req_info1;
    } tEM_BasicInfoTwoByteReq;

#define EM_BASIC_TWO_BYTE_INFO_REQ_LEN   sizeof(tEM_BasicInfoTwoByteReq)

#endif /* EM_ISI_MIN_VERSION(7,12) */


/* ----------------------------------------------------------------------- */
/* Message: EM_ADC_READ_RESP - Valid from version 007.000                  */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   trans_id;
    uint8_t   message_id;
    uint8_t   resp_status;  /* Values from the constant table EM_STATUS */
    uint8_t   reserved1;
    /* Return value passed from the ADC library function adc_average_raw_read
    */
    uint32_t  resp_data;
    } tEM_BasicInfoFourResp;

#define EM_BASIC_INFO_FOUR_RESP_LEN   sizeof(tEM_BasicInfoFourResp)


/* ----------------------------------------------------------------------- */
/* Message: EM_ADC_UNIT_LOCK_REQ - Valid from version 007.005              */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   trans_id;
    uint8_t   message_id;
    uint8_t   data0;   /* Values from the constant table EM_ADC_CHANNEL_INFO */
    uint8_t   data1;      /* Values from the constant table EM_ADC_LOCK_INFO */
    uint32_t  data2;
    } tEM_BasicInfoFourReq;

#define EM_BASIC_INFO_FOUR_REQ_LEN   sizeof(tEM_BasicInfoFourReq)


/* ----------------------------------------------------------------------- */
/* Message: EM_ADC_CAL_TUNE_REQ - Valid from version 007.009               */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   trans_id;
    uint8_t   message_id;
    /* Timer that controls interval of successive readings to determine if
       the trigger level has settled. If settled, measurement via
       adc_unit_read()/adc_raw_read() can be made.
    */
    uint16_t  state_transition_timer_value;
    /* Stop meassuring procedure if this timer is reached and send the now
       measured data.
    */
    uint16_t  timeout_timer_value;
    uint8_t   data0;
    uint8_t   sb_amount;
    /* Subblock list:
       EM_ADC_CAL_TUNE_REQ_DATA
    */
    uint8_t   sub_blocks[EM_ANY_SIZE];
    } tEM_AdcCalTuneReq;

#define EM_ADC_CAL_TUNE_REQ_LEN   (4*sizeof(uint8_t) + 2*sizeof(uint16_t))


/* ----------------------------------------------------------------------- */
/* Message: EM_ADC_CAL_TUNE_RESP - Valid from version 007.009              */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   trans_id;
    uint8_t   message_id;
    uint8_t   status;       /* Values from the constant table EM_STATUS */
    uint8_t   sb_amount;
    /* Subblock list:
       EM_ADC_CAL_TUNE_RESP_DATA
    */
    uint8_t   sub_blocks[EM_ANY_SIZE];
    } tEM_AdcCalTuneResp;

#define EM_ADC_CAL_TUNE_RESP_LEN   (4*sizeof(uint8_t))


/* ----------------------------------------------------------------------- */
/* Message: EM_PSM_EXTERNAL_WRITE_REQ - Valid from version 007.000         */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   trans_id;
    uint8_t   message_id;
    /* Values from the constant table EM_PSM_EXTERNAL_DEVICE_INFO */
    uint8_t   req_info0;
    uint8_t   reserved1;
    uint16_t  req_info1;
    uint8_t   reserved2;
    uint8_t   reserved3;
    } tEM_BasicInfoByteWordReq;

#define EM_BASIC_INFO_BYTE_WORD_REQ_LEN   sizeof(tEM_BasicInfoByteWordReq)


/* ----------------------------------------------------------------------- */
/* Message: EM_INFO_IND - Versions 007.000 - 007.003                       */
/* ----------------------------------------------------------------------- */

#if EM_ISI_MIN_VERSION(7,0) && !EM_ISI_MIN_VERSION(7,3)

typedef struct
    {
    uint8_t   trans_id;
    uint8_t   message_id;
    uint16_t  ind_info;  /* Values from the bitmask table EM_INDICATION_INFO */
    } tEM_Info_Ind;

#define EM_INFO_IND_LEN   sizeof(tEM_Info_Ind)

#endif /* EM_ISI_MIN_VERSION(7,0) && !EM_ISI_MIN_VERSION(7,3) */


/* ----------------------------------------------------------------------- */
/* Message: EM_INFO_IND - Valid from version 007.003                       */
/* ----------------------------------------------------------------------- */

#if EM_ISI_MIN_VERSION(7,3)

typedef struct
    {
    uint8_t   trans_id;
    uint8_t   message_id;
    uint16_t  ind_info;  /* Values from the bitmask table EM_INDICATION_INFO */
    uint8_t   reserved1;
    uint8_t   reserved2;
    uint8_t   reserved3;
    uint8_t   sb_amount;
    /* Subblock list:
       EM_CHARGER_STATUS_DATA
       EM_CHARGING_MODE_DATA
       EM_CHARGING_STATE_DATA
       EM_MONITORING_BATT_BARS_DATA
       EM_MONITORING_BATT_POWER_DATA
    */
    } tEM_Info_Ind;

#define EM_INFO_IND_LEN   (6*sizeof(uint8_t) + sizeof(uint16_t))

#endif /* EM_ISI_MIN_VERSION(7,3) */


/* ----------------------------------------------------------------------- */
/* Message: EM_TEMPERATURE_QUERY_REQ - Valid from version 007.010          */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   trans_id;
    uint8_t   message_id;
    uint8_t   data0;
    uint8_t   data1;
    } tEM_TemperatureReq;

#define EM_TEMPERATURE_REQ_LEN   sizeof(tEM_TemperatureReq)


/* ----------------------------------------------------------------------- */
/* Message: EM_SOS_EVENT_NTF - Valid from version 007.015                  */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   trans_id;
    uint8_t   message_id;
    uint8_t   ntf_event; /* Values from the constant table EM_SOS_EVENT_INFO */
    uint8_t   reserved1;
    } tEM_Sos_Event_Ntf;

#define EM_SOS_EVENT_NTF_LEN   sizeof(tEM_Sos_Event_Ntf)


/* ----------------------------------------------------------------------- */
/* Message: EM_MEASUREMENT_REQ - Valid from version 008.006                */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   trans_id;
    uint8_t   message_id;
    /* Values from the constant table EM_MEASUREMENT_ACTION */
    uint8_t   measurement_action;
    uint8_t   sb_amount;
    /* Only the first subblock is analysed for sampling period,
       EM_MEASUREMENT_NTF will contain all EM_MEASUREMENT_TYPEs
       Subblock list:
       EM_MEASUREMENT_TYPE
    */
    uint8_t   sub_blocks[EM_ANY_SIZE];
    } tEM_Measurement_Req;

#define EM_MEASUREMENT_REQ_LEN   (4*sizeof(uint8_t))

/* Only the header part is included in the message length. The sub_blocks
   array is only used for indexing into the sub-blocks, so sizeof
   (tEM_RT_Measurement_Req) cannot be used for message memory allocation          */

/* ----------------------------------------------------------------------- */
/* Message: EM_MEASUREMENT_RESP - Valid from version 008.006               */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   trans_id;
    uint8_t   message_id;
    /* Values from the constant table EM_MEASUREMENT_RESULT */
    uint8_t   measurement_result;
    uint8_t   fill1;
    uint32_t  time;         /* MCU OS timestamp (32bit wraparound counter) */
    } tEM_Measurement_Resp;

#define EM_MEASUREMENT_RESP_LEN   sizeof(tEM_Measurement_Resp)


/* ----------------------------------------------------------------------- */
/* Message: EM_MEASUREMENT_NTF - Valid from version 008.006                */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   trans_id;
    uint8_t   message_id;
    uint8_t   fill1;
    uint8_t   sb_amount;
    /* Subblock list:
       EM_MEASUREMENT
    */
    uint8_t   sub_blocks[EM_ANY_SIZE];
    } tEM_Measurement_Ntf;

#define EM_MEASUREMENT_NTF_LEN   (4*sizeof(uint8_t))


/* ----------------------------------------------------------------------- */
/* Message: EM_SELFTEST_REQ - Valid from version 008.007                   */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   trans_id;
    uint8_t   message_id;
    uint8_t   selftest_id;  /* Values from the constant table EM_SELFTEST_ID */
    uint8_t   reserved1;
    } tEM_Selftest_Req;

#define EM_SELFTEST_REQ_LEN   sizeof(tEM_Selftest_Req)

/* Only the header part is included in the message length. The sub_blocks
   array is only used for indexing into the sub-blocks, so sizeof
   (tEM_Selftest_Req) cannot be used for message memory allocation          */

/* ----------------------------------------------------------------------- */
/* Message: EM_SELFTEST_RESP - Valid from version 008.007                  */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   trans_id;
    uint8_t   message_id;
    /* Values from the constant table EM_SELFTEST_RESULT */
    uint8_t   selftest_result;
    uint8_t   fill1;
    } tEM_Selftest_Resp;

#define EM_SELFTEST_RESP_LEN   sizeof(tEM_Selftest_Resp)


/* ----------------------------------------------------------------------- */
/* Message: EM_ME_STATE_REQ - Valid from version 008.009                   */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   trans_id;
    uint8_t   message_id;
    /* Values from the constant table EM_ME_STATE_ACTION */
    uint8_t   mestate_onoff;
    uint8_t   reserved1;
    } tEM_MeState_Req;

#define EM_ME_STATE_REQ_LEN   sizeof(tEM_MeState_Req)


/* ----------------------------------------------------------------------- */
/* Message: EM_ME_STATE_RESP - Valid from version 008.009                  */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   trans_id;
    uint8_t   message_id;
    /* Values from the constant table EM_ME_STATE_RESULT */
    uint8_t   mestate_result;
    uint8_t   fill1;
    } tEM_MeState_Resp;

#define EM_ME_STATE_RESP_LEN   sizeof(tEM_MeState_Resp)


/* ----------------------------------------------------------------------- */
/* Message: EM_ADC_CHIPSET_CAL_CALCULATE_REQ - Valid from version 008.024  */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   trans_id;
    uint8_t   message_id;
    uint16_t  option;    /* Values from the bitmask table EM_CHIPSET_OPT_CAL */
    uint8_t   sb_amount;
    uint8_t   reserved1[3];
    /* Subblock list:
       EM_ADC_CHIPSET_CAL_CALCULATE_REQ_DATA
    */
    uint8_t   sub_blocks[EM_ANY_SIZE];
    } tEM_AdcChipsetCalCalculateReq;

#define EM_ADC_CHIPSET_CAL_CALCULATE_REQ_LEN   (6*sizeof(uint8_t) + \
        sizeof(uint16_t))


/* ----------------------------------------------------------------------- */
/* Message: EM_ADC_CHIPSET_CAL_CALCULATE_RESP - Valid from version 008.024 */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   trans_id;
    uint8_t   message_id;
    uint8_t   status;       /* Values from the constant table EM_STATUS */
    uint8_t   sb_amount;
    /* Subblock list:
       EM_ADC_CHIPSET_CAL_READ_RESP_DATA
    */
    uint8_t   sub_blocks[EM_ANY_SIZE];
    } tEM_AdcChipsetCalCalculateResp;

#define EM_ADC_CHIPSET_CAL_CALCULATE_RESP_LEN   (4*sizeof(uint8_t))


/* ----------------------------------------------------------------------- */
/* Message: EM_ADC_CHIPSET_CAL_READ_REQ - Valid from version 008.024       */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   trans_id;
    uint8_t   message_id;
    uint8_t   sb_amount;
    uint8_t   reserved1;
    /* Subblock list:
       EM_ADC_CHIPSET_CAL_READ_REQ_DATA
    */
    uint8_t   sub_blocks[EM_ANY_SIZE];
    } tEM_AdcChipsetCalReadReq;

#define EM_ADC_CHIPSET_CAL_READ_REQ_LEN   (4*sizeof(uint8_t))


/* ----------------------------------------------------------------------- */
/* Message: EM_ADC_CHIPSET_CAL_READ_RESP - Valid from version 008.024      */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   trans_id;
    uint8_t   message_id;
    uint8_t   status;       /* Values from the constant table EM_STATUS */
    uint8_t   sb_amount;
    /* Subblock list:
       EM_ADC_CHIPSET_CAL_READ_RESP_DATA
    */
    uint8_t   sub_blocks[EM_ANY_SIZE];
    } tEM_AdcChipsetCalReadResp;

#define EM_ADC_CHIPSET_CAL_READ_RESP_LEN   (4*sizeof(uint8_t))


/* ----------------------------------------------------------------------- */
/* Message: EM_ADC_CHIPSET_CAL_STORE_REQ - Valid from version 008.024      */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   trans_id;
    uint8_t   message_id;
    uint8_t   action; /* Values from the constant table EM_CHIPSET_CAL_STORE */
    uint8_t   reserved1;
    } tEM_AdcChipsetCalStoreReq;

#define EM_ADC_CHIPSET_CAL_STORE_REQ_LEN   sizeof(tEM_AdcChipsetCalStoreReq)


/* ----------------------------------------------------------------------- */
/* Message: EM_ADC_CHIPSET_CAL_STORE_RESP - Valid from version 008.024     */
/* ----------------------------------------------------------------------- */

typedef struct
    {
    uint8_t   trans_id;
    uint8_t   message_id;
    uint8_t   status;       /* Values from the constant table EM_STATUS */
    uint8_t   reserved1;
    } tEM_AdcChipsetCalStoreResp;

#define EM_ADC_CHIPSET_CAL_STORE_RESP_LEN   \
        sizeof(tEM_AdcChipsetCalStoreResp)




/* EM ISI message structure definition */
typedef tEM_BasicInfoReq          tEMChargerInfoReq;
typedef tEM_BasicInfoResp         tEMChargerInfoResp;
typedef tEM_Write_Req             tEMControlWriteReq;
typedef tEM_BasicInfoOneResp      tEMControlWriteResp;
typedef tEM_BasicInfoResp         tEMControlReadResp;
typedef tEM_BasicInfoTwoReq       tEMBatteryInfoReq;
typedef tEM_BasicInfoResp         tEMBatteryInfoResp;
typedef tEM_BasicInfoReq          tEMChargingInfoReq;
typedef tEM_BasicInfoResp         tEMChargingInfoResp;
typedef tEM_BasicInfoReq          tEMMonitoringInfoReq;
typedef tEM_BasicInfoResp         tEMMonitoringInfoResp;
typedef tEM_BasicInfoTwoReq       tEMMonitoringVoltageReq;
typedef tEM_BasicInfoOneResp      tEMMonitoringVoltageResp;
typedef tEM_Info_Ind              tEMMonitoringVoltageInd;
typedef tEM_BasicInfoTwoByteReq   tEMAdcReadReq;
typedef tEM_BasicInfoFourResp     tEMAdcReadResp;
typedef tEM_BasicInfoTwoByteReq   tEMAdcUnitReq;
typedef tEM_BasicInfoFourResp     tEMAdcUnitResp;
typedef tEM_BasicInfoReq          tEMPsmCsStateWriteReq;
typedef tEM_BasicInfoOneResp      tEMPsmCsStateWriteResp;
typedef tEM_BasicInfoReq          tEMPsmCsProtocolWriteReq;
typedef tEM_BasicInfoOneResp      tEMPsmCsProtocolWriteResp;
typedef tEM_BasicInfoReq          tEMPsmCsIdleActivityReq;
typedef tEM_BasicInfoOneResp      tEMPsmCsIdleActivityResp;
typedef tEM_BasicInfoTwoByteReq   tEMPsmInternalWriteReq;
typedef tEM_BasicInfoOneResp      tEMPsmInternalWriteResp;
typedef tEM_BasicInfoByteWordReq  tEMPsmExternalWriteReq;
typedef tEM_BasicInfoOneResp      tEMPsmExternalWriteResp;
typedef tEM_BasicInfoReq          tEMPsmSwFeatureReq;
typedef tEM_BasicInfoOneResp      tEMPsmSwFeatureResp;
typedef tEM_BasicInfoTwoReq       tEMPsmReadReq;
typedef tEM_BasicInfoResp         tEMPsmReadResp;
typedef tEM_Info_Ind              tEMInfoInd;
typedef tEM_Write_Req             tEMAdcCalWriteReq;
typedef tEM_BasicInfoResp         tEMAdcCalWriteResp;
typedef tEM_BasicInfoTwoByteReq   tEMAdcCalReadReq;
typedef tEM_BasicInfoResp         tEMAdcCalReadResp;
typedef tEM_BasicInfoFourReq      tEMAdcUnitLockReq;
typedef tEM_BasicInfoResp         tEMAdcUnitLockResp;
typedef tEM_AdcCalTuneReq         tEMAdcCalTuneReq;
typedef tEM_AdcCalTuneResp        tEMAdcCalTuneResp;
typedef tEM_TemperatureReq        tEMTemperatureReq;
typedef tEM_BasicInfoFourResp     tEMTemperatureResp;
typedef tEM_BasicInfoFourResp     tEMTemperatureInd;
typedef tEM_BasicInfoTwoByteReq   tEMPowerReq;
typedef tEM_BasicInfoOneResp      tEMPowerResp;
typedef tEM_Write_Req             tEMSosEventReq;
typedef tEM_BasicInfoOneResp      tEMSosEventResp;
typedef tEM_Sos_Event_Ntf         tEMSosEventNtf;

/* EM ISI message sub-block structure definition */
typedef tEM_SbByteData            tEMChargerStatusData;
typedef tEM_SbByteData            tEMChargerTypeData;
typedef tEM_SbWordData            tEMChargerVoltageData;
typedef tEM_SbWordData            tEMChargerCurrentData;
typedef tEM_SbByteData            tEMControlDisableChargingData;
typedef tEM_SbByteData            tEMControlPauseChargingData;
typedef tEM_SbByteData            tEMControlHwVoltLimitData;
typedef tEM_SbByteData            tEMControlTxVoltLimitData;
typedef tEM_SbByteData            tEMControlBackupBatteryData;
typedef tEM_Sb2ByteData           tEMControlPwmData;
typedef tEM_SbWordData            tEMBatteryTypeData;
typedef tEM_SbWordData            tEMBatteryNominalCapaData;
typedef tEM_SbWordData            tEMBatteryTempData;
typedef tEM_SbWordData            tEMBatteryVoltageData;
typedef tEM_SbWordData            tEMBatteryVoltageTxOnData;
typedef tEM_SbWordData            tEMBatteryVoltageTxOffData;
typedef tEM_SbWordData            tEMBatteryVoltagePwmOnData;
typedef tEM_SbWordData            tEMBatteryVoltagePwmOffData;
typedef tEM_SbWordData            tEMBatteryGenerationData;
typedef tEM_SbByteData            tEMChargingStateData;
typedef tEM_SbByteData            tEMChargingModeData;
typedef tEM_SbByteData            tEMMonitoringBattPowerData;
typedef tEM_Sb2ByteData           tEMMonitoringBattBarsData;
typedef tEM_SbWordData            tEMMonitoringBattCapaData;
typedef tEM_SbWordData            tEMMonitoringBattTimeData;
typedef tEM_SbWordData            tEMPsmBatteryCurrentData;
typedef tEM_SbWordData            tEMPsmPhoneCurrentData;
typedef tEM_SbWordData            tEMPsmDischargeAmountData;
typedef tEM_SbByteData            tEMPsmCsActiveStateData;
typedef tEM_SbByteData            tEMPsmCsActiveProtocolData;
typedef tEM_SbByteData            tEMPsmCsIdleActivityData;
typedef tEM_SbWordData            tEMPsmBatmon4PhoneStateData;
typedef tEM_SbWordData            tEMPsmSwFeatureCounterData;
typedef tEM_SbDwordData           tEMPsmActivityData;
typedef tEM_SbWordData            tEMBatteryVoltageShChkData;
typedef tEM_Sb2Byte2DwordData     tEMAdcCalGenData;
typedef tEM_Sb2Byte4WordData      tEMAdcCalLogData;
typedef tEM_Sb2ByteData           tEMMonitoringBattAudioBarsData;
typedef tEM_AdcCalTuneReqData     tEMAdcCalTuneReqData;
typedef tEM_AdcCalTuneRespData    tEMAdcCalTuneRespData;
typedef tEM_SbWordData            tEMSosTimerEventData;
typedef tEM_Sb2Byte4WordData      tEMADCCalAlgData;
typedef tEM_SbWordData            tEMMonitoringBattPercData;



/* ----------------------------------------------------------------------- */
/* Notes                                                                   */
/* ----------------------------------------------------------------------- */
/*
   /1/   Autogeneration Process
         Lotus Notes Database: Engine TEC DocMan
         Document Number:      DSJ00311
         Filename:             autogen_proc.doc

   /2/   ISI Server Specification Documentation Guidelines
         Part:      ISI:INSTRUCTIONS.BASE
         Item name: ISI:DOCUMENTATION_GUIDELINES.BASE-MISC
         Workset:   ISI:WS_ISI
         Filename:  i_docgui.doc

   /3/   ISI General Information
         Part:      ISI:INSTRUCTIONS.BASE
         Item name: ISI:GENERAL_INFORMATION.BASE-MISC
         Workset:   ISI:WS_ISI
         Filename:  i_geninf.doc

   /4/   ISI Common Message Descriptions
         Continuus Database: ou1gif
         Continuus Project:  GIF_SPECS-ou1gif#browse
         Directory path:     GIF_SPECS/CoreSW
         Filename:           i_comm_m.html

   /5/   ISI Common Feature Descriptions
         Continuus Database: ou1gif
         Continuus Project:  GIF_SPECS-ou1gif#browse
         Directory path:     GIF_SPECS/CoreSW
         Filename:           i_comm_fp.doc

   /6/   ISI Energy Management (EM) Server Feature & Message Descriptions
         Continuus Database: ou1gif
         Continuus Project:  GIF_SPECS-ou1gif#browse
         Directory path:     GIF_SPECS/CoreSW
         Filename:           i_em_fm.html

   /7/   ISI Energy Management (EM) Server Protocol Descriptions
         Continuus Database: ou1gif
         Continuus Project:  GIF_SPECS-ou1gif#browse
         Directory path:     GIF_SPECS/CoreSW
         Filename:           i_em_p.doc

   /8/   EM SW ADC Calibration specification
         Continuus Database: co1core
         Continuus Project:  Core_SW_Cph
         Directory path:     Core_SW_Cph/Components/EM_Server
         Filename:           em_sw_adc_calibration_specification.doc
         Instance:           co_core#1

   /9/   EM SW Integration Guide
         Continuus Database: co1core
         Continuus Project:  Core_SW_Cph
         Directory path:     Core_SW_Cph/Components/EM_Server
         Filename:           em_sw_int_guide.doc
         Instance:           co_core#1

   /10/  Common R&D Display Data and Layout
         Part:      SW_TESTNG:COMMON_SPEC.BASE
         Item name: RD_TEST_DISPLAY_SPEC.BASE
         Workset:   SW_TESTING_43UPGRADE
         Filename:  rd_display_spec.doc
*/


#endif /* _EM_ISI_H */
