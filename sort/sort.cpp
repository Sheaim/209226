#ifndef SORT_CPP_
#define SORT_CPP_

#include <iostream>
#include <fstream>
#include <math.h>
#include <cstdlib>

#include "sort.h"

CombSorter::CombSorter(int setArrayLength)
{
    sortedArray = new int[setArrayLength];
    arrayLength = setArrayLength;
    shrinkFactor = 1.3; //usual value for comb sort.
}

CombSorter::~CombSorter()
{
    delete[] sortedArray;
    arrayLength = 0;
}
void CombSorter::resizeArray(int newArrayLength)
{
    delete[] sortedArray;
    sortedArray = new int[newArrayLength];
    arrayLength = newArrayLength;
}

void CombSorter::generateArray()
{

    for (int i=0;i<arrayLength;i++)
    {
        sortedArray[i]=rand()%1000;
        std::cout<<sortedArray[i]<<" ";
    }
    std::cout<<std::endl;
}

void CombSorter::combSort()
{
    int gap = arrayLength;
    int i;
    int temp;
    while(!checkIfSorted())
    {
        std::cout<<"I'm doing something"<<std::endl;
        gap = gap/shrinkFactor;
        std::cout<<"New gap: "<<gap<<std::endl;
        if(gap<1)
        {
            gap=1;
        }
        i=0;
        while(i+gap < arrayLength)
            {
                std::cout<<"comparing "<<sortedArray[i]<<" with "<<sortedArray[i+gap]<<std::endl;
                if(sortedArray[i]>sortedArray[i+gap])
                {
                    temp = sortedArray[i];
                    sortedArray[i] = sortedArray[i+gap];
                    sortedArray[i+gap] = temp;
                    std::cout<<"swapping"<<std::endl;
                }
                ++i;
            }

    }
}

bool CombSorter::checkIfSorted()
{
    for (int i=0; i<arrayLength-1; ++i)
    {
        std::cout<<sortedArray[i]<<" ";
        if(sortedArray[i]>sortedArray[i+1])
            {
                std::cout<<sortedArray[i+1];
                std::cout<<"\nError: Array not sorted"<<std::endl;
                return false;
            }
    }
    std::cout<<sortedArray[arrayLength-1]<<std::endl;
    std::cout<<"Array sorted"<<std::endl;
    return true;
}
#endif // SORT_CPP_
