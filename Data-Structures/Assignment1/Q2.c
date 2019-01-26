/* CS261- Assignment 1 - Q.2*/
/* Name: Erin Alltop
 * Date: 1/20/17
 * Solution description: The program is a demontration of how passing-by-reference and
 * passing-by-value works. Three variables are declared and are passed to the foo() function.
 * One of the variables is passed as a copy only. The foo() function does some calculations
 * alterinng the values of the variables and returns c to the main function. The variables
 * are printed a second time, demonstrating that only two have been changed.
 */
 
#include <stdio.h>
#include <stdlib.h>

 /*********************************************************************
 ** Function: int foo(int* a, int* b, int c)
 ** Description: This function takes two pointers and an int, performs
 ** calculations on the variables and return the value of the int.
 ** Parameters: int pointer, in pointer, int
 ** Pre-Conditions: Variables in the main have been declared and 
 ** initialized and passed to the function.
 ** Post-Conditions: Returns the value of c
 *********************************************************************/

int foo(int* a, int* b, int c){
	/*Set a to double its original value*/
	*a = *a * 2;

	/*Set b to half its original value*/
	*b = *b / 2;

	/*Assign a+b to c*/
	c = *a + *b;

	/*Return c*/
	return c;
}

/*********************************************************************
** Function: int main()
** Description: This function declares three integers and initialized them.
** It then prints the values of the integers, and passes them to the functions,
** two by reference, and one by value. It then prints the value returned
** by foo() and prints the values of the three integers again. And returns 0.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/

int main() {
	/*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
	int x = 5;
	int y = 6;
	int z = 7;

	/*Print the values of x, y and z*/
	printf("Value of x: %d\n", x);
	printf("Value of y: %d\n", y);
	printf("Value of z: %d\n", z);

	/*Call foo() appropriately, passing x,y,z as parameters*/
	int val = foo(&x, &y, z);

	/*Print the value returned by foo*/
	printf("Value returned by foo: %d\n", val);

	/*Print the values of x, y and z again*/
	printf("Value of x: %d\n", x);
	printf("Value of y: %d\n", y);
	printf("Value of z: %d\n", z);

	/*Is the return value different than the value of z?  Why?*/
	/* The return value is different than the value of z, because z a COPY of z
	 * was passed to the foo() function instead of the address of z like in the case 
	 * of x and y. Because of this, when the function foo() does its operations, x and
	 * y are changed (as a and b) because the value at their address was changed directly.
	 * However, only the copy of z was affected in the foo() function. So c returns a 
	 * value that has been altered within the function, but this does not change
	 * the value of z in the main function.*/

	return 0;
}
    
    
