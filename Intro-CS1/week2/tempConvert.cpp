/**************************************************************************
 ** Author: Erin Alltop
 ** Date: 1/12/16
 ** Description: A program that converts Celsius temperatures to Fahrenheit
***************************************************************************/

#include <iostream>
using namespace std;

int main ( )
{

	float celsius;
	float fahrenheit;

	//Ask user to enter a Celsius temperature
	cout << "Please enter a Celsius temperature. \n";
	cin >> celsius;

	//Calculate conversion from Celsius to Fahrenheit
	fahrenheit = static_cast<double>(9)/5 * celsius + 32;

	//Display fahrenheit temperature
	cout <<"The equivalent Fahrenheit temperature is: " << fahrenheit << endl;

}


