/**
 * \file Utils.h
 * \author Orion Serup (orionserup@gmail.com)
 * \brief 
 * \version 0.1
 * \date 01-24-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef UTILS
#define UTILS

#include "Array.h"

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

// Fancy Assert For Much Easier Debug, Prints Custom Message, Line Number and File Name in Red
#ifdef __unix__
/// Linux/MAC Debug Assert, Adds Coloration, Messages, and File and Line Numbers for Better Debugging
#define Assert(condition, msg) assert(condition || !fprintf(stderr, "\x1B[31m%s on Line: %d of File %s\n\x1B[0m", msg, __LINE__, __FILE__))
#else
/// Implementation of any other OS, no Colors but otherwise the same
#define Assert(condition, msg) assert(condition || !fprintf(stderr, "\t%s on Line: %d of File %s\n", msg, __LINE__, __FILE__))
#endif

/**
 * \brief Sums all of the elements in an Array and returns the value
 * 
 * \param array: The Array to Sum
 * \return Data: The Sum of the Array
 */
Data SumArray(const Array array);

#define SumArr(arr, size) SumArray((Array){ arr, size });

/**
 * \brief 
 * 
 * \param array 
 * \return size_t 
 */
size_t FindArrayMax(const Array array);

#define FindArrMax(arr, size) FindArrayMax({ arr, size })

#define ArrayMax(array) array.ptr[FindArrayMax(array)]
#define ArrMax(arr, size) arr[FindArrMax(arr, size)] 

/**
 * \brief 
 * 
 * \param array 
 * \return size_t 
 */
size_t FindArrayMin(const Array array);

/// Wrapper for C Arrays
#define FindArrMin(arr, size) FindArrayMin({ arr, size })

/// Shortcut
#define ArrayMin(array) array.ptr[FindArrayMin(array)]

/// Wrapper for C Arrays
#define ArrMin(arr, size) arr[FindArrMin(arr, size)] 

void FPrintArray(FILE* const file, const Array array);

#define FPrintArr(arr, size) FPrintArray({arr, size})

#define PrintArray(array) FPrintArray(stdout, array)
#define PrintArr(arr, size) PrintArray({arr, size})

#endif
