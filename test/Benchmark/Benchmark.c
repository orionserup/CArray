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

#ifndef _MSC_VER
#define DATA_PATH "../data/"
#else
#define DATA_PATH "..\\..\\data\\"
#endif

static inline void WriteTimeDataToFile(FILE* const file, const TimeData data);

static void BenchmarkSubArrayFunction(const ArraySubFun fun, const Array trials, const size_t numtimes);
static void BenchmarkArraySort(const ArraySort sort, const Array trials, const size_t numtimes);
static void BenchmarkArraySearch(const ArraySearch, const Array trials, const size_t numtimes);


TimeData TimeSubArrayFun(const SubFunc fun, const Array array, Array* const result) {

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

TimeData TimeArraySortFunc(const SortFunc sort, const Array array) {

    Assert(sort, "Invalid Sort Function in Time Sort Function");
    Assert(array.ptr, "Invalid Array in Time Sort Function");

    clock_t start = clock();
    sort(array);
    clock_t end = clock();

    TimeData data = (TimeData) { 
        .n = array.size , 
        .time_ms = (end - start)*1000.0f/CLOCKS_PER_SEC 
    };

    return data;

}

TimeData TimeArraySearchFunc(const SearchFunc search, const Array array, const Data value, size_t* const result) {

    Assert(search, "Invalid Search Function in Time Search Function");
    Assert(array.ptr, "Invalid Array in Time Search Function");

    clock_t start = clock();
    *result = search(array, value);
    clock_t end = clock();

    TimeData data = (TimeData) { 
        .n = array.size , 
        .time_ms = (end - start)*1000.0f/CLOCKS_PER_SEC 
    };

    return data;

}


void BenchmarkArrayFunction(const ArrayFunction func, const Array trials, const size_t numtimes) {

    switch(func.functiontype) {

        case SUB:
            BenchmarkSubArrayFunction(func.function.subfun, trials, numtimes);
            break;
        case SORT:
            BenchmarkArraySort(func.function.sortfun, trials, numtimes);
            break;
        case SEARCH:
            BenchmarkArraySearch(func.function.searchfun, trials, numtimes);
            break;

        default: break;
    }
}

void BenchmarkSubArrayFunction(const ArraySubFun fun, const Array trials, const size_t numtimes) {

    Assert(fun.function, "Invalid Sub Array Function in Benchmark Sub Array Function");
    Assert(trials.ptr, "Invalid Trials Array in Benchmark Sub Array Function");

    // Find the Largest Number of elements we are to test, we need an array that size
    Data max = ArrayMax(trials);
    #ifndef VLA
    // We need an Array that can hold up to the max number of elements we will be using
    Data* arr = malloc(sizeof(Data) * max);
    // We need a time point for every trials run numtimes times
    TimeData* times = malloc(sizeof(TimeData) * trials.size * numtimes); 
    #else
    // Same as Above but with Variable Length Arrays
    Data arr[max];
    TimeData data[trials.size * numtimes];
    #endif
    
    Assert(sizeof(DATA_PATH) < 125, "Data Path is too Long");
    Assert(strlen(fun.name) < 125, "Function Name is Too Long");

    char buffer[255];
    strncpy(buffer, DATA_PATH, 125);
    strncat(buffer, fun.name, 125);
    strcat(buffer, ".csv");
    FILE* file = fopen(buffer, "w");
    #ifdef LOG
    strcpy(buffer + strlen(buffer) - 3, "log");
    FILE* log = fopen(buffer, "w");
    fprintf(log, "%s Log \n\n", fun.name);
    #endif

    Array array = { arr, max };
    
    for(size_t j = 0; j < numtimes; j++) {

        srand(clock());
        for(size_t i = 0; i < array.size; i++)
            array.ptr[i] = (Data)(rand() & 4? rand(): -rand()); // generates a stream of negative and positve random numbers

        for(size_t i = 0; i < trials.size; i++) {

            Array output; /// we need an array to store the output in
            array.size = trials.ptr[i]; // We are using the size sepcified by the trials array
            times[i + trials.size * j] = TimeSubArrayFun(fun.function, array, &output);

            #ifdef LOG
            fputs("Searched Array: \n", log);
            FPrintArray(log, array);
            fputs("Sub Array Found: \n", log);
            FPrintArray(log, output);
            fprintf(log, "Sum of the Array: %ld\n\n", (long)SumArray(output));
            #endif
        }
    }

    for(size_t i = 0; i < trials.size; i++) {

        for(size_t j = 1; j < numtimes; j++)
            times[i].time_ms += times[i + j * trials.size].time_ms;

        times[i].time_ms /= numtimes;

        WriteTimeDataToFile(file, times[i]);

    }

    #ifndef VLA
    free(arr);
    free(times);
    #endif
    #ifdef LOG
    fclose(log);
    #endif

    fclose(file);

}

void BenchmarkArraySort(const ArraySort sort, const Array trials, const size_t numtimes) {}
void BenchmarkArraySearch(const ArraySearch search, const Array trials, const size_t numtimes) {}


void WriteTimeDataToFile(FILE* const file, const TimeData data) {

    Assert(file, "Invalid File Pointer in Write Time Data to File");

    fprintf(file, "%zu, %lf\n", data.n, data.time_ms);

}

