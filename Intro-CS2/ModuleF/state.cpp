/************************************************************************************
** Author: Erin Alltop
** Date: 5/27/16
** Description: This program is a traffic simulator. It takes input from the user
** for how many cycles of the light they would like to see and outputs the
** arivals/depatures of vehicles at each cycle. At the end of the program it
** displays the total number of arrivals/depatures for each lane.
** It also displays the average total wait time for each vehicle per lane.
** This program utilizes queues.
************************************************************************************/


#include "state.hpp"
#include <cmath>
#include <iostream>
#include <string>
#include <cstdlib>

/***************************************************************************
** Function: Default Constructor
** Description: This is the default constructor that is needed
** in order to utilize the constructor with multiple
** parameters.
**************************************************************************/

State::State()
{

}

State::~State()
{

  

}

/***************************************************************************
** Function: Non-efault Constructor
** Description: This constructor takes two strings for each direction when
** an object is initialized. It then sets the directions of these two
** lanes for each object. It also initializes the other variables of
** the program to 0.
**************************************************************************/

State::State(std::string dir1, std::string dir2, State* state)
{
	setDirection1(dir1);
	setDirection2(dir2);
	setNextState(state);
	setNrArrivedDir1(0);
	setNrArrivedDir2(0);
	setNrDepartedDir1(0);
	setNrDepartedDir2(0);
	Arrived1 = 0;
	Arrived2 = 0;
	Departed1 = 0;
	Departed2 = 0;
	setVehiclesDir1(0);
	setVehiclesDir2(0);
	waitTime1 = 0;
	waitTime2 = 0;
	totalWaitTime1 = 0;
	totalWaitTime2 = 0;
	//initialize values of front and rear to NULL
	frontDir1 = NULL;
	rearDir1 = NULL;
	frontDir2 = NULL;
	rearDir2 = NULL;


}

/************************************************************************************
** Function: add
** Description: This function adds a new node to the doubly linked struct in the queue.
** Parameters: char value
** Input/Output: None
*************************************************************************************/
void State::addHeadDir1(int value)
{
	queueNodeDir1* newNode = new queueNodeDir1(value);
	if (isEmptyDir1()) //if the queue is empty
	{
		frontDir1 = newNode; //assign the front queue location to a new node
						 //	rear = front; //then, assign rear to front
		return;
	}

	//if the queue is not empty
	//	rear->next = new queueNode(value); //assign the next pointer of rear to a new node
	//	rear = rear->next; //then, assign rear to rear's next pointer
	frontDir1->prevDir1 = newNode;
	newNode->nextDir1 = frontDir1;
	frontDir1 = newNode;

}

void State::addDir1(int value) //adds to the tail
{
	queueNodeDir1* newNode = new queueNodeDir1(value); //create a new node

	if (isEmptyDir1()) //if the queue is empty
	{
		newNode->prevDir1 = NULL; //setnewNode previous to NULL
		newNode->nextDir1 = NULL; //set newNode next to NULL
		frontDir1 = newNode; //set front node to newNode
		rearDir1 = newNode; //set rear node to newNode
		return;
	}

	else //if the queue is not empty
	{
		newNode->nextDir1 = NULL; //set newNode next to NULL
		rearDir1->nextDir1 = newNode; //set the rear node next to the newNode
		newNode->prevDir1 = rearDir1; //set newNode previous to rear
		rearDir1 = newNode; //set rear node to newNode 
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
int State::removeDir1()
{
	queueNodeDir1 *tempDir1; //create a temp pointer node

	if (isEmptyDir1()) //if the queue is empty, indicate there is a problem
	{
		//std::cout << "Empty queue!";
		//exit(1);
		return 0;
	}
	else
	{ //if queue is not empty..
		int dataDir1 = frontDir1->valueDir1; //assign the value of the front member to a new data member
		tempDir1 = frontDir1; //assign temp to equal the front value
		frontDir1 = frontDir1->nextDir1; //reassign front to equal the next location
		delete tempDir1; //delete the temp pointer
		return dataDir1; //return the data from the original front value
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
void State::displayQueueDir1()
{
	while (!isEmptyDir1()) //while the queue is not empty
	{
		std::cout << removeDir1(); //call the remove function to move through the queue
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
bool State::isEmptyDir1() const
{
	if (frontDir1 == NULL) //if the front value is null, the queue is empty
		return true;
	else
		return false;
}

/************************************************************************************
** Function: add
** Description: This function adds a new node to the doubly linked struct in the queue.
** Parameters: char value
** Input/Output: None
*************************************************************************************/
void State::addHeadDir2(int value)
{
	queueNodeDir2* newNode = new queueNodeDir2(value);
	if (isEmptyDir2()) //if the queue is empty
	{
		frontDir2 = newNode; //assign the front queue location to a new node
							 //	rear = front; //then, assign rear to front
		return;
	}

	//if the queue is not empty
	//	rear->next = new queueNode(value); //assign the next pointer of rear to a new node
	//	rear = rear->next; //then, assign rear to rear's next pointer
	frontDir2->prevDir2 = newNode;
	newNode->nextDir2 = frontDir2;
	frontDir2 = newNode;

}

void State::addDir2(int value) //adds to the tail
{

	queueNodeDir2* newNode = new queueNodeDir2(value); //create a new node

	if (isEmptyDir2()) //if the queue is empty
	{
		newNode->prevDir2 = NULL; //set newNode previous to NULL
		newNode->nextDir2 = NULL; //set newNode next to NULL
		frontDir2 = newNode; //set front node to newNode
		rearDir2 = newNode; //set rear node to newNode
		return;
	}

	else //if the queue is not empty
	{
		newNode->nextDir2 = NULL; //set newNode next to NULL
		rearDir2->nextDir2 = newNode; //set the rear node next to the newNode
		newNode->prevDir2 = rearDir2; //set newNode previous to rear
		rearDir2 = newNode; //set rear node to newNode
	}
}

/**************************************************************************************
Function: remove
Description: This function checks to see if the queue is empty. If not, then it assigns
** the front value of the queue to a int data member, reassigns the front value
to the next value, and the returns the data from the function (the value of the original
** front value.
** Input: none
** Output: This function returns a int value from the queue
**************************************************************************************/
int State::removeDir2()
{
	queueNodeDir2 *tempDir2; //create a temp pointer node

	if (isEmptyDir2()) //if the queue is empty, indicate there is a problem
	{
		//std::cout << "Empty queue!";
		//exit(1);
		return 0;
	}
	else
	{ //if queue is not empty..
		int dataDir2 = frontDir2->valueDir2; //assign the value of the front member to a new data member
		tempDir2 = frontDir2; //assign temp to equal the front value
		frontDir2 = frontDir2->nextDir2; //reassign front to equal the next location
		delete tempDir2; //delete the temp pointer
		return dataDir2; //return the data from the original front value
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
void State::displayQueueDir2()
{
	while (!isEmptyDir2()) //while the queue is not empty
	{
		std::cout << removeDir2(); //call the remove function to move through the queue
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
bool State::isEmptyDir2() const
{
	if (frontDir2 == NULL) //if the front value is null, the queue is empty
		return true;
	else
		return false;
}
/************************************************************************************
** Function: nrOfVehiclesArrive
** Description: This function randomly generates numbers of arrivals for both
** directions of the current state. It then sets the randomly gemerated number
** to the variable for the number arrived for each direction to be used later in
** the program.
*************************************************************************************/

void State::nrOfVehiclesArrive(int counter)
{
	//initialize variables
	int arrive1 = 0;
	int arrive2 = 0;

	//if directions are green, roll random arrivals
	if (getDirection1() != "NoGreen" && getDirection2() != "NoGreen")
	{
		int roll1 = rand() % 6 + 1;
		int roll2 = rand() % 6 + 1;
		int roll3 = rand() % 6 + 1;
		int roll4 = rand() % 6 + 1;
		arrive1 = roll1 + roll2;
		arrive2 = roll3 + roll4;

	}

	//if directions are yellow or red, arrivals are 0
	else if (getDirection1() == "NoGreen" && getDirection2() == "NoGreen")
	{
		arrive1 = 0;
		arrive2 = 0;
	}

	//set numbers arrived for each direction
	setNrArrivedDir1(arrive1); 
	setNrArrivedDir2(arrive2);

		//for the number of arrivals for direction1, add the cars to the queue (number of cycle - counter)
		for (int i = 0; i < arrive1; i++)
		{
			addDir1(counter);
		}


		//for the number of arrivals for direction2, add the cars to the queue (number of cycle - counter)
		for (int i = 0; i < arrive2; i++)
		{
			addDir2(counter);
		}
}

/************************************************************************************
** Function: nrOfVehiclesDepart
** Description: This function randomly generates numbers of departures for both
** directions of the current state. It then sets the randomly gemerated number
** to the variable for the number departed for each direction to be used later in
** the program.
*************************************************************************************/

void State::nrOfVehiclesDepart(int counter)
{
	//initialize variables
	int depart1 = 0;
	int depart2 = 0;

	//if the lights are green, calculate random departures
	if (getDirection1() != "NoGreen" && getDirection2() != "NoGreen")
	{
		depart1 = (rand() % (8 - 4) + 4);
		depart2 = (rand() % (8 - 4) + 4);
	}

	//if the lights are yellow or red, departures are 0
	else if (getDirection1() == "NoGreen" && getDirection2() == "NoGreen")
	{
		depart1 = 0;
		depart2 = 0;
	}

	//if the number arrived minus departed is greater than 0
	if (getNrArrivedDir1() - depart1 >= 0)
	{
		setNrDepartedDir1(depart1); //set depart direction1

		//for each departure (car), calcuate wait time and remove from queue
		for (int i = 0; i < depart1; i++)
		{
			setWaitTime1((counter - removeDir1())); //wait time is current cycle (counter) minus int of car entering queue 
													//which is returned by removeDir1

			setTotalWaitTime1(waitTime1); //add wait time for car to total wait time for all cars
		}
	}

	//if the number arrived minus departed is a negative number (impossible)
	else if (getNrArrivedDir1() - depart1 < 0)
	{
		setNrDepartedDir1(getNrArrivedDir1()); //set the number departed to the number arrived (the max that can leave)

		//for each arrival (departure), calculate wait time and remove from queue
		for (int i = 0; i < getNrArrivedDir1(); i++)
		{
			setWaitTime1((counter - removeDir1()));//wait time is current cycle (counter) minus int of car entering queue 
													//which is returned by removeDir2

			setTotalWaitTime1(waitTime1); //add wait time for car to total wait time for all cars
		}
	}

	//if the number arrived minus departed is greater than 0
	if (getNrArrivedDir2() - depart2 >= 0)
	{
		setNrDepartedDir2(depart2); //set depart direction2


		//for each departure (car), calcuate wait time and remove from queue
		for (int i = 0; i < depart2; i++)
		{
			setWaitTime2((counter - removeDir2())); //wait time is current cycle (counter) minus int of car entering queue 
													//which is returned by removeDir2

			setTotalWaitTime2(waitTime2); //add wait time for car to total wait time for all cars
		}
	}

	//if the number arrived minus departed is a negative number (impossible)
	else if (getNrArrivedDir2() - depart2 < 0)
	{
		setNrDepartedDir2(getNrArrivedDir2()); //set the number departed to the number arrived (the max that can leave)

		//for each arrival (departure), calculate wait time and remove from queue
		for (int i = 0; i < getNrArrivedDir2(); i++)
		{
			setWaitTime2((counter - removeDir2())); //wait time is current cycle (counter) minus int of car entering queue 
													//which is returned by removeDir2

			setTotalWaitTime2(waitTime2); //add wait time for car to total wait time for all cars
		}
	}
}


/************************************************************************************
** Function: setDirection1
** Description: This function takes a parameter of a string to set the direction of
** each lane for later use in the program when displaying statistics on each lane.
** Parameter: string of the direction
*************************************************************************************/

void State::setDirection1(std::string dir1)
{
	direction1 = dir1;
}


/************************************************************************************
** Function: getDirection1
** Description: This function simply returns the direction of each lane. It is
** used primarly for display puroses at the end of the program.
** Output: string of the direction
*************************************************************************************/

std::string State::getDirection1()
{
	return direction1;
}

/************************************************************************************
** Function: setDirection2
** Description: This function takes a parameter of a string to set the direction of
** each lane for later use in the program when displaying statistics on each lane.
** Parameter: string of the direction
*************************************************************************************/

void State::setDirection2(std::string dir2)
{
	direction2 = dir2;
}

/************************************************************************************
** Function: getDirection2
** Description: This function simply returns the direction of each lane. It is
** used primarly for display puroses at the end of the program.
** Output: string of the direction
*************************************************************************************/

std::string State::getDirection2()
{
	return direction2;
}

/************************************************************************************
** Function: setVehicleDir1
** Description: This function takes a parameter of int and sets the number of
** vehicles in each direction. This is used in the program to display the number
** of vehicles in each lane per each cycle.
** Parameter: int for number of vehicles in the lane
*************************************************************************************/

void State::setVehiclesDir1(int lane1)
{
	nrVehiclesDir1 = lane1;
}

/************************************************************************************
** Function: getVehiclesDir1
** Description: This function simply returns the number of vehicles in each lane. It is
** used primarly for display puroses at the end of the program for the number of
** vehicles in each lane at each cycle.
** Output: int of the number of vehicles
*************************************************************************************/

int State::getVehiclesDir1()
{
	return nrVehiclesDir1;
}

/************************************************************************************
** Function: setVehicleDir2
** Description: This function takes a parameter of int and sets the number of
** vehicles in each direction. This is used in the program to display the number
** of vehicles in each lane per each cycle.
** Parameter: int for number of vehicles in the lane
*************************************************************************************/

void State::setVehiclesDir2(int lane2)
{
	nrVehiclesDir2 = lane2;
}

/************************************************************************************
** Function: getVehiclesDir2
** Description: This function simply returns the number of vehicles in each lane. It is
** used primarly for display puroses at the end of the program for the number of
** vehicles in each lane at each cycle.
** Output: int of the number of vehicles
*************************************************************************************/

int State::getVehiclesDir2()
{
	return nrVehiclesDir2;
}

/************************************************************************************
** Function: getArrived1
** Description: This function simply returns the number of arriving in the lane. It is
** used primarly for display purposes at the end of the program for the total number of
** vehicles that have arrived each lane for all of the cycles combined.
** Output: int of the number of vehicles arrived
*************************************************************************************/

int State::getArrived1()
{
	return Arrived1;
}

/************************************************************************************
** Function: setArrived1
** Description: This function takes a parameter of int and sets the number of
** vehicles in each direction. This function is used an overall counter for the
** each lane. This is used at the end of the program to display the total number of
** cars that have arrived in each lane.
** It adds the current arrivals to the running total.
** Parameter: int for number of vehicles arriving in the lane
*************************************************************************************/

void State::setArrived1(int arri)
{
	Arrived1 += arri;
}

/************************************************************************************
** Function: getDeparted1
** Description: This function simply returns the number of departing in the lane. It is
** used primarly for display purposes at the end of the program for the total number of
** vehicles that have departed each lane for all of the cycles combined.
** Output: int of the number of vehicles departed
*************************************************************************************/


int State::getDeparted1()
{
	return Departed1;
}

/************************************************************************************
** Function: setDeparted1
** Description: This function takes a parameter of int and sets the number of
** vehicles departed in each direction. This function is used an overall counter for the
** each lane. This is used at the end of the program to display the total number of
** cars that have departed in each lane.
** It adds the current departures to the running total.
** Parameter: int for number of vehicles departing the lane
*************************************************************************************/

void State::setDeparted1(int dep)
{
	Departed1 += dep;
}

/************************************************************************************
** Function: getArrived2
** Description: This function simply returns the number of arriving in the lane. It is
** used primarly for display purposes at the end of the program for the total number of
** vehicles that have arrived each lane for all of the cycles combined.
** Output: int of the number of vehicles arrived
*************************************************************************************/

int State::getArrived2()
{
	return Arrived2;
}

/************************************************************************************
** Function: setArrived2
** Description: This function takes a parameter of int and sets the number of
** vehicles in each direction. This function is used an overall counter for the
** each lane. This is used at the end of the program to display the total number of
** cars that have arrived in each lane.
** It adds the current arrivals to the running total.
** Parameter: int for number of vehicles arriving in the lane
*************************************************************************************/

void State::setArrived2(int arri)
{
	Arrived2 += arri;
}

/************************************************************************************
** Function: getDeparted2
** Description: This function simply returns the number of departing in the lane. It is
** used primarly for display purposes at the end of the program for the total number of
** vehicles that have departed each lane for all of the cycles combined.
** Output: int of the number of vehicles departed
*************************************************************************************/

int State::getDeparted2()
{
	return Departed2;
}

/************************************************************************************
** Function: setDeparted1
** Description: This function takes a parameter of int and sets the number of
** vehicles departed in each direction. This function is used an overall counter for the
** each lane. This is used at the end of the program to display the total number of
** cars that have departed in each lane.
** It adds the current departures to the running total.
** Parameter: int for number of vehicles departing the lane
*************************************************************************************/

void State::setDeparted2(int dep)
{
	Departed2 += dep;
}

/************************************************************************************
** Function: setWaitTime1
** Description: This function is used to calculate the wait time for each lane.
** It takes the number of cycles from the user input and it divides to total number
** of departures from the each lane by the cycles. This gives an average wait
** time for data collection at the end of the program.
*************************************************************************************/

void State::setWaitTime1(int wait1)
{
	waitTime1 = wait1;
}

/************************************************************************************
** Function: setWaitTime2
** Description: This function is used to calculate the wait time for each lane.
** It takes the number of cycles from the user input and it divides to total number
** of departures from the each lane by the cycles. This gives an average wait
** time for data collection at the end of the program.
*************************************************************************************/

void State::setWaitTime2(int wait2)
{
	waitTime2 = wait2;
}

/************************************************************************************
** Function: getWaitTime1
** Description: This function returns the average wait time for direction1. It
** is used at the end of the program to call the number that was calculated by
** set WaitTime for display purposes.
*************************************************************************************/

int State::getWaitTime1()
{
	return waitTime1;
}

/************************************************************************************
** Function: getWaitTime2
** Description: This function returns the average wait time for direction1. It
** is used at the end of the program to call the number that was calculated by
** set WaitTime for display purposes.
*************************************************************************************/

int State::getWaitTime2()
{
	return waitTime2;
}

/************************************************************************************
** Function: setTotalWaitTime1
** Description: This function is used to calculate the wait time for each lane.
** It takes the number of cycles from the user input and it divides to total number
** of departures from the each lane by the cycles. This gives an average wait
** time for data collection at the end of the program.
*************************************************************************************/

void State::setTotalWaitTime1(int waitTime1)
{
	totalWaitTime1 += waitTime1;
}

/************************************************************************************
** Function: setTotalWaitTime2
** Description: This function is used to calculate the wait time for each lane.
** It takes the number of cycles from the user input and it divides to total number
** of departures from the each lane by the cycles. This gives an average wait
** time for data collection at the end of the program.
*************************************************************************************/

void State::setTotalWaitTime2(int waitTime2)
{
	totalWaitTime2 += waitTime2;
}

/************************************************************************************
** Function: getTotalWaitTime2
** Description: This function returns the average wait time for direction1. It
** is used at the end of the program to call the number that was calculated by
** set WaitTime for display purposes.
*************************************************************************************/

int State::getTotalWaitTime1()
{
	return totalWaitTime1;
}

/************************************************************************************
** Function: getTotalWaitTime2
** Description: This function returns the average wait time for direction1. It
** is used at the end of the program to call the number that was calculated by
** set WaitTime for display purposes.
*************************************************************************************/

int State::getTotalWaitTime2()
{
	return totalWaitTime2;
}

/************************************************************************************
** Function: setNextState
** Description: This function sets the next state of the current linked object.
** It takes a paramter of a pointer to State and sets this pointer to the variable
** containing the nextState for future use in the program.
** Parameter: pointer to State
*************************************************************************************/

void State::setNextState(State* next)
{
	nextState = next;
}

/************************************************************************************
** Function: getNextState
** Description: This function gets the next state of the current linked object.
** It is used by the currentState pointer to find the next state of the linked objects
** in order to rotate through them in the program.
** Parameter: None
*************************************************************************************/

State* State::getNextState()
{
	return nextState;
}

/************************************************************************************
** Function: setNrArrivedDir1
** Description: This function takes a parameter of the number of vehicles arrived
** (int) and sets this amount to the current variable for the the vehicles
** that have arrived in the lane. This is used later in the program for
** display purposes of each light cycle.
** Parameter: int of arrivals
*************************************************************************************/

void State::setNrArrivedDir1(int arrive)
{
	arrive1 = arrive;
}

/************************************************************************************
** Function: getNrArriveDir1
** Description: This function simply returns the number of arriving in the lane. It is
** used primarly for display purposes at the end of the program for the total number of
** vehicles that have arrived each lane for the current cycle
** Output: int of the number of vehicles arrived
*************************************************************************************/

int State::getNrArrivedDir1()
{
	return arrive1;
}

/************************************************************************************
** Function: setNrDepartedDir1
** Description: This function takes a parameter of the number of vehicles departed
** (int) and sets this amount to the current variable for the the vehicles
** that have departed in the lane. This is used later in the program for
** display purposes of each light cycle.
** Parameter: int of departures
*************************************************************************************/

void State::setNrDepartedDir1(int depart)
{
	depart1 = depart;
}

/************************************************************************************
** Function: getNrDepartedDir1
** Description: This function simply returns the number of departures in the lane. It is
** used primarly for display purposes at the end of the program for the total number of
** vehicles that have departed each lane for the current cycle
** Output: int of the number of vehicles departed
*************************************************************************************/

int State::getNrDepartedDir1()
{
	return depart1;
}

/************************************************************************************
** Function: setNrArrivedDir2
** Description: This function takes a parameter of the number of vehicles arrived
** (int) and sets this amount to the current variable for the the vehicles
** that have arrived in the lane. This is used later in the program for
** display purposes of each light cycle.
** Parameter: int of arrivals
*************************************************************************************/

void State::setNrArrivedDir2(int arrive)
{
	arrive2 = arrive;
}

/************************************************************************************
** Function: getNrArriveDir2
** Description: This function simply returns the number of arriving in the lane. It is
** used primarly for display purposes at the end of the program for the total number of
** vehicles that have arrived each lane for the current cycle
** Output: int of the number of vehicles arrived
*************************************************************************************/

int State::getNrArrivedDir2()
{
	return arrive2;
}

/************************************************************************************
** Function: setNrDepartedDir2
** Description: This function takes a parameter of the number of vehicles departed
** (int) and sets this amount to the current variable for the the vehicles
** that have departed in the lane. This is used later in the program for
** display purposes of each light cycle.
** Parameter: int of departures
*************************************************************************************/

void State::setNrDepartedDir2(int depart)
{
	depart2 = depart;
}

/************************************************************************************
** Function: getNrDepartedDir2
** Description: This function simply returns the number of departures in the lane. It is
** used primarly for display purposes at the end of the program for the total number of
** vehicles that have departed each lane for the current cycle
** Output: int of the number of vehicles departed
*************************************************************************************/

int State::getNrDepartedDir2()
{
	return depart2;
}


