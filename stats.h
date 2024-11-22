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
 * @file stats.h
 * @brief Declaration and documentation of statistical functions.
 *
 * This file declares, and documents, a number of useful statistical functions.
 * Most functions take as input a unsigned char pointer to an n-element data
 * array and unsigned integer as the size of the array, and return an unsigned
 * character result.
 * 
 *
 * @author Hatem Alamir
 * @date 11/20/2024
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief A function that prints the statistics of an array including minimum,
 * maximum, mean, and median
 *
 * This function takes an input array of data and length, it calculates some
 * useful statistics like minimum, maximum, mean, and median, by calling other
 * specialized functions, format the output of each to be easily and pleasantly
 * readable, and printing the results to the screen.
 * *WARNING*: This function chantes the order of the array elements since it sorts
 * the array first to speed up calculating the different statistics.
 *
 * @param arr The input array for which to calculate and print stats
 * @param length The length of the array 
 *
 * @return This function does not return any value 
 */
void print_statistics(unsigned char* arr, const unsigned int length);

/**
 * @brief Given an array of data and a length, prints the array to the screen
 *
 * This function specializes in printing an array to the screen. It serves as an
 * encapsulation of a rather common operation. The logic is simple, just loop
 * over the array and print the items one by one in one line separated by commas
 * and surrounded by square brackets. Standard output library is used.
 *
 * @param arr The input array for which to calculate and print stats
 * @param length The length of the array 
 *
 * @return This function does not return any value 
 */
void print_array(const unsigned char* arr, const unsigned int length);

/**
 * @brief Given an array of data and a length, returns the median value 
 *
 * This function calculates and returns the median of an array. If the array is
 * sorted, which is expected of the input to this function, the median is simply
 * the element in the middle of the array. If the array lenght is an even
 * number, the median would be the average of the two elements in the middle,
 * rounded to the nearest integer.
 *
 * @param arr DESCENDINGLY SORTED array for which to calculate the median
 * @param length The length of the array 
 *
 * @return This function does not return any value 
 */
unsigned char find_median(unsigned char* arr, const unsigned int length);

/**
 * @brief Given an array of data and a length, returns the mean 
 *
 * This function calculates and returns the mean of an array. The mean is the
 * mathematical average, which is the sum of elements divided by their number.
 *
 * @param arr The input array for which to calculate the mean
 * @param length The length of the array 
 *
 * @return This function does not return any value 
 */
unsigned char find_mean(unsigned char* arr, const unsigned int length);

/**
 * @brief Given an array of data and a length, returns the maximum
 *
 * This function calculates and returns the maximum value in an array. The
 * elements of the array are assumed to be sorted in an ascending order. That way
 * the maximum is just the first element of the array, index: 0 
 *
 * @param arr DESCENDINGLY SORTED array for which to calculate the maximum
 * @param length The length of the array 
 *
 * @return This function does not return any value 
 */
unsigned char find_maximum(unsigned char* arr, const unsigned int length);

/**
 * @brief Given an array of data and a length, returns the minimum
 *
 * This function calculates and returns the minimum value in an array. The
 * elements of the array are assumed to be sorted in an ascending order. That
 * way the minimum is just the last element of the array, index: length - 1
 * 
 *
 * @param arr DESCENDINGLY SORTED array for which to calculate the minimum
 * @param length The length of the array 
 *
 * @return This function does not return any value 
 */
unsigned char find_minimum(unsigned char* arr, const unsigned int length);

/**
 * @brief Given an array of data and a length, sorts the array from largest to
 * smallest
 *
 * This function sorts an array in a descending order, the zeroth Element should
 * be the largest value, and the last element (n-1) should be the smallest 
 * value. Merge sort is used here.
 * 
 *
 * @param arr array to be sorted
 * @param length The length of the array 
 *
 * @return This function does not return any value 
 */
unsigned char sort_array(unsigned char* arr, const unsigned int length);

#endif /* __STATS_H__ */
