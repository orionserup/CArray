/**
 * \file Benchmark.c
 * \author Orion Serup (orionserup@gmail.com)
 * \brief 
 * \version 0.1
 * \date 01-24-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Benchmark.h"

static inline void WriteTimeDataToFile(const FILE* file, const TimeData data);

TimeData TimeSubArrFunc(const SubArrFunc fun, const Array array, Array* const result) {

    Assert(fun, "Invalid Funciton Pointer in Time Sub Array Function");
    Assert(array.ptr, "Invalid Array Pointer in Time Sub Array Function");
    
    clock_t start = clock();
    *result = fun(array);
    clock_t end = clock();

    TimeData data = (TimeData) { 
        .n = array.size , 
        .time_ms = (end - start)*1000.0f/CLOCKS_PER_SEC 
    };

    return data;
}

TimeData TimeArraySortFunc(const ArrSortFunc fun, const Array array) {

    Assert(fun, "Invalid Soryt Function in Time Sort Function");
    Assert(array.ptr, "Invalid Array in Time Sort Function");

    clock_t start = clock();
    fun(array);
    clock_t end = clock();

    TimeData data = (TimeData) { 
        .n = array.size , 
        .time_ms = (end - start)*1000.0f/CLOCKS_PER_SEC 
    };

    return data;

}

TimeData TimeArraySearchFunc(const ArrSearchFunc fun, const Array array, const Data value, size_t* const result) {

    Assert(fun, "Invalid Search Function in Time Search Function");
    Assert(array.ptr, "Invalid Array in Time Search Function");

    clock_t start = clock();
    *result = fun(array, value);
    clock_t end = clock();

    TimeData data = (TimeData) { 
        .n = array.size , 
        .time_ms = (end - start)*1000.0f/CLOCKS_PER_SEC 
    };

    return data;

}


void BenchmarkArrayFunction(const ArrayFunction func, const Data* trials, const size_t numtrials, const size_t numtimes) {



}

void WriteTimeDatemToFile(const FILE* const file, const TimeData* const data, const size_t size) {

    Assert(file, "Invalid File Pointer In Write ");

    for(size_t i = 0; i < size; i++)
        WriteTimeDataToFile(file, data[i]);

}

void WriteTimeDataToFile(const FILE* file, const TimeData data) {

    Assert(file, "Invalid File Pointer in Write Time Data to File");

    fprintf(file, "%zu, %lf\n", data.n, data.time_ms);

}