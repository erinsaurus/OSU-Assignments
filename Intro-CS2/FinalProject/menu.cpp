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

#include <iostream>
#include <iomanip>
#include "menu.hpp"

/************************************************************************************************
** Function: recipeOptions
** Description: This function is used to display the menu to the user for the options of
** recipes they can make. it displays the ingredients for each recipe and their cost.
** Output: displays menu only
************************************************************************************************/

void Menu::recipeOptions()
{

	std::cout << "\nWhat recipe have you decided to make for your party?\n" << std::endl;

	std::cout << "Option A: \n" << std::endl;
	std::cout << std::left << std::setw(1) << " " << "Chicken Parmesan, Salad, and Breadsticks\n\n"
		<< std::left << std::setw(6) << " " << "Ingredients"
		<< std::left << std::setw(11) << " " << "Price" << std::endl;


	std::cout << std::left << std::setw(6) << " " << "1) Chicken "
		<< std::left << std::setw(11) << " " << "$5.00" << std::endl;
	
	std::cout << std::left << std::setw(6) << " " << "2) Lettuce"
		<< std::left << std::setw(12) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "3) Tomato"
		<< std::left << std::setw(13) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "4) Carrot"
		<< std::left << std::setw(13) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "5) Salad Dressing"
		<< std::left << std::setw(5) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "6) Parmesan Cheese"
		<< std::left << std::setw(4) << " " << "$3.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "7) Breadsticks"
		<< std::left << std::setw(8) << " " << "$4.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "8) Spice Packet"
		<< std::left << std::setw(7) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "9) Bonus: Wine"
		<< std::left << std::setw(8) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "10) Bonus: Chocolate"
		<< std::left << std::setw(2) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "Total Cost"
		<< std::left << std::setw(12) << " " << "$35.00" << std::endl;

	//Option B

	std::cout << "\nOption B: \n" << std::endl;
	std::cout << std::left << std::setw(1) << " " << "Filet Mignon, Roasted Veggies, and Dinner Rolls\n\n"
		<< std::left << std::setw(6) << " " << "Ingredients"
		<< std::left << std::setw(11) << " " << "Price" << std::endl;


	std::cout << std::left << std::setw(6) << " " << "1) Filet Mignon "
		<< std::left << std::setw(6) << " " << "$10.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "2) Spice Packet"
		<< std::left << std::setw(7) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "3) Carrot"
		<< std::left << std::setw(13) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "4) Potato"
		<< std::left << std::setw(13) << " " << "$1.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "5) Zucchini"
		<< std::left << std::setw(11) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "6) Garlic"
		<< std::left << std::setw(13) << " " << "$1.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "7) Goat Cheese"
		<< std::left << std::setw(8) << " " << "$3.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "8) Dinner Rolls"
		<< std::left << std::setw(7) << " " << "$4.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "9) Bonus: Wine"
		<< std::left << std::setw(8) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "10) Bonus: Chocolate"
		<< std::left << std::setw(2) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "Total Cost"
		<< std::left << std::setw(12) << " " << "$35.00" << std::endl;

	//Option C

	std::cout << "\nOption C: \n" << std::endl;
	std::cout << std::left << std::setw(1) << " " << "Ham and Pineapple Pizza\n\n"
		<< std::left << std::setw(6) << " " << "Ingredients"
		<< std::left << std::setw(11) << " " << "Price" << std::endl;


	std::cout << std::left << std::setw(6) << " " << "1) Ham"
		<< std::left << std::setw(16) << " " << "$6.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "2) Pineapple"
		<< std::left << std::setw(10) << " " << "$4.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "3) Tomato"
		<< std::left << std::setw(13) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "4) Garlic"
		<< std::left << std::setw(13) << " " << "$1.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "5) Pizza Dough"
		<< std::left << std::setw(8) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "6) Spice Packet"
		<< std::left << std::setw(7) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "7) Mozzarella Cheese"
		<< std::left << std::setw(2) << " " << "$3.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "8) Spinach"
		<< std::left << std::setw(12) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "9) Bonus: Wine"
		<< std::left << std::setw(8) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "10) Bonus: Chocolate"
		<< std::left << std::setw(2) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "Total Cost"
		<< std::left << std::setw(12) << " " << "$35.00" << std::endl;
		std::cout << std::endl;


}

/************************************************************************************************
** Function: displayListA
** Description: This function is used to display the recipe of the first recipe.
** It lists the ingredients and cost of the items as well as the total cost.
** It is called for reference by the user during the game.
************************************************************************************************/

void Menu::displayListA()
{
	std::cout << std::endl;
	std::cout << std::left << std::setw(1) << " " << "Chicken Parmesan, Salad, and Breadsticks\n\n"
		<< std::left << std::setw(6) << " " << "Ingredients"
		<< std::left << std::setw(11) << " " << "Price" << std::endl;


	std::cout << std::left << std::setw(6) << " " << "1) Chicken "
		<< std::left << std::setw(11) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "2) Lettuce"
		<< std::left << std::setw(12) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "3) Tomato"
		<< std::left << std::setw(13) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "4) Carrot"
		<< std::left << std::setw(13) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "5) Salad Dressing"
		<< std::left << std::setw(5) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "6) Parmesan Cheese"
		<< std::left << std::setw(4) << " " << "$3.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "7) Breadsticks"
		<< std::left << std::setw(8) << " " << "$4.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "8) Spice Packet"
		<< std::left << std::setw(7) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "9) Bonus: Wine"
		<< std::left << std::setw(8) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "10) Bonus: Chocolate"
		<< std::left << std::setw(2) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "Total Cost"
		<< std::left << std::setw(12) << " " << "$35.00" << std::endl;
	std::cout << std::endl;
}

/************************************************************************************************
** Function: displayListB
** Description: This function is used to display the recipe of the second recipe.
** It lists the ingredients and cost of the items as well as the total cost.
** It is called for reference by the user during the game.
************************************************************************************************/

void Menu::displayListB()
{
	std::cout << std::endl;

	std::cout << std::left << std::setw(1) << " " << "Filet Mignon, Roasted Veggies, and Dinner Rolls\n\n"
		<< std::left << std::setw(6) << " " << "Ingredients"
		<< std::left << std::setw(11) << " " << "Price" << std::endl;


	std::cout << std::left << std::setw(6) << " " << "1) Filet Mignon "
		<< std::left << std::setw(6) << " " << "$10.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "2) Spice Packet"
		<< std::left << std::setw(7) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "3) Carrot"
		<< std::left << std::setw(13) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "4) Potato"
		<< std::left << std::setw(13) << " " << "$1.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "5) Zucchini"
		<< std::left << std::setw(11) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "6) Garlic"
		<< std::left << std::setw(13) << " " << "$1.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "7) Goat Cheese"
		<< std::left << std::setw(8) << " " << "$3.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "8) Dinner Rolls"
		<< std::left << std::setw(7) << " " << "$4.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "9) Bonus: Wine"
		<< std::left << std::setw(8) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "10) Bonus: Chocolate"
		<< std::left << std::setw(2) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "Total Cost"
		<< std::left << std::setw(12) << " " << "$35.00" << std::endl;

	std::cout << std::endl;

}

/************************************************************************************************
** Function: displayListC
** Description: This function is used to display the recipe of the third recipe.
** It lists the ingredients and cost of the items as well as the total cost.
** It is called for reference by the user during the game.
************************************************************************************************/

void Menu::displayListC()
{
	std::cout << std::endl;

	std::cout << std::left << std::setw(1) << " " << "Ham and Pineapple Pizza\n\n"
		<< std::left << std::setw(6) << " " << "Ingredients"
		<< std::left << std::setw(11) << " " << "Price" << std::endl;


	std::cout << std::left << std::setw(6) << " " << "1) Ham"
		<< std::left << std::setw(16) << " " << "$6.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "2) Pineapple"
		<< std::left << std::setw(10) << " " << "$4.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "3) Tomato"
		<< std::left << std::setw(13) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "4) Garlic"
		<< std::left << std::setw(13) << " " << "$1.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "5) Pizza Dough"
		<< std::left << std::setw(8) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "6) Spice Packet"
		<< std::left << std::setw(7) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "7) Mozzarella Cheese"
		<< std::left << std::setw(2) << " " << "$3.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "8) Spinach"
		<< std::left << std::setw(12) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "9) Bonus: Wine"
		<< std::left << std::setw(8) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "10) Bonus: Chocolate"
		<< std::left << std::setw(2) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "Total Cost"
		<< std::left << std::setw(12) << " " << "$35.00" << std::endl;

	std::cout << std::endl;
}

/************************************************************************************************
** Function: displayProduce
** Description: This function displays the stock of the specific stall. It displays what the 
** stall carries and what the cost of the items are. The user uses this menu to select
** what item they will buy next.
************************************************************************************************/

void Menu::displayProduce()
{
	std::cout << std::left << std::setw(13) << " " << "Produce Stall\n\n"
		<< std::left << std::setw(6) << " " << "Stock"
		<< std::left << std::setw(17) << " " << "Price" << std::endl;


	std::cout << std::left << std::setw(6) << " " << "A) Carrot"
		<< std::left << std::setw(13) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "B) Lettuce"
		<< std::left << std::setw(12) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "C) Salad Dressing"
		<< std::left << std::setw(5) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "D) Potato"
		<< std::left << std::setw(13) << " " << "$1.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "E) Zucchini"
		<< std::left << std::setw(11) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "F) Garlic"
		<< std::left << std::setw(13) << " " << "$1.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "G) Pineapple"
		<< std::left << std::setw(10) << " " << "$4.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "H) Asparagus"
		<< std::left << std::setw(10) << " " << "$3.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "I) Spinach"
		<< std::left << std::setw(12) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "J) Tomato"
		<< std::left << std::setw(13) << " " << "$1.00" << std::endl;

	std::cout << std::endl;
}

/************************************************************************************************
** Function: displayButcher
** Description: This function displays the stock of the specific stall. It displays what the
** stall carries and what the cost of the items are. The user uses this menu to select
** what item they will buy next.
************************************************************************************************/

void Menu::displayButcher()
{
	std::cout << std::endl;
	std::cout << std::left << std::setw(13) << " " << "Butcher Stall\n\n"
		<< std::left << std::setw(6) << " " << "Stock"
		<< std::left << std::setw(17) << " " << "Price" << std::endl;


	std::cout << std::left << std::setw(6) << " " << "A) Chicken"
		<< std::left << std::setw(12) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "B) Salmon"
		<< std::left << std::setw(13) << " " << "$6.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "C) Rib Eye"
		<< std::left << std::setw(11) << " " << "$10.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "D) Turkey"
		<< std::left << std::setw(13) << " " << "$7.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "E) Veal"
		<< std::left << std::setw(14) << " " << "$20.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "F) Filet Mignon"
		<< std::left << std::setw(6) << " " << "$10.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "G) Pepperoni"
		<< std::left << std::setw(10) << " " << "$4.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "H) Ham"
		<< std::left << std::setw(16) << " " << "$6.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "I) Bison"
		<< std::left << std::setw(13) << " " << "$15.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "J) Shrimp"
		<< std::left << std::setw(13) << " " << "$5.00" << std::endl;

	std::cout << std::endl;
}

/************************************************************************************************
** Function: displayChocolate
** Description: This function displays the stock of the specific stall. It displays what the
** stall carries and what the cost of the items are. The user uses this menu to select
** what item they will buy next.
************************************************************************************************/

void Menu::displayChocolate()
{
	std::cout << std::endl;
	std::cout << std::left << std::setw(13) << " " << "Chocolate Stall\n\n"
		<< std::left << std::setw(6) << " " << "Stock"
		<< std::left << std::setw(17) << " " << "Price" << std::endl;


	std::cout << std::left << std::setw(6) << " " << "A) Milk"
		<< std::left << std::setw(15) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "B) Dark"
		<< std::left << std::setw(15) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "C) White"
		<< std::left << std::setw(14) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "D) Bittersweet"
		<< std::left << std::setw(8) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "E) Baking"
		<< std::left << std::setw(13) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "F) Chocolate Oil"
		<< std::left << std::setw(6) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "G) Unsweetened"
		<< std::left << std::setw(8) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "H) Chocolate Liqeur"
		<< std::left << std::setw(3) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "I) Cacao"
		<< std::left << std::setw(14) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "J) Ground"
		<< std::left << std::setw(13) << " " << "$5.00" << std::endl;

	std::cout << std::endl;
}

/************************************************************************************************
** Function: displayWine
** Description: This function displays the stock of the specific stall. It displays what the
** stall carries and what the cost of the items are. The user uses this menu to select
** what item they will buy next.
************************************************************************************************/

void Menu::displayWine()
{
	std::cout << std::endl;
	std::cout << std::left << std::setw(16) << " " << "Wine Stall\n\n"
		<< std::left << std::setw(6) << " " << "Stock"
		<< std::left << std::setw(17) << " " << "Price" << std::endl;


	std::cout << std::left << std::setw(6) << " " << "A) Bordeaux"
		<< std::left << std::setw(11) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "B) Merlot"
		<< std::left << std::setw(13) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "C) Pinot Noir"
		<< std::left << std::setw(9) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "D) Pinot Grigio"
		<< std::left << std::setw(7) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "E) Chardonnay"
		<< std::left << std::setw(9) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "F) Champagne"
		<< std::left << std::setw(10) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "G) Prosecco"
		<< std::left << std::setw(11) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "H) Port"
		<< std::left << std::setw(15) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "I) Marsala"
		<< std::left << std::setw(12) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "J) Cava"
		<< std::left << std::setw(15) << " " << "$5.00" << std::endl;

	std::cout << std::endl;
}

/************************************************************************************************
** Function: displayCheese
** Description: This function displays the stock of the specific stall. It displays what the
** stall carries and what the cost of the items are. The user uses this menu to select
** what item they will buy next.
************************************************************************************************/

void Menu::displayCheese()
{
	std::cout << std::endl;
	std::cout << std::left << std::setw(13) << " " << "Cheese Stall\n\n"
		<< std::left << std::setw(6) << " " << "Stock"
		<< std::left << std::setw(17) << " " << "Price" << std::endl;


	std::cout << std::left << std::setw(6) << " " << "A) Cheddar"
		<< std::left << std::setw(12) << " " << "$3.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "B) Colby Jack"
		<< std::left << std::setw(9) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "C) Mozzarella"
		<< std::left << std::setw(9) << " " << "$3.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "D) American"
		<< std::left << std::setw(11) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "E) Goat"
		<< std::left << std::setw(15) << " " << "$3.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "F) Bleu"
		<< std::left << std::setw(15) << " " << "$4.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "G) Parmesan"
		<< std::left << std::setw(11) << " " << "$3.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "H) Feta"
		<< std::left << std::setw(15) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "I) Meunster"
		<< std::left << std::setw(11) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "J) Pepper Jack"
		<< std::left << std::setw(8) << " " << "$4.00" << std::endl;

	std::cout << std::endl;
}

/************************************************************************************************
** Function: displaySpices
** Description: This function displays the stock of the specific stall. It displays what the
** stall carries and what the cost of the items are. The user uses this menu to select
** what item they will buy next.
************************************************************************************************/

void Menu::displaySpices()
{
	std::cout << std::endl;
	std::cout << std::left << std::setw(13) << " " << "Spices Stall\n\n"
		<< std::left << std::setw(6) << " " << "Stock"
		<< std::left << std::setw(17) << " " << "Price" << std::endl;


	std::cout << std::left << std::setw(6) << " " << "A) Pepper"
		<< std::left << std::setw(13) << " " << "$3.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "B) Salt"
		<< std::left << std::setw(15) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "C) Rosemary"
		<< std::left << std::setw(11) << " " << "$3.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "D) Cayenne"
		<< std::left << std::setw(12) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "E) Parsley"
		<< std::left << std::setw(12) << " " << "$3.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "F) Cumin"
		<< std::left << std::setw(14) << " " << "$4.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "G) Cinnamon"
		<< std::left << std::setw(11) << " " << "$3.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "H) Nutmeg"
		<< std::left << std::setw(13) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "I) Paprika"
		<< std::left << std::setw(12) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "J) Spice Pack"
		<< std::left << std::setw(9) << " " << "$2.00" << std::endl;

	std::cout << std::endl;
}

/************************************************************************************************
** Function: displayBakery
** Description: This function displays the stock of the specific stall. It displays what the
** stall carries and what the cost of the items are. The user uses this menu to select
** what item they will buy next.
************************************************************************************************/

void Menu::displayBakery()
{
	std::cout << std::left << std::setw(13) << " " << "Bakery Stall\n\n"
		<< std::left << std::setw(6) << " " << "Stock"
		<< std::left << std::setw(17) << " " << "Price" << std::endl;


	std::cout << std::left << std::setw(6) << " " << "A) White"
		<< std::left << std::setw(14) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "B) French Bread"
		<< std::left << std::setw(7) << " " << "$2.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "C) Breadsticks"
		<< std::left << std::setw(8) << " " << "$4.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "D) Hotdog Buns"
		<< std::left << std::setw(8) << " " << "$1.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "E) Dinner Rolls"
		<< std::left << std::setw(7) << " " << "$4.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "F) Pizza Dough"
		<< std::left << std::setw(8) << " " << "$5.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "G) Wheat"
		<< std::left << std::setw(14) << " " << "$4.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "H) Multigrain"
		<< std::left << std::setw(9) << " " << "$3.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "I) Garlic Bread"
		<< std::left << std::setw(7) << " " << "$1.00" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "J) Pastry"
		<< std::left << std::setw(13) << " " << "$1.00" << std::endl;

	std::cout << std::endl;
}