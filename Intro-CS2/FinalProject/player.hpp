/**************************************************************************************************
** Name: Erin Alltop
** Date: 6/1/16
** Description: Final Project. This program is a text based game. The play is in a street market
** and has to collect certain ingredients on her shopping list. Points can be earned by buying
** or earning rare ingredients, performing small tasks, winning short games, and other
** various ways for bonus points. The final score is displayed at the end.
** This program makes use of polymorphism and containers. The player has a shopping bag that is
** a stack, and each shop is a derived class of the "space" class.
***************************************************************************************************/

#ifndef player_hpp
#define player_hpp
#include <string>
#include "menu.hpp"
#include "inventory.hpp"
#include <cstdlib>

class Player
{
private:
	double Wallet;
	char Recipe;
	int puzzlePieces = 0;
	int Bonus = 0;
	int Score = 0;

	std::string Location;
	std::string bagContents[15]; //string array for the bag contents for display purposes only

	//stack struct
	struct ShoppingBag
	{
		Inventory* item;
		ShoppingBag* next;
		ShoppingBag(Inventory* type, ShoppingBag* next1 = NULL)
		{
			item = type;
			next = next1;
		}
	};

	ShoppingBag* top;

	int Time;
	int bagCount = 0;


public:
	void removeMoney(double cost);
	Player() {}
	Player(char choice);
	~Player() {}
	void setWallet(double money);
	double getWallet();
	void setRecipe(char choice);
	char getRecipe();
	void shoppingList();
	void add(Inventory* value);
	Inventory* remove();
	void displayStack();
	bool isEmpty() const;
	void setTime(int time);
	int getTime();
	void adjustTime();
	bool gameOver();
	int getBagCount();
	void incBagCount();
	void displayBagContents();
	void changeBagContents(std::string newItem);
	void puzzlePiece();
	int getPuzzlePieces();
	void incBonus(int inc);
	int getBonus();
	void finalScore();
	int getFinalScore();
	void setScore(int points);
	void endGame();
};


#endif
