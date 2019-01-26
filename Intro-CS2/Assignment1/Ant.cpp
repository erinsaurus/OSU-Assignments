
/********************************************************************
** Author: Erin Alltop
** Date: 4/6/16
** Description: This program moves an ant around a grid. If it
** lands on a white spot, it turns right and makes it black. If it
** lands on a black spot, it turns left and makes it white until
** the program terminates.
*********************************************************************/

#include <iostream>
#include "aGrid.hpp"
#include "Ant.hpp"


/****************************************************************
** Function: playGame
** Description: This function is called to begin the game. It
** actually contains two functions as I had issues with enum
** to separate out the coordinate adjustment function.
** Parameters: Array by reference, x and y coordinates,
** rows and columns, and number of steps to perform.
** Pre-Conditions: array created, user input complete
** Post-Conditions: none. Game complete after running function.
*****************************************************************/
void Ant::playGame(char **&antG, int xCoor, int yCoor, int rows, int cols, int numSteps)
{
    int stepCounter = 0;
    Direction currDir = NORTH;

while(xCoor <= rows || yCoor <= cols){
    while(stepCounter <= numSteps){


 //adjust coordinates
    if(currDir == NORTH)
        xCoor -= 1;
    else if(currDir == EAST)
        yCoor += 1;
    else if(currDir == SOUTH)
        xCoor += 1;
    else if(currDir == WEST)
        yCoor -= 1;

/* This function determines what direction the ant will
 * travel in next. */

    switch(currDir)
    {
     case NORTH: {

                    if(antG[xCoor][yCoor] == '.')
                        currDir = EAST;
                    else if (antG[xCoor][yCoor] == '#')
                        currDir = WEST;

                 }
                break;
    case EAST:
                 {
                    if (antG[xCoor][yCoor] == '.')
                        currDir = SOUTH;
                    else if (antG[xCoor][yCoor] == '#')
                        currDir = NORTH;
                }

                break;
    case SOUTH:
                {
                    if (antG[xCoor][yCoor] == '.')
                        currDir = WEST;
                    else if (antG[xCoor][yCoor] == '#')
                        currDir = EAST;
                }
                break;
    case WEST:
                {
                    if (antG[xCoor][yCoor] == '.')
                        {currDir = NORTH;}
                    else if (antG[xCoor][yCoor] == '#')
                        currDir = SOUTH;
                }
                break;
    }

            stepCounter++; //counter to keep track of moves


    /* Call to the function to change the color of the coordinates */
    changeColor(antG, xCoor, yCoor, rows, cols);

    std::cout << "The ant has taken " << stepCounter-1 << " steps." << std::endl;

}

}
  std::cout << "The ant has left the grid! It is squashed. :( " << std::endl;
}


/****************************************************************
** Function: changeColor
** Description: This function changes the color of the current
** location of the ant to the opposite color. It also prints out
** the array with the updated color change.
** Parameters: Array by reference, x and y coordinates,
** rows and columns.
** Pre-Conditions: playGame function started, user input complete.
** Post-Conditions: color of tile has changed.
*****************************************************************/

void Ant::changeColor(char **&antG, int xCoor, int yCoor, int rows, int cols) //return the color
{

    aGrid print; // aGrid object
    if(antG[xCoor][yCoor] == '.') // if tile is currently white..
        {
            antG[xCoor][yCoor] = '*'; // add ant to tile..
            print.printArray(antG, rows, cols); //take a "snapshot" of grid with ant on tile..
            std::cout << std::endl;
            antG[xCoor][yCoor] = '#'; // change tile color to black.
        }

        else if(antG[xCoor][yCoor] == '#') //if tile is currently black..
        {
            antG[xCoor][yCoor] = '*'; //add ant to tile..
            print.printArray(antG,rows,cols); // take a "snapshot" of grid with ant on tile..
            std::cout << std::endl;
            antG[xCoor][yCoor] = '.'; //change tile color to white.

        }

}
