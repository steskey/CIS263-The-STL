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

TEST_CASE( "Intersection test", "[intersection]" ){
	std::vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::vector<int> b{2, 4, 6, 8, 10, 12, 14, 16, 18};
	auto c = inBoth(a, b);
	CHECK( c.size() == 5 );
	CHECK( c[0] == 2 );
	CHECK( c[1] == 4 );
	CHECK( c[2] == 6 );
	CHECK( c[3] == 8 );
	CHECK( c[4] == 10 );
}

// ST 5-14-2017 My tests start below.
TEST_CASE( "Vector copy test of edge cases", "[std::copy]" ){
    std::vector<int> emptyVec;
    auto copiedEmptyVec = copyVec(emptyVec);
    CHECK( std::equal(emptyVec.begin(), emptyVec.end(), copiedEmptyVec.begin()));
   
    std::vector<int> negativeInts {-1, -5, -5, -88, -3, -100, -5};
    auto copiedNegVec = copyVec(negativeInts);
    CHECK( std::equal(negativeInts.begin(), negativeInts.end(), copiedNegVec.begin()));
    
    std::vector<int> allZeros {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    auto copiedAllZeros = copyVec(allZeros);
    CHECK( std::equal(allZeros.begin(), allZeros.end(), copiedAllZeros.begin()));
}

TEST_CASE( "Vector sort test of edge cases", "[std::sort]" ){
    std::vector<int> emptyVec; 
    sortVec(emptyVec); 
    CHECK(0 == emptyVec.size()); // Making sure it was not altered
    
    std::vector<int> mixedSigns {2, -99, 0, -1, 99, -51, -50};
    sortVec(mixedSigns);
    CHECK(std::is_sorted(mixedSigns.begin(), mixedSigns.end()));
    bool sorted = true;
    for(size_t i = 0; i < mixedSigns.size(); ++i){
        if(i > 0){
	        if(mixedSigns[i] < mixedSigns[i-1]){
                sorted = false;
            }
        }
    }
    CHECK(sorted);
    
    mixedSigns.push_back(-2);
    sortVec(mixedSigns);
    CHECK(std::is_sorted(mixedSigns.begin(), mixedSigns.end()));
}

TEST_CASE( "Doubling test edge cases", "[for-each]" ){
    std::vector<int> emptyVec;
    doubleVec(emptyVec); 
    CHECK(0 == emptyVec.size()); // Making sure it was not altered
    
    std::vector<int> negativeInts {-11, -1, -5, -2,  -66,  -3, -100, -12};
    std::vector<int> copiedNegVec(negativeInts);
    doubleVec(negativeInts);
    for (size_t i = 0; i < negativeInts.size(); ++i){
        CHECK(negativeInts[i] == 2*copiedNegVec[i]);
    }
    
    std::vector<int> zerosVec {0,  0,  0,  0,  0};
    doubleVec(zerosVec);
    for (auto i : zerosVec)
    {
        CHECK(0 == i);
    }
}

TEST_CASE( "Contains test extended",  "[contains]" ){
    std::vector<std::string> myVec {"pizza", "cupcakes", "guac", "bananas"};
    std::string& pizza = myVec[0];
    std::string& cupcakes = myVec[1];
    std::string& guac = myVec[2];
    std::string& bananas = myVec[3];
    std::string hamburger("hamburger");
    
    CHECK(containsItem(myVec, pizza));
    CHECK(containsItem(myVec, guac));
    CHECK(containsItem(myVec, cupcakes));
    CHECK(containsItem(myVec, bananas));
    CHECK(!containsItem(myVec, hamburger));
}

TEST_CASE( "Intersection test extened", "[intersection]" ){
    std::vector<int> vecA {-7, -5, -3, -6, 4, 0, -2, 55};
    std::vector<int> vecB {-6, 55, 10, -44, 12};
    std::vector<int> vecAB = inBoth(vecA, vecB);
    
    CHECK(2 == vecAB.size());
    CHECK(-6 == vecAB[0]);
    CHECK(55 == vecAB[1]);
}
