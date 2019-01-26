/******************************************************************************
 ** Author: Erin Alltop
 ** Date: 2/29/16
 ** Description: A game of TicTacToe for two players. This program takes the
 ** player's move and prints out the board after each turn. When the game
 ** ends in a win or a draw the game prints out a statement to inform user.
 *****************************************************************************/

#include "Board.hpp"
#include <iostream>


using namespace std;

//intialize array to empty
Board::Board()
{
    
    for (int row = 0; row < NUM_ROWS; row++)
        for (int col = 0; col < NUM_COLUMNS; col++)
            displayBoard[row][col] = '.';
}

//makeMove function that adds the x or o to the board via user input
bool Board::makeMove(int rowIn, int columnIn, char currentPlayer)
{
    if(displayBoard[rowIn][columnIn] == '.')
    {
        displayBoard[rowIn][columnIn] = currentPlayer;
        return true;
    }
    else
        return false;
}

//function to print board
    void Board::print()
    {
    cout << "  0 1 2 \n";
        for(int row = 0; row < NUM_ROWS; row++)
        { cout << row << " ";
            for (int col = 0; col < NUM_COLUMNS; col++)
        
    {
        cout << displayBoard[row][col] << " ";
    }
       // cout << row;
        cout << endl;
    }
}


// Inefficient brute force method to determine win, draw, and unfinished because I had trouble
// getting loops to work properly

State Board::gameState()
{
    State currentState = UNFINISHED;
              
              
    if(displayBoard[0][0]=='x' && displayBoard[0][1]=='x' && displayBoard[0][2]=='x') //top across x
                  currentState = X_WON;
    else if(displayBoard[1][0]=='x' && displayBoard[1][1]=='x' && displayBoard[1][2]=='x') //middle across x
                  currentState = X_WON;
    else if(displayBoard[2][0]=='x' && displayBoard[2][1]=='x' && displayBoard[2][2]=='x') //bottom across x
                  currentState = X_WON;
    else if(displayBoard[0][0]=='x' && displayBoard[1][0]=='x' && displayBoard[2][0]=='x') // left column x
                  currentState = X_WON;
    else if(displayBoard[0][1]=='x' && displayBoard[1][1]=='x' && displayBoard[2][1]=='x') //middle column x
                  currentState = X_WON;
    else if(displayBoard[0][2]=='x' && displayBoard[1][2]=='x' && displayBoard[2][2]=='x') // right column x
                  currentState = X_WON;
    else if(displayBoard[0][0]=='x' && displayBoard[1][1]=='x' && displayBoard[2][2]=='x') // diagonal 1 x
                  currentState = X_WON;
    else if(displayBoard[2][0]=='x' && displayBoard[1][1]=='x' && displayBoard[0][2]=='x') //diagonal 2 x
                  currentState = X_WON;
    else if(displayBoard[0][0]=='o' && displayBoard[0][1]=='o' && displayBoard[0][2]=='o') //top across o
                  currentState = O_WON;
    else if(displayBoard[1][0]=='o' && displayBoard[1][1]=='o' && displayBoard[1][2]=='o') //middle across o
                  currentState = O_WON;
    else if(displayBoard[2][0]=='o' && displayBoard[2][1]=='o' && displayBoard[2][2]=='o') //bottom across o
                  currentState = O_WON;
    else if(displayBoard[0][0]=='o' && displayBoard[1][0]=='o' && displayBoard[2][0]=='o') // left column o
                  currentState = O_WON;
    else if(displayBoard[0][1]=='o' && displayBoard[1][1]=='o' && displayBoard[2][1]=='o') //middle column o
                  currentState = O_WON;
    else if(displayBoard[0][2]=='o' && displayBoard[1][2]=='o' && displayBoard[2][2]=='o') // right column o
                  currentState = O_WON;
    else if(displayBoard[0][0]=='o' && displayBoard[1][1]=='o' && displayBoard[2][2]=='o') // diagonal 1 o
                  currentState = O_WON;
    else if(displayBoard[2][0]=='o' && displayBoard[1][1]=='o' && displayBoard[0][2]=='o') //diagonal 2 o
                  currentState = O_WON;
             
    if(currentState !=X_WON && currentState != O_WON)
        if(displayBoard[0][0] == 'x' || displayBoard[0][0] == 'o')
            if(displayBoard[0][1] == 'x' || displayBoard[0][1]=='o')
                if(displayBoard[0][2] == 'x' || displayBoard[0][2]=='o')
                    if(displayBoard[1][0]=='x' || displayBoard[1][0]=='o')
                        if(displayBoard[1][1]=='x' || displayBoard[1][1]=='o')
                            if(displayBoard[1][2]=='x' || displayBoard[1][2]=='o')
                                if(displayBoard[2][0]=='x' || displayBoard[2][0]=='o')
                                    if(displayBoard[2][1]=='x'||displayBoard[2][1]=='o')
                                        if(displayBoard[2][2]=='x' || displayBoard[2][2]=='o')
                                            currentState = DRAW;
                  
              
return currentState;
                  
          }


   
    
