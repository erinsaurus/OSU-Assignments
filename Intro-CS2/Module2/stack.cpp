/*************************************************************************************
** Author: Erin Alltop
** Date: 5/13/16
** Description: This program demonstrates the use of a stack and a queue. It allows
** the user to decide which concept they wish to execute, then it takes in the
** characters the user would like to display. For the stack, it adds the characters
** to the stack and then displays them in reverse order. For the queue, it adds the
** characters to the queue and then displays them in order.
**************************************************************************************/
#include "stack.hpp"
#include <cstdlib>

/************************************************************************************
** Function: add
** Description: This function adds a new node to the singly linked struct on the stack.
** Parameters: char value 
** Input/Output: None
*************************************************************************************/
void Stack::add(char value)
{
	top = new Stacknode(value, top);
}

/***************************************************************************************
** Function: displayStack
** Description: This function prints out the data of the stack to the screen. While
** the stack is not empty, the function continues to call the remove function to find
** the data of the top of the queue and displays it to the screen.
** Parameters: None
** Input: None
** Output: Displays the contents of the stack to the screen in "reverse" order
****************************************************************************************/
void Stack::displayStack()
{
	while (!isEmpty()) //while the stack is not empty
	{
		std::cout << remove(); //continually call the remove function to find the
							   //top value of the stack and display it to the screen
	}
	std::cout << std::endl;
}

/**************************************************************************************
Function: remove
Description: This function checks to see if the stack is empty. If not, then it assigns
** the top value of the queue to a char data member, reassigns the top value
to the next value, and the returns the data from the function (the value of the original
** top value.
** Input: none
** Output: This function returns a character value from the stack
**************************************************************************************/
char Stack::remove()
{
	Stacknode *temp; //create a temp pointer to a Stacknode

	if (isEmpty()) //if the stack is empty, indicate there is a problem
	{
		std::cout << "Empty stack! You should not see this.";
		exit(1);
	}
	else //if the stack is not empty..
	{
		char data = top->value; //assign a new data member to the value of the top location
		temp = top; //assign the temp pointer to top
		top = top->next; //re-assign top to the next pointer in the struct
		delete temp; //delete the temp pointer
		return data; //return the data that was the original top location value
	}
}

/****************************************************************************
** Function: isEmpty
** Description: This function is a helper function used to determine if the
** current stack/struct is empty or not. This is used by other functions
** to carry out their functions and prevent an underflow of the stack.
** Input: none
** Output: returns true if stack is empty. returns false if not.
*****************************************************************************/
bool Stack::isEmpty() const
{
	if (!top) //if there is not a top value, stack is empty
		return true;
	else
		return false;
}
