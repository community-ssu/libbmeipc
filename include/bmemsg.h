/**
   @file bmemsg.h

   @brief BME IPC message definitions
   <p>
   Copyright (C) 2010 Nokia Corporation.

   @author Markus Lehtonen <markus.lehtonen@nokia.com>
   @author Matti Halme <matti.halme@nokia.com>

   This file is part of libbme.

   Libbme is free software; you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License
   version 2.1 as published by the Free Software Foundation.

   Libbme is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with libbme. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef BMEMSG_H
#define BMEMSG_H

#include <stdint.h>

#include "bmeisa.h"

#ifndef TRUE
 #define TRUE          1
#endif

#ifndef EM_MON_ADC_LOCK_SUPPORT
 #define EM_MON_ADC_LOCK_SUPPORT       TRUE
#endif

#ifndef EM_FEA_FAST_ADC_ALIGNMENT
 #define EM_FEA_FAST_ADC_ALIGNMENT     TRUE
#endif

#ifndef EM_FTD_ENABLE
 #define EM_FTD_ENABLE                        TRUE
#endif

typedef uint8_t adc_channels_t;

/* Generic constants */
#define BME_INFO_NOT_KNOWN_YET        0x00
#define BME_INFO_NOT_SUPPORTED        0xFFFF
#define BME_INFO_NO_SUPPORT           0xFF

/* Battery info flags */
#define BME_BATTERY_TYPE              0x0001
#define BME_BATTERY_NOMINAL_CAPA      0x0002
#define BME_BATTERY_TEMP              0x0004
#define BME_BATTERY_VOLTAGE           0x0008
#define BME_BATTERY_VOLTAGE_TX_ON     0x0010
#define BME_BATTERY_VOLTAGE_TX_OFF    0x0020
#define BME_BATTERY_VOLTAGE_PWM_ON    0x0040
#define BME_BATTERY_VOLTAGE_PWM_OFF   0x0080
#define BME_BATTERY_GENERATION        0x0100
#define BME_BATTERY_VOLTAGE_SH_CHK    0x0200

/* Indication info flags */
#define BME_IND_CHARGER_STATE_CHANGE      0x0001
#define BME_IND_BATTERY_STATE_CHANGE      0x0002
#define BME_IND_CHARGING_STATE_CHANGE     0x0004
#define BME_IND_MONITORING_STATE_CHANGE   0x0008

/*
 * Constants below are enumerated explicitly to keep BME API consistent
 */
enum bme_info_battery_type_e {
  BME_INFO_BATTERY_TYPE_NONE    = 0,
  BME_INFO_BATTERY_TYPE_SERVICE = 1,
  BME_INFO_BATTERY_TYPE_NICKEL  = 2,
  BME_INFO_BATTERY_TYPE_LI4V1   = 3,
  BME_INFO_BATTERY_TYPE_LI4V2   = 4
};

enum bme_info_charger_status_e {
  BME_INFO_CHARGER_STATUS_DISCONNECTED  = 0,
  BME_INFO_CHARGER_STATUS_CONNECTED     = 1
};

enum bme_info_ind_charging_state_e {
  BME_INFO_CHARGING_STATE_OFF         = 1,
  BME_INFO_CHARGING_STATE_ON          = 2,
  BME_INFO_CHARGING_STATE_ALMOST_FULL = 3,
  BME_INFO_CHARGING_STATE_FULL        = 4,
  BME_INFO_CHARGING_STATE_ERROR       = 5,
  BME_INFO_CHARGING_STATE_CONTINUE    = 6
};

/*
 * Message ID's
 */
#define BME_BATTERY_INFO_REQ    0x06
#define BME_MONITOR_INFO_REQ    0x0a
#define BME_INFO_IND            0x21

/*** Client request and reply messages ****************************************/

/* Measurement mode definitions */
typedef enum {
  EM_SRV_MEASUREMENT_MODE_STOPPED,
  EM_SRV_MEASUREMENT_MODE_250MS,
  EM_SRV_MEASUREMENT_MODE_1S,
  EM_SRV_MEASUREMENT_MODE_5S
} EM_SRV_MEASUREMENT_MODE_TYPE;

/* Measurement action request element */
struct emsg_measurement_req_elem {
    uint8_t	type;
    uint8_t	period;
};

/* Measurement action request */
struct emsg_measurement_req {
    uint16_t	type, subtype;
    uint32_t	measurement_action;
    uint8_t	channel_count;
    struct	emsg_measurement_req_elem data[0];
};

/* Charger info request */
struct emsg_charger_info_req {
    uint16_t	type, subtype;
    uint32_t	flags;
};

/* Charger info reply */
struct emsg_charger_info_reply {
    uint32_t	zero;
    uint32_t	flags;
    uint8_t	status;
    uint8_t	charger_type;
    uint16_t	voltage;
    uint16_t	current;
    uint16_t	reserved;
};

union emsg_charger_info {
    struct emsg_charger_info_req	request;
    struct emsg_charger_info_reply	reply;
};


/* Control write request */
struct emsg_control_write_req {
    uint16_t			type, subtype;
    em_cha_ctrl_info_type	ctrl;
};


/* Control read request */
struct emsg_control_read_req {
    uint16_t	type, subtype;
    uint32_t	flags;
    em_cha_ctrl_info_type	ctrl;
};

/* Control read reply */
struct emsg_control_read_reply {
    uint32_t			zero;
    em_cha_ctrl_info_type	ctrl;
};

union emsg_control_read {
    struct emsg_control_read_req	request;
    struct emsg_control_read_reply	reply;
};

/**
 * Battery info request
 */
struct emsg_battery_info_req {
  uint16_t type; /**< BME_BATTERY_INFO_REQ */
  uint16_t subtype;
  uint32_t flags;
} __attribute__((packed));

/**
 * Battery info reply
 */
struct emsg_battery_info_reply {
  uint32_t zero;
  uint32_t flags;
  uint16_t bat_type;        /* bme_info_battery_type_e */
  uint16_t nominal_capa;
  uint16_t temp;            /* Kelvin */
  uint16_t voltage;
  uint16_t voltage_tx_on;
  uint16_t voltage_tx_off;
  uint16_t voltage_pwm_on;
  uint16_t voltage_pwm_off;
  uint16_t generation;
  uint16_t voltage_sh_chk;
} __attribute__((packed));

union emsg_battery_info {
  struct emsg_battery_info_req request;
  struct emsg_battery_info_reply reply;
};

/* Charging info request */
struct emsg_charging_info_req {
    uint16_t	type, subtype;
    uint32_t	flags;
};

/* Charging info reply */
struct emsg_charging_info_reply {
    uint32_t	zero;
    uint32_t	flags;
    uint8_t	state;
    uint8_t	mode;
    uint16_t	reserved;
};

union emsg_charging_info {
    struct emsg_charging_info_req	request;
    struct emsg_charging_info_reply	reply;
};


/* Monitoring info request */
struct emsg_monitoring_info_req {
    uint16_t	type, subtype;
    uint32_t	flags;
};

/* Monitoring info reply */
struct emsg_monitoring_info_reply {
    uint32_t	zero;
    uint32_t	flags;
    uint8_t	batt_power;
    uint8_t	reserved;
    uint8_t	batt_max_num_bars;
    uint8_t	batt_bars;
    uint16_t	batt_capa;
    uint16_t	batt_time;
    uint8_t	batt_max_audio_bars;
    uint8_t	batt_audio_bars;
    uint16_t	reserved2;
};

union emsg_monitoring_info {
    struct emsg_monitoring_info_req	request;
    struct emsg_monitoring_info_reply	reply;
};


/* Set monitoring voltage request */
struct emsg_monitoring_voltage_req {
    uint16_t	type, subtype;
    uint16_t	voltage_level;
    uint16_t	reserved;
};


/* ADC read request */
struct emsg_adc_read_req {
    uint16_t	type, subtype;
    uint8_t	channel;
    uint8_t	num_reads;
    uint16_t	reserved;
};

/* ADC read reply */
struct emsg_adc_read_reply {
    uint32_t	zero;
    int32_t	result;
};

union emsg_adc_read {
    struct emsg_adc_read_req	request;
    struct emsg_adc_read_reply	reply;
};


/* ADC unit read request */
struct emsg_adc_unit_req {
    uint16_t	type, subtype;
    uint8_t	channel;
    uint8_t	num_reads;
    uint16_t	reserved;
};

/* ADC unit read reply */
struct emsg_adc_unit_reply {
    uint32_t	zero;
    int32_t	result;
};

union emsg_adc_unit {
    struct emsg_adc_unit_req	request;
    struct emsg_adc_unit_reply	reply;
};


/* Write ADC calibration data request */
struct emsg_adc_cal_write_req {
    /* Fixed part, must be sent first and atomically */
    uint16_t	type, subtype;
    uint8_t	num_data;
    uint8_t	action;
    /* num_data elements follow */
};


/* Read ADC calibration data request */
struct emsg_adc_cal_read_req {
    uint16_t	type, subtype;
    uint8_t	action;
    /* The channel number may be also one of "pseudo-channel" IDs:
       EM_ADC_MAIN_CAL (to get calibration data for AD converter), or
       EM_ADC_ALL_CAL (to get calibration data for all channels */
    uint8_t	channel;
};

/* Structure of 'ADC channel calibration data' element */
struct adc_chan_cal_data_elem {
    em_hal_adc_cal_data_str_t	cdata;
    uint8_t		alg;
    uint8_t		reserved;
    uint16_t		parameter1;		/* Usually reference_voltage */
};

/* Read ADC calibration data reply */
struct emsg_adc_cal_read_reply {
    uint8_t	num_data;
    /* num_data elements follow */
    struct adc_chan_cal_data_elem accd[0];
};

union emsg_adc_cal_read {
    struct emsg_adc_cal_read_req	request;
    struct emsg_adc_cal_read_reply	reply;
};


/* PSM feature request */
struct emsg_psm_feature_req {
    uint16_t	type, subtype;
    uint8_t	state;
};


/* PSM read request */
struct emsg_psm_read_req {
    uint16_t	type, subtype;
    uint32_t	flags;
};

/* PSM read reply */
struct emsg_psm_read_reply {
    uint32_t	zero;
    uint32_t	flags;
    uint16_t	bat_current;
    uint16_t	phone_current;
    uint16_t	discharge_amount;
    uint8_t	cs_act_state;
    uint8_t	cs_act_protocol;
    uint8_t	cs_idle_activity;
    uint8_t	reserved;
    uint16_t	batmon4_phone_state;
    uint16_t	feature_counter;
    uint32_t	activity;
};

union emsg_psm_read {
    struct emsg_psm_read_req	request;
    struct emsg_psm_read_reply	reply;
};

/* PSM internal write request */
struct emsg_psm_internal_write_req {
    uint16_t	type, subtype;
    uint8_t	device;
    uint8_t	activity_level;
};

#if (EM_MON_ADC_LOCK_SUPPORT == TRUE)
/* Set/lock ADC unit calibration data request */
struct emsg_srv_adc_unit_lock_req {
    uint16_t	type, subtype;
    adc_channels_t channel;
    uint8_t	action;
    int16_t	value;
};

#endif

#if (EM_FEA_FAST_ADC_ALIGNMENT == TRUE)

/* ADC tuning request element */
struct adc_tune_req_elem {
    uint8_t	chan_id;
    uint8_t	num_samples;
    int16_t	trigger_level;
};

/* Start ADC tuning request */
struct emsg_adc_tune_req {
    uint16_t	type, subtype;
    uint8_t	reserved;
    uint8_t	num_states;
    uint16_t	state_trans_timer_val;
    uint16_t	timeout_timer_val;
    /* num_states elements follow */
    struct adc_tune_req_elem reqarr[0];
};

/* ADC tuning reply element */
struct adc_tune_reply_elem {
    uint16_t	status;
    uint16_t	chan_id;
    int16_t	meas_val;
};

/* ADC tuning reply */
struct emsg_adc_tune_reply {
    uint8_t	num_blocks;
    /* num_blocks elements follow */
    struct adc_tune_reply_elem replyarr[0];
};

union emsg_adc_tune {
    struct emsg_adc_tune_req	request;
    struct emsg_adc_tune_reply	reply;
};

#endif


#if (EM_FEA_THERMOMETER_ENABLED == TRUE)
/* Thermo request */
struct emsg_thermo_req {
    uint16_t	type, subtype;
};

/* Thermo reply */
struct emsg_thermo_reply {
    uint32_t	zero;
    uint32_t	result;
    uint8_t	status;
    uint8_t	reserved[3];
};

union emsg_thermo {
    struct emsg_thermo_req	request;
    struct emsg_thermo_reply	reply;
};
#endif


#if (EM_FEA_POWER_MANAGEMENT_ENABLED == TRUE)
/* Power request */
struct emsg_power_req {
    uint16_t		type, subtype;
    uint8_t		consumer;
    uint8_t		state;
    uint16_t		reserved;
};

/* Power reply */
struct emsg_power_reply {
    uint32_t	zero;
    uint8_t	status;
    uint8_t	reserved[3];
};

union emsg_power {
    struct emsg_power_req	request;
    struct emsg_power_reply	reply;
};
#endif


#if (EM_FTD_ENABLE == TRUE)

/* FTD information request */
struct emsg_ftd_data_req {
    uint16_t	type, subtype;
    uint32_t	flags;
};

/* FTD information reply */
struct emsg_ftd_data_reply {
    uint32_t	zero;
    uint32_t	flags_reserved;
    uint32_t	result;
};

/* FTD bulk information data reply */
struct emsg_ftd_bulk_data_reply {
   uint32_t	zero;
    uint32_t	flags;
    uint8_t	status;
    uint16_t	instant_v_bat;
    uint32_t	remain_stby_mins;
    uint16_t	no_bat_low_warnings;
    uint8_t	misc_flags_mask1;
    uint16_t	check_v_bat;
    uint16_t	warn_interval_cnt;
    uint16_t	dmf_out_voltage;
    uint16_t	bm4_init_v_bat;
    uint16_t	time_per_bar_min;
    uint16_t	v_bat_1st_bat_low;
    uint32_t	avg_phone_curr_ua;
    int16_t	last_cha_amount;
    uint16_t	lowest_v_txoff;
    uint16_t	lowest_v_txon;
    int16_t	largest_dv;
    uint8_t	batt_bar_log_mask;
    uint8_t	prev_batt_bar_lev;
    uint8_t	batt_low_reason;
    /* Added 21.6.05 */
    uint8_t	cs_state;
    uint8_t	num_bat_bars;
    uint16_t	bat_type;
    int16_t	bat_temp;
    uint16_t	bat_capacity;
    uint16_t	bat_imp;
    uint16_t	bat_full_thres;
    uint16_t	bat_low_thres;
    uint16_t	mon_alg_adj;
    uint16_t	mon_param_errors;
    uint32_t	curr_mon_est2;
};

/* FTD bulk information data2 reply */
struct emsg_ftd_bulk_data2_reply {
    uint32_t	zero;
    uint32_t	flags;
    uint32_t	elapsed_time;
    uint16_t	txoff_volt;
    uint16_t	txon_volt;
    uint8_t	power_state;
    uint8_t	mon_flags2;
    uint8_t	mon_flags3;
    uint8_t	cha_method;
    uint16_t	last_v_model_mv;
    uint16_t	phi0_mv;
    int16_t	delta_phi0_mv;
    uint8_t	cha_mode;
    uint8_t	prev_cha_mode;
    uint8_t	chr_type;
    uint8_t	prev_chr_type;
    int16_t	cha_inst_bat_volt;
    uint8_t	num_chr_checks;
    uint8_t	chr_rec_state;
    uint32_t	inst_chr_current;
    uint16_t	cha_time;
    uint16_t	avg_chr_volt;
    uint16_t	chr_current;
    uint8_t	bat_full;
    uint8_t	hw_pwm_val;
    uint8_t	sw_pwm_val;
    uint8_t	reserved1;
    int16_t	vbat_osv;
    int16_t	vbat_csv;
};

/* FTD bulk information data3 reply */
struct emsg_ftd_bulk_data3_reply {
    uint32_t	zero;
    uint32_t	flags;
    uint16_t	conf_bat_footprint;
    uint16_t	conf_min_current;
    uint16_t	conf_bat_safety_level;
    uint16_t	conf_bat_empty_level;
    uint8_t	conf_bat_bars;    
};

union emsg_ftd_data {
    struct emsg_ftd_data_req	request;
    struct emsg_ftd_data_reply	reply;
};

union emsg_ftd_bulk_data {
    struct emsg_ftd_data_req		request;
    struct emsg_ftd_bulk_data_reply	reply;
    struct emsg_ftd_bulk_data2_reply	reply2;
    struct emsg_ftd_bulk_data3_reply	reply3;
};

#endif


/* Test mode request */
struct auxmsg_test_mode_req {
    uint16_t	type, subtype;
    uint8_t	onoff;
};

/* USB charge mode request */
struct auxmsg_usb_charge_mode_req {
    uint16_t	type, subtype;
    uint8_t	mode;
    uint8_t	reserved[3];
};

/* This union combines all possible messages */
union bme_ext_messages {
    union emsg_charger_info	charger_info;
    union emsg_charging_info	charging_info;
    union emsg_battery_info	battery_info;
    union emsg_monitoring_info	monitoring_info;
    struct emsg_monitoring_voltage_req set_monitoring_voltage;
    union emsg_control_read	ctrl_read;
    struct emsg_control_write_req ctrl_write;
    union emsg_adc_read		adc_raw_read;
    union emsg_adc_unit		adc_unit_read;
    union emsg_adc_cal_read	adc_cal_read;
    struct emsg_adc_cal_write_req adc_cal_write;
    struct emsg_psm_feature_req psm_feature;
    union emsg_psm_read		psm_read;
    struct emsg_psm_internal_write_req psm_write;
#if (EM_MON_ADC_LOCK_SUPPORT == TRUE)
    struct emsg_srv_adc_unit_lock_req adc_unit_lock;
#endif
#if (EM_FEA_FAST_ADC_ALIGNMENT == TRUE)
    union emsg_adc_tune		adc_tune;
#endif
#if (EM_FEA_POWER_MANAGEMENT_ENABLED == TRUE)
    union emsg_power		power;
#endif
#if (EM_FEA_THERMOMETER_ENABLED == TRUE)
   union emsg_thermo		thermo;
#endif
#if (EM_FTD_ENABLE == TRUE)
    union emsg_ftd_bulk_data	ftd_data;
#endif
    struct auxmsg_test_mode_req	aux_test;
    struct emsg_measurement_req measurement;
    struct auxmsg_usb_charge_mode_req usb_charge_mode;
};

/*** Indication messages ******************************************************/

/**
 * Monitor info request
 */
struct emsg_monitor_info_req {
  uint16_t type; /**< BME_MONITOR_INFO_REQ */
  uint16_t subtype;
  uint32_t flags;
} __attribute__((packed));

/**
 * Monitor info reply
 */
struct emsg_monitor_info_reply {
  uint32_t zero;
  uint32_t flags;
  uint16_t unk8;
  uint8_t  batt_max_num_bars;
  uint8_t  batt_bars_data;
  uint16_t capa_remaining;    /* mAh */
  uint16_t unk14;
  uint16_t unk16;
  uint16_t unk18;
} __attribute__((packed));

/**
 * EM info indication
 */
struct emsg_info_ind {
  uint16_t type;
  uint16_t subtype;
  uint32_t flags;
  uint8_t charger_status;   /* bme_info_charger_status_e */
  uint8_t charging_state;   /* bme_info_ind_charging_state_e */
  uint8_t charging_mode;
  uint8_t batt_max_num_bars;
  uint8_t batt_bars_data;
  uint8_t batt_power_data;
  uint16_t batt_idletime;
  uint16_t batt_usetime;
}  __attribute__((packed));

#endif
