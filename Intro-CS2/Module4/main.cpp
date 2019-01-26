/*********************************************************************************
 ** Author: Erin Alltop
 ** Date: 5/31/16
 ** Description: This program was written to contain four different types of 
 ** functions and evaluate their performance speed. It contains a recursive
 ** and iterative Fibonacci function and a tail-recursive and non-tail-recursive
 ** factorial function. Code for the functions were borrowed from the assignment
 ** description (from the textbook) and from the JBossDeveloper website for
 ** educational code. 
 *********************************************************************************/
 
#include <iostream>
#include <time.h>

/**********************************************************************************
 ** Function: Fibonacci Recursive Function
 ** Description: This code was borrowed from JBossDeveloper. It is a simple
 ** Fibonnaci sequence using a recursive function.
 **********************************************************************************/

int fiboR(int n) 
{
	if (n <= 1) 
	{
		return n;
	}

	else {

		return fiboR(n - 1) + fiboR(n - 2);
	}
}

/**********************************************************************************
** Function: Fibonacci Non-Recursive Function
** Description: This code was borrowed from JBossDeveloper. It is a simple
** Fibonnaci sequence using an iterative function.
**********************************************************************************/

int fiboNR(int n) {
	if (n <= 1) {
		return n;
	}
	int fibo = 1;
	int fiboPrev = 1;
	for (int i = 2; i < n; ++i) {
		int temp = fibo;
		fibo += fiboPrev;
		fiboPrev = temp;

	}

	return fibo;
}

/***************************************************************************************
** Function: Factorial Non-Tail-Recursive Function
** Description: This code was borrowed from the textbook/lecture slides. It is a simple
** factorial function using a non-tail-recurive technique.
***************************************************************************************/

long rfactorial(int n) 
	{ 
		if (n == 1)           
			return 1;      
		else      
			return (n * rfactorial(n - 1));
	}

/***************************************************************************************
** Function: Factorial Tail-Recursive Function
** Description: This code was borrowed from the textbook/lecture slides. It is a simple
** factorial function using a tail-recurive technique.
***************************************************************************************/

long factorialHelper(int n, int result) 
{ 
	if (n == 1)           
		return result;      
	else      
		return factorialHelper(n - 1, n * result); 
}  

/***************************************************************************************
** Function: Factorial Helper Function
** Description: This code was borrowed from the textbook/lecture slides. It is a simple
** factorial helper function used in the tail-recursive function above.
***************************************************************************************/

long factorial(int n) 
{ 
	return factorialHelper(n, 1); 
}

/***************************************************************************************
** Function: Main Function
** Description: This function is used to execute the four different functions above.
** It also makes use of the clock() library to test the performance speed of each
** function. It measures the time it takes to complete each function in seconds and
** outputs the time to the user for testing purposes.
***************************************************************************************/

int main()
{
	clock_t start1, start2, end1, end2, start3, start4, end3, end4;
	

	long double duration;
	long double duration2;
	long double duration3;
	long double duration4;

	//get user input for testing
	int fibon;
	std::cout << "What number would you like to try? " << std::endl;
	std::cin >> fibon;

	//recursive function and time test
	start1 = clock();
	std::cout << fiboR(fibon) << std::endl;
	end1 = clock();
	duration = ((float)end1 - (float)start1) / CLOCKS_PER_SEC;
	std::cout << "Fibonacci Recursive duration: " << duration << std::endl;

	//non-recursive function and time test
	start2 = clock();
	std::cout << fiboNR(fibon) << std::endl;
	end2 = clock();
	duration2 = ((float)end2 - (float)start2) / CLOCKS_PER_SEC;
	std::cout << "Non-Recursive Fibonacci duration: " << duration2 << std::endl;

	//factorial non-tail-recursive function and time test
	start3 = clock();
	std::cout << rfactorial(fibon) << std::endl;
	end3 = clock();
	duration3 = ((float)end3 - (float)start3) / CLOCKS_PER_SEC;
	std::cout << "Non-Tail-Recursive Factorial duration: " << duration3 << std::endl;

	//factorial tail-recursive function and time test
	start4 = clock();
	std::cout << factorial(fibon) << std::endl;
	end4 = clock();
	duration4 = ((float)end4 - (float)start4) / CLOCKS_PER_SEC;
	std::cout << "Tail-Recursive Factorial duration: " << duration4 << std::endl;


//	system("pause");
}
