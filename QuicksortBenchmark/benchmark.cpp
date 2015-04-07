#include <iostream>
#include "benchmark.h"
#include "common/logger.h"
#include "Stoper.hh"

benchmark_number::benchmark_number(int* inputArray, int inputArrayLenght)
{
    arrayStack = new Stos<int>();
    for(int i=0; i<inputArrayLenght; ++i)
    {
        arrayStack->push200(inputArray[i]);
    }
    timer = 0;
}
benchmark_number::~benchmark_number()
{
    delete arrayStack;
    timer=0;
}

double benchmark_number::readTimer()
{
    return timer;
}

double benchmark_number::runBenchmark()
{
    return timer;
}
void benchmark_number::changeArray(int* newArray, int newArrayLenght)
{
    delete arrayStack;
    arrayStack = new Stos<int>;
    for(int i=0; i<newArrayLenght; ++i)
    {
        arrayStack->push200(newArray[i]);
    }
}
void benchmark_number::resetTimer()
{
//    timer=0;
}
