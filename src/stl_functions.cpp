/*****************************************************************
For CIS263 HW2. A series of functions that act on std::vector<>s.
All functions use the STL library as required.
@author Samantha Teskey
@version 5-14-2017
*****************************************************************/
#include "stl_functions.h"
#include <algorithm>

// Hint:  Remember to include the *.h file that has the
// headers for this file.
//
// Implementation goes in this file.


/*****************************************************************
Uses STL std::copy to create an exact copy of the vector passed
into the function. A new vector is created using the size of the
old vector. std::copy iterates through the new vector and copies
the elements through the provided range of oldVector.

Sources used: 
http://www.cplusplus.com/reference/algorithm/copy/
*****************************************************************/
std::vector<int> copyVec(const std::vector<int> & oldVector){
    
    // We first get the size of the passed in oldVector
    size_t SIZE_OF_OLD_VECTOR = oldVector.size();

    // Making a new vector with the same number of ints as oldVector
    std::vector<int> copiedVec(SIZE_OF_OLD_VECTOR);
    
    // Now the values can be copied in
    std::copy(oldVector.begin(), oldVector.end(), copiedVec.begin());
    
    return copiedVec;
}


/*****************************************************************
Uses std::sort to put the elements of oldVector in ascending
order. 

Sources used: 
http://www.cplusplus.com/reference/algorithm/sort/
*****************************************************************/
void sortVec(std::vector<int> & oldVector){
    
    // Will sort in ascending order
    std::sort(oldVector.begin(), oldVector.end());
}


/*****************************************************************
Uses std::for_each to double all the integers contained in the
vector passed in by reference. 

Sources used: 
http://en.cppreference.com/w/cpp/algorithm/for_each
In one of the examples, they used a lambda for the function
object. I used this example, but modified it to double the int 
rather than just incrementing it. I also defined it outside
the function call to std::for_each in order to make it more
readible.
*****************************************************************/
void doubleVec(std::vector<int> & oldVector){
    
    // This will double whichever int it is applied to
    auto doubleInt = [](int &n){
        n *= 2;
    };
    
    std::for_each(oldVector.begin(), oldVector.end(), doubleInt);
}


/*****************************************************************
Uses std::find to determine if ourVector contains the provided
std::string item. If std::find cannot locate the item, it returns
an iterator pointing past the end of the vector. This means that
the vector contains the item if the result of std::find is an
iterator other than ourVector.end().

Sources used:
http://www.cplusplus.com/reference/algorithm/find/
*****************************************************************/
bool containsItem(std::vector<std::string> & ourVector, std::string \
item){
    
    // Iterator points at the matching item
    auto it = std::find(ourVector.begin(), ourVector.end(), item);
    
    // If there is no matching item, it points to the end
    return it != ourVector.end();
}


/*****************************************************************
Creates a vector of ints called unitedVec that only contains the
ints found in both vector a and vector b. It first reserves the
max size of the new vector by checking for the smallest vector
size among a and b. It then creates a lambda function that captures
a reference to unitedVec and vector b and accepts an integer as
a paramater. If the integer is found in vector b, we add it to
unitedVec. We then use this lambda by cycling through vector a
using std::for_each and calling the function on each element
of vector a.

Sources used: 
http://www.cplusplus.com/reference/vector/vector/reserve/
http://en.cppreference.com/w/cpp/algorithm/for_each
I learned lambdas through my co-op.
*****************************************************************/
std::vector<int> inBoth(std::vector<int> a, std::vector<int> b){
    
    // The max possible size will be the smallest of the 2 vectors
    size_t VEC_MAX_SIZE = a.size() < b.size() ?  a.size() : b.size();

    std::vector<int> unitedVec;
    
    // For efficiency (we won't need a vector larger than this).
    unitedVec.reserve(VEC_MAX_SIZE);
    
    // This lambda puts the int n in unitedVec if found in b
    auto addIfAlsoInB = [&b, &unitedVec](int n){ 
        if (b.end() != std::find(b.begin(),  b.end(), n)){
            unitedVec.push_back(n);
        }
    };
    std::for_each(a.begin(),  a.end(), addIfAlsoInB);
      
    return unitedVec;
}