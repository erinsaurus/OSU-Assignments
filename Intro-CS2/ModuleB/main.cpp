/****************************************************************************
 ** Author: Erin Alltop
 ** Date: 4/6/16
 ** Description: This program takes user input for the size of the 2D array,
 ** number of critter objects, and number of steps the critters will take.
 ** Input: Row size, Column size, number of critters, number of steps
 ** Output: Critter movement in random directions until number of steps is
 ** reached. Critters do not overlap or fall off grid.
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
   srand(time(0));
    Grid squash; //Grid object
    int cols;
    int rows;
    int critters;
    int moves;

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

    //user input and validation for the number of critters
    std::cout << "How many critters would you like? ";
    std::cin >> critters;
    while(critters <= 0){
        std::cout << "Please enter at least one critter to play: ";
        std::cin >> critters;}
    while(critters >= (rows * cols)){
        std::cout << "Please enter a number of critter less than " << (rows * cols) << " to play: ";
        std::cin >> critters;
        {
            while(critters <= 0){
                std::cout << "Please enter at least one critter to play: ";
                std::cin >> critters;
                std::cout << std::endl;
            }
        }
    }

    //user input and validation for the number of steps to take
    std::cout << "How many steps would you like the critters to take? ";
    std::cin >> moves;
    while(moves <= 0){
        std::cout << "Please enter at least one step to take: ";
        std::cin >> moves;

    }

    //set user inputs
    squash.setRows(rows);
    squash.setCols(cols);
    squash.setNumCrit(critters);
    squash.setNumMoves(moves);

    //run game
    squash.updateLocation();

    return 0;
}
