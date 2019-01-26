/****************************************************************************
** Author: Erin Alltop
** Date: 3/29/16
** Description: This program takes user input for the size of a 2D array
** and also for the beginning location of a critter. The critter then takes
** steps in random directions until it goes off the grid, in which case
** it is squashed.
*****************************************************************************/


#include <iostream>
#include <cstdlib>
#include <ctime>
#include "grid.hpp"
#include "critter.hpp"


int main()
{
    //random number seed
    srand((unsigned int)time(NULL));

    Grid squash; //Grid object
    int cols;
    int rows;

    //user input and input validation for number of rows
    std::cout << "Please enter the number of rows: ";
    std::cin >> rows;
    while(rows <= 0){
        std::cout << "Please enter a number greater than 0: ";
        std::cin >> rows;
    }

    //user input and input validation for number of columns
    std::cout << "Please enter the number of columns: ";
    std::cin >> cols;
    while(cols <= 0){
        std::cout << "Please enter a number greater than 0: ";
        std::cin >> cols;
    }

    //set user input as rows and columns
    squash.setRows(rows);
    squash.setCols(cols);

    //run game
    squash.updateLocation();


return 0;


}
