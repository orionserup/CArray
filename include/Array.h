/**
 * \file Array.h
 * \author Orion Serup (orionserup@gmail.com)
 * \brief 
 * \version 0.1
 * \date 01-25-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef ARRAY

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


/// The Data Being stored in the array
typedef int64_t Data; 

typedef Data* Arr;

typedef struct {

    Arr ptr;
    size_t size;

} Array;

/**
 * \brief 
 * 
 * \param size 
 * \return Array 
 */
Array AllocArray(const size_t size);

#define AllocArr(size) AllocArray(size).ptr

/**
 * \brief 
 * 
 * \param array 
 */
void DeleteArray(const Array array);

#define DeleteArr(arr) DeleteArray((Array){arr, 0})

#define ARRAY Array
#endif

