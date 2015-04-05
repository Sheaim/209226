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
#include "../logger.h"

TEST_CASE( "logger logSimpleString", "[factorial]" ) {

	// pre
	const std::string logFileName = "lolz.txt";
	std::auto_ptr<student::common::Logger> pLogger(new student::common::Logger(logFileName));

	// given
	std::string logEntry = "tralalala";

	// when
	pLogger->log(logEntry);
	// delete pLogger;

	std::string logFileContent;

	std::fstream logfile;

	logfile.open(logFileName, std::fstream::in);
	logfile >> logFileContent;

	logfile.close();

	// then
	REQUIRE(logFileContent == logEntry);

	//cleanup
	remove("lolz.txt");

}
