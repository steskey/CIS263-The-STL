// Hint:  Remember to include the *.h file that has the
// headers for this file.
//
// Implementation goes in this file.
#include "stl_functions.h"

#include <algorithm>

/**
 * copyVec
 * Must use the STL std::copy.
 */
// Hints:  You need to create a new vector.
// Hints:  Are they the same size?

std::vector<int> copyVec(const std::vector<int> & oldVector){
    size_t sizeOfOldVector = oldVector.size();
    std::vector<int> copiedVector(sizeOfOldVector);
    
    // http://www.cplusplus.com/reference/algorithm/copy/
    std::copy(oldVector.begin(), oldVector.end(), copiedVector.begin());
    
    return copiedVector;
}

/**
 * sortVec
 * Must use STL std::sort function
 */

void sortVec(std::vector<int> & oldVector){
    // http://www.cplusplus.com/reference/algorithm/sort/
    std::sort(oldVector.begin(), oldVector.end());
}

/**
 * doubleVec
 * Must use STL std::for_each
 * 
 * 
 */

void doubleVec(std::vector<int> & oldVector){
    // http://en.cppreference.com/w/cpp/algorithm/for_each
    // In one of the examples, they used a lambda for the function object.
    // I used this example, but modified it to double the int rather 
    // than just incrementing it
    std::for_each(oldVector.begin(), oldVector.end(), [](int &n){ n *= 2; } );
}

/**
 * containsItem
 * Must use STL std::find
 */

bool containsItem(std::vector<std::string> & ourVector, std::string item){
    // http://www.cplusplus.com/reference/algorithm/find/
    return std::find(ourVector.begin(), ourVector.end(), item) != ourVector.end();
}

/**
 * inBoth
 * Returns a vector that contains only the elements that
 * are in both of the input parameter vectors.
 */

std::vector<int> inBoth(std::vector<int> a, std::vector<int> b){
    size_t vectorMaxSize = a.size() < b.size() ?  a.size() : b.size();

    std::vector<int> unitedVec;
    // http://www.cplusplus.com/reference/vector/vector/reserve/
    unitedVec.reserve(vectorMaxSize);
    
    // Making a lambda here to be used in for_each below
    // This lambda puts the int n in unitedVec if found in b
    auto addToUnitedIfAlsoInB = [b, &unitedVec](int n){ 
        if (b.end() != std::find(b.begin(),  b.end(), n)){
            unitedVec.push_back(n);
        }
    };
    std::for_each(a.begin(),  a.end(), addToUnitedIfAlsoInB);
      
    return unitedVec;
}
