/********************************************************************
** Author: Erin Alltop
** Date: 4/6/16
** Description: This program moves an ant around a grid. If it
** lands on a white spot, it turns right and makes it black. If it
** lands on a black spot, it turns left and makes it white until
** the program terminates.
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "aGrid.hpp"
#include "Ant.hpp"

int main()
{

srand((unsigned int)time(0)); //random number seed

//variables
char **antG;
int rows;
int cols;
int xCoor;
int yCoor;
int pick;
int numSteps;
//objects
aGrid grid;
Ant game;

/* This block of code prompts the user for information about the array size and ant location
 * and also does thorough input validation*/

std::cout << "How many rows and columns would you like? Please enter separated by a space: " ;
std::cin >> rows >> cols;

 while(rows <= 0 || cols <=0){
        std::cout << "Please enter a number greater than 0: ";
        std::cin >> rows >> cols;
    }

std::cout << std::endl;

/* Here we dynamically allocate memory to the array, initialize it, and print a black array*/
antG = grid.createArray(rows, cols);
grid.fillArray(antG, rows, cols);
grid.printArray(antG, rows, cols);
std::cout << std::endl;

std::cout << "Please enter 1 for a random starting location or 2 to pick your own! ";
std::cin >> pick;

while(pick <= 0 || pick >= 3){
    std::cout << "Invalid input. Please enter 1 for a random starting location or 2 to pick your own! ";
    std::cin >> pick;
    std::cout << std::endl;
}

/* Finding random coordinates for starting point */
if(pick == 1)
{
    xCoor = rand() % rows;
    yCoor = rand() % cols;
}

else if (pick == 2)
{
    std::cout << "Enter x and y separated by a space: ";
    std::cin >> xCoor >> yCoor;
    std::cout << std::endl;

while(xCoor > rows || xCoor <= 0 || yCoor > cols || yCoor <= 0){
    std::cout << "Please enter coordinates that are on the grid. ";
    std::cout << "\n Enter x and y separated by a space: ";
    std::cin >> xCoor >> yCoor;
    std::cout << std::endl;
}

}

/* This block of code prints out the ant in its beginning location
 * for the user to see, and then asks for how many steps the user
 * would like the ant to take */

antG[xCoor][yCoor] = '*';
grid.printArray(antG, rows, cols);
std::cout << std::endl;

std::cout << "Please enter how many steps the ant should take: ";
std::cin >> numSteps;

while(numSteps <= 0) {
    std::cout << "Please take at least one step! Try again: ";
    std::cin >> numSteps;
    std::cout << std::endl;
}

/* Here we preemptively change the starting coordinates to
 * be a black square and then call the object and function
 * to begin the game. */

antG[xCoor][yCoor] = '#';
game.playGame(antG, xCoor, yCoor, rows, cols, numSteps);

}
