/**
 * \file MaxSub.h
 * \author Orion Serup (orionserup@gmail.com)
 * \brief 
 * \version 0.1
 * \date 01-24-2022
 * 
 * \copyright Copyright (c) 2022
 * 
 */
#ifndef MAXSUBARRAY
#include "Utils.h"

/**
 * \brief 
 * 
 * \param array 
 * \param subarrsize 
 * \return Array 
 */
Array MaxSubArrayBrute(const Array array);
#define MAXSUB_BRUTE (ArrayFunction){ MaxSubArrayBrute, SUB }  // a global definition for benchmarking

/// Wrapper for C Array Calls
#define MaxSubArrBrute(arr, size) MaxSubArrayBrute({arr, size})

/**
 * \brief 
 * 
 * \param array 
 * \param subarrsize 
 * \return Array 
 */
Array MaxSubArrayRec(const Array array);

/// C Array Wrapper
#define MaxSubArrRec(arr, size, subarrsize) MaxSubArrRec({arr, size})

/**
 * \brief 
 * 
 * \param array 
 * \param subarrsize 
 * \return Array 
 */
Array MaxSubArrayLin(const Array array);

/// C Array Wrapper
#define MaxSubArrLin(arr, size, subarrsize) MaxSubArrayLin({arr, size})

/// The Default Function: Choose the Fastest One
#define MAXSUBARRAY MaxSubArrayLin
#define MaxSubArr(arr, size, subsize) MaxSubArray({arr, size})

#endif
