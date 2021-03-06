/*
The MIT License (MIT)
Copyright (c) 2017 Rohm Semiconductor

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef __BH1745_REGISTERS_H__
#define __BH1745_REGISTERS_H__
/* registers */
#define BH1745_REGISTER_DUMP_START 0x40
#define BH1745_SYSTEM_CONTROL 0x40
// Writing MODE_CONTROL1/2/3 restarts measurement if any.
#define BH1745_MODE_CONTROL1 0x41
#define BH1745_MODE_CONTROL2 0x42
// Always write 02h
#define BH1745_MODE_CONTROL3 0x44
// Least significant byte of uint16 RED measurement value
#define BH1745_RED_DATA_LSBS 0x50
// Most significant byte of uint16 RED measurement value
#define BH1745_RED_DATA_MSBS 0x51
#define BH1745_GREEN_DATA_LSBS 0x52
#define BH1745_GREEN_DATA_MSBS 0x53
#define BH1745_BLUE_DATA_LSBS 0x54
#define BH1745_BLUE_DATA_MSBS 0x55
#define BH1745_CLEAR_DATA_LSBS 0x56
#define BH1745_CLEAR_DATA_MSBS 0x57
// DINT data is used for internal calculation of BH1745NUC.
#define BH1745_DINT_DATA_LSBS 0x58
// DINT registers are used for IC test only.
#define BH1745_DINT_DATA_MSBS 0x59
#define BH1745_INTERRUPT 0x60
#define BH1745_PERSISTENCE 0x61
#define BH1745_TH_LSBS 0x62
#define BH1745_TH_MSBS 0x63
#define BH1745_TL_LSBS 0x64
#define BH1745_TL_MSBS 0x65
#define BH1745_ID_REG 0x92
#define BH1745_REGISTER_DUMP_END 0x92
/* registers bits */
// Initial reset is not started
#define BH1745_SYSTEM_CONTROL_SW_RESET_NOT_STARTED (0x00 << 7)
// Initial reset is started
#define BH1745_SYSTEM_CONTROL_SW_RESET_START (0x01 << 7)
// In specification "not_initialized"
#define BH1745_SYSTEM_CONTROL_INT_PIN_ACTIVE (0x00 << 6)
// high impedance
#define BH1745_SYSTEM_CONTROL_INT_PIN_INACTIVE (0x01 << 6)
#define BH1745_SYSTEM_CONTROL_PART_ID (0x0B << 0)
#define BH1745_MODE_CONTROL1_RESERVED_WRITE00000 (0x00 << 3)
// 160msec
#define BH1745_MODE_CONTROL1_ODR_6P25 (0x00 << 0)
// 320msec
#define BH1745_MODE_CONTROL1_ODR_3P125 (0x01 << 0)
// 640msec
#define BH1745_MODE_CONTROL1_ODR_1P5625 (0x02 << 0)
// 1280msec
#define BH1745_MODE_CONTROL1_ODR_0P78125 (0x03 << 0)
// 2560msec
#define BH1745_MODE_CONTROL1_ODR_0P390625 (0x04 << 0)
// 5120msec
#define BH1745_MODE_CONTROL1_ODR_0P1953125 (0x05 << 0)
// forbidden6
#define BH1745_MODE_CONTROL1_ODR_FORBIDDEN6 (0x06 << 0)
// forbidden7
#define BH1745_MODE_CONTROL1_ODR_FORBIDDEN7 (0x07 << 0)
#define BH1745_MODE_CONTROL2_DATA_UPDATED_NO (0x00 << 7)
#define BH1745_MODE_CONTROL2_DATA_UPDATED_YES (0x01 << 7)
#define BH1745_MODE_CONTROL2_RESERVED65_WRITE00 (0x00 << 5)
#define BH1745_MODE_CONTROL2_RGBC_MEASUREMENT_INACTIVE (0x00 << 4)
#define BH1745_MODE_CONTROL2_RGBC_MEASUREMENT_ACTIVE (0x01 << 4)
#define BH1745_MODE_CONTROL2_RESERVED32_WRITE00 (0x00 << 2)
#define BH1745_MODE_CONTROL2_ADC_GAIN_1X (0x00 << 0)
#define BH1745_MODE_CONTROL2_ADC_GAIN_2X (0x01 << 0)
#define BH1745_MODE_CONTROL2_ADC_GAIN_16X (0x02 << 0)
#define BH1745_MODE_CONTROL2_ADC_GAIN_FORBIDDEN3 (0x03 << 0)
#define BH1745_MODE_CONTROL3_ALWAYS_02H (0x02 << 0)
#define BH1745_INTERRUPT_STATUS_INACTIVE (0x00 << 7)
#define BH1745_INTERRUPT_STATUS_ACTIVE (0x01 << 7)
#define BH1745_INTERRUPT_RESERVED65_WRITE00 (0x00 << 5)
// INT pin is latched until INTERRUPT register is read or initialized
#define BH1745_INTERRUPT_LATCH_ENABLE (0x00 << 4)
// INT pin is updated after each measurement
#define BH1745_INTERRUPT_LATCH_DISABLE (0x01 << 4)
// red channel
#define BH1745_INTERRUPT_SOURCE_SELECT_RED (0x00 << 2)
// green channel
#define BH1745_INTERRUPT_SOURCE_SELECT_GREEN (0x01 << 2)
// blue channel
#define BH1745_INTERRUPT_SOURCE_SELECT_BLUE (0x02 << 2)
// clear channel
#define BH1745_INTERRUPT_SOURCE_SELECT_CLEAR (0x03 << 2)
#define BH1745_INTERRUPT_RESERVED1_WRITE0 (0x00 << 1)
#define BH1745_INTERRUPT_PIN_DISABLE (0x00 << 0)
#define BH1745_INTERRUPT_PIN_ENABLE (0x01 << 0)
#define BH1745_PERSISTENCE_RESERVED72_WRITE000000 (0x00 << 2)
// Interrupt status is toggled at each measurement end.
#define BH1745_PERSISTENCE_OF_INTERRUPT_STATUS_TOGGLE_AFTER_MEASUREMENT (0x00 << 0)
// Interrupt status is updated at each measurement end.
#define BH1745_PERSISTENCE_OF_INTERRUPT_STATUS_UPDATE_AFTER_MEASUREMENT (0x01 << 0)
// Interrupt status is updated if 4 consecutive threshold judgements are the same
#define BH1745_PERSISTENCE_OF_INTERRUPT_STATUS_UPDATE_AFTER_4_SAME (0x02 << 0)
// Interrupt status is updated if 8 consecutive threshold judgements are the same
#define BH1745_PERSISTENCE_OF_INTERRUPT_STATUS_UPDATE_AFTER_8_SAME (0x03 << 0)
#define BH1745_ID_REG_MANUFACTURER_ID (0xE0 << 0)
 /*registers bit masks */
#define BH1745_SYSTEM_CONTROL_SW_RESET_MASK 0x80

#define BH1745_SYSTEM_CONTROL_INT_PIN_MASK 0x40

#define BH1745_SYSTEM_CONTROL_PART_MASK 0x3F
#define BH1745_MODE_CONTROL1_RESERVED_MASK 0xF8
#define BH1745_MODE_CONTROL1_ODR_MASK 0x07
// Is the RGBC data updated after last MODE_CONTROL1/2 reg writing or MODE_CONTROL2 reading. In specification named as VALID.
#define BH1745_MODE_CONTROL2_DATA_UPDATED_MASK 0x80
#define BH1745_MODE_CONTROL2_RESERVED65_MASK 0x60
#define BH1745_MODE_CONTROL2_RGBC_MEASUREMENT_MASK 0x10
#define BH1745_MODE_CONTROL2_RESERVED32_MASK 0x0C
#define BH1745_MODE_CONTROL2_ADC_GAIN_MASK 0x03
#define BH1745_MODE_CONTROL3_ALWAYS_MASK 0xFF
#define BH1745_INTERRUPT_STATUS_MASK 0x80
#define BH1745_INTERRUPT_RESERVED65_MASK 0x60
#define BH1745_INTERRUPT_LATCH_MASK 0x10

#define BH1745_INTERRUPT_SOURCE_MASK 0x0C
// Write 0
#define BH1745_INTERRUPT_RESERVED1_MASK 0x02
#define BH1745_INTERRUPT_PIN_MASK 0x01
#define BH1745_PERSISTENCE_RESERVED72_MASK 0xFC
#define BH1745_PERSISTENCE_OF_INTERRUPT_MASK 0x03

#define BH1745_ID_REG_MANUFACTURER_MASK 0xFF
#endif

