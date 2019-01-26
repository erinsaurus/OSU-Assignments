/* CS261- Assignment 1 - Q.3*/
/* Name: Erin Alltop
 * Date: 1/20/17
 * Solution description: This program creates an array of 20 random numbers. It then prints
 * the numbers unsorted. After sorting the numbers in ascending order, it prints them
 * again in the main function.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

 /*********************************************************************
 ** Function: void sort(int* number, int n)
 ** Description: This function sorts the given array in ascending order.
 ** It tests every two numbers that are next to each other and switches
 ** them if the previous is larger than the second number. 
 ** Parameters: pointer to number array, int size of array
 ** Pre-Conditions: Size of array declared and array created.
 ** Post-Conditions: Array is sorted in ascending order. Returns nothing.
 *********************************************************************/

void sort(int* number, int n){ 

	 /*Sort the given array number , of length n*/


	/* Loop through n times twice, comparing two subsequent
	 * numbers in the array. If the first number is greater than
	 * the second, then switch them to have the larger number
	 * be the second number. Continue until all numbers have been
	 * tested and sorted.*/

	for (int i = 0; i < n; i++) {

		for (int j = i + 1; j < n; j++) {

			if (number[i] > number[j]) {

				int switchNum = number[i];
				number[i] = number[j];
				number[j] = switchNum;
			}
		}
	}
}

/*********************************************************************
** Function: int main()
** Description: This function declares and int n and sets it to 20.
** It allocates an array for int n size, fills the array with random
** numbers, prints the array as is, calls a sort function to sort in
** ascending order, and prints the array a second time.
** Parameters:None
** Pre-Conditions: None
** Post-Conditions: Array is printed unsorted and then sorted. Returns 0.
*********************************************************************/

int main(){
	/*Declare an integer n and assign it a value of 20.*/
	int n = 20;

	/*Allocate memory for an array of n integers using malloc.*/
	int *nIntArray = (int *)malloc(sizeof(int) * n);

	/*Fill this array with random numbers, using rand().*/

	/* Generate random numbers */
	for (int i = 0; i < n; i++) {
		*(nIntArray + i) = rand() % 50;
	}

	/*Print the contents of the array.*/
	printf("Unsorted Array\n");
	for (int i = 0; i < n; i++) {
		printf("%d\n", *(nIntArray + i));
	}

	/*Pass this array along with n to the sort() function of part a.*/
	sort(nIntArray, n);

	/*Print the contents of the array.*/
	printf("\nSorted Array\n");
	for (int i = 0; i < n; i++) {
		printf("%d\n", *(nIntArray + i));
	}


	return 0;
}
