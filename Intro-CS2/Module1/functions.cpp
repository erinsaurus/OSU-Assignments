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


#include "functions.hpp"
#include <string>
#include <iostream>

/************************************************************************
** Function: ReverseString
** Description: This function takes a string and uses recursion to
** reverse the string and return the reversed string to main.
** Parameters: User input string
** Output: reversed string
*************************************************************************/

std::string Functions::reverseString(std::string sent) 
{
	if (sent.length() == 1)  // base case
	{
		return sent;
	}
	else // recursive case
	{
		return reverseString(sent.substr(1, sent.length())) + sent.at(0);
	}
}

/************************************************************************
** Function: triangleNum
** Description: This function recursively calculates the triangular number
** for a number of rows. For as many rows there are, the function
** calculates how many total elements the triangle holds.
** Parameters: User input number of rows
** Output: triangular number
*************************************************************************/

int Functions::triangleNum(int triangle)
{
	if (triangle == 0) //base case
		return 0;
	else  //recursive case
		return triangle + triangleNum(triangle - 1);
}

/************************************************************************
** Function: numArray
** Description: This function sums the elements of an array
** Parameters: int array, and size of the array by user input
** Output: the sum of the elements of the array 
*************************************************************************/

int Functions::sumArray(int array[], int size)
{
	if (size == 0) //base case
	{
		return 0; 
	}
	else   //recursive case 
	{
		return (sumArray(array, (size - 1)) + array[size - 1]);
	}
}