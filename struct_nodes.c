/*This program has two function
(1) Function 1 shall:
// (1) Print out the number of nodes on the given reference list
// (2) Print out the negative values from the list
// (3) calculate, print and return the product of the EVEN values of the list

(2) Function 2 shall:
// This function will:
// (1) determine  and prin the lenght of the c-string
// (2) print out the lower case letters of the c-string
// (3) returns the number of words containing the letter 'E'

Program Name: In Lab Final
System: Microsoft Visual Studio Community 2015, Windows 10
@author: TAK'S JOSEPH REFUGIO
@version: April 26, 2017
*/
// STRUCTURE DEFINITIONS
typedef struct Node {
	int data;
	int next;
}Node;

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// FUNCTION PROTOTYPES
int function1(Node*);
int function2(Node*);

int main()
{
	Node* myList = NULL;
	
	// TEST CASE FOR FUNCTION #1
	Node* node1;
	node1 = (Node*)malloc(sizeof(Node));
	node1->data = 1;
	node1->next = NULL;

	Node* node2;
	node2 = (Node*)malloc(sizeof(Node));
	node2->data = 1;
	node2->next = node1;

	myList = node2;

	// TEST CASE FOR FUNCTION #2
	char *userString;
	userString = (char*)malloc(sizeof(char) * 500);
	strcpy(userString, "Programming in C");
	
	
	// Function1 doesn't work for some reason
	// Although compiler can compile
	int function1_answer = function1(myList);
	printf("Product of the even values is: %d\n", function1_answer);

	int numLetter = function2(userString);
	printf("E occurs %d times in the string.\n", numLetter);	

	return 0;
}
// This function will:
// (1) determine  and prin the lenght of the c-string
// (2) print out the lower case letters of the c-string
// (3) returns the number of words containing the letter 'E'
int function2(char*userString)
{
	int returnValue = 0;
	// Initializing user string variable
	char *finalUserString;
	finalUserString = (char*)malloc(sizeof(char));

	// Only getting thee first word (i.e. before any white space) of the string
	int ctr = 0;
	while (((userString[ctr] != ' ') && (userString[ctr] != '\0')) && (userString[ctr] != '\n'))
	{
		finalUserString = (char*)realloc(finalUserString, sizeof(char*)*(ctr + 1));
		finalUserString[ctr] = userString[ctr];


		// Printing the lower case letters
		if (islower(finalUserString[ctr]))
		{
			printf("%c", finalUserString[ctr]);
		}
		printf("\n");

		// Determinining which ones are the letter 'E'
		if (finalUserString[ctr] == 'e' || finalUserString[ctr] == 'E')
			returnValue++;

		// Printing the finalized  user string (without white space)
		//printf("%c", finalUserString[ctr]);
		ctr++;
	}
	//printf("\n");

	// Printing the length of the c-string
	printf("The length of the c-string is: %d\n", ctr);

	return returnValue;
}

// This function will:
// (1) Print out the number of nodes on the given reference list
// (2) Print out the negative values from the list
// (3) calculate, print and return the product of the EVEN values of the list
int function1(Node*thisList)
{
	// Initializing function variables
	int returnValue = 1;		// this is the return value
	int tempEvenNumber = 0;		// this keeps track of the even numbers
	int num_Nodes = 0;			// this keeps track of how many nodes are in the list

	while (thisList != NULL)
	{
		// Increments the number of nodes
		num_Nodes++;

		// Determines which integers are negative and prints them
		if (thisList->data < 0)
		{
			printf("Negative values are: ");
			printf("%d ", thisList->data);
		}

		// Determines which integers are even and calculates
		if (thisList->data % 2 == 0)
		{
			tempEvenNumber = thisList->data;
			returnValue = returnValue * tempEvenNumber;
		}
		thisList = thisList->next;
	}
	printf("\n");

	// Prints the number of nodes in the list
	printf("The number of nodes in the list is: %d\n", num_Nodes);

	// If there are no even numbers (that's what it means by returnValue == 1, then the returnValue is set to zero. 
	if (returnValue == 1)
	{
		returnValue = 0;
	}

	return returnValue;
}
