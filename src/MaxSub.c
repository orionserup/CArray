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

static Array MaxCrossingSub(const Array array);

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

Array MaxSubArrayRec(const Array array) {

    Assert(array.ptr, "Invalid Array In Max Sub Array Recursize");

    if(array.size < 2) 
        return array;

    size_t mid = array.size / 2;

    Array maxes[3]; // hold the top sub arrays
    Data sums[3]; // to hold the sum of the sub arrays

    maxes[0] = MaxSubArrayRec((Array){ array.ptr, mid });
    sums[0] = SumArray(maxes[0]);
    
    maxes[1] = MaxSubArrayRec((Array){ array.ptr + mid, array.size - mid });
    sums[1] = SumArray(maxes[1]);

    maxes[2] = MaxCrossingSub(array);
    sums[2] = SumArray(maxes[2]);

    return maxes[FindArrMax(sums, 3)];

}

Array MaxCrossingSub(const Array array) {

    Assert(array.ptr, "Invalid Array Pointer In Max Crossing Sub");

    Data sum = 0;
    Data sums[3];

    size_t middle = array.size / 2;
    size_t left = middle;
    size_t right = middle;

    sums[0] = minof(Data);
    for(size_t i = middle; i >= 0; i--) {
        sum += array.ptr[i];
        if(sum > sums[0]) {
            sums[0] = sum;
            left = i;
        }
    }

    sum = 0;
    sums[1] = minof(Data);
    for(size_t i = middle + 1; i < array.size; i++) {
        sum += array.ptr[i];
        if(sum > sums[1]) {
            sums[1] = sum;
            right = i;
        }
    }

    sums[2] = SumArr(sums, 2);

    Array arrays[] = {
         { array.ptr + left, middle - left },
         { array.ptr + middle, right - middle},
         { array.ptr + left, array.size - right - left }
    };

    return arrays[FindArrMax(sums, 3)];

}

Array MaxSubArrayLin(const Array array) {


    return array;

}




