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
 * This file contains implementation of all statistical function defined in
 * stats.h.  Most functions process an array of unsigned chars with size passed
 * as unsigned int. The main output function prints different statistics to the
 * standard output.
 *
 * @author Hatem Alamir
 * @date 11/21/2024
 *
 */



#include <stdio.h>
#include <errno.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
  print_statistics(test, SIZE);
}

void print_statistics(unsigned char* arr, const unsigned int length) {
  PRINTF(">> Original Array: ");
  print_array(arr, length);
  PRINTF("\n");

  PRINTF(">> Sorted Array: ");
  sort_array(arr, length);
  print_array(arr, length);
  PRINTF("\n");

  errno = 0;
  unsigned char temp = find_median(arr, length);
  if(errno == EINVAL) {
      perror("Error calculating median. Possible empty array!");
  }
  PRINTF(">> Median: %d\n", temp);

  errno = 0;
  temp = find_mean(arr, length);
  if(errno == EINVAL) {
      perror("Error calculating mean. Possible empty array!");
  }
  PRINTF(">> Mean: %d\n", temp);

  errno = 0;
  temp = find_maximum(arr, length);
  if(errno == EINVAL) {
      perror("Error calculating maximum. Possible empty array!");
  }
  PRINTF(">> Maximum: %d\n", temp);

  errno = 0;
  temp = find_minimum(arr, length);
  if(errno == EINVAL) {
      perror("Error calculating minimum. Possible empty array!");
  }
  PRINTF(">> Minimum: %d\n", temp);
}

void print_array(const unsigned char* arr, const unsigned int length) {
#ifdef VERBOSE
    PRINTF("[");
    for(unsigned int i = 0; i < length - 1; i++)
        PRINTF("%d, ", arr[i]);
    if(length > 0)
        PRINTF("%d]", arr[length - 1]);
#endif
}

/**
 * @brief Given an array of data and two indices, swap the data at those indices 
 *
 * An array is passed as a pointer, and two indices as offsets from that
 * pointer. Using array notation, swap the data values at those two indices.
 * 
 *
 * @param arr array of data
 * @param i1 first index to be swapped
 * @param i2 second index to be swapped 
 *
 * @return This function does not return any value. 
 */
void swap(unsigned char* arr, const int i1, const int i2) {
    unsigned char temp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = temp;
}

void sort_array(unsigned char* arr, const unsigned int length) {
    for(int i = 0; i < length; i++)
        for(int j = length - 1; j > i; j--)
            if(arr[j] > arr[j - 1])
                swap(arr, j, j - 1);
}

unsigned char find_median(unsigned char* arr, const unsigned int length) {
    if(length < 1) {
        errno = EINVAL;
        return 0;
    }
    if(length % 2 == 0)
        return (arr[length / 2] + arr[length / 2 + 1]) / 2;
    else 
        return arr[length / 2];
}

unsigned char find_mean(unsigned char* arr, const unsigned int length) {
    if(length < 1) {
        errno = EINVAL;
        return 0;
    }
    unsigned int sum = 0;
    for(unsigned int i = 0; i < length; i++)
        sum += arr[i];
    return sum / length;
}

unsigned char find_maximum(unsigned char* arr, const unsigned int length) {
    if(length < 1) {
        errno = EINVAL;
        return 0;
    }
    return arr[0];
}

unsigned char find_minimum(unsigned char* arr, const unsigned int length) {
    if(length < 1) {
        errno = EINVAL;
        return 0;
    }
    return arr[length - 1];
}
