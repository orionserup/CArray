/**
 * \file Utils.c
 * \author Orion Serup (orionserup@gmail.com)
 * \brief 
 * \version 0.1
 * \date 01-24-2022
 * 
 * \copyright Copyright (c) 2022
 * 
 */

#include "Utils.h"

Data SumArray(const Array array) {

    Assert(array.ptr, "Invalid Array Data In Sum Array");

    Data sum = 0;
    for(size_t i = 0; i < array.size; i++)
        sum += array.ptr[i];

    return sum;
}

size_t FindArrayMax(const Array array) {

    Assert(array.ptr, "Invalid Array In Find Array Max");

    size_t index = 0;
    for(size_t i = 1; i < array.size; i++) 
        if(array.ptr[i] > array.ptr[index])
            index = i;

    return index;

}

size_t FindArrayMin(const Array array) {

    Assert(array.ptr, "Invalid Array In Find Array Max");

    size_t index = 0;
    for(size_t i = 1; i < array.size; i++) 
        if(array.ptr[i] < array.ptr[index])
            index = i;

    return index;

}

void FPrintArray(FILE* const file, const Array array) {

    Assert(file, "Invalid File Pointer in Print Array to File");

    for(size_t i = 0; i < array.size; i++)
        fprintf(file, "%ld ", (int64_t)array.ptr[i]);

    fputc('\n', file);

}
