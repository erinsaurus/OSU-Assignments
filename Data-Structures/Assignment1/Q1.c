/* CS261- Assignment 1 - Q.1*/
/* Name: Erin Alltop
 * Date: 1/20/17
 * Solution description: This program creates a struct for students with IDs and scores. It 
 * creates random and unique IDs for students and random scores to be assigned to the struct.
 * It prints the unsorted IDs and scores of all the students, as well as the minimum score,
 * maximum score, and average score of the ten students. Afterwards, it frees the memory
 * allocated to students.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

/*********************************************************************************************
** Function: struct student * allocate()
** Description: This function allocates memory to the struct and then returns a pointer of it.
** Parameters: None
** Pre-Conditions: struct has been created
** Post-Conditions: Pointer to struct has been created, memory with proper size has been 
** allocated, and pointer has been returned.
*********************************************************************************************/

struct student* allocate(){
     /*Allocate memory for ten students*/
	struct student *studentPtr = (struct student *) malloc(10 * sizeof(struct student));
     

     /*return the pointer*/
	return studentPtr;
}

/*********************************************************************************************
** Function: void generate(struct student* students)
** Description: This fuction generates random and unique IDs and random IDs for students. It 
** first creates a temporary array of unique numbers, then it uses a for loop to assign the 
** unique numbers as random student IDs. It then assigns each student a random score.
** Parameters: pointer to student struct
** Pre-Conditions: Student struct has been created 
** Post-Conditions: Unique and random IDs and random scores assigned to student struct.  
*********************************************************************************************/

void generate(struct student* students){
/*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/

	/*Create an array of unique IDs*/
	int uniqueArr[10]; 

	for (int i = 0; i < 10; i++) {
		uniqueArr[i] = i + 1;
	}

	/*Cycle through 10 times to find random positions for the unique IDs*/
	for (int i = 0; i < 10; i++) {
		int j = i + rand() % (10 - i);
		int tempNum = uniqueArr[i];
		uniqueArr[i] = uniqueArr[j];
		uniqueArr[j] = tempNum;

		/*Assign random position(ID) to student ID. Assign random score*/
		(students + i)->id = uniqueArr[i];
		(students + i)->score = rand() % 100 + 1;
	}
}

/*********************************************************************************************
** Function: void output(struct student* students)
** Description: This function prints the IDs and Scores of the 10 students in the struct.
** Parameters: Pointer to the students struct
** Pre-Conditions: The students struct must have been filled with unique and random IDs and 
** random scores.
** Post-Conditions: Print IDs and Scores. Returns nothing.
*********************************************************************************************/

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/

	for (int i = 0; i < 10; i++) {
		printf("ID: %d	Score: %d\n", (students + i)->id, (students + i)->score);
	}

}

/*********************************************************************************************
** Function: void summary(struct student* students)
** Description: This function tests each student score to see whether it is the current minimum
** and/or maximum score. It adds the score to the total score and when the loops completes for
** all 10 students, it calculates the average score. It then displays the min, max, and avg scores.
** Parameters: Pointer to the students struct
** Pre-Conditions: The struct is complete with unique and random IDs and random scores for each
** of the 10 students
** Post-Conditions: Function displays the min, max, and average scores.
*********************************************************************************************/

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/

	/*Declare and initialize variable. min is set to 100 and max is set to 0*/
	int currMin = 100;  
	int currMax = 0;    
	int total = 0;
	float avg = 0.00;

	/*Loop through the 10 students. If the student score is higher than the
	 * cuurMin then it becomes the new currMin. If it is lover than the currMax
	 * then it becomes the new currMax. It adds to student score to the total */
	for (int i = 0; i < 10; i++) {
		if (currMin > (students + i)->score) {    
			currMin = (students + i)->score;
		}
		if (currMax < (students + i)->score) {   
			currMax = (students + i)->score;
		}

		total += (students + i)->score;     
	}

	avg = total / 10.00;                      

	/* Print the max score, min score, and average score*/
	printf("Maximum Score: %d\n", currMax);
	printf("Minimum Score: %d\n", currMin);
	printf("Average Score: %.2f\n", avg);   
     
}

/*********************************************************************************************
** Function: void deallocate(struct student* stud)
** Description: This functions deallocates memory for the struct
** Parameters: Pointer to the student struct
** Pre-Conditions: None
** Post-Conditions: Memory has been freed for the struct
*********************************************************************************************/

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/

	if (stud != NULL) {
		free(stud);
		stud = 0;
	}
}

/*********************************************************************************************
** Function: int main()
** Description: This function creates a pointer to the student struct and initializes it to 0.
** It then calls functions allocate, generate, output, summary, and deallocate for use with the
** struct it created.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************************************/

int main(){

	
    struct student* stud = NULL;


	/*call allocate*/
	stud = allocate(stud);

	/*call generate*/
	generate(stud);

	/*call output*/
	output(stud);

	/*call summary*/
	summary(stud);

	/*call deallocate*/
	deallocate(stud);


	return 0;
}
