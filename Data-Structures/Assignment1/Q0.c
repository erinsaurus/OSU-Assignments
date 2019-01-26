/* CS261- Assignment 1 - Q. 0*/
/* Name: Erin Alltop
 * Date: 1/20/17
 * Solution description: This program is a demonstration of how passing pointers to functions works. 
 * will print the address of a variable, pass the variable address to function fooA which will
 * print the value, the address pointed to by the pointer, and the address of the pointer itself.
 * After returning to the main functions, the value of the variable will be printed again.
 */
 
#include <stdio.h> 
#include <stdlib.h>

/*********************************************************************************************
 ** Function: void fooA(int* iptr)
 ** Description: This function prints three things: The value pointed to by iptr*, the address
 ** pointed to by iptr*, and the address of iptr itself. It then exits the function.
 ** Parameters: Address of a variable
 ** Pre-Conditions: The address of a variable is passed to the function through main()
 ** Post-Conditions: None. This function only prints and does not return anything.
 *********************************************************************************************/


void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
	printf("value pointed to by iptr* = %d\n", *iptr);
     
     /*Print the address pointed to by iptr*/
	printf("address pointed to by iptr* = %p\n", iptr);
     
     /*Print the address of iptr itself*/
	printf("address of iptr itself = %p\n", &iptr);
}

/*********************************************************************************************
** Function: int main()
** Description: This is the main function. It declares and assigns an int variable, prints the
** address of the variable, calls a function fooA and passes in the address of the variable,
** prints the value of the variable, and exits the program with 0.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************************************/

int main(){
    
    /*declare an integer x*/
	int x = 5;

    /*print the address of x*/
	printf("address of x = %p\n", &x);
    
    /*Call fooA() with the address of x*/
	fooA(&x);

    /*print the value of x*/
	printf("value of x = %d\n", x);
    
    return 0;
}
