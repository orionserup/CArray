/**
 * \file MaxSub.c
 * \author Orion Serup (orionserup@gmail.com)
 * \brief 
 * \version 0.1
 * \date 01-24-2022
 * 
 * \copyright Copyright (c) 2022
 * 
 */

#include "MaxSub.h"

Array MaxSubArrayBrute(const Array array) {

    Assert(array.ptr, "Invalid Array Data in Max Sub Array");

    if(array.size < 2) 
        return array; 

    Data* arr = array.ptr;
    size_t size = array.size;

    Data sum = 0; 
    Data max = SumArray(array);

    for(size_t i = 0; i < array.size; i++, sum = 0) {
        for(size_t j = i; j < array.size; j++) {

            sum += array.ptr[j];
            if(sum > max) {
                max = sum;
                arr = array.ptr + i;
                size = j - i + 1;
            }
        }
    }

    return (Array){ arr, size };

}

Array MaxSubArrayRec(const Array const array) {




}

Array MaxSubArrayLin(const Array const array) {


    return array;

}




