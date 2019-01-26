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


#include <iostream>
#include "state.hpp"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

/*******************************************************************************
** Function: getArrDep
** Description: This function was moved out of the main function in order to 
** reduce the amount of lines that main has. It simply calls the functions
** to calculate arrivals and departures for the lanes and sets how many
** vehicles are in each lane.
********************************************************************************/

void getArrDep(State* currentState, int counter)
{
		currentState->nrOfVehiclesArrive(counter); //get arrivals for both directions
		currentState->nrOfVehiclesDepart(counter); //get departures for both directions

		//assign departures/arrivals to variables for ease of use and less code
		int depart1 = currentState->getNrDepartedDir1();
		int arrive1 = currentState->getNrArrivedDir1();
		int depart2 = currentState->getNrDepartedDir2();
		int arrive2 = currentState->getNrArrivedDir2();

		if ((arrive1 - depart1) >= 0) //if the difference is at least 0, update number of vehicles in each lane
		{
			currentState->setVehiclesDir1(currentState->getVehiclesDir1() + (arrive1 - depart1));
		}

		if ((arrive2 - depart2) >= 0) //if the difference is at least 0, update number of vehicles in each lane
		{
			currentState->setVehiclesDir2(currentState->getVehiclesDir2() + (arrive2 - depart2));
		}
}

/************************************************************************
 ** Function: main
 ** Description: main function to run the program!
 ************************************************************************/

int main()
{
	srand(time(NULL));
	std::cout << "This is a traffic simulation. How many light cycles would you like? ";
	std::cout << "\nKeep it simple with 10-15 or 50-100 light cycles might be interesting! ";
	int cycles;
	std::cin >> cycles; //user input for number of cycles
	while (cycles <= 0) //input validation for user input
	{
		std::cout << "Please pick at least one cycle to go through: ";
		std::cin >> cycles;
	}

	//create pointers to states and current state. Create new objects and initialize them.
	State* currentState = NULL;
	State* state1 = NULL;
	State* state2 = NULL;
	State* state3 = NULL;
	State* state4 = NULL;

	state1 = new State("East", "West", state2); //EW-G NS-R
	state2 = new State("NoGreen", "NoGreen", state3); //EW-Y NS-R
	state3 = new State("North", "South", state4); //EW-R NS-G
	state4 = new State("NoGreen", "NoGreen", state1); //EW-R NS-Y

	state1->setNextState(state2);
	state2->setNextState(state3);
	state3->setNextState(state4);
	state4->setNextState(state1);

	currentState = state1; //set pointer to current state to state 1

	int counter = 1; //counter variable

	while (counter <= cycles) //loop until number of cycles is complete
	{
		
		for (int i = 0; i < cycles; i++) //loop to display output for arrivals/departures at each light
		{
			getArrDep(currentState, counter);

			std::cout << "\n\nCycle " << counter << ": \n" << std::endl;

			if (currentState->getDirection1() != "NoGreen" && currentState->getDirection2() != "NoGreen")
			{
				std::cout << currentState->getDirection1() << " lane: \n"
					<< "Number of vehicles arrived: "
					<< currentState->getNrArrivedDir1() << std::endl;
				std::cout << "Number of vehicles departed: "
					<< currentState->getNrDepartedDir1() << std::endl;
				std::cout << currentState->getDirection2()
					<< " lane: \n" << "Number of vehicles arrived: "
					<< currentState->getNrArrivedDir2() << std::endl;
				std::cout << "Number of vehicles departed: "
					<< currentState->getNrDepartedDir2() << std::endl;
			}

			//This block of code adds the current counts in each lane to a total counter
			//for each cycle to be displayed at the end
			currentState->setArrived1(currentState->getNrArrivedDir1());
			currentState->setDeparted1(currentState->getNrDepartedDir1());
			currentState->setArrived2(currentState->getNrArrivedDir2());
			currentState->setDeparted2(currentState->getNrDepartedDir2());
			currentState = currentState->getNextState(); //change state

			getArrDep(currentState, counter);

			if (currentState->getDirection1() == "NoGreen" && currentState->getDirection2() == "NoGreen")
			{
				if (currentState->getNextState()->getDirection1() == "North")
				{
					std::cout << "North lane: \n"
						<< "Number of vehicles arrived: "
						<< currentState->getNrArrivedDir1() << std::endl;
					std::cout << "Number of vehicles departed: "
						<< currentState->getNrDepartedDir1() << std::endl;
					std::cout << "South lane: \n"
						<< "Number of vehicles arrived: "
						<< currentState->getNrArrivedDir2() << std::endl;
					std::cout << "Number of vehicles departed: "
						<< currentState->getNrDepartedDir2() << std::endl;
				}

				else if (currentState->getNextState()->getDirection1() == "East")
				{
					std::cout << "East lane: \n"
						<< "Number of vehicles arrived: "
						<< currentState->getNrArrivedDir1() << std::endl;
					std::cout << "Number of vehicles departed: "
						<< currentState->getNrDepartedDir1() << std::endl;
					std::cout << "West lane: \n"
						<< "Number of vehicles arrived: "
						<< currentState->getNrArrivedDir2() << std::endl;
					std::cout << "Number of vehicles departed: "
						<< currentState->getNrDepartedDir2() << std::endl;
				}
			}

			//This block of code adds the current counts in each lane to a total counter
			//for each cycle to be displayed at the end
			currentState->setArrived1(currentState->getNrArrivedDir1());
			currentState->setDeparted1(currentState->getNrDepartedDir1());
			currentState->setArrived2(currentState->getNrArrivedDir2());
			currentState->setDeparted2(currentState->getNrDepartedDir2());
			currentState = currentState->getNextState(); //change state
			sleep(1);
			counter++; //increment counter variable

		}

			sleep(1); //slight delay of output

		currentState = currentState->getNextState(); //change state
	}


	std::cout << "\n\nTotal number of arrivals and departures for each lane: \n" << std::endl;

	for (int i = 0; i < 4; i++) //loop to display total output for arrivals/departures at each light
	{
		if (currentState->getDirection1() != "NoGreen" && currentState->getDirection2() != "NoGreen")
		{
			//currentState->setWaitTime(cycles); //calculate the total wait times for each lane

			std::cout << currentState->getDirection1() << " lane: \n"
				<< "Number of vehicles arrived: "
				<< currentState->getArrived1() << std::endl;
			std::cout << "Number of vehicles departed: "
				<< currentState->getDeparted1() << std::endl;
			std::cout << "Average wait time: "
				<< (currentState->getTotalWaitTime1() / currentState->getDeparted1()) << std::endl;
			std::cout << currentState->getDirection2()
				<< " lane: \n" << "Number of vehicles arrived: "
				<< currentState->getArrived2() << std::endl;
			std::cout << "Number of vehicles departed: "
				<< currentState->getDeparted2() << std::endl;
			std::cout << "Average wait time: "
				<< (currentState->getTotalWaitTime2() / currentState->getDeparted2()) << std::endl;
		}

		currentState = currentState->getNextState(); //change state
	}

		//delete pointers
		//delete state1;
		//delete state2;
		//delete state3;
		//delete state4;
		//delete currentState;
		
		
	//system("PAUSE");

	return 0;
}

