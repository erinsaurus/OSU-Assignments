/************************************************************************************
** Author: Erin Alltop
** Date: 5/7/16
** Description: This program is a traffic simulator. It takes input from the user
** for how many cycles of the light they would like to see and outputs the
** arivals/depatures of vehicles at each cycle. At the end of the program it
** displays the total number of arrivals/depatures for each lane.
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


}
/************************************************************************************
** Function: nrOfVehiclesArrive
** Description: This function randomly generates numbers of arrivals for both
** directions of the current state. It then sets the randomly gemerated number
** to the variable for the number arrived for each direction to be used later in
** the program.
*************************************************************************************/

void State::nrOfVehiclesArrive()
{
	int arrive1;
	int arrive2;
	if (getDirection1() != "NoGreen" && getDirection2() != "NoGreen")
	{
		int roll1 = rand() % 6 + 1;
		int roll2 = rand() % 6 + 1;
		int roll3 = rand() % 6 + 1;
		int roll4 = rand() % 6 + 1;
		arrive1 = roll1 + roll2;
		arrive2 = roll3 + roll4;
	}
	else if (getDirection1() == "NoGreen" && getDirection2() == "NoGreen")
	{
		arrive1 = 0;
		arrive2 = 0;
	}

	setNrArrivedDir1(arrive1);
	setNrArrivedDir2(arrive2);
}


/************************************************************************************
** Function: nrOfVehiclesDepart
** Description: This function randomly generates numbers of departures for both
** directions of the current state. It then sets the randomly gemerated number
** to the variable for the number departed for each direction to be used later in
** the program.
*************************************************************************************/

void State::nrOfVehiclesDepart()
{
	int depart1;
	int depart2;

	if (getDirection1() != "NoGreen" && getDirection2() != "NoGreen")
	{
		depart1 = (rand() % (8 - 4) + 4);
		depart2 = (rand() % (8 - 4) + 4);
	}

	else if (getDirection1() == "NoGreen" && getDirection2() == "NoGreen")
	{
		depart1 = 0;
		depart2 = 0;
	}

	setNrDepartedDir1(depart1);
	setNrDepartedDir2(depart2);
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
** Function: setWaitTime
** Description: This function is used to calculate the wait time for each lane.
** It takes the number of cycles from the user input and it divides to total number
** of departures from the each lane by the cycles. This gives an average wait
** time for data collection at the end of the program.
*************************************************************************************/

void State::setWaitTime(int cycles)
{
	waitTime1 = getDeparted1() / cycles;
	waitTime2 = getDeparted2() / cycles;
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


