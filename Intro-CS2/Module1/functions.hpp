/************************************************************************
** Author: Erin Alltop
** Date: 4/29/16
** Desciption: This program demonstrates three difference recursive
** functions: recursively reversing a string, adding the sum of
** array elements, and calculating the triangular number of rows.
** Input: User input for string sentence/word, array size and elements
** and rows.
** Output: Reversed string, sum of array elements, and triangular
** number of rows.
************************************************************************/

#ifndef functions_hpp
#define functions_hpp
#include <string>

class Functions
{
private:
public:
	std::string reverseString(std::string sent);
	int triangleNum(int triangle);
	int sumArray(int array[], int size);

};

#endif
