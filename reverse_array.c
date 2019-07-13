/*
This takes a user input array of integers and outputs 
the same array but the elements are in reverse.

Code written by: TAK'S JOSEPH REFUGIO
Code written on: Summer 2017
Code written for: For myself. Just practicing
*/
#include <stdio.h>
#define MAX_ARRAY_SIZE 1000
int myArray[MAX_ARRAY_SIZE];
int usersize = 0;

// Prompts the user for the number of items inside the array
void promptUser(int*num) {
	scanf("%d", num);
}

// Takes in userinput and populates the array 
void populateArray(int*anArray, int size) {
	for (int i = 0; i < size; i++) { scanf("%d", &anArray[i]); }
}

// Prints the array in the right order
void printArray (int*anArray, int size) {
	for (int j = 0; j < size; j++) { printf("%d", anArray[j]); }
}

// Prints the array in reverse order
void printArrayReverse (int*anArray, int size) {
	for (int ctr = size-1; ctr >= 0; ctr--) { printf("%d ", anArray[ctr]); }
}

// MAIN FUNCTION
int main(void)
{
	promptUser(&usersize);
	populateArray(myArray, usersize);
	printArrayReverse(myArray, usersize);
	return 0;
}