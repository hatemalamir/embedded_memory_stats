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
#include "memory.h"

#define MAX_CHAR_LEN (33)
/***********************************************************
 Function Definitions
***********************************************************/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
    uint8_t idx = 0;
    int8_t sign = 0;
    if(data < 0) {
        *(ptr + idx++) = '-';
        data *= -1;
        sign = 1;
    }
    int32_t rem;
    while(data > 0 && idx < MAX_CHAR_LEN - 1) {
        rem = data % base;
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
    else
        my_reverse(ptr + sign, idx - sign);
    *(ptr + idx++) = '\0';
    return idx;
}

uint8_t atoi_ch(uint8_t ach, uint8_t base) {
    if(ach >= '0' && ach <= '9')
        return ach - '0';
    else if(base > 10 && ach >= 'A' && ach <= 'E')
        return ach - 'A';
    else if(base > 10 && ach >= 'a' && ach <= 'e')
        return ach - 'a';
    else
        return 0;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
    if(digits < 2)
        return 0;

    int32_t result = 0;
    int32_t power = 1;
    for(digits -= 2; digits > 0; digits--) {
        result += atoi_ch(*(ptr + digits), base) * power;
        power *= base;
    }
    if(*ptr == '-')
        result *= -1;
    else
        result += atoi_ch(*ptr, base) * power;
    return result;
}
