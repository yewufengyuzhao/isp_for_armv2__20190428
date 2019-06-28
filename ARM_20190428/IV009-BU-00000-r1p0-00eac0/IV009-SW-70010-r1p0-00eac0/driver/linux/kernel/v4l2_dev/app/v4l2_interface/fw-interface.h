/*
*
* SPDX-License-Identifier: GPL-2.0
*
* Copyright (C) 2011-2018 ARM or its affiliates
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; version 2.
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
* for more details.
* You should have received a copy of the GNU General Public License along
* with this program; if not, write to the Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*
*/

#ifndef _FW_INTERFACE_H_
#define _FW_INTERFACE_H_

#include <linux/videodev2.h>

/* fw-interface isp control interface */
int fw_intf_isp_init( uint32_t hw_isp_addr );
int fw_intf_is_isp_started( void );
void fw_intf_isp_deinit( void );
int fw_intf_isp_start( void );
void fw_intf_isp_stop( void );
int fw_intf_isp_get_current_ctx_id( uint32_t ctx_id );
int fw_intf_isp_get_sensor_info( uint32_t ctx_id, isp_v4l2_sensor_info *sensor_info );
int fw_intf_isp_get_sensor_preset( uint32_t ctx_id );
int fw_intf_isp_set_sensor_preset( uint32_t ctx_id, uint32_t preset );

//calibration
uint32_t fw_calibration_update( uint32_t ctx_id );

/* fw-interface per-stream control interface */
int fw_intf_stream_start( uint32_t ctx_id, isp_v4l2_stream_type_t streamType );
void fw_intf_stream_stop( uint32_t ctx_id, isp_v4l2_stream_type_t streamType );

/* fw-interface sensor hw stream control interface */
int fw_intf_sensor_pause( uint32_t ctx_id );
int fw_intf_sensor_resume( uint32_t ctx_id );

/* fw-interface per-stream config interface */
int fw_intf_stream_set_resolution( uint32_t ctx_id, const isp_v4l2_sensor_info *sensor_info,
                                   isp_v4l2_stream_type_t streamType, uint32_t *width, uint32_t *height );
int fw_intf_stream_set_output_format( uint32_t ctx_id, isp_v4l2_stream_type_t streamType, uint32_t format );

/* fw-interface isp config interface */
bool fw_intf_validate_control( uint32_t id );
int fw_intf_set_test_pattern( uint32_t ctx_id, int val );
int fw_intf_set_test_pattern_type( uint32_t ctx_id, int val );
int fw_intf_set_af_refocus( uint32_t ctx_id, int val );
int fw_intf_set_af_roi( uint32_t ctx_id, int val );
int fw_intf_set_brightness( uint32_t ctx_id, int val );
int fw_intf_set_contrast( uint32_t ctx_id, int val );
int fw_intf_set_saturation( uint32_t ctx_id, int val );
int fw_intf_set_hue( uint32_t ctx_id, int val );
int fw_intf_set_sharpness( uint32_t ctx_id, int val );
int fw_intf_set_color_fx( uint32_t ctx_id, int val );
int fw_intf_set_hflip( uint32_t ctx_id, int val );
int fw_intf_set_vflip( uint32_t ctx_id, int val );
int fw_intf_set_autogain( uint32_t ctx_id, int val );
int fw_intf_set_gain( uint32_t ctx_id, int val );
int fw_intf_set_exposure_auto( uint32_t ctx_id, int val );
int fw_intf_set_exposure( uint32_t ctx_id, int val );
int fw_intf_set_variable_frame_rate( uint32_t ctx_id, int val );
int fw_intf_set_white_balance_auto( uint32_t ctx_id, int val );
int fw_intf_set_white_balance( uint32_t ctx_id, int val );
int fw_intf_set_focus_auto( uint32_t ctx_id, int val );
int fw_intf_set_focus( uint32_t ctx_id, int val );
int fw_intf_set_output_fr_on_off( uint32_t ctx_id, uint32_t ctrl_val );
int fw_intf_set_output_ds1_on_off( uint32_t ctx_id, uint32_t ctrl_val );
int fw_intf_set_temper3_mode( uint32_t ctx_id, int enable_temper3_mode );
int fw_intf_set_system_freeze_firmware( uint32_t ctx_id, int val );
int fw_intf_set_system_manual_exposure( uint32_t ctx_id, int val );
int fw_intf_set_system_manual_integration_time( uint32_t ctx_id, int val );
int fw_intf_set_system_manual_max_integration_time( uint32_t ctx_id, int val );
int fw_intf_set_system_manual_sensor_analog_gain( uint32_t ctx_id, int val );
int fw_intf_set_system_manual_sensor_digital_gain( uint32_t ctx_id, int val );
int fw_intf_set_system_manual_isp_digital_gain( uint32_t ctx_id, int val );
int fw_intf_set_system_manual_exposure_ratio( uint32_t ctx_id, int val );
int fw_intf_set_system_manual_awb( uint32_t ctx_id, int val );
int fw_intf_set_system_manual_saturation( uint32_t ctx_id, int val );
int fw_intf_set_system_max_exposure_ratio( uint32_t ctx_id, int val );
int fw_intf_set_system_exposure( uint32_t ctx_id, int val );
int fw_intf_set_system_integration_time( uint32_t ctx_id, int val );
int fw_intf_set_system_exposure_ratio( uint32_t ctx_id, int val );
int fw_intf_set_system_max_integration_time( uint32_t ctx_id, int val );
int fw_intf_set_system_sensor_analog_gain( uint32_t ctx_id, int val );
int fw_intf_set_system_max_sensor_analog_gain( uint32_t ctx_id, int val );
int fw_intf_set_system_sensor_digital_gain( uint32_t ctx_id, int val );
int fw_intf_set_system_max_sensor_digital_gain( uint32_t ctx_id, int val );
int fw_intf_set_system_isp_digital_gain( uint32_t ctx_id, int val );
int fw_intf_set_system_max_isp_digital_gain( uint32_t ctx_id, int val );
int fw_intf_set_system_awb_red_gain( uint32_t ctx_id, int val );
int fw_intf_set_system_awb_blue_gain( uint32_t ctx_id, int val );
int fw_intf_set_isp_modules_manual_iridix( uint32_t ctx_id, int val );
int fw_intf_set_isp_modules_manual_sinter( uint32_t ctx_id, int val );
int fw_intf_set_isp_modules_manual_temper( uint32_t ctx_id, int val );
int fw_intf_set_isp_modules_manual_auto_level( uint32_t ctx_id, int val );
int fw_intf_set_isp_modules_manual_frame_stitch( uint32_t ctx_id, int val );
int fw_intf_set_isp_modules_manual_raw_frontend( uint32_t ctx_id, int val );
int fw_intf_set_isp_modules_manual_black_level( uint32_t ctx_id, int val );
int fw_intf_set_isp_modules_manual_shading( uint32_t ctx_id, int val );
int fw_intf_set_isp_modules_manual_demosaic( uint32_t ctx_id, int val );
int fw_intf_set_isp_modules_manual_cnr( uint32_t ctx_id, int val );
int fw_intf_set_isp_modules_manual_sharpen( uint32_t ctx_id, int val );
int fw_intf_set_image_resize_enable( uint32_t ctx_id, int val );
int fw_intf_set_image_resize_type( uint32_t ctx_id, int val );
int fw_intf_set_image_crop_xoffset( uint32_t ctx_id, int val );
int fw_intf_set_image_crop_yoffset( uint32_t ctx_id, int val );
int fw_intf_set_image_resize_width( uint32_t ctx_id, int val );
int fw_intf_set_image_resize_height( uint32_t ctx_id, int val );

int fw_intf_get_test_pattern( uint32_t ctx_id, int *ret_val );
int fw_intf_get_test_pattern_type( uint32_t ctx_id, int *ret_val );
int fw_intf_get_sensor_preset( uint32_t ctx_id, int *ret_val );
int fw_intf_get_af_roi( uint32_t ctx_id, int *ret_val );
int fw_intf_get_output_fr_on_off( uint32_t ctx_id, int *ret_val );
int fw_intf_get_output_ds1_on_off( uint32_t ctx_id, int *ret_val );
int fw_intf_get_temper3_mode( uint32_t ctx_id, int *ret_val );
int fw_intf_get_system_freeze_firmware( uint32_t ctx_id, int *ret_val );
int fw_intf_get_system_manual_exposure( uint32_t ctx_id, int *ret_val );
int fw_intf_get_system_manual_integration_time( uint32_t ctx_id, int *ret_val );
int fw_intf_get_system_manual_max_integration_time( uint32_t ctx_id, int *ret_val );
int fw_intf_get_system_manual_sensor_analog_gain( uint32_t ctx_id, int *ret_val );
int fw_intf_get_system_manual_sensor_digital_gain( uint32_t ctx_id, int *ret_val );
int fw_intf_get_system_max_sensor_digital_gain( uint32_t ctx_id, int *ret_val );
int fw_intf_get_system_manual_isp_digital_gain( uint32_t ctx_id, int *ret_val );
int fw_intf_get_system_manual_exposure_ratio( uint32_t ctx_id, int *ret_val );
int fw_intf_get_system_manual_awb( uint32_t ctx_id, int *ret_val );
int fw_intf_get_system_manual_saturation( uint32_t ctx_id, int *ret_val );
int fw_intf_get_system_max_exposure_ratio( uint32_t ctx_id, int *ret_val );
int fw_intf_get_system_max_integration_time( uint32_t ctx_id, int *ret_val );
int fw_intf_get_system_max_sensor_analog_gain( uint32_t ctx_id, int *ret_val );
int fw_intf_get_system_max_isp_digital_gain( uint32_t ctx_id, int *ret_val );
int fw_intf_get_isp_modules_manual_iridix( uint32_t ctx_id, int *ret_val );
int fw_intf_get_isp_modules_manual_sinter( uint32_t ctx_id, int *ret_val );
int fw_intf_get_isp_modules_manual_temper( uint32_t ctx_id, int *ret_val );
int fw_intf_get_isp_modules_manual_auto_level( uint32_t ctx_id, int *ret_val );
int fw_intf_get_isp_modules_manual_frame_stitch( uint32_t ctx_id, int *ret_val );
int fw_intf_get_isp_modules_manual_raw_frontend( uint32_t ctx_id, int *ret_val );
int fw_intf_get_isp_modules_manual_black_level( uint32_t ctx_id, int *ret_val );
int fw_intf_get_isp_modules_manual_shading( uint32_t ctx_id, int *ret_val );
int fw_intf_get_isp_modules_manual_demosaic( uint32_t ctx_id, int *ret_val );
int fw_intf_get_isp_modules_manual_cnr( uint32_t ctx_id, int *ret_val );
int fw_intf_get_isp_modules_manual_sharpen( uint32_t ctx_id, int *ret_val );
int fw_intf_get_image_resize_enable( uint32_t ctx_id, int *ret_val );
int fw_intf_get_image_resize_type( uint32_t ctx_id, int *ret_val );
int fw_intf_get_image_crop_xoffset( uint32_t ctx_id, int *ret_val );
int fw_intf_get_image_crop_yoffset( uint32_t ctx_id, int *ret_val );
int fw_intf_get_image_resize_width( uint32_t ctx_id, int *ret_val );
int fw_intf_get_image_resize_height( uint32_t ctx_id, int *ret_val );

int fw_intf_get_system_exposure( uint32_t ctx_id, int *ret_val );
int fw_intf_get_system_integration_time( uint32_t ctx_id, int *ret_val );
int fw_intf_get_system_exposure_ratio( uint32_t ctx_id, int *ret_val );
int fw_intf_get_system_sensor_analog_gain( uint32_t ctx_id, int *ret_val );
int fw_intf_get_system_sensor_digital_gain( uint32_t ctx_id, int *ret_val );
int fw_intf_get_system_isp_digital_gain( uint32_t ctx_id, int *ret_val );
int fw_intf_get_system_awb_red_gain( uint32_t ctx_id, int *ret_val );
int fw_intf_get_system_awb_blue_gain( uint32_t ctx_id, int *ret_val );
int fw_intf_get_status_info_exposure_log2( uint32_t ctx_id, int *ret_val );
int fw_intf_get_status_info_gain_log2( uint32_t ctx_id, int *ret_val );
int fw_intf_get_status_info_gain_ones( uint32_t ctx_id, int *ret_val );
int fw_intf_get_status_info_awb_mix_light_contrast( uint32_t ctx_id, int *ret_val );
int fw_intf_get_status_info_af_lens_pos( uint32_t ctx_id, int *ret_val );
int fw_intf_get_status_info_af_focus_value( uint32_t ctx_id, int *ret_val );
int fw_intf_get_info_fw_revision( uint32_t ctx_id, int *ret_val );
int fw_intf_get_ae_compensation( uint32_t ctx_id, int *ret_val );
int fw_intf_set_ae_compensation( uint32_t ctx_id, int val );
int fw_intf_get_system_dynamic_gamma_enable( uint32_t ctx_id, int *ret_val );
int fw_intf_set_system_dynamic_gamma_enable( uint32_t ctx_id, int val );

#endif
