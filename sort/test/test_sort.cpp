/*
 * test_test_sort.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: Sheaimss
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <string>
#include <fstream>

#include "common/catch.hpp"
#include "common/logger.h"
#include "../sort.h"
#include "../Stoper.hh"

TEST_CASE( "sorter sortSimpleArrays", "[factorial]" ) {
//pre
    const std::string logFileName = "lolz.txt";
	std::auto_ptr<student::common::Logger> pLogger(new student::common::Logger(logFileName));
	LARGE_INTEGER performanceCountStart,performanceCountEnd;
    double tm;
    double time = 0;
    CombSorter* pCombSorter;
//given
    int arrayLength = 10;
//when

    for (int i=0; i<5; i++)
    {
        for(int i=0; i<5; i++)
        {
            arrayLength *= 10;
            pCombSorter = new CombSorter(arrayLength);
            pCombSorter->generateArray();
            performanceCountStart = startTimer();
            pCombSorter->combSort();
            performanceCountEnd = endTimer();
            tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
            time = time +tm;
            delete pCombSorter;
        }
        time = time/5;
        pLogger->log("number of elements: ");
        pLogger->log(arrayLength);
        pLogger->log("time");
        pLogger->log(time);
    }
//then
    REQUIRE(false);
//cleanup
}
