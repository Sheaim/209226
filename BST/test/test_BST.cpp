/*
 * test_logger.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: sheaim
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <string>
#include <fstream>

#include <math.h>
#include "common/logger.h"
#include "common/catch.hpp"
#include "../BST.h"
#include "common/observer.h"

TEST_CASE( "BST binary tree, simple test", "[factorial]" ) {

	// pre
	std::cout<<"abc"<<std::endl;
    const std::string logFileName = "logfileb.txt";
	std::auto_ptr<student::common::Logger> pLogger(new student::common::Logger(logFileName));
	Observer* obs = new Observer();
	// given
	BSTree* testingTree = new BSTree();
	int n;
	// when
	//adding elements
	double meanAddTime = 0;
	double meanSearchTime = 0;
	for(int i=0;i<(1000);++i)
    {
        n = i;
        obs->triggerTimer();
        testingTree->push(n);
        obs->triggerTimer();
        obs->logTimer();
        meanAddTime = obs->giveTimerData()[0];
        obs->reset();
        std::cout<<"\n\n\nnodes added"<<std::endl;
        obs->triggerTimer();
        //The algorithm will search for an element with the given number and return true should it find it.
        testingTree->search(n);
        obs->triggerTimer();
        obs->logTimer();
        meanSearchTime = obs->giveTimerData()[0];
        obs->reset();
        //searching
        testingTree->print(testingTree->getRoot(), 1);
        pLogger->log("elements:");
        pLogger->log(i);
        pLogger->log("----AddTime----");
        pLogger->log(meanAddTime);
        pLogger->log("----SearchTime----");
        pLogger->log(meanSearchTime);
        pLogger->log("-------");
    }
	// then
    REQUIRE(false);
}
