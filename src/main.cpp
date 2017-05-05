#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "stl_functions.h"

// Test cases take two parameters - the first is a test
// name and the second is a tag.
// This test merely checks that 1 is equal to 1.  It
// should always pass.  It is included here to show how
// to write test cases.

TEST_CASE( "My first test", "[testing, my_tests]" ){
	// REQUIRE causes the execution to stop
	// if the test fails.
	REQUIRE( 1 == 1 );
}
