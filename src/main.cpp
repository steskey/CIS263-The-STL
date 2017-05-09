#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <algorithm>
#include "catch.hpp"
#include "stl_functions.h"

// Test cases take two parameters - the first is a test
// name and the second is a tag.
// This test merely checks that 1 is equal to 1.  It
// should always pass.  It is included here to show how
// to write test cases.

TEST_CASE( "Vector copy test", "[std::copy]" ){
	std::vector<int> m { 1, 4, 6, 3, 7, 9, 4, 23, 42, 5, 6 };
	auto n = copyVec(m);
	CHECK( std::equal( m.begin(), m.end(), n.begin()));
}

TEST_CASE( "Vector sort test", "[std::sort]" ){
	std::vector<int> m(100);
	std::generate(m.begin(), m.end(), []() {return rand() % 1000;});
	sortVec(m);
	CHECK( std::is_sorted(m.begin(), m.end()) );
}

TEST_CASE( "For-each test", "[for-each]" ){
	std::vector<int> m(100);
	std::vector<int> n(m);
	std::generate(m.begin(), m.end(), []() {return rand() % 1000;});
	std::copy(m.begin(), m.end(), n.begin());
	doubleVec(m);
	for(size_t i=0; i<m.size(); i++){
		CHECK( m[i] == (n[i] * 2) );
	}
}

TEST_CASE( "Contains test", "[contains]" ){
	std::vector<std::string> v;
	std::string one("One");
	std::string two("Two");
	std::string three("Three");
	std::string four("Four");
	std::string five("Five");
	v.push_back(one);
	v.push_back(three);
	v.push_back(five);
	v.push_back(four);
	CHECK( containsItem(v, one) );
	CHECK( !containsItem(v, two) );
	CHECK( containsItem(v, four) );
}
