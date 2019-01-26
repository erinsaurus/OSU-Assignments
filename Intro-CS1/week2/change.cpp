/************************************************************************************
 ** Author: Erin Alltop
 ** Date: 1/12/16
 ** Description: A program that outputs how many of each type of coin represents a number of cents
	with fewest total number of coins.
************************************************************************************/

#include <iostream>
using namespace std;

int main ( )
{

	int cents;
	int quarter = 25;
	int dime = 10;
	int nickel = 5;
	int penny = 1;

	//Ask user to enter amount in cents less than a dollar.
	cout << "Please enter an amount in cents less than a dollar. \n";
	cin >> cents;

	//Determine how many of each type of coin represent number of cents with 
	//fewest total number of coins.
	double totalQuarter = (cents / quarter);
	cents %= quarter;
	double totalDime = (cents / dime);
	cents %= dime;
	double totalNickel = (cents / nickel);
	cents %= nickel;
	double totalPenny = (cents / penny);
	cents %= penny;

	//Display number of coins
	cout <<"Your change will be: \n";
	cout << "Q: " << totalQuarter;
	cout << "\nD: " << totalDime;
	cout << "\nN: " << totalNickel;
	cout << "\nP: " << totalPenny; endl;

}

