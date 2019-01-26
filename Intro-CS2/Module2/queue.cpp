/*************************************************************************************
** Author: Erin Alltop
** Date: 5/13/16
** Description: This program demonstrates the use of a stack and a queue. It allows
** the user to decide which concept they wish to execute, then it takes in the
** characters the user would like to display. For the stack, it adds the characters
** to the stack and then displays them in reverse order. For the queue, it adds the
** characters to the queue and then displays them in order.
**************************************************************************************/

#include "queue.hpp"
#include <cstdlib>

Queue::Queue()
{ //initialize values of front and rear to NULL
	front = NULL;
	rear = NULL;
}

/************************************************************************************
** Function: add
** Description: This function adds a new node to the doubly linked struct in the queue.
** Parameters: char value
** Input/Output: None
*************************************************************************************/
void Queue::addHead(char value)
{
	queueNode* newNode = new queueNode(value);
	if (isEmpty()) //if the queue is empty
	{
		front = newNode; //assign the front queue location to a new node
	//	rear = front; //then, assign rear to front
		return;
	}
	
	//if the queue is not empty
	//	rear->next = new queueNode(value); //assign the next pointer of rear to a new node
	//	rear = rear->next; //then, assign rear to rear's next pointer
		front->prev = newNode;
		newNode->next = front;
		front = newNode;

	}

void Queue::add(char value) //adds to the tail
{
	queueNode* newNode = new queueNode(value); //create a new node

	if (isEmpty()) //if the queue is empty
	{
		newNode->prev = NULL; //set newNode previous to NULL
		newNode->next = NULL; //set newNode next to NULL
		front = newNode; //set front node to newNode
		rear = newNode; //set rear node to newNode
		return; //return
	}

	else //if the queue is not empty
	{ 
		newNode->next = NULL; //set newNode next to NULL
		rear->next = newNode; //set the rear node next to the newNode
		newNode->prev = rear; //set newNode previous to rear
		rear = newNode; //set rear node to newNode
	}
}

/**************************************************************************************
Function: remove
Description: This function checks to see if the queue is empty. If not, then it assigns
** the front value of the queue to a char data member, reassigns the front value
to the next value, and the returns the data from the function (the value of the original
** front value.
** Input: none
** Output: This function returns a character value from the queue
**************************************************************************************/
char Queue::remove()
{
	queueNode *temp; //create a temp pointer node

	if (isEmpty()) //if the queue is empty, indicate there is a problem
	{
		std::cout << "Empty queue!";
		exit(1);
	}
	else
	{ //if queue is not empty..
		char data = front->value; //assign the value of the front member to a new data member
		temp = front; //assign temp to equal the front value
		front = front->next; //reassign front to equal the next location
		delete temp; //delete the temp pointer
		return data; //return the data from the original front value
	}
}

/***************************************************************************************
** Function: displayQueue
** Description: This function prints out the data of the queue to the screen. While
** the queue is not empty, the function continues to call the remove function to find
** the data of the front of the queue and displays it to the screen.
** Parameters: None
** Input: None
** Output: Displays the contents of the queue to the screen in order
****************************************************************************************/
void Queue::displayQueue()
{
	while (!isEmpty()) //while the queue is not empty
	{ 
		std::cout << remove(); //call the remove function to move through the queue
	}						   //queue and displays the values
	
	std::cout << std::endl;
}

/****************************************************************************
** Function: isEmpty
** Description: This function is a helper function used to determine if the
** current queue/struct is empty or not. This is used by other functions
** to carry out their functions and prevent an underflow of the queue.
** Input: none
** Output: returns true if queue is empty. returns false if not.
*****************************************************************************/
bool Queue::isEmpty() const
{
	if (front == NULL) //if the front value is null, the queue is empty
		return true;
	else
		return false;
}
