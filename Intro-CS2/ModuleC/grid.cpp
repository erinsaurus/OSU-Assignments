/****************************************************************************
** Author: Erin Alltop
** Date: 4/15/16
** Description: This program takes user input for the size of the 2D array,
** number of ant objects, and number of steps the ant will take. If the
** ant moves 3 times, it breeds and leaves a new ant in its spot when it moves.
** Input: Row size, Column size, number of ants, number of steps
** Output: ant movement in random directions until number of steps is
** reached. Ants do not overlap or fall off grid.
*****************************************************************************/

#include "grid.hpp"
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
** Function: createArray
** Description: This function creates a temporary array to
** dynamically allocate memory for the array at compile time.
** I used the TA examples as a guide for this function.
** Parameters: number of Rows and Columns for the array
** Pre-Conditions: numRows and numCols declared
** Post-Conditions: new temporary array
*****************************************************************/


Ant ***Grid::createArray(int numRows, int numCols)

{
	Ant ***tArray;

	tArray = new Ant**[numRows];
	for (int i = 0; i < numRows; i++) {
		tArray[i] = new Ant*[numCols];
	}
	return tArray;
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


void Grid::fillArray(Ant ***&gArray, int numRows, int numCols)

{
	//initialize all locations to NULL
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++) {
			gArray[i][j] = NULL;
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
void Grid::startPos(Ant ***&gArray, int numRows, int numCols, int numCrit)
{



	//for each critter, search through the array and insert critter objects in unoccupied cells
	for (int i = 0; i < numCrit; i++) {
		int xCoor = rand() % numRows;
		int yCoor = rand() % numCols;
		if (gArray[xCoor][yCoor] == NULL)
		{
			gArray[xCoor][yCoor] = new Ant;
			gArray[xCoor][yCoor]->setXcoor(xCoor);
			gArray[xCoor][yCoor]->setYcoor(yCoor);
		} //if the cell is already occupied, set the counter back by one
		else if (gArray[xCoor][yCoor] != NULL)
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

void Grid::printArray(Ant ***bGrid, int numRows, int numCols)

{

	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j <numCols; j++) {
			if (!bGrid[i][j])
				std::cout << " " << '.';
			else
				std::cout << " " << 'A';

		}
		std::cout << std::endl;
	}

}

/*********************************************************************
** Function: setRows
** Description: This function sets the number of rows from main
** Parameters: int number of rows
** Pre-Conditions: User input from main for number of rows
** Post-Conditions: number of rows
************************************************************************/
void Grid::setRows(int rows)
{
	numRows = rows;
}


/*********************************************************************
** Function: setCols
** Description: This function sets the number of columns from main
** Parameters: int number of columns
** Pre-Conditions: User input from main for number of columns
** Post-Conditions: number of columns
************************************************************************/
void Grid::setCols(int cols)
{
	numCols = cols;
}

/*********************************************************************
** Function: getRows
** Description: This function returns the number of set rows
** Parameters: None
** Pre-Conditions: setRows function
** Post-Conditions: returns rows
************************************************************************/
int Grid::getRows()
{
	return numRows;
}


/*********************************************************************
** Function: getCols
** Description: This function returns the number of set columns
** Parameters: None
** Pre-Conditions: User input from main for number of columns
** Post-Conditions: returns columns
************************************************************************/
int Grid::getCols()
{
	return numCols;
}


/*********************************************************************
** Function: setNumCrit
** Description: This function sets the number of critters from main
** Parameters: int number of critters
** Pre-Conditions: User input from main for number of critters
** Post-Conditions: number of critters
************************************************************************/
void Grid::setNumCrit(int critters)
{
	numCrit = critters;
}


/*********************************************************************
** Function: getNumCrit
** Description: This function returns the number of critters
** Parameters: None
** Pre-Conditions: number of critters set in setNumCrit
** Post-Conditions: returns number of critters
************************************************************************/
int Grid::getNumCrit()
{
	return numCrit;
}

/*********************************************************************
** Function: setNumMoves
** Description: This function sets the number of moves from main
** Parameters: int number of moves
** Pre-Conditions: User input from main for number of moves
** Post-Conditions: sets the number of moves
************************************************************************/
void Grid::setNumMoves(int moves)
{
	numMoves = moves;
}

/*********************************************************************
** Function: getNumMoves
** Description: This function gets the number of moves
** Parameters: None
** Pre-Conditions: Number of moves set in setNumMoves()
** Post-Conditions: returns the number of moves
************************************************************************/

int Grid::getNumMoves()
{
	return numMoves;
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

	Ant ***bGrid;

	 //create, fill, and print array with starting locations of critters
	bGrid = createArray(getRows(), getCols());
	fillArray(bGrid, getRows(), getCols());
	startPos(bGrid, getRows(), getCols(), getNumCrit());
	printArray(bGrid, getRows(), getCols());

	std::cout << std::endl;

	int numMoves = 0; //counter

	//continue looping until number of steps is complete
	do { //searching array
		for (int i = 0; i < getRows(); i++) {
			for (int j = 0; j < getCols(); j++) {
				if (bGrid[i][j] != NULL)
				{
					if (bGrid[i][j]->getMoveCheck() != 1) //check if ant has not moved
					{
						bGrid[i][j]->randomDirection(); //get direction
						//determine whether the critter can move and move it if it is safe to do so
						if ((bGrid[i][j]->getDirection()) == 1) //North
						{
							if ((bGrid[i][j]->getXcoor() > 0) && (bGrid[(bGrid[i][j]->getXcoor() - 1)][bGrid[i][j]->getYcoor()] == NULL))
							{
								bGrid[i][j]->moveCritter(numCols, numRows); //call move function
							}
							else {/*do nothing*/ }
						}
						else if ((bGrid[i][j]->getDirection()) == 2) //East
						{
							if ((bGrid[i][j]->getYcoor() < (numCols - 1)) && (bGrid[bGrid[i][j]->getXcoor()][(bGrid[i][j]->getYcoor() + 1)] == NULL))
							{
								bGrid[i][j]->moveCritter(numCols, numRows); //call move function
							}
							else {/*do nothing*/ }
						}
						else if ((bGrid[i][j]->getDirection()) == 3) //South
						{
							if ((bGrid[i][j]->getXcoor() < (numRows - 1)) && bGrid[(bGrid[i][j]->getXcoor() + 1)][bGrid[i][j]->getYcoor()] == NULL)
							{
								bGrid[i][j]->moveCritter(numCols, numRows); //call move function
							}
							else {/*do nothing*/ }
						}
						else if ((bGrid[i][j]->getDirection()) == 4) //West
						{
							if ((bGrid[i][j]->getYcoor() > 0) && (bGrid[bGrid[i][j]->getXcoor()][(bGrid[i][j]->getYcoor() - 1)] == NULL))
							{
								bGrid[i][j]->moveCritter(numCols, numRows); //call move function
							}
							else {/*do nothing*/ }
						}

						if (bGrid[bGrid[i][j]->getXcoor()][bGrid[i][j]->getYcoor()] == bGrid[i][j])
						{ /* Do not set location to NULL if critter has not moved!*/
						}
						else if (bGrid[bGrid[i][j]->getXcoor()][bGrid[i][j]->getYcoor()] != bGrid[i][j])
						{   //if critter has moved, call Breed function to determine whether it breeds or not
							bGrid[bGrid[i][j]->getXcoor()][bGrid[i][j]->getYcoor()] = bGrid[i][j];
							bGrid[i][j] = bGrid[i][j]->Breed();
							if (bGrid[i][j] != NULL) 
							{ //if the critter breeds, set the new x and y coordinates to the current location
								bGrid[i][j]->setXcoor(i);
								bGrid[i][j]->setYcoor(j);
							}
							else
							{/*do nothing*/}
						}
					}

					//reset the move check variable to not moved
					else if (bGrid[i][j]->getMoveCheck() == 1){
						bGrid[i][j]->setMoveCheck(2);
					}
				}
				else if (bGrid[i][j] == NULL)
				{/*do nothing*/}
			}
		}

		printArray(bGrid, getRows(), getCols()); //print the array
		std::cout << std::endl;
		numMoves++; //move counter

	} while (numMoves < getNumMoves()); //loop while move counter is less than or equal to number of moves requested
	std::cout << std::endl;

//remove(bGrid, numRows, numCols);
}



/****************************************************************
** Function: remove Array
** Description: This function deallocates the array at the end
** of the program.
** Parameters: Array by reference, number of columns
** Pre-Conditions: array dynamically allocated, program complete
** Post-Conditions: initialized array

** Note: I have still be unsuccessful in getting this deallocation
** to work within the destructor without significantly changing
** the way my program works. 
*****************************************************************/

void Grid::remove(Ant ***&bGrid, int numRows, int numCols)
{
	









	for (int i = 0; i < getRows(); ++i)
	{
		for (int j = 0; j < getCols(); ++j)
			delete[] bGrid[i][j];
		delete[] bGrid[i];
	}
	delete[] bGrid;
}
