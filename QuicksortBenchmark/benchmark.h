#ifndef BENCHMARK_H_
#define BENCHMARK_H_

#include "Stos.hh"

class benchmark_number
{
private:
    Stos<int> *arrayStack;
    double timer;

protected:
    benchmark_number();

public:
    benchmark_number(int* inputArray, int inputArrayLenght);
    virtual ~benchmark_number();

public:
    virtual double runBenchmark();
    virtual void changeArray(int* newArray, int newArraySize);
    virtual void resetTimer();
    virtual double readTimer();
};



#endif // BENCHMARK_H_
