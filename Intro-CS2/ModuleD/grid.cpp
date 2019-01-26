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

#include "grid.hpp"
#include "doodlebug.hpp"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>


/*********************************************************************
** Function: Constructor
** Description: This is the constructor for the Grid class
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
************************************************************************/
//constructor
Grid::Grid()

{

}

/****************************************************************
** Function: overloaded constructor
** Description: This function creates a temporary array to
** dynamically allocate memory for the array at compile time.
** I used the TA examples as a guide for this function.
** Parameters: number of Rows and Columns, ants, and doodlebugs
*****************************************************************/


Grid::Grid(int rows, int cols, int ant, int doo)

{
	numRows = rows;
	numCols = cols;
	numAnts = ant;
	numDoodles = doo;

	critters = new Critter**[numRows];
	for (int i = 0; i < numRows; i++) {
		critters[i] = new Critter*[numCols];
	}
}


/****************************************************************
** Function: fillArray
** Description: This function initializes the new array with
** dots before it can be used in other functions. I used the TA
** Example as a guide to create this function.
** Parameters: Array by reference, number of rows and columns
** number of critters by user input
** Pre-Conditions: array dynamically allocated
** Post-Conditions: initialized array
*****************************************************************/


void Grid::fillArray()

{
	//initialize all locations to NULL
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++) {
			critters[i][j] = NULL;
		}
	}
}

/*********************************************************************
** Function: startPos
** Description: This functions starts the critters in random positions
** on the grid
** Parameters: grid by reference, number of rows, number of columns,
** number of critters
** Pre-Conditions: User input for all values
** Post-Conditions: sets the critters in random starting positions
************************************************************************/
void Grid::startPos()
{
	//for each ant, search through the array and insert ant objects in unoccupied cells
	for (int i = 0; i < numAnts; i++) {
		int xCoor = rand() % numRows;
		int yCoor = rand() % numCols;
		if (critters[xCoor][yCoor] == NULL)
		{	//delete critters[xCoor][yCoor];
			critters[xCoor][yCoor] = new Ant;
			critters[xCoor][yCoor]->setXcoor(xCoor);
			critters[xCoor][yCoor]->setYcoor(yCoor);
		} //if the cell is already occupied, set the counter back by one
		else if (critters[xCoor][yCoor] != NULL)
			--i;
	}

	//for each doodlebug, search through the array and insert doodlebug objects in unoccupied cells
	for (int i = 0; i < numDoodles; i++) {
		int xCoor = rand() % numRows;
		int yCoor = rand() % numCols;
		if (critters[xCoor][yCoor] == NULL)
		{	//delete critters[xCoor][yCoor];
			critters[xCoor][yCoor] = new Doodlebug;
			critters[xCoor][yCoor]->setXcoor(xCoor);
			critters[xCoor][yCoor]->setYcoor(yCoor);
		} //if the cell is already occupied, set the counter back by one
		else if (critters[xCoor][yCoor] != NULL)
			--i;
	}
}


/****************************************************************
** Function: printArray
** Description: This function simply prints out the array. It
** uses two for loops to print out each element of the array.
** I used the TA examples as a guide for this function.
** Parameters: pointer to array, number of rows and columns
** Pre-Conditions: numRows and numCols declared, array dynamically
** allocated and initialized
** Post-Conditions: array printed out
*****************************************************************/

void Grid::printArray()

{

	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j <numCols; j++) {
			if (critters[i][j])
			{
				if (critters[i][j]->getClass() == "Doodlebug")
					std::cout << " " << 'D';
				else if (critters[i][j]->getClass() == "Ant")
					std::cout << " " << 'A';
			}
			else
				std::cout << " " << '.';

		}
		std::cout << std::endl;
	}

}


/*********************************************************************
** Function: updateLocation
** Description: This function updates the location of the critter.
** It calls the moveCritter location from the Critter class to
** find the direction that the critter has moved, and then prints
** The program terminates after the number of steps is complete.
** Parameters: Array by reference, beginning x and y coordinates,
** and number of rows and columns.
** Pre-Conditions: all parameters declared and initialized
** Post-Conditions: Critter has exited the grid, and numSteps outputted.
************************************************************************/

void Grid::updateLocation()
{
	//create, fill, and print array with starting locations of critters
	fillArray();
	startPos();
	printArray();

	std::cout << std::endl;

	//continue looping until grid is full
	do { //searching array
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) {
				if (critters[i][j] != NULL)
				{
					if (critters[i][j]->getMoveCheck() != 1) //check if ant has not moved
					{
						critters[i][j]->randomDirection(); //get direction
						
						if (critters[i][j]->getClass() == "Ant") //if the object is an ant object, move the ant
						{
							moveAnt(critters[i][j]->getXcoor(), critters[i][j]->getYcoor());
						}
						else if (critters[i][j]->getClass() == "Doodlebug") //if the object is a doodlebug object, move the doodlebug
						{
							moveDoodlebug(critters[i][j]->getXcoor(), critters[i][j]->getYcoor());
						}
						if (critters[critters[i][j]->getXcoor()][critters[i][j]->getYcoor()] == critters[i][j])
						{ /* Do not set location to NULL if critter has not moved!*/
						}
						else if (critters[critters[i][j]->getXcoor()][critters[i][j]->getYcoor()] != critters[i][j])
						{   //if critter has moved, call Breed function to determine whether it breeds or not
							critters[critters[i][j]->getXcoor()][critters[i][j]->getYcoor()] = critters[i][j];
							critters[i][j] = critters[i][j]->Breed();
							if (critters[i][j] != NULL)
							{ //if the critter breeds, set the new x and y coordinates to the current location
								critters[i][j]->setXcoor(i);
								critters[i][j]->setYcoor(j);
							}
							else
							{/*do nothing*/}
						}
					}

					//reset the move check variable to not moved
					else if (critters[i][j]->getMoveCheck() == 1) {
						critters[i][j]->setMoveCheck(2);
					}

					if (critters[i][j] != NULL) //if the location is not null
					{
						if (critters[i][j]->getClass() == "Doodlebug") // if it is occupied by a Doodlebug
						{
							if (static_cast<Doodlebug *>(critters[i][j])->getNoEat() == 3) //if it hasn't eaten in three turns
								critters[i][j] = NULL; //the doodlebug dies :(
							else
							{/*do nothing*/}
						}
					}
				}
				else if (critters[i][j] == NULL)
				{/*do nothing*/}
			}
		}
	//	system("CLS");
		printArray(); //print the array
		std::cout << std::endl;

	} while (isFull() == false);

	std::cout << std::endl;
}


/****************************************************************
** Function: Destructor
** Description: This function deallocates the array at the end
** of the program.
** Pre-Conditions: array dynamically allocated, program complete
** Post-Conditions: initialized array
*****************************************************************/

Grid::~Grid()
{
	for (int i = 0; i < numRows; ++i)
	{
		for (int j = 0; j < numCols; ++j)
			delete critters[i][j];
		delete[] critters[i];
	}
	delete[] critters;









}

/****************************************************************
** Function: moveAnt
** Description: This function moves the ant in the grid.
** It determines when the doodlebug breeds.
** Paramters: x and y coordinates of the specific ant
*****************************************************************/
void Grid::moveAnt( int xCoor, int yCoor)
{
	//determine whether the ant can move and move it if it is safe to do so
	if ((critters[xCoor][yCoor]->getDirection()) == 1) //North
	{
		if ((xCoor > 0) && (critters[(xCoor - 1)][yCoor] == NULL))
		{
			critters[xCoor][yCoor]->moveCritter(numCols, numRows); //call move function
		}
		else
		{
			critters[xCoor][yCoor]->setMoveCheck(1); //set move check to "moved"
		}
	}
	else if ((critters[xCoor][yCoor]->getDirection()) == 2) //East
	{
		if ((yCoor < (numCols - 1)) && (critters[xCoor][(yCoor + 1)] == NULL))
		{
			critters[xCoor][yCoor]->moveCritter(numCols, numRows); //call move function
		}
		else
		{
			critters[xCoor][yCoor]->setMoveCheck(1); //set move check to "moved"
		}
	}
	else if ((critters[xCoor][yCoor]->getDirection()) == 3) //South
	{
		if ((xCoor < (numRows - 1)) && (critters[(xCoor + 1)][yCoor] == NULL))
		{
			critters[xCoor][yCoor]->moveCritter(numCols, numRows); //call move function
		}
		else
		{
			critters[xCoor][yCoor]->setMoveCheck(1); //set move check to "moved"
		}
	}
	else if ((critters[xCoor][yCoor]->getDirection()) == 4) //West
	{
		if ((yCoor > 0) && (critters[xCoor][(yCoor - 1)] == NULL))
		{
			critters[xCoor][yCoor]->moveCritter(numCols, numRows); //call move function
		}
		else
		{
			critters[xCoor][yCoor]->setMoveCheck(1); //set move check to "moved"
		}
	}
}


/****************************************************************
** Function: moveDoodlebug
** Description: This function moves the doodlebug in the grid.
** It determines when the doodlebug breeds, eats, or starves.
** Paramters: x and y coordinates of the specific doodlebug
*****************************************************************/
void Grid::moveDoodlebug(int xCoor, int yCoor)
{
	//determine the move, starve, and eat functions of the doodlebug
	if ((critters[xCoor][yCoor]->getDirection()) == 1) //North
	{
		if ((xCoor > 0) && (critters[(xCoor - 1)][yCoor] == NULL)) //if it can move but not eat
		{
			static_cast<Doodlebug *>(critters[xCoor][yCoor])->Starve(); //call the starve function
			critters[xCoor][yCoor]->moveCritter(numCols, numRows); //call move function
		}
		else if ((xCoor > 0) && (critters[(xCoor - 1)][yCoor]->getClass() == "Ant")) //if there is an ant
		{
			critters[xCoor][yCoor]->Eat(); //eat the ant
			critters[xCoor][yCoor]->moveCritter(numCols, numRows); //call move function
		}
		else
		{  //if the doodlebug can't move, call the starve function
			static_cast<Doodlebug *>(critters[xCoor][yCoor])->Starve();
			critters[xCoor][yCoor]->setMoveCheck(1);
		}
	}
	else if ((critters[xCoor][yCoor]->getDirection()) == 2) //East
	{
		if ((yCoor < (numCols - 1)) && (critters[xCoor][(yCoor + 1)] == NULL)) //if it can move but not eat
		{
			static_cast<Doodlebug *>(critters[xCoor][yCoor])->Starve(); //call the starve function
			critters[xCoor][yCoor]->moveCritter(numCols, numRows); //call move function
		}
		else if ((yCoor < (numCols - 1)) && (critters[xCoor][(yCoor + 1)]->getClass() == "Ant")) //if there is an ant
		{
			critters[xCoor][yCoor]->Eat(); //eat the ant
			critters[xCoor][yCoor]->moveCritter(numCols, numRows); //call move function
		}
		else
		{	//if the doodlebug can't move, call the starve function
			static_cast<Doodlebug *>(critters[xCoor][yCoor])->Starve();
			critters[xCoor][yCoor]->setMoveCheck(1);
		}
	}
	else if ((critters[xCoor][yCoor]->getDirection()) == 3) //South
	{
		if ((xCoor < (numRows - 1)) && (critters[(xCoor + 1)][yCoor] == NULL)) //if it can move but not eat
		{
			static_cast<Doodlebug *>(critters[xCoor][yCoor])->Starve(); //call the starve function
			critters[xCoor][yCoor]->moveCritter(numCols, numRows); //call move function
		}
		else if ((xCoor < (numRows - 1)) && (critters[(xCoor + 1)][yCoor]->getClass() == "Ant")) //if there is an ant
		{
			critters[xCoor][yCoor]->Eat(); //eat the ant
			critters[xCoor][yCoor]->moveCritter(numCols, numRows); //call move function
		}
		else
		{	//if the doodlebug can't move, call the starve function
			static_cast<Doodlebug *>(critters[xCoor][yCoor])->Starve();
			critters[xCoor][yCoor]->setMoveCheck(1);
		}
	}
	else if ((critters[xCoor][yCoor]->getDirection()) == 4) //West
	{
		if ((yCoor > 0) && (critters[xCoor][(yCoor - 1)] == NULL)) //if it can move but not eat
		{
			static_cast<Doodlebug *>(critters[xCoor][yCoor])->Starve(); //call the starve function
			critters[xCoor][yCoor]->moveCritter(numCols, numRows); //call move function
		}
		else if ((yCoor > 0) && (critters[xCoor][(yCoor - 1)]->getClass() == "Ant")) //if there is an ant
		{
			critters[xCoor][yCoor]->Eat(); //eat the ant
			critters[xCoor][yCoor]->moveCritter(numCols, numRows); //call move function
		}
		else 
		{	//if the doodlebug can't move, call the starve function
			static_cast<Doodlebug *>(critters[xCoor][yCoor])->Starve();
			critters[xCoor][yCoor]->setMoveCheck(1);
		}
	}
}


/****************************************************************
** Function: isFull
** Description: This is a helper function to determine if the
** array is full or not. If it is not full, it returns false,
** and if it is full it returns true.
*****************************************************************/
bool Grid::isFull()
{
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
			if (critters[i][j] == NULL)
				return false;
	}
	
	return true;
}
