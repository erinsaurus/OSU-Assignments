/********************************************************************************
 ** Name: Erin Alltop
 ** Date: 1/28/17
 ** File: stackapp.c
 ** Description: This program takes a string from the command line and uses
 ** a stack to cycle through the string, store characters into an array and then
 ** compare them to determine if the string is balanced.
 ** Examples:
 ** ({[]}) = Balanced
 ** {{[]}) = Not balanced
 ** (())) = Not balanced
 *********************************************************************************/


/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post: return 0 if not balanced, and 1 if balanced
*/
int isBalanced(char* s)
{ 	/* FIXME: You will write this function */

	//create a dynamic stack array and initialize it
	int cap = 50;
	DynArr *stringArr;
	stringArr = newDynArr(cap);
	char currentCh;

	//while character array does not end
	while ((currentCh = nextChar(s)) != '\0') {

		/*For each open bracket, put it in the stack in order.
		 * If there is a closed bracket, make sure the array is not empty first,
		 * and if the top of the stack corresponds with the bracket type, pop it 
		 * from the stack. If it does not match, break and return 0 because the 
		 * equation is not balanced.
		 * If the array is empty when there is a closed bracket, then the equation
		 * is also not balanced because it has an extraneous bracket.
		 */
		switch (currentCh) {
		case '{':
			pushDynArr(stringArr, '{');
			break;
		case '[':
			pushDynArr(stringArr, '[');
			break;
		case '(':
			pushDynArr(stringArr, '(');
			break;

		case '}':
			if (!(isEmptyDynArr(stringArr)) && (topDynArr(stringArr) == '{')) {
				popDynArr(stringArr);
				break;
			}
			return 0;

		case ']':
			if (!(isEmptyDynArr(stringArr)) && (topDynArr(stringArr) == '[')) {
				popDynArr(stringArr);
				break;
			}
			return 0;

		case ')':
			if (!(isEmptyDynArr(stringArr)) && (topDynArr(stringArr) == '(')) {
				popDynArr(stringArr);
				break;
			}
			return 0;

		}
	}
	
	deleteDynArr(stringArr);
	return 1;
}

int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

