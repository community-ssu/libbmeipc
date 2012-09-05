/*
 * @file    bmeisa.h: definitions needed by bmeipc library users
 *
 * @author    <mikko.k.ylinen at nokia.com>
 *
 * @modified  <aliaksei.katovich at nokia.com>
 *
 * @date    Created: Fri Sep 18 10:58:46 EEST 2009
 *
 * Copyright (C) 2009 Nokia. All rights reserved.
 *
 */

/* These are copied from (and must be kept in sync with):
 *	em_hal.h
 *	em_cha_main.h
 *	em_usb_interface.h
 */

#ifndef __BMEISA_H__
#define __BMEISA_H__

#include <stdint.h>

/* constants for charging */

enum {
	/* USB charger */
	BMEISA_USB_CHARGE_MODE_DISCONNECTED = 0,	/* orig: EM_USB_* */
	BMEISA_USB_CHARGE_MODE_SUSPENDED,
	BMEISA_USB_CHARGE_MODE_100MA,
	BMEISA_USB_CHARGE_MODE_500MA,
	BMEISA_USB_CHARGE_MODE_WALL_CHARGER,
	BMEISA_USB_CHARGE_MODE_VBUS_DETECTED,
	BMEISA_USB_CHARGE_MODE_MISDETECTION,
	BMEISA_USB_CHARGE_MODE_NO_VBUS_AT_STARTUP,
	BMEISA_USB_CHARGE_MODE_HOST_CHARGER_HIGH_SPEED,
	BMEISA_USB_CHARGE_MODE_HOST_CHARGER_FULL_SPEED,

	/* Dynamo charger */
	BMEISA_DYN_CHARGE_MODE_CONNECTED,		/* orig.: EM_DYN_* */
	BMEISA_DYN_CHARGE_MODE_DISCONNECTED,
	BMEISA_USB_CHARGE_MODE_900MA,
};

/* charging info */

typedef struct {
	uint8_t  charger_action;	/* Action to be performed */
	uint32_t charger_value;		/* Value field from subblock */
	uint8_t  info;			/* Info byte */
	uint8_t  charging_ctrl;		/* Enable/disable charging byte */
	uint8_t  charging_pause_ctrl;	/* Pause/resume charging byte */
	uint8_t  hw_volt_limit;		/* OVer Voltage limitation byte */
	uint8_t  tx_volt_limit;		/* Power consuming charging mode byte */
	uint8_t	 bub_cha_ctrl;		/* Backup battery charging control */
	uint8_t	 bub_cha_action;	/* Backup battery charging action */
	uint32_t bub_cha_value;		/* Backup battery charging value */
	uint8_t  pwm_frq_ctrl;		/* PWM frequency byte */
	uint8_t  pwm_value;		/* PWM value byte */
} bmeisa_cha_ctrl_info_t; /* orig.: em_cha_ctrl_info_type */

/*
 * Type definitions of structures to hold ADC calibration for the different
 * channel types used.
 */
typedef struct {		/* raw_reading-->voltage conversion data */
	int16_t offset;		/* unit: 1 mV */
	int16_t gain;		/* unit: 0.0001mV/bit */
} bmeisa_adc_main_conv_cal_par_t; /* orig.: em_hal_adc_main_conv_cal_par_t */

/* voltage-->unit conversion data for linear channel */
typedef struct {
	int16_t offset;	/* unit: mV or mA */
	int16_t fill;	/* filler word */
	int32_t gain;	/* unit: 0.0001mV/mV or 0.0001mA/mV or 0.0001K/mv */
} bmeisa_adc_lin_chan_cal_par_t; /* orig.: em_hal_adc_lin_chan_cal_par_t */

/* voltage-->unit conversion data for hyperbolical channel */
typedef struct {
	int16_t gain;	/* unit: 10 Ohm */
} bmeisa_adc_hyp_chan_cal_par_t; /* orig.: em_hal_adc_hyp_chan_cal_par_t */

/* voltage-->unit conversion data for logarithmical channel */
typedef struct {
	int16_t gain;		/* unit: 1        */
	int16_t b;		/* unit: 1        */
	int16_t t_ref;		/* unit: 1 Kelvin */
} bmeisa_adc_log_chan_cal_par_t; /* orig.: em_hal_adc_log_chan_cal_par_t */

typedef struct bmeisa_adc_cal_data {
	uint8_t channel;	/* Logical ADC channel */
	uint8_t tr_func_id;	/* The used transfer function for the channel */
	union {
		/* The calibration data for the AD converter itself */
		bmeisa_adc_main_conv_cal_par_t adc_ch;

		/* The calibration data for linear channels */
		bmeisa_adc_lin_chan_cal_par_t lin_ch;

		/* The calibration data for hyperbolic channels */
		bmeisa_adc_hyp_chan_cal_par_t hyp_ch;

		/* The calibration data for logarithmic channels */
		bmeisa_adc_log_chan_cal_par_t log_ch;
	} u;
} bmeisa_adc_cal_data_str_t; /* orig.: em_hal_adc_cal_data_str_t */

#endif /* __BMEISA_H__ */
