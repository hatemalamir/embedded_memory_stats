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
 * @file stats.c
 * @brief Implementation of a group of statistical functions in stats.h
 *
 * This file contains definition of all statistical function defined in stats.c.
 * Most functions deal with array of unsigned chars with size passed as unsigned
 * int. The main output function prints to the standard output.
 *
 * @author Hatem Alamir
 * @date 11/21/2024
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

}

void print_statistics(unsigned char* arr, const unsigned int length) {}

void print_array(const unsigned char* arr, const unsigned int length) {}

unsigned char find_median(unsigned char* arr, const unsigned int length) {}

unsigned char find_mean(unsigned char* arr, const unsigned int length) {}

unsigned char find_maximum(unsigned char* arr, const unsigned int length) {}

unsigned char find_minimum(unsigned char* arr, const unsigned int length) {}

unsigned char sort_array(unsigned char* arr, const unsigned int length) {}
