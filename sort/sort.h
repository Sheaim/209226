#ifndef SORT_H_
#define SORT_H_

#include <iostream>
#include <fstream>
#include <math.h>

class CombSorter
{
protected:
    CombSorter(); //we don't want someone to try to use this.

private:
    int* sortedArray;
    int arrayLength;
    float shrinkFactor;

public:
    CombSorter(int setArrayLength);
    virtual ~CombSorter();

public:
    virtual void resizeArray(int newArraySize);
    virtual void generateArray();
    virtual void combSort();
    virtual bool checkIfSorted();
};

#endif // SORT_H_
