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
    }
}

void CombSorter::combSort()
{
    int gap = arrayLength;
    int i;
    int temp;
    while(!checkIfSorted())
    {
        gap = gap/shrinkFactor;
        if(gap<1)
        {
            gap=1;
        }
        i=0;
        while(i+gap < arrayLength)
            {
                if(sortedArray[i]>sortedArray[i+gap])
                {
                    temp = sortedArray[i];
                    sortedArray[i] = sortedArray[i+gap];
                    sortedArray[i+gap] = temp;
                }
                ++i;
            }

    }
}

bool CombSorter::checkIfSorted()
{
    for (int i=0; i<arrayLength-1; ++i)
    {
        if(sortedArray[i]>sortedArray[i+1])
            {
                return false;
            }
    }
    std::cout<<"Array sorted"<<std::endl;
    return true;
}
#endif // SORT_CPP_
