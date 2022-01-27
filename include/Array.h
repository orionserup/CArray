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
typedef int32_t Data; 

typedef Data* Arr;

typedef struct {

    Arr ptr;
    size_t size;

} Array;

/**
 * \brief Get the Element object
 * 
 * \param array 
 * \param element 
 * \return Data 
 */
inline Data GetElement(const Array array, const size_t element);

/**
 * \brief Get the Element object
 * 
 * \param array 
 * \param element 
 * \return Data 
 */
inline Data SetElement(const Array array, const size_t element, const Data value);

/**
 * \brief Get the C Array Pointer from the Array
 * 
 * \param array 
 * \return Data* 
 */
inline Arr GetCArr(const Array* const array);

/**
 * \brief Get the Size object
 * 
 * \param array 
 * \return size_t 
 */
inline size_t GetSize(const Array* const array);

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

#define DeleteArr(arr) DeleteArray({arr, 0})

#define ARRAY Array
#endif