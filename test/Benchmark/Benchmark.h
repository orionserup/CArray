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

typedef Array (*SubArrFunc)(const Array array);
typedef size_t (*ArrSearchFunc)(const Array array, const Data value);
typedef Array (*ArrSortFunc)(const Array array);

typedef union {

    SubArrFunc subfun;
    ArrSearchFunc searchfun;
    ArrSortFunc sortfun;

} ArrayFunc;

typedef enum {

    SEARCH,
    SORT,
    SUB

} ArrayFuncType;

typedef struct {

    ArrayFunc function;
    ArrayFuncType functiontype;

} ArrayFunction;


typedef struct {

    Array array;
    size_t index;

} FuncResult;

typedef struct {

    size_t n;
    double time_ms;

} TimeData;

typedef struct {

    Array array;
    TimeData timedata;

} SubArrayTimeData;

typedef SubArrayTimeData ArraySortTimeData;

typedef struct {

    size_t index;
    TimeData timedata;

} ArraySearchTimeData;

typedef union {

    ArraySearchTimeData searchdata;
    ArraySortTimeData sortdata;
    SubArrayTimeData subdata;

} ArrayTimeData;


/**
 * \brief 
 * 
 * \param fun 
 * \param array 
 * \param subarrsize 
 * \return TimeData 
 */
TimeData TimeSubArrFunc(const SubArrFunc fun, const Array array, Array* const output);

/**
 * \brief 
 * 
 * \param func 
 * \param trials 
 * \param numtrials 
 * \param numtimes 
 */
void BenchmarkArrayFunction(const ArrayFunction func, const Data* trials, const size_t numtrials, const size_t numtimes);

#endif

