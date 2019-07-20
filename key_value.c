#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct KEY_VALUE_PAIR {
	char* name;
	int phoneNumber;
} KEY_VALUE_PAIR;


//Takes a string pointer from main and this function will prompt the user to type a string
//and it will return the string pointer with said user input string
char* getUserString() {
	char*teststring = malloc(sizeof(char));
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
	return teststring;
}


int getPhoneNumber() {
	int dumloc = 0;
	scanf("%d", &dumloc);
	return dumloc;
}


int getNumOfAccounts() {
	int dumloc = 0;
	scanf("%d", &dumloc);
	return dumloc;
}

int main()
{
	int SIZE = getNumOfAccounts();

	KEY_VALUE_PAIR account[SIZE];

	for (int i=0; i<SIZE; i++) {
		account[i].name = getUserString();
		account[i].phoneNumber = getPhoneNumber();
	}

	// TO-DO: Print contents of account[SIZE] to make sure no loss of data
	return 0;
}
