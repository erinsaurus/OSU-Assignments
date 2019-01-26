/******************************************************************************
 ** Author: Erin Alltop
 ** Date: 2/29/16
 ** Description: A game of TicTacToe for two players. This program takes the
 ** player's move and prints out the board after each turn. When the game
 ** ends in a win or a draw the game prints out a statement to inform user.
 *****************************************************************************/
#ifndef TicTacToe_hpp
#define TicTacToe_hpp
#include "Board.hpp"
#include <iostream>

using namespace std;


class TicTacToe
{
private:
    char player;
public:
    //constructor with parameter that specifies whether 'x' or 'o' should have the first move
    TicTacToe(char firstMove);
    // function prototype for play method
    void play();

};


#endif