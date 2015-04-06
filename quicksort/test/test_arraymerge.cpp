/*
 * test_logger.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: sheaim
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <string>
#include <fstream>

#include "common/logger.h"
#include "../catch.hpp"
#include "../quicksort.h"

TEST_CASE( "arraymerge mergeSimpleArrays", "[factorial]" ) {

	// pre
	std::cout<<"abc"<<std::endl;
    const std::string logFileName = "lolz.txt";
	std::auto_ptr<student::common::Logger> pLogger(new student::common::Logger(logFileName));

	// given
	int testing_low[2] = {1, 2};
	int testing_high[3] = {3, 4, 5};
	int expected_tab[5] = {1, 2, 3, 4, 5};
    int low_lenght = sizeof(testing_low)/sizeof(int);
    int high_lenght = sizeof(testing_high)/sizeof(int);
    int tab_lenght = sizeof(expected_tab)/sizeof(int);
	int* result_tab = new int[tab_lenght];
	// when
	pLogger->log(testing_low, low_lenght);
	pLogger->log(testing_high, high_lenght);
	result_tab = merge_arrays(testing_low, low_lenght, testing_high, high_lenght);
    pLogger->log(result_tab, tab_lenght);
    pLogger->log(expected_tab, tab_lenght);
	// then
	for(int i=0; i<tab_lenght;++i)
	{
        REQUIRE(result_tab[i] == expected_tab[i]);
	}
	//cleanup

}
