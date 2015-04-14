
/*
 * test_hArray.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: sheaim
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <string>
#include <fstream>

#include "common/logger.h"
#include "common/catch.hpp"
#include "../hArray.h"

const std::string generic_file_error_message = "Error: file not open: ";

TEST_CASE ("simple hashing array test", "[factorial]")
{
    //pre
    std::cout<<"abc"<<std::endl;
    const std::string logFileName = "log.txt";
    const std::string readFileName = "Example.txt";
	std::auto_ptr<student::common::Logger> pLogger(new student::common::Logger(logFileName));
//    //given
    HArray* pHArray = new HArray();
    std::string testString = "test string";
//    //when
    std::fstream readfile;
    readfile.open(readFileName, std::fstream::in);
    if(!readfile.is_open())
    {
        std::cout<<generic_file_error_message<<readFileName<<std::endl;
    }
    else
    {
        while(!readfile.eof())
        {
            readfile >> testString;
            pLogger->log(testString);
            pHArray->add(testString);
        }
    }
    pHArray->printHArray();
    readfile.close();
    //then
    REQUIRE(false);
    //cleanup
    delete pHArray;
}
