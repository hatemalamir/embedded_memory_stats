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
 * @file data.h
 * @brief Very basic data manipulation.
 *
 * This header file provides functions for simple data manipulations like data
 * conversion
 *
 * @author Hatem Alamir
 * @date December 1 2024
 *
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

#include<stdint.h>

/**
 * @brief Conversion from integer to string 
 *
 * Integer-to-ASCII needs to convert data from a standard integer type into an
 * ASCII string.
 * All operations need to be performed using pointer arithmetic, not array
 * indexing.
 * The number to be converted is passed in as a signed 32-bit integer.
 * Bases 2 to 16 are supported by specifying the integer value of the target
 * base.
 * The converted character string is copied to the uint8_t* pointer passed in as
 * a parameter (ptr)
 * The signed 32-bit number has a maximum string size.
 * A null terminator is placed at the end of the converted c-string
 * Function returns the length of the converted data (including a negative
 * sign). Example my_itoa(ptr, 1234, 10) returns an ASCII string length of 5
 * (including the null terminator).
 * This function handles signed data.
 * No string functions or libraries are used.
 *
 * @param data Signed integer to covert string
 * @param ptr Space to write out the coverted string
 * @param base Base to be used for coversion, 2 to 16
 *
 * @return length of the converted data including a negative sign
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Conversion from an ASCII represented string into an integer 
 *
 * ASCII-to-Integer converts data back from an ASCII represented string into an
 * integer type.
 * All operations are performed using pointer arithmetic, not array indexing.
 * The character string to convert is passed in as a uint8_t * pointer (ptr).
 * The number of digits in your character set is passed in as a uint8_t integer.
 * Bases 2 to 16 are supported
 * Signed data is handled.
 * No string functions or libraries are used.
 *
 * @param ptr Character string to convert
 * @param digits Number of digits in character set
 * @param base Base to be used for coversion, 2 to 16
 *
 * @return The converted 32-bit signed integer
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
