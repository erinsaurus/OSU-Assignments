/****************************************************************************
** Author: Erin Alltop
** Date: 4/29/16
** Description: This program takes user input for the size of the 2D array,
** number of ant objects, nomber of doodlebug objects, and number of steps 
** the critters will take. If the ant moves 3 times, it breeds and leaves a 
** new ant in its spot when it moves. It does not eat or starve. If the 
** doodlebug moves 8 times, it breeds and leaves a new doodlebug in its
** spot when it moves. If it doesn't eat in 3 moves/move attempts it starves
** and dies. 
** Input: Row size, Column size, number of ants, number of doodlebugs
** number of steps
** Output: ant/doodlebug movement in random directions until number of steps is
** reached. Doodlebugs eat ants but not doodlebugs. Critters do not fall
** of the grid.
*****************************************************************************/


#include <iostream>
#include <cstdlib>
#include <ctime>
#include "grid.hpp"
#include "critter.hpp"

int main()
{
	//random number seed
	// srand((unsigned int)time(NULL));
	srand((unsigned int)time(0));
	int cols;
	int rows;
	int ants;
	int doodle;

	//user input and input validation for number of rows
	std::cout << "Please enter the number of rows: ";
	std::cin >> rows;
	while (rows <= 0) {
		std::cout << "Please enter a number greater than 0: ";
		std::cin >> rows;
	}

	//user input and input validation for number of columns
	std::cout << "Please enter the number of columns: ";
	std::cin >> cols;
	while (cols <= 0) {
		std::cout << "Please enter a number greater than 0: ";
		std::cin >> cols;
	}

	//user input and validation for the number of ants
	std::cout << "How many ants would you like? ";
	std::cin >> ants;
	while (ants <= 0) {
		std::cout << "Please enter at least one ant to play: ";
		std::cin >> ants;
	}
	while (ants >= (rows * cols)) {
		std::cout << "Please enter a number of ant less than " << (rows * cols) << " to play: ";
		std::cin >> ants;
		{
			while (ants <= 0) {
				std::cout << "Please enter at least one ant to play: ";
				std::cin >> ants;
				std::cout << std::endl;
			}
		}
	}

	//user input and validation for the number of doodlebugs
	std::cout << "How many doodlebugs would you like? ";
	std::cin >> doodle;
	while (doodle <= 0) {
		std::cout << "Please enter at least one doodlebug to play: ";
		std::cin >> doodle;
	}
	while (doodle >= ((rows * cols) - ants)) {
		std::cout << "Please enter a number of doodlebugs less than " << ((rows * cols) - ants) << " to play: ";
		std::cin >> doodle;
		{
			while (doodle <= 0) {
				std::cout << "Please enter at least one doodlebug to play: ";
				std::cin >> doodle;
				std::cout << std::endl;
			}
		}
	}

	//create grid object and initialize variables
	Grid squash(rows, cols, ants, doodle); 
	//run game
	squash.updateLocation();

	//	system("pause");

	return 0;
}
