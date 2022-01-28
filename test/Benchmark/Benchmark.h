/**
 * \file Benchmark.h
 * \author Orion Serup (orionserup@gmail.com)
 * \brief 
 * \version 0.1
 * \date 01-24-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef BENCHMARK_H
#define BENCHMARK_H

#include "MaxSub.h"
#include "Utils.h"

/// The Signature for a Sub Array Function
typedef Array (*SubFunc)(const Array array);

/// The Signature for a Search Function
typedef size_t (*SearchFunc)(const Array array, const Data value);

/// The Signature for a Sorting Function
typedef Array (*SortFunc)(const Array array);

typedef struct {

    SubFunc function; ///< The Sub Array Function Pointer
    const char* const name; ///< The Name of the Functions

} ArraySubFun;  // Structure representing a Sub Array Function

typedef ArraySubFun ArraySort; // Sorts and SUb Array Functions have the same signature

typedef struct {

    SearchFunc function;  ///< The Actual Search Function Pointer
    const char* const name; ///< The Name of the Function

} ArraySearch;  // A Generic Structure for all Array Searching Functions

/// A Generic Object With any Array Function
typedef union { 

    ArraySubFun subfun;  ///< It could be a Sub Array Function
    ArraySearch searchfun; ///< Search Function
    ArraySort sortfun; ///< or Sorting Function

} ArrayFunc; // Good for benchmarking

/// Function Identification
typedef enum { // an Identifier for What Type of Function a Pointer is

    SEARCH,  ///< Is it a Searching Function
    SORT,    ///< A Sorting Function
    SUB      ///< Or a Sub Array Function

} ArrayFuncType;

/// A Complete Generic Function Structure
typedef struct {

    ArrayFunc function; ///< A Generic Function
    ArrayFuncType functiontype; ///< The Type of that Function

} ArrayFunction;

/// A Struct to Record the Number of Elements and Time of an Operation
typedef struct {

    size_t n;  ///< The Number of Elements
    double time_ms; ///< The Time in Milliseconds

} TimeData;

/**
 * \brief Times a Sub Array Function
 * 
 * \param fun: The Function to Run on the Array
 * \param array: The Array to Time it with
 * \param output[out]: The Resulting Sub Array from the Operation
 * \return TimeData The Number of Elements and Time it took
 */
TimeData TimeSubArrayFun(const SubFunc fun, const Array array, Array* const result) ;


/**
 * \brief Times an Array Search Function
 * 
 * \param search: The Search Function to Time
 * \param array: The Array to Look in
 * \param value: The Value to Look for
 * \param result[out]: The Location of the Element
 * \return TimeData: The Size of the Array Searched and How Long it Took
 */
TimeData TimeArraySearch(const SearchFunc search, const Array array, const Data value, size_t* const result);

/// Wrapper for Basic C Array Usage
#define TimeArrSearch(search, arr, size, result) TimeArraySearch(search, {arr, size}, result)

/**
 * \brief Times a Sorting Function on a Given Array
 * 
 * \param sort: The Actual Sort Function
 * \param array: The Array to Sort 
 * \return TimeData: The Number of Elements that were sorted and how long it took 
 */
TimeData TimeArraySort(const SortFunc sort, const Array array);
/// Wrapper for Basic C Array Usage
#define TimeArrSort(sort, arr, size) TimeArraySort(sort, {arr, sort})

/**
 * \brief 
 * 
 * \param func 
 * \param trials 
 * \param numtrials 
 * \param numtimes 
 */
void BenchmarkArrayFunction(const ArrayFunction func, const Array trials, const size_t numtimes);

/**
 * \brief 
 * 
 * \param funcs 
 * \param numfuncs 
 * \param trials 
 * \param numtimes 
 */
void BenchmarkArrayFunctions(const ArrayFunction* funcs, const size_t numfuncs, const Array trials, const size_t numtimes);

#endif

