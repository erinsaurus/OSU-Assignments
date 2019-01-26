/*********************************************************************
 ** Author: Erin Alltop
 ** Date: 1/27/16
 ** Description: A function that runs a hailstone sequence and returns 
	how many steps it takes to reach one
*********************************************************************/

#include <iostream>
using namespace std;

//prototype
int hailstone(int num);

int main()
{
	//variable
	int num;

	//get integer
	cout << "Enter a positive integer: " << endl;
	cin >> num;

	//display number of steps
	cout << "Number of steps to 1 is: " << hailstone(num) << endl;

}

int hailstone(int num)
{

	if (num == 1)
	{
		return 0;
	}

	if (num%2 == 0)
	{
		num = num/2;
	}

	else
	{
		num = num*3 + 1;
	}

	return 1 + hailstone(num);

}


