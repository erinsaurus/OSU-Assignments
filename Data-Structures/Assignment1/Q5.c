/* CS261- Assignment 1 - Q.5*/
/* Name: Erin Alltop
 * Date: 1/20/17
 * Solution description: This program takes in a single word from the
 * user, converts it to sticky caps, and prints the new word.
 */
 
#define _CRT_SECURE_NO_WARNINGS	
#include <stdio.h>
#include <stdlib.h>


 /*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch) {
	return ch - 'a' + 'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch) {
	return ch - 'A' + 'a';
}

/*********************************************************************
** Function:
** Description: While the characters in the word do not equal /0 (the
** end of the word), cycle through each character and check to see if it
** upper or lower case. If any of the letters are uppercase, convert to 
** lowercase. Then, go through every other letter and conver it to
** uppercase, creating the sticky keys.
** Parameters: pointer to array of characters
** Pre-Conditions: array of characters created
** Post-Conditions: word converted to sticky caps
*********************************************************************/

void sticky(char* word) {
	/*Convert to sticky caps*/
	
	for (int i = 0; word[i] != '\0'; i++) {
		if (word[i] >= 'a' && word[i] <= 'b') {
			word[i] = toUpperCase(word[i]);
		}
	}
	for (int i = 1; word[i] != '\0'; i = i + 2) {
		word[i] = toLowerCase(word[i]);
	}
}

/*********************************************************************
** Function: int main()
** Description: This functions takes user input for a single word,
** calls the sticky function to convert it to sticky caps, and prints
** the new word
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Takes in word, prints new word. returns 0
*********************************************************************/

int main() {
	/*Read word from the keyboard using scanf*/
	char str[50];
	printf("Please enter a single word to appear with sticky caps: \n");
	scanf("%s", str);

	/*Call sticky*/
	sticky(str);

	/*Print the new word*/
	printf("Word with sticky caps: %s\n", str);
	return 0;
}