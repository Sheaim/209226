#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <string>
#include <fstream>

#include "../catch.hpp"
#include "../observer.h"

TEST_CASE( "logger logSimpleString", "[factorial]" ) {

	// pre
	Observer* pObs = new Observer();
	// given
	// when
	// then
	pObs->triggerTimer();
	pObs->triggerTimer();
	pObs->triggerTimer();
	pObs->logTimer();
	pObs->triggerTimer();
	pObs->logTimer();
	pObs->reset();
	pObs->triggerTimer();
	pObs->triggerTimer();
	pObs->triggerTimer();
	pObs->logTimer();
	pObs->reset();
	//cleanup
    REQUIRE(false);
}
