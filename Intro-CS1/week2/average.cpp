/******************************************************************************************
 ** Author: Erin Alltop
 ** Date: 1/12/16
 ** Description: A program that takes five user-inputted numbers and prints out the average.
*******************************************************************************************/

#include <iostream>
using namespace std;

int main ( )
{

	double NumberA,
	NumberB,
	NumberC,
	NumberD,
	NumberE;
	double average;

	//Ask user to enter five numbers
	cout << "Please enter five numbers. \n";
	cout << " ";
	cin >> NumberA;
	cout << " ";
	cin >> NumberB;
	cout << " ";
	cin >> NumberC;
	cout << " ";
	cin >> NumberD;
	cout << " ";
	cin >> NumberE;

	//Calculate average of five numbers
	average = (NumberA + NumberB + NumberC + NumberD + NumberE) / 5 ;

	//Display average
	cout <<"The average of those numbers is: \n" << average << endl;

}
