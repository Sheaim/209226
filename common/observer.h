/*
 *  observer.h
 *  author: Sheaim
 *  created on: 30 Apr. 2015
 *
 */


#ifndef OBSERVER_H_
#define OBSERVER_H_
#include <windows.h>
#include "logger.h"

class Observer
{
private:
    std::string logFileName;
    student::common::Logger* pLogger;
    double* timerData;
    int numberOfDataEntries;
    double start;
    double stop;

public:
    Observer();
    virtual ~Observer();

public:
    virtual void triggerTimer();
    virtual void logTimer();
    virtual void reset();
    virtual double* giveTimerData();
};
#endif
