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

void quicksort_number(int* collection)
{
    int array_size;
    array_size = sizeof(collection)/sizeof(int);
    int pivot;
    int* low;
    int* high;
    int counterOfLowArrayElements=0;
    int counterOfHighArrayElements=0;
    for (int i=0; i<array_size; ++i)
    {
        pivot = collection[i];
    }
    pivot = pivot/array_size;
    for(int i=0;i<array_size;i++)
    {
        if (collection[i]<=pivot)
        {
            low[counterOfLowArrayElements]=collection[i];
            ++counterOfLowArrayElements;
        }
        else
            if(collection[i]>pivot)
        {
            high[counterOfHighArrayElements]=collection[i];
            ++counterOfHighArrayElements;
        }
        else
        {
            std::cout<<wrong_value_error_message<<std::endl;
            break;
        }
    }
}




