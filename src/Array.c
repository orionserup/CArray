/**
 * \file Array.c
 * \author Orion Serup (orionserup@gmail.com)
 * \brief 
 * \version 0.1
 * \date 01-25-2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Array.h"
#include "Utils.h"

/**
 * \brief Get the Element object
 * 
 * \param array 
 * \param element 
 * \return Data 
 */
inline Data GetElement(const Array array, const size_t element) {

    Assert(array.ptr, "Invalid Array Pointer in Get Element");
    #ifndef NDEBUG

    if(element >= array.size)
        Assert(false, "ERROR: Invalid Array Access, Element too Large");
        getchar();
        exit(EXIT_FAILURE);

    #endif

    return array.ptr[element];

}

/**
 * \brief Get the Element object
 * 
 * \param array 
 * \param element 
 * \return Data 
 */
inline Data SetElement(const Array array, const size_t element, const Data value) {

    Assert(array.ptr, "Invalid Array Pointer in Get Element");
    #ifndef NDEBUG

    if(element >= array.size)
        Assert(false, "ERROR: Invalid Array Access, Element too Large");
        getchar();
        exit(EXIT_FAILURE);

    #endif
    
    array.ptr[element] = value;
    return value; 

}


