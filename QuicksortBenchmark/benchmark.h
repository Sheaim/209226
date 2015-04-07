#ifndef BENCHMARK_H_
#define BENCHMARK_H_

#include "Stos.hh"
#include "common/logger.h"
#include "Stoper.hh"
#include "quicksort/quicksort.h"


template <typename type>
class benchmark_number
{
private:
    Stos<type> *arrayStack;
    double timer;

protected:
    benchmark_number();

public:
    benchmark_number(type* inputArray, int inputArrayLenght);
    virtual ~benchmark_number();

public:
    virtual double runBenchmark();
    virtual void changeArray(type* newArray, int newArraySize);
    virtual void resetTimer();
    virtual double readTimer();
};

//As templates can't be defined outside header file

template <typename type>
benchmark_number<type>::benchmark_number(type* inputArray, int inputArrayLenght)
{
    arrayStack = new Stos<type>();
    for(int i=0; i<inputArrayLenght; ++i)
    {
        arrayStack->push200(inputArray[i]);
    }
    timer = 0;
}

template <typename type>
benchmark_number<type>::~benchmark_number()
{
    delete arrayStack;
    timer=0;
}

template <typename type>
double benchmark_number<type>::readTimer()
{
    return timer;
}

template <typename type>
double benchmark_number<type>::runBenchmark()
{

    int tempLenght = arrayStack->size_licznik();
    int* temp = new type[tempLenght];

    LARGE_INTEGER performanceCountStart,performanceCountEnd;
    performanceCountStart = startTimer();
    for(int i=0; i<tempLenght; ++i)
    {
        temp[i] = quicksort(arrayStack->getTab(), arrayStack->size_licznik())[i];
        performanceCountEnd = endTimer();
    }
    delete arrayStack;
    arrayStack = new Stos<type>();
    for (int i=0; i<tempLenght; ++i)
    {
        arrayStack->push200(temp[i]);
    }
    timer = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
    return timer;
}

template <typename type>
void benchmark_number<type>::changeArray(type* newArray, int newArrayLenght)
{
    delete arrayStack;
    arrayStack = new Stos<type>;
    for(int i=0; i<newArrayLenght; ++i)
    {
        arrayStack->push200(newArray[i]);
    }
}
template <typename type>
void benchmark_number<type>::resetTimer()
{
    timer=0;
}



#endif // BENCHMARK_H_
