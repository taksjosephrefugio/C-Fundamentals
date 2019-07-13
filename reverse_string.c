/*
This program takes a user input string and outputs it in reverse order. 
Furthermore, Dynamic Memory Allocation for storage of the user string is implemented. 

Compilation:	Successful
Version: 		Working
Code Written by: TAK'S JOSEPH REFUGIO
Code Written for: Synapse Product Development Interview Challenge
Code Written on: January 2019
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Takes a string pointer from main and this function will prompt the user to type a string
//and it will populate the string pointer with said user input string
void getUserString (char*teststring) {
	int strlen = 0;
	char userchar;												//For storing char to be tested
	while ((userchar != ' ' && userchar != '\n') && userchar != '\t') 
	{
		scanf("%c", &userchar);											//Prompting user to input a char
		strlen++;													// Increase length of string by one corresponding to user inputting a char
		teststring = realloc(teststring, sizeof(char) * strlen);	// increasing size of teststring by one

		//append the new char to the end of teststring
		if ((userchar != ' ' && userchar != '\n') && userchar != '\t') {
			teststring[strlen-1] = userchar;
		}
		//if the user input is a SPACE,TAB, or NEWLINE then add a terminator at the end of teststring
		else if ((userchar != ' ' || userchar != '\n') || userchar != '\t') {
			teststring[strlen-1] = '\0';
		}
		else {
			printf("Logic Error. Please check if-else statement.\n");	//Error-Message when logic fails
		}	
	}
}

//Replaces the string with the reverse order of its characters
void string_reverse1(char *string) {
	//Getting string length
	int strlen = 0;
	while (string[strlen] != '\0') { strlen++; }
	
	//For storing the reverse version of the string
	char *tempstring = malloc(sizeof(char)*strlen);
	int index_ctr = strlen - 1;						//to be used in getting string characters
	int i = 0; 
	while (i < strlen) { tempstring[i++] = string[index_ctr--]; }
	
	printf("%s\n", tempstring);
	strcpy(string,tempstring);		//copy what's in tempstring into string
	printf("%s\n", string);
}

//Also replaces the string with the reversed order but as a return value
char *string_reverse2(const char *string) {
	int strlen = 0;
	while(string[strlen] != '\0') { strlen++; }

	char*tempstring = malloc(sizeof(char)*strlen);
	int i=0;
	int j=strlen - 1;
	while (i < strlen) {tempstring[i++] = string[j--]; }

    return tempstring;
}
//////////////////////
/////// MAIN ////////
////////////////////
int main()
{
	char *userstring = malloc(sizeof(char));				//Allocating memory - initially to just 1 char - for the user's string
	
	getUserString(userstring);								//Prompting user for a string
	string_reverse1(userstring);							//Reversing the order of the user string
	printf("Result1: %s\n", userstring);

	getUserString(userstring);								//Prompting user for a string
	userstring = string_reverse2(userstring);
	printf("Result2: %s\n", userstring);
	
	free(userstring);										//Freeing allocated space for userstring
    return 0;
}