
/*
 * test_hash.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: sheaim
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <string>
#include <fstream>

#include "common/logger.h"
#include "common/catch.hpp"
#include "../hash.h"

TEST_CASE ("simple hasher function", "[factorial]")
{
    //pre
    std::cout<<"abc"<<std::endl;
    const std::string logFileName = "log.txt";
    const std::string readFileName = "Example.txt";
	std::auto_ptr<student::common::Logger> pLogger(new student::common::Logger(logFileName));
    //given
    std::string testString = "test string";
    Hash* Hasher = new Hash();
    int result = 0;
    //when
    std::fstream readfile;
    readfile.open(readFileName, std::fstream::in);
    while(!readfile.eof())
    {
        readfile >> testString;
        pLogger->log(testString);
        result = Hasher->h(testString);
        pLogger->log(result);
    }
    readfile.close();
    //then
    REQUIRE(false);
    //cleanup;
}
