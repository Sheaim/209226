/*
 * quicksort.cpp
 * created on april 5 2015
 * author: sheaim
 *
 */
#include <iostream>
#include "quicksort/quicksort.h"
#include "common/logger.h"


void quicksort_number(int* collection)
{
    int array_size;
    array_size = sizeof(collection)/sizeof(int);
    int pivot;
    int* temp;
    for (int i=0; i<array_size; ++i)
    {
        pivot = collection[i];
    }
    pivot = pivot/array_size;
    int* first_counter=&collection[0];
    int* second_counter=&collection[array_size];
    while(*first_counter<=*second_counter)
    {
        while(*first_counter<pivot)
        {
            ++first_counter;
            while(*second_counter>pivot)
            {
                --second_counter;
            }
        }
        temp = first_counter;
        first_counter=second_counter;
        second_counter=temp;
    }
}




