/**************************************************************************
 ** Author: Erin Alltop
 ** Date: 1/27/16
 ** Description: A program that sorts three integers into ascending order
**************************************************************************/

#include <iostream>
using namespace std;

//prototype
void smallSort(int&, int&, int&);

int main()
{

	int a = 14;
	int b = -90;
	int c = 2;

	//call function
	smallSort(a, b, c);

	//Display numbers in ascending order
	cout << a << ", " << b << ", " << c << endl;

}

void smallSort(int &a, int &b, int &c)
{

	if (a > b)
	{  int temp = a;
		a = b;
		b = temp;
	}
	if (a > c)
	{ int temp = a;
		a = c;
		c = temp;
	}
	if (b > c)
	{ int temp = b;
		b = c;
		c = temp;
	}
}

