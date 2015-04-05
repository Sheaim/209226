/*
 * test_logger.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: topeerz
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <string>
#include <fstream>

#include "../catch.hpp"
#include "../quicksort.h"

TEST_CASE( "quicksort sortSimpleArray", "[factorial]" ) {

	// pre


	// given
	int testing_tab[5] = {2, 3, 5, 4, 1};
	int expected_tab[5] = {1, 2, 3, 4, 5};
    int tab_lenght = sizeof(testing_tab)/sizeof(int);
	// when
	quicksort_number(testing_tab);


	// then
	for(int i=0; i<tab_lenght;++i)
	{
        REQUIRE(testing_tab[i] == expected_tab[i]);
	}
	//cleanup

}
