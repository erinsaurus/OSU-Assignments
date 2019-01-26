/************************************************************************************
** Author: Erin Alltop
** Date: 5/7/16
** Description: This program is a traffic simulator. It takes input from the user
** for how many cycles of the light they would like to see and outputs the
** arivals/depatures of vehicles at each cycle. At the end of the program it
** displays the total number of arrivals/depatures for each lane.
************************************************************************************/

#ifndef state_hpp
#define state_hpp
#include <string>

class State
{
private:
	std::string direction1;
	std::string direction2;
	int nrVehiclesDir1;
	int nrVehiclesDir2;
	State* nextState;
	int Arrived1;
	int Departed1;
	int Arrived2;
	int Departed2;
	int arrive1;
	int arrive2;
	int depart1;
	int depart2;
	float  waitTime1;
	float  waitTime2;

public:

	void nrOfVehiclesArrive(); //random generator for arrivals
	void nrOfVehiclesDepart(); //random generator for departures
	void setDirection1(std::string dir1); //label direction
	std::string getDirection1(); //get label for direction
	void setDirection2(std::string dir2); //label direction
	std::string getDirection2(); //get label for direction
								 //number of vehicles currently in the lanes
	void setVehiclesDir1(int lane1);
	int getVehiclesDir1();
	void setVehiclesDir2(int lane2);
	int getVehiclesDir2();
	State();
	State(std::string dir1, std::string dir2, State* next);
	State* getNextState();
	void setNextState(State* next);
	//number of arrivals/departures for each cycle
	void setNrArrivedDir1(int arrive);
	int getNrArrivedDir1();
	void setNrDepartedDir1(int depart);
	int getNrDepartedDir1();
	void setNrArrivedDir2(int arrive);
	int getNrArrivedDir2();
	void setNrDepartedDir2(int depart);
	int getNrDepartedDir2();
	//total number of arrivals/departures
	int getArrived1();
	void setArrived1(int arri);
	int getDeparted1();
	void setDeparted1(int dep);
	int getArrived2();
	void setArrived2(int arri);
	int getDeparted2();
	void setDeparted2(int dep);
	//wait time data calculations
	void setWaitTime(int departed);
	int getWaitTime1();
	int getWaitTime2();
};

#endif
