/*************************************************************************************
** Author: Erin Alltop
** Date: 5/13/16
** Description: This program demonstrates the use of a stack and a queue. It allows
** the user to decide which concept they wish to execute, then it takes in the
** characters the user would like to display. For the stack, it adds the characters
** to the stack and then displays them in reverse order. For the queue, it adds the
** characters to the queue and then displays them in order.
**************************************************************************************/


#ifndef stack_hpp
#define stack_hpp
#include <iostream>
#include <cstdlib>

class Stack
{

private:
	struct Stacknode
	{
		char value;
		Stacknode *next;
		Stacknode(char val, Stacknode *next1 = NULL)
		{
			value = val;
			next = next1;
		}
	};

	Stacknode *top;

public:
	void add(char value);
	char remove();
	void displayStack();
	bool isEmpty() const;
	Stack() {
		top = NULL;
	}
};


#endif