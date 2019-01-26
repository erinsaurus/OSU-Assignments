/******************************************************************************
 ** Author: Erin Alltop
 ** Date: 2/29/16
 ** Description: A game of TicTacToe for two players. This program takes the 
 ** player's move and prints out the board after each turn. When the game
 ** ends in a win or a draw the game prints out a statement to inform user.
 *****************************************************************************/

#include "TicTacToe.hpp"
#include "Board.hpp"
#include <iostream>

using namespace std;


int main()
{
    char currentPlayer;
    TicTacToe goFirst(currentPlayer);
    goFirst.play();
    
}

TicTacToe::TicTacToe(char currentPlayer)
{
    currentPlayer=player;
}


void TicTacToe::play()
{
    char player;
    int rowIn;
    int columnIn;
    char currentPlayer;
    
    //find out who goes first
    cout << "This is the game of TicTacToe!" << endl;
     cout << "Which player should go first? " << endl;
     cout << "Please enter x or o: ";
     cin >> player;
     currentPlayer = player;
    
    // create Board object
    Board game;
    
    cout << "\nLet's play!\n" << endl;
    do
    {
        //print empty board and ask player what they would like to play
        game.print();
        cout << "\nPlayer " << player << ": please make your move: ";
        cin >> rowIn >> columnIn;
        
        //field to keep track of what player's turn it is
        currentPlayer = player;
        if (player == 'x')
            player = 'o';
        else if (player == 'o')
            player = 'x';
        cout << "\nIt's your turn player " << player << "!" << endl;
        cout << endl;
        
        //input validation for when spot is already taken
        while(!game.makeMove(rowIn, columnIn, currentPlayer))
        {
            cout << "\nThat spot is taken!\n" << endl;
            game.print();
            cout << "\nPlayer " << player << ": please make your move: ";
            cin >> rowIn >> columnIn;
            cout << endl;
        }
        
        game.makeMove(rowIn, columnIn, currentPlayer);
        
        
        
        // while game is unfinished with no win or draw, continue looping
    }while(game.gameState() == UNFINISHED);
    
    // call gameState function to test for win or draw after each move
    if(game.gameState() == X_WON)
    {
        cout << "CONGRATULATIONS X YOU WON!! YOU'RE AWESOME!!\n" << endl;
    }
    if(game.gameState() == O_WON)
    {
        cout << "CONGRATULATIONS O YOU WON!! YOU'RE THE BEST!!\n" << endl;
    }
    if(game.gameState() == DRAW)
    {
        cout << "IT'S A DRAW!! YA'LL ARE BOTH PRETTY OK!\n" << endl;
    }
    
    game.makeMove(rowIn, columnIn, currentPlayer);
    game.print();
    
}

