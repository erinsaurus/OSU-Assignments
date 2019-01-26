/**************************************************************************************************
** Author: Erin Alltop
** Date: 5/19/16
** Description: This program is a fantasy combat game. It allows the user to pick two teams of
** fighters to compete in a tournament. The two teams fight each other until one team has lost.
** The program gives several options for output as well.
** Input: User choices for number of fighters, types of fighters, and names of fighters.
** Output: Step-by-step battle stats until one team loses
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

	std::cout << "Please select from the menu below: \n" << std::endl;


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

	std::cout << std::endl;

}