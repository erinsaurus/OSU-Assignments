/**************************************************************************************************
** Author: Erin Alltop
** Date: 5/6/16
** Description: This program is a fantasy combat game. It allows the user to pick two opponents
** to battle to the death. There are 5 different types of opponents that can battle each other or
** themselves. They each have different stats and abilities. Once one of them runs of out Strength
** Points then the game ends and the program terminates.
** Input: User choices for two opponents to battle
** Output: Step-by-step battle stats until one opponent loses
**************************************************************************************************/


#include <iostream>
#include <iomanip>
#include "menu.hpp"

/************************************************************************************************
 ** Function: menu
 ** Description: This function is used to display the menu to the user for the options of 
 ** opponents they can pick to battle each other. It displays the stats for each choice as well
 ** to give the user an idea of what they are picking.
 ** Output: displays menu only
 ************************************************************************************************/

void Menu::menu()
{

	std::cout << "This is a fantasy combat game. You can pick two opponents to fight ";
	std::cout << "\neach other to the death! Please select your two opponents below: \n" << std::endl;


	std::cout << std::left << std::setw(6) << " " << "Creature"
		<< std::left << std::setw(10) << " " << "Attack"
		<< std::left << std::setw(6) << " " << "Defense"
		<< std::left << std::setw(6) << " " << "Armor"
		<< std::left << std::setw(6) << " " << "Strength Points"
		<< std::left << std::setw(6) << " " << "Special Ability" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "1) Barbarian"
		<< std::left << std::setw(6) << " " << "2d6"
		<< std::left << std::setw(9) << " " << "2d6"
		<< std::left << std::setw(10) << " " << "0"
		<< std::left << std::setw(10) << " " << "12"
		<< std::left << std::setw(19) << " " << "None" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "2) Medusa"
		<< std::left << std::setw(9) << " " << "2d6"
		<< std::left << std::setw(9) << " " << "1d6"
		<< std::left << std::setw(10) << " " << "3"
		<< std::left << std::setw(10) << " " << "8"
		<< std::left << std::setw(20) << " " << "Glare" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "3) Baba Yaga"
		<< std::left << std::setw(6) << " " << "2d6"
		<< std::left << std::setw(9) << " " << "1d10"
		<< std::left << std::setw(9) << " " << "3"
		<< std::left << std::setw(10) << " " << "12"
		<< std::left << std::setw(19) << " " << "Soul" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "4) Blue Men"
		<< std::left << std::setw(7) << " " << "2d10"
		<< std::left << std::setw(8) << " " << "3d6"
		<< std::left << std::setw(10) << " " << "3"
		<< std::left << std::setw(10) << " " << "12"
		<< std::left << std::setw(19) << " " << "Mob" << std::endl;

	std::cout << std::left << std::setw(6) << " " << "5) Harry Potter"
		<< std::left << std::setw(3) << " " << "2d6"
		<< std::left << std::setw(9) << " " << "2d6"
		<< std::left << std::setw(10) << " " << "0"
		<< std::left << std::setw(10) << " " << "10/20"
		<< std::left << std::setw(16) << " " << "Hogwarts" << std::endl;


}