/*
 * quicksort.cpp
 * created on april 5 2015
 * author: sheaim
 *
 */
#include <iostream>
#include "quicksort/quicksort.h"
#include "common/logger.h"

const std::string wrong_value_error_message = "Error: array part is not a number.";

int* merge_arrays(int* low, int lowArraySize, int* high, int highArraySize)
{
    for(int i=0; i<lowArraySize;++i)
    {
        std::cout<<low[i]<<" ";
    }
    std::cout<<std::endl;
    int mergedArraySize = lowArraySize+highArraySize;
    int* mergedArray = new int[mergedArraySize];
    for(int i=0; i<lowArraySize;++i)
    {
        mergedArray[i] = low[i];
    }
    for(int i=0; i<highArraySize;++i)
    {
        std::cout<<high[i]<<" ";
    }
    std::cout<<std::endl;
    for(int i=0; i<highArraySize;++i)
    {
        mergedArray[i+lowArraySize] = high[i];
    }
    for(int i=0; i<mergedArraySize;++i)
    {
        std::cout<<mergedArray[i]<<" ";
    }
    std::cout<<std::endl;
    return mergedArray;
}

int* quicksort_number(int* collection, int array_size)
{
    int pivot;
    int* low = new int[array_size];
    int* high = new int[array_size];
    int counterOfLowArrayElements=0;
    int counterOfHighArrayElements=0;
    for(int i=0; i<array_size;++i)
    {
        std::cout<<collection[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"finding pivot"<<std::endl;
    pivot = 0;
    for (int i=0; i<array_size; ++i)
    {
        pivot = pivot + collection[i];
    }
    pivot = pivot/array_size;
    for(int i=0; i<array_size; ++i)
    {
        if (collection[i]<=pivot)
        {
            std::cout<<"adding "<<collection[i]<<"to low"<<std::endl;
            low[counterOfLowArrayElements]=collection[i];
            ++counterOfLowArrayElements;
        }
        else
            if(collection[i]>pivot)
        {
            high[counterOfHighArrayElements]=collection[i];
            ++counterOfHighArrayElements;
            std::cout<<"adding "<<collection[i]<<"to high"<<std::endl;
        }
        else
        {
            std::cout<<wrong_value_error_message<<std::endl;
            break;
        }
    }

    if(counterOfLowArrayElements!=1)
    {
        quicksort_number(low, counterOfLowArrayElements);
        quicksort_number(high, counterOfHighArrayElements);
    }

    collection = merge_arrays(low, counterOfLowArrayElements, high, counterOfHighArrayElements);
    for(int i=0; i<array_size;++i)
    {
        std::cout<<collection[i]<<" ";
    }
    std::cout<<std::endl;
    return collection;
}




