/* CS261- Assignment 1 - Q.4*/
/* Name: Erin Alltop
 * Date: 1/20/17
 * Solution description: This program creates an array of n number of students, allocates
 * memory for n students, assigns random and unique IDs and random scores for each student,
 * Displays the unsorted array of IDs and scores, sorts the scores by ascending order (and
 * keeps their unique IDs), and then displays the array again now sorted.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

/*********************************************************************************************
** Function: void generate(struct student* students)
** Description: This fuction generates random and unique IDs and random IDs for students. It
** first creates a temporary array of unique numbers, then it uses a for loop to assign the
** unique numbers as random student IDs. It then assigns each student a random score.
** Parameters: pointer to student struct, n number of students declared and initialized
** Pre-Conditions: Student struct has been created, n number of students
** Post-Conditions: Unique and random IDs and random scores assigned to student struct.
*********************************************************************************************/

void generate(struct student* students, int n) {
	/*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/

	/*Create an array of unique IDs*/
	int uniqueArr[20];

	for (int i = 0; i < 20; i++) {
		uniqueArr[i] = i + 1;
	}

	/*Cycle through 10 times to find random positions for the unique IDs*/
	for (int i = 0; i < n; i++) {
		int j = i + rand() % (n - i);
		int tempNum = uniqueArr[i];
		uniqueArr[i] = uniqueArr[j];
		uniqueArr[j] = tempNum;

		/*Assign random position(ID) to student ID. Assign random score*/
		(students + i)->id = uniqueArr[i];
		(students + i)->score = rand() % 100 + 1;
	}
}

/*********************************************************************
** Function: void sort(struct student* students, int n)
** Description: This function sorts the give array of n students into
** ascending order of scores, and keeps the unique ID attached to them.
** Parameters: students struct, n number of students
** Pre-Conditions: struct has been created and initialized, with memory
** allocated for n students. n has been declared and initialized.
** Post-Conditions: struct is sorted in ascending order by scores,
** IDs remain attached to score and is unique and random.
*********************************************************************/

void sort(struct student* students, int n){

	/*Sort the n students based on their score*/
	/* Remember, each student must be matched with their original score after sorting */

	/* Loop through n times twice, comparing two subsequent
	* numbers in the array. If the first number is greater than
	* the second, then switch them to have the larger number
	* be the second number. Continue until all numbers have been
	* tested and sorted.*/

	for (int i = 0; i < n; i++) {

		for (int j = i + 1; j < n; j++) {

			if ((students + i)->score > (students + j)->score) {

				int switchScore = (students + i)->score;
				(students + i)->score = (students + j)->score;
				(students + j)->score = switchScore;

				int switchID = (students + i)->id;
				(students + i)->id = (students + j)->id;
				(students + j)->id = switchID;
			}
		}
	}
}

/*********************************************************************
** Function: int main()
** Description: This function, declares and initialzes an int variable n.
** It creates a struct and allocates memory for n students. It calls a
** helper function to generate random and unique IDs and random scores for
** each student. It prints the contents of the array, unsorted. Calls a
** sort function to sort the students by scores, and prints the sorted
** struct by ascending order of scores.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Prints struct of unsorted scores and sorted scores.
** Returns 0 when done.
*********************************************************************/

int main(){
	/*Declare an integer n and assign it a value.*/
	int n = 20;

	/*Allocate memory for n students using malloc.*/
	struct student *students = (struct student*) (malloc(sizeof(struct student) * n));

	/*Generate random and unique IDs and random scores for the n students, using rand().*/
	generate(students, n);

	/*Print the contents of the array of n students.*/
	printf("Unsorted Student Scores:\n");
	for (int i = 0; i < n; i++) {
		printf("ID: %d	 Score: %d\n", (students + i)->id, (students + i)->score);
	}
	printf("\n");

	/*Pass this array along with n to the sort() function*/
	sort(students, n);

	/*Print the contents of the array of n students.*/
	printf("Sorted Student Scores:\n");
	for (int i = 0; i < n; i++) {
		printf("ID: %d	 Score: %d\n", (students + i)->id, (students + i)->score);
	}

	return 0;
}
