/******************************************************************************
 * Copyright (C) 2024 by Hatem Alamir
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Hatem Alamir is not liable for any misuse of this material.
 *
 *****************************************************************************/
/**
 * @file data.c
 * @brief Very basic data manipulation.
 *
 * This implementation provides functions for simple data manipulations like
 * data conversion.
 *
 * @author Hatem Alamir 
 * @date December 1 2024
 *
 */

#include<stdint.h>
#include "data.h"

#define MAX_CHAR_LEN (33)
/***********************************************************
 Function Definitions
***********************************************************/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
    uint8_t idx = 0;
    if(data < 0) {
        *(ptr + idx++) = '-';
        idx += 1;
        data *= -1;
    }
    while(data > 0 && idx < MAX_CHAR_LEN - 1) {
        uint32_t rem = data % base;
        if(rem >= 10)
            *(ptr + idx++) = 'A' + (rem - 10);
        else
            *(ptr + idx++) = '0' + rem;
        data /= base;
    }
    // Most commonly when data is 0. Also, as a default in case there is an
    // error with the logic above.
    if(idx == 0)
        *(ptr + idx++) = '0';
    *(ptr + idx++) = '\0';
    return idx;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {

}
