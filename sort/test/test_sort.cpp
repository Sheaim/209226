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

TEST_CASE( "logger logSimpleString", "[factorial]" ) {

    int arrayLength = 10;

    for (int i=0; i<5; i++)
    {
        arrayLength *= 10;
        CombSorter* pCombSorter = new CombSorter(arrayLength);
        pCombSorter->generateArray();
        pCombSorter->combSort();
    }
    REQUIRE(false);
}
