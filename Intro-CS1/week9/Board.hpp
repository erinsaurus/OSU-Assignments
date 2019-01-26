/******************************************************************************
 ** Author: Erin Alltop
 ** Date: 2/29/16
 ** Description: A game of TicTacToe for two players. This program takes the
 ** player's move and prints out the board after each turn. When the game
 ** ends in a win or a draw the game prints out a statement to inform user.
 *****************************************************************************/

#ifndef Board_hpp
#define Board_hpp
#include <iostream>

// Enumerated variables and array size are both constant
enum State {X_WON, O_WON, DRAW, UNFINISHED};
const int NUM_ROWS = 3;
const int NUM_COLUMNS = 3;


class Board
{
private:

public:
    
    //default constructor
    Board();
    //function prototypes
    bool makeMove(int rowIn, int columnIn, char playerTurn);
    char displayBoard[NUM_ROWS][NUM_COLUMNS];
    void print();
    State gameState();
    
};


#endif
