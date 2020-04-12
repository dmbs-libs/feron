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

#ifndef _FERON_H_
#define _FERON_H_

#include <stdint.h>

/*
    Init feron library
 */
void
feron_init(void);

/*
    Abort transmit
 */
void
feron_abort(void);

uint8_t
feron_exec_native(uint8_t command, uint8_t repeat);

/*
    Set BH (0x00 to 0xFF) without dimming effect
 */
uint8_t
feron_bh_set(uint8_t bh);

/*
    Set BH (0x00 to 0xFF) with dimming effect
 */
uint8_t
feron_bh_dim(uint8_t bh);

/*
    Load BH from preset (0 to 15) with dimming effect
 */
uint8_t
feron_preset_load_dimming(uint8_t preset);

/*
    Load BH from preset (0 to 15) without dimming effect
 */
uint8_t
feron_preset_load_force(uint8_t preset);

/*
    Save BH to preset (0 to 15)
 */
uint8_t
feron_preset_save(uint8_t preset);

/*
    Set hue value (0 to 15)
 */
uint8_t
feron_hue_set(uint8_t value);

/*
    Set brightness value (0 to 15)
 */
uint8_t
feron_brightness_set(uint8_t value);

/*
    Add value to hue (0 to 15)
 */
uint8_t
feron_hue_add(uint8_t value);

/*
    Subtract value from hue (0 to 15)
 */
uint8_t
feron_hue_sub(uint8_t value);

/*
    Add value to brightness (0 to 15)
 */
uint8_t
feron_brightness_add(uint8_t value);

/*
    Subtract value from brightness (0 to 15)
 */
uint8_t
feron_brightness_sub(uint8_t value);

/*
    Inverse power
 */
uint8_t
feron_power_inv(void);

/*
    Power on
 */
uint8_t
feron_power_on(void);

/*
    Power off
 */
uint8_t
feron_power_off(void);

/*
    Hue increment
 */
uint8_t
feron_hue_inc(uint8_t repeat);

/*
    Hue decrement
 */
uint8_t
feron_hue_dec(uint8_t repeat);

/*
    Hue rotate
 */
uint8_t
feron_hue_rotate(uint8_t repeat);

/*
    Brightness increment
 */
uint8_t
feron_brightness_inc(uint8_t repeat);

/*
    Brightness decrement
 */
uint8_t
feron_brightness_dec(uint8_t repeat);

/*
    Brightness rotate
 */
uint8_t
feron_brightness_rotate(uint8_t repeat);

/*
    BH random
 */
uint8_t
feron_bh_rand(uint8_t repeat);

#endif // _FERON_H_
