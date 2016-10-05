/**
* This file is autogenerated by nRFgo Studio 1.17.1.3252
*/

#ifndef SETUP_MESSAGES_H__
#define SETUP_MESSAGES_H__

#include "hal_platform.h"
#include "aci.h"

// You have now chosen to upload the configuration to OTP on the device.
// This will result in a device that you can not modify afterwards. If this is your intention,
// remove this comment and the #error below
#error Generating configuration for OTP. Please verify usage by removing this error message from include file.

#define SETUP_ID 26682
#define SETUP_FORMAT 3 /** nRF8001 D */
#define ACI_DYNAMIC_DATA_SIZE 213

/* Service: Gap - Characteristic: Device name - Pipe: SET */
#define PIPE_GAP_DEVICE_NAME_SET          1
#define PIPE_GAP_DEVICE_NAME_SET_MAX_SIZE 17

/* Service: HID Service - Characteristic: HID Report - Pipe: TX */
#define PIPE_HID_SERVICE_HID_REPORT_TX          2
#define PIPE_HID_SERVICE_HID_REPORT_TX_MAX_SIZE 8

/* Service: HID Service - Characteristic: HID Report - Pipe: SET */
#define PIPE_HID_SERVICE_HID_REPORT_SET          3
#define PIPE_HID_SERVICE_HID_REPORT_SET_MAX_SIZE 8

/* Service: HID Service - Characteristic: HID Protocol Mode - Pipe: RX */
#define PIPE_HID_SERVICE_HID_PROTOCOL_MODE_RX          4
#define PIPE_HID_SERVICE_HID_PROTOCOL_MODE_RX_MAX_SIZE 1

/* Service: HID Service - Characteristic: HID Protocol Mode - Pipe: SET */
#define PIPE_HID_SERVICE_HID_PROTOCOL_MODE_SET          5
#define PIPE_HID_SERVICE_HID_PROTOCOL_MODE_SET_MAX_SIZE 1

/* Service: HID Service - Characteristic: HID Control Point - Pipe: RX */
#define PIPE_HID_SERVICE_HID_CONTROL_POINT_RX          6
#define PIPE_HID_SERVICE_HID_CONTROL_POINT_RX_MAX_SIZE 1

/* Service: HID Service - Characteristic: HID Report Output - Pipe: RX */
#define PIPE_HID_SERVICE_HID_REPORT_OUTPUT_RX          7
#define PIPE_HID_SERVICE_HID_REPORT_OUTPUT_RX_MAX_SIZE 1

/* Service: HID Service - Characteristic: HID Report Output - Pipe: RX_ACK_AUTO */
#define PIPE_HID_SERVICE_HID_REPORT_OUTPUT_RX_ACK_AUTO          8
#define PIPE_HID_SERVICE_HID_REPORT_OUTPUT_RX_ACK_AUTO_MAX_SIZE 1

/* Service: HID Service - Characteristic: Boot Keyboard Input Report - Pipe: TX */
#define PIPE_HID_SERVICE_BOOT_KEYBOARD_INPUT_REPORT_TX          9
#define PIPE_HID_SERVICE_BOOT_KEYBOARD_INPUT_REPORT_TX_MAX_SIZE 8

/* Service: HID Service - Characteristic: Boot Keyboard Output Report - Pipe: RX */
#define PIPE_HID_SERVICE_BOOT_KEYBOARD_OUTPUT_REPORT_RX          10
#define PIPE_HID_SERVICE_BOOT_KEYBOARD_OUTPUT_REPORT_RX_MAX_SIZE 1

/* Service: HID Service - Characteristic: Boot Keyboard Output Report - Pipe: RX_ACK_AUTO */
#define PIPE_HID_SERVICE_BOOT_KEYBOARD_OUTPUT_REPORT_RX_ACK_AUTO          11
#define PIPE_HID_SERVICE_BOOT_KEYBOARD_OUTPUT_REPORT_RX_ACK_AUTO_MAX_SIZE 1

/* Service: Battery - Characteristic: Battery Level - Pipe: SET */
#define PIPE_BATTERY_BATTERY_LEVEL_SET          12
#define PIPE_BATTERY_BATTERY_LEVEL_SET_MAX_SIZE 1

/* Service: Battery - Characteristic: Battery Power State - Pipe: SET */
#define PIPE_BATTERY_BATTERY_POWER_STATE_SET          13
#define PIPE_BATTERY_BATTERY_POWER_STATE_SET_MAX_SIZE 1

/* Service: Scan Parameters Service - Characteristic: Scan Interval Window - Pipe: RX */
#define PIPE_SCAN_PARAMETERS_SERVICE_SCAN_INTERVAL_WINDOW_RX          14
#define PIPE_SCAN_PARAMETERS_SERVICE_SCAN_INTERVAL_WINDOW_RX_MAX_SIZE 4

/* Service: Scan Parameters Service - Characteristic: Scan Param Refresh Characteristic - Pipe: TX */
#define PIPE_SCAN_PARAMETERS_SERVICE_SCAN_PARAM_REFRESH_CHARACTERISTIC_TX          15
#define PIPE_SCAN_PARAMETERS_SERVICE_SCAN_PARAM_REFRESH_CHARACTERISTIC_TX_MAX_SIZE 1

/* Service: Device Information - Characteristic: Hardware Revision String - Pipe: SET */
#define PIPE_DEVICE_INFORMATION_HARDWARE_REVISION_STRING_SET          16
#define PIPE_DEVICE_INFORMATION_HARDWARE_REVISION_STRING_SET_MAX_SIZE 9


#define NUMBER_OF_PIPES 16

#define SERVICES_PIPE_TYPE_MAPPING_CONTENT {\
  {ACI_STORE_LOCAL, ACI_SET},   \
  {ACI_STORE_LOCAL, ACI_TX},   \
  {ACI_STORE_LOCAL, ACI_SET},   \
  {ACI_STORE_LOCAL, ACI_RX},   \
  {ACI_STORE_LOCAL, ACI_SET},   \
  {ACI_STORE_LOCAL, ACI_RX},   \
  {ACI_STORE_LOCAL, ACI_RX},   \
  {ACI_STORE_LOCAL, ACI_RX_ACK_AUTO},   \
  {ACI_STORE_LOCAL, ACI_TX},   \
  {ACI_STORE_LOCAL, ACI_RX},   \
  {ACI_STORE_LOCAL, ACI_RX_ACK_AUTO},   \
  {ACI_STORE_LOCAL, ACI_SET},   \
  {ACI_STORE_LOCAL, ACI_SET},   \
  {ACI_STORE_LOCAL, ACI_RX},   \
  {ACI_STORE_LOCAL, ACI_TX},   \
  {ACI_STORE_LOCAL, ACI_SET},   \
}

#define GAP_PPCP_MAX_CONN_INT 0x10 /**< Maximum connection interval as a multiple of 1.25 msec , 0xFFFF means no specific value requested */
#define GAP_PPCP_MIN_CONN_INT  0x6 /**< Minimum connection interval as a multiple of 1.25 msec , 0xFFFF means no specific value requested */
#define GAP_PPCP_SLAVE_LATENCY 25
#define GAP_PPCP_CONN_TIMEOUT 0x12c /** Connection Supervision timeout multiplier as a multiple of 10msec, 0xFFFF means no specific value requested */

#define NB_SETUP_MESSAGES 38
#define SETUP_MESSAGES_CONTENT {\
    {0x00,\
        {\
            0x07,0x06,0x00,0x00,0x03,0x02,0x42,0x07,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x10,0x00,0x3a,0x68,0x00,0x00,0x02,0x00,0x0c,0x00,0x10,0x01,0x01,0x00,0x00,0x02,0x00,0x04,\
            0x81,0x12,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x10,0x1c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
            0x00,0x00,0x40,0x12,0x00,0x00,0x00,0x00,0x03,0x99,0x00,0x64,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x10,0x38,0x02,0xff,0x02,0x58,0x05,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
            0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x05,0x06,0x10,0x54,0x01,0x01,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0x00,0x04,0x04,0x02,0x02,0x00,0x01,0x28,0x00,0x01,0x00,0x18,0x04,0x04,0x05,0x05,0x00,\
            0x02,0x28,0x03,0x01,0x0e,0x03,0x00,0x00,0x2a,0x04,0x34,0x11,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0x1c,0x0f,0x00,0x03,0x2a,0x00,0x01,0x4b,0x65,0x79,0x62,0x6f,0x61,0x72,0x64,0x20,0x4e,\
            0x6f,0x72,0x64,0x69,0x63,0x00,0x00,0x04,0x04,0x05,0x05,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0x38,0x04,0x28,0x03,0x01,0x02,0x05,0x00,0x01,0x2a,0x06,0x04,0x03,0x02,0x00,0x05,0x2a,\
            0x01,0x01,0xc1,0x03,0x04,0x04,0x05,0x05,0x00,0x06,0x28,0x03,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0x54,0x01,0x02,0x07,0x00,0x04,0x2a,0x06,0x04,0x09,0x08,0x00,0x07,0x2a,0x04,0x01,0x06,\
            0x00,0x10,0x00,0x19,0x00,0x2c,0x01,0x04,0x04,0x02,0x02,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0x70,0x08,0x28,0x00,0x01,0x01,0x18,0x04,0x04,0x02,0x02,0x00,0x09,0x28,0x00,0x01,0x12,\
            0x18,0x04,0x04,0x05,0x05,0x00,0x0a,0x28,0x03,0x01,0x12,0x0b,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0x8c,0x00,0x4d,0x2a,0x14,0x0c,0x08,0x00,0x00,0x0b,0x2a,0x4d,0x01,0x00,0x00,0x00,0x00,\
            0x00,0x00,0x00,0x00,0x46,0x34,0x03,0x02,0x00,0x0c,0x29,0x02,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0xa8,0x01,0x00,0x00,0x06,0x0c,0x03,0x02,0x00,0x0d,0x29,0x08,0x01,0x00,0x01,0x04,0x04,\
            0x05,0x05,0x00,0x0e,0x28,0x03,0x01,0x02,0x0f,0x00,0x4a,0x2a,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0xc4,0x06,0x0c,0x05,0x04,0x00,0x0f,0x2a,0x4a,0x01,0x11,0x01,0x00,0x03,0x04,0x04,0x05,\
            0x05,0x00,0x10,0x28,0x03,0x01,0x06,0x11,0x00,0x4e,0x2a,0x46,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0xe0,0x3c,0x02,0x01,0x00,0x11,0x2a,0x4e,0x01,0x01,0x04,0x04,0x05,0x05,0x00,0x12,0x28,\
            0x03,0x01,0x04,0x13,0x00,0x4c,0x2a,0x46,0x30,0x02,0x01,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x20,0xfc,0x13,0x2a,0x4c,0x01,0x00,0x04,0x04,0x05,0x05,0x00,0x14,0x28,0x03,0x01,0x02,0x15,\
            0x00,0x4b,0x2a,0x06,0x0c,0x4d,0x4c,0x00,0x15,0x2a,0x4b,0x01,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x21,0x18,0x05,0x01,0x09,0x06,0xa1,0x01,0x05,0x07,0x19,0xe0,0x29,0xe7,0x15,0x00,0x25,0x01,\
            0x75,0x01,0x95,0x08,0x81,0x02,0x95,0x01,0x75,0x08,0x81,0x01,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x21,0x34,0x95,0x05,0x75,0x01,0x05,0x08,0x19,0x01,0x29,0x05,0x91,0x02,0x95,0x01,0x75,0x03,\
            0x91,0x01,0x95,0x06,0x75,0x08,0x15,0x00,0x25,0x65,0x05,0x07,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x21,0x50,0x19,0x00,0x29,0x65,0x81,0x00,0x09,0x05,0x15,0x00,0x26,0xff,0x00,0x75,0x08,0x95,\
            0x02,0xb1,0x02,0xc0,0x04,0x04,0x05,0x05,0x00,0x16,0x28,0x03,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x21,0x6c,0x01,0x0e,0x17,0x00,0x4d,0x2a,0x44,0x3c,0x01,0x01,0x00,0x17,0x2a,0x4d,0x01,0x00,\
            0x06,0x0c,0x03,0x02,0x00,0x18,0x29,0x08,0x01,0x00,0x02,0x04,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x21,0x88,0x04,0x05,0x05,0x00,0x19,0x28,0x03,0x01,0x12,0x1a,0x00,0x22,0x2a,0x16,0x0c,0x09,\
            0x08,0x00,0x1a,0x2a,0x22,0x01,0x00,0x00,0x00,0x00,0x00,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x21,0xa4,0x00,0x00,0x46,0x34,0x03,0x02,0x00,0x1b,0x29,0x02,0x01,0x00,0x00,0x04,0x04,0x05,\
            0x05,0x00,0x1c,0x28,0x03,0x01,0x0e,0x1d,0x00,0x32,0x2a,0x46,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x21,0xc0,0x3c,0x02,0x01,0x00,0x1d,0x2a,0x32,0x01,0x00,0x04,0x04,0x02,0x02,0x00,0x1e,0x28,\
            0x00,0x01,0x0f,0x18,0x04,0x04,0x05,0x05,0x00,0x1f,0x28,0x03,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x21,0xdc,0x01,0x02,0x20,0x00,0x19,0x2a,0x06,0x0c,0x02,0x01,0x00,0x20,0x2a,0x19,0x01,0x32,\
            0x04,0x04,0x05,0x05,0x00,0x21,0x28,0x03,0x01,0x02,0x22,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x21,0xf8,0x1a,0x2a,0x06,0x0c,0x02,0x01,0x00,0x22,0x2a,0x1a,0x01,0x2f,0x04,0x04,0x02,0x02,\
            0x00,0x23,0x28,0x00,0x01,0x13,0x18,0x04,0x04,0x05,0x05,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x22,0x14,0x24,0x28,0x03,0x01,0x04,0x25,0x00,0x4f,0x2a,0x46,0x30,0x05,0x04,0x00,0x25,0x2a,\
            0x4f,0x01,0x00,0x00,0x00,0x00,0x04,0x04,0x05,0x05,0x00,0x26,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x22,0x30,0x28,0x03,0x01,0x10,0x27,0x00,0x31,0x2a,0x14,0x00,0x01,0x00,0x00,0x27,0x2a,0x31,\
            0x01,0x00,0x46,0x34,0x03,0x02,0x00,0x28,0x29,0x02,0x01,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x22,0x4c,0x00,0x04,0x04,0x02,0x02,0x00,0x29,0x28,0x00,0x01,0x0a,0x18,0x04,0x04,0x05,0x05,\
            0x00,0x2a,0x28,0x03,0x01,0x02,0x2b,0x00,0x50,0x2a,0x06,0x0c,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x22,0x68,0x08,0x07,0x00,0x2b,0x2a,0x50,0x01,0x02,0x15,0x19,0xee,0xee,0x00,0x01,0x04,0x04,\
            0x05,0x05,0x00,0x2c,0x28,0x03,0x01,0x02,0x2d,0x00,0x27,0x2a,\
        },\
    },\
    {0x00,\
        {\
            0x16,0x06,0x22,0x84,0x04,0x0c,0x09,0x00,0x00,0x2d,0x2a,0x27,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
            0x00,0x00,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x40,0x00,0x2a,0x00,0x01,0x00,0x80,0x04,0x00,0x03,0x00,0x00,0x2a,0x4d,0x01,0x00,0x82,0x04,\
            0x00,0x0b,0x00,0x0c,0x2a,0x4e,0x01,0x00,0x88,0x04,0x00,0x11,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x40,0x1c,0x00,0x00,0x2a,0x4c,0x01,0x00,0x08,0x04,0x00,0x13,0x00,0x00,0x2a,0x4d,0x01,0x04,\
            0x08,0x04,0x00,0x17,0x00,0x00,0x2a,0x22,0x01,0x00,0x02,0x04,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x40,0x38,0x00,0x1a,0x00,0x1b,0x2a,0x32,0x01,0x04,0x08,0x04,0x00,0x1d,0x00,0x00,0x2a,0x19,\
            0x01,0x00,0x80,0x04,0x00,0x20,0x00,0x00,0x2a,0x1a,0x01,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x40,0x54,0x80,0x04,0x00,0x22,0x00,0x00,0x2a,0x4f,0x01,0x00,0x08,0x04,0x00,0x25,0x00,0x00,\
            0x2a,0x31,0x01,0x00,0x02,0x04,0x00,0x27,0x00,0x28,0x2a,0x27,\
        },\
    },\
    {0x00,\
        {\
            0x0b,0x06,0x40,0x70,0x01,0x00,0x80,0x04,0x00,0x2d,0x00,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x1f,0x06,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x0b,0x06,0x60,0x1c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x19,0x06,0x70,0x00,0x19,0x02,0xc1,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
            0x00,0x00,0x00,0x00,0x00,0x00,\
        },\
    },\
    {0x00,\
        {\
            0x06,0x06,0xf0,0x00,0x83,0x55,0x66,\
        },\
    },\
}

#endif
