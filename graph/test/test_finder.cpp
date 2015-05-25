/*
 * test_logger.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: topeerz
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <string>
#include <fstream>

#include "common/catch.hpp"
#include "common/logger.h"
#include "../finder.h"

TEST_CASE( "logger logSimpleString", "[factorial]" ) {

	// pre
	const std::string logFileName = "logfile.txt";
	std::auto_ptr<student::common::Logger> pLogger(new student::common::Logger(logFileName));

	// given
    Graph* gr = new Graph();
    gr->addNode(0);
    gr->addNode(1);
    gr->addNode(2);
    gr->addNode(3);
    gr->addNode(4);
    gr->addNode(5);
    gr->addNode(6);
    gr->addNode(7);
    gr->addNode(8);
    gr->addEdge(0, 1, 1);
    gr->addEdge(0, 2, 1);
    gr->addEdge(1, 3, 1);
    gr->addEdge(1, 4, 1);
    gr->addEdge(3, 3, 1);
    gr->addEdge(3, 6, 1);
    gr->addEdge(4, 6, 1);
    gr->addEdge(2, 4, 1);
    gr->addEdge(2, 5, 1);
    gr->addEdge(2, 6, 1);
    gr->addEdge(5, 7, 1);
    gr->addEdge(7, 8, 1);
	// then
	Finder* f = new Finder(gr);
	f->findNodePath(8);
	REQUIRE(false);

	//cleanup
	delete f;
}
