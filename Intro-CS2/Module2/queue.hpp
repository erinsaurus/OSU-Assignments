/*************************************************************************************
** Author: Erin Alltop
** Date: 5/13/16
** Description: This program demonstrates the use of a stack and a queue. It allows
** the user to decide which concept they wish to execute, then it takes in the 
** characters the user would like to display. For the stack, it adds the characters
** to the stack and then displays them in reverse order. For the queue, it adds the
** characters to the queue and then displays them in order.
**************************************************************************************/

#ifndef queue_hpp
#define queue_hpp
#include <iostream>
#include <cstdlib>

class Queue
{
private:
	struct queueNode
	{
		char value;
		queueNode *next;
		queueNode *prev;
		queueNode(char val, queueNode *next1 = NULL, queueNode *prev1 = NULL)
		{
			value = val;
			next = next1;
			prev = prev1;
		}
	};
	queueNode *front;
	queueNode *rear;


public:
	Queue();
	void addHead(char value);
	void add(char value);
	char remove();
	bool isEmpty() const;
	void displayQueue();
};
#endif