# CIS263-The-STL

Complete the following functions.  Do not change any function signature!

> **You MUST use the STL functions to perform the operations.  Each function ```HINTS:``` section will tell you which function to learn to complete the task.  If you do not use that function, you will not earn the points.**

Remember:

- interface for this one is provided for you already in the ```*.h``` file.
- all implementation should be in the ```src/stl_functions.cpp``` file.
- don't forget to include libraries.
- pay attention to the ```HINTS: ``` sections.

1.  ```std::vector<int> copyVec(const std::vector<int> & oldVector);``` - Should produce an exact copy (as far as the ```std::equal``` function is concerned) of the provided ```oldVector```.  Must use ```std::copy```.

2.  ```void sortVec(std::vector<int> & oldVector);``` - Should sort ```oldVector``` in incrementing order using the ```std::sort()``` function.
3.  ```void doubleVec(std::vector<int> & oldVector);``` - Write a function that doubles every number in ```oldVector```.  The function must use the ```std::for_each``` function.
4.  ```bool containsItem(std::vector<std::string> & ourVector, std::string item);``` - Using std::find determine if ```item``` is contained within the vector ```ourVector```.
5.  ```std::vector<int> inBoth(std::vector<int> a, std::vector<int> b);``` - Using std::set_intersection return a new vector that contains all of the elements from ```a``` and ```b```.

## Grading

1.  15 Points each problem (5 problems = 75 points).  No points for a problem if you don't use the required functions to complete the task.

2.  15 Additional tests cases (1 point per case, max of three per ```TEST```).

3.  10 Points adhering to [Style Guide](http://www.cis.gvsu.edu/java-coding-style-guide/ "Java Style Guide").  Yes, I know this is a style guide for Java, but we are going to use it anyway.  Other than Javadoc tags the guide still applies.

**Grading Caveats***

1.  Code that doesn't compile on EOS by typing ```make``` from within the project directory automatically loses 25 points.

2.  Code that compiles but has warnings loses 10 points.  We should have zero warnings in our code, even if they are "harmless".

3.  We ALWAYS cite the proper sources.  This means if we find a way to do something by talking to our friend, or if we find some sample code on Stack Overflow, that we document that in the comments of our code.  Code is just like lyrics in a song or words written in a book - it is a creative endeavor and we owe it to others to give credit where it is due.  You will receive a 0 on any work that does not attribute credit.
