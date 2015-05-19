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
#include "common/catch.hpp"
#include "../AVL.h"

TEST_CASE( "AVL binary tree, simple test", "[factorial]" ) {

	// pre
	std::cout<<"abc"<<std::endl;
    const std::string logFileName = "lolz.txt";
	std::auto_ptr<student::common::Logger> pLogger(new student::common::Logger(logFileName));
	// given
	BTree* testingTree = new BTree();
	int n;
	// when
	for(int i=0;i<10;++i)
    {
        n = rand()%10;
        testingTree->addNode(n, testingTree->getRoot());
        std::cout<<"nodes added"<<std::endl;
    }
    delete testingTree;
	// then
    REQUIRE(false);
}
