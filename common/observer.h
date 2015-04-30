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
	std::auto_ptr<student::common::Logger> pLogger(new student::common::Logger(logFileName));
    double* timer_data;

public:
    Observer();
    virtual ~Observer();

public:
    virtual void timer_start();
    virtual void timer_stop();
    virtual void log_timer();
};



#endif
