/*********************************************************************
 ** Author: Erin Alltop
 ** Date: 1/27/16
 ** Description: A program that takes time in seconds and returns the
    distance the object has fallen in that time.
*********************************************************************/

#include <iostream>
using namespace std;

double fallDistance(double time);

int main()
{
	double time;
	double fallDis;

	//get time for testing
	cout << "Enter time: ";
	cin >> time;

	//call function and pass value
	fallDistance(time);

	//output for testing
	fallDis = fallDistance(time);
	cout << "The distance the object fell is: " << fallDis << endl;
}

double fallDistance(double time)
{

	double distance;
	distance = 0.5 * 9.8 * (time * time);

	return distance;
}

