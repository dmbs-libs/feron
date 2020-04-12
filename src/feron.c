/* 
 *  MIT License
 *  
 *  Copyright (c) 2019 Sergey V. DUDANOV
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

#include <stdint.h>
#include "nec.h"
#include "feron.h"

// CUSTOM ADDRESS FOR SET HB-VALUE (AS COMMAND) WITH DIMMING
#define FERON_ADDRESS_DIM_BH    0xB721
// CUSTOM ADDRESS FOR SET HB-VALUE (AS COMMAND) WITHOUT DIMMING
#define FERON_ADDRESS_SET_BH    0xB781
// NATIVE ADDRESS
#define FERON_ADDRESS_NATIVE    0xB7A0

/*
 * SIMPLE COMMANDS
 */
// IR REMOTE NATIVE
#define FERON_PWR_INV           0xE9
#define FERON_HUE_INC           0xEF
#define FERON_HUE_DEC           0xEB
#define FERON_BR_INC            0xAB
#define FERON_BR_DEC            0xBC
#define FERON_MAX               0xAC
#define FERON_MIN               0xF5
#define FERON_BH_RAND           0xDB
#define FERON_TIM_1H            0xA8
#define FERON_TIM_30M           0xFA
// CUSTOM NATIVE
#define FERON_PWR_ON            0xEA
#define FERON_PWR_OFF           0xEC
#define FERON_HUE_ROT           0xF0
#define FERON_BR_ROT            0xA2

/*
 *  VALUE COMMANDS
 */
// 0x0X: LOAD BH FROM PRESET [X] WITH DIMMING
#define FERON_PRESET_LOAD_DIM   0x00
// 0x1X: LOAD BH FROM PRESET [X] WITHOUT DIMMING
#define FERON_PRESET_LOAD       0x10
// 0x2X: SAVE CURRENT BH AS PRESET [X]
#define FERON_PRESET_SAVE       0x20
// 0x3X: HUE  = [X]
#define FERON_HUE_SET           0x30
// 0x4X: BR   = [X]
#define FERON_BR_SET            0x40
// 0x5X: HUE += [X]
#define FERON_HUE_ADD           0x50
// 0x6X: HUE -= [X]
#define FERON_HUE_SUB           0x60
// 0x7X: BR  += [X]
#define FERON_BR_ADD            0x70
// 0x8X: BR  -= [X]
#define FERON_BR_SUB            0x80

static uint8_t
feron_exec_native_value(const uint8_t command, uint8_t value)
{
    if (value > 15)
        value = 15;
    
    return feron_exec_native(command | value, 0);
}

void
feron_init(void)
{
    nec_init();
}

void
feron_abort(void)
{
    nec_abort();
}

uint8_t
feron_exec_native(const uint8_t command, const uint8_t repeat)
{
    return nec_send_ex(command, FERON_ADDRESS_NATIVE, repeat);
}

uint8_t
feron_bh_set(const uint8_t bh)
{
    return nec_send_ex(bh, FERON_ADDRESS_SET_BH, 0);
}

uint8_t
feron_bh_dim(const uint8_t bh)
{
    return nec_send_ex(bh, FERON_ADDRESS_DIM_BH, 0);
}

uint8_t
feron_preset_load_dimming(const uint8_t preset)
{
    return feron_exec_native_value(FERON_PRESET_LOAD_DIM, preset);
}

uint8_t
feron_preset_load_force(const uint8_t preset)
{
    return feron_exec_native_value(FERON_PRESET_LOAD, preset);
}

uint8_t
feron_preset_save(const uint8_t preset)
{
    return feron_exec_native_value(FERON_PRESET_SAVE, preset);
}

uint8_t
feron_hue_set(const uint8_t value)
{
    return feron_exec_native_value(FERON_HUE_SET, value);
}

uint8_t
feron_brightness_set(const uint8_t value)
{
    return feron_exec_native_value(FERON_BR_SET, value);
}

uint8_t
feron_hue_add(const uint8_t value)
{
    return feron_exec_native_value(FERON_HUE_ADD, value);
}

uint8_t
feron_hue_sub(const uint8_t value)
{
    return feron_exec_native_value(FERON_HUE_SUB, value);
}

uint8_t
feron_brightness_add(const uint8_t value)
{
    return feron_exec_native_value(FERON_BR_ADD, value);
}

uint8_t
feron_brightness_sub(const uint8_t value)
{
    return feron_exec_native_value(FERON_BR_SUB, value);
}

uint8_t
feron_power_inv(void)
{
    return feron_exec_native(FERON_PWR_INV, 0);
}

uint8_t
feron_power_on(void)
{
    return feron_exec_native(FERON_PWR_ON, 0);
}

uint8_t
feron_power_off(void)
{
    return feron_exec_native(FERON_PWR_OFF, 0);
}

uint8_t
feron_hue_inc(const uint8_t repeat)
{
    return feron_exec_native(FERON_HUE_INC, repeat);
}

uint8_t
feron_hue_dec(const uint8_t repeat)
{
    return feron_exec_native(FERON_HUE_DEC, repeat);
}

uint8_t
feron_hue_rotate(const uint8_t repeat)
{
    return feron_exec_native(FERON_HUE_ROT, repeat);
}

uint8_t
feron_brightness_inc(const uint8_t repeat)
{
    return feron_exec_native(FERON_BR_INC, repeat);
}

uint8_t
feron_brightness_dec(const uint8_t repeat)
{
    return feron_exec_native(FERON_BR_DEC, repeat);
}

uint8_t
feron_brightness_rotate(const uint8_t repeat)
{
    return feron_exec_native(FERON_BR_ROT, repeat);
}

uint8_t
feron_bh_rand(const uint8_t repeat)
{
    return feron_exec_native(FERON_BH_RAND, repeat);
}
