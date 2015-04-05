#include "observer.h"
#include "windows.h"
Observer::Observer()
{
    logFileName = "ObserverOutput.txt";
    pLogger = new student::common::Logger(logFileName);
    numberOfDataEntries = -1;
    timerData = NULL;
}

Observer::~Observer()
{
    delete pLogger;
    delete timerData;
    numberOfDataEntries = -1;
}

double trigger()
{
    LARGE_INTEGER trig;
    DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
    QueryPerformanceCounter(&trig);
    SetThreadAffinityMask(GetCurrentThread(), oldmask);
    return trig.QuadPart;
}

void Observer::triggerTimer()
{
    if(numberOfDataEntries==-1)
        {

            start = trigger();
            ++numberOfDataEntries;
        }
    else
        {
            stop = trigger();
            if(numberOfDataEntries==0)
            {

                ++numberOfDataEntries;
                timerData = new double [numberOfDataEntries];
                timerData[numberOfDataEntries] = stop - start;
            }
            else
            {
                double* temp = new double [numberOfDataEntries];
                temp = timerData;
                ++numberOfDataEntries;
                delete[] timerData;
                for (int i=0; i<numberOfDataEntries-1; ++i)
                {
                    timerData[i] = temp[i];
                }
                timerData[numberOfDataEntries-1] = stop - start;
            }
        }
}

void Observer::logTimer()
{
    pLogger->log(timerData, numberOfDataEntries);
}

void Observer::reset()
{
    delete[] timerData;
    numberOfDataEntries = -1;
}
