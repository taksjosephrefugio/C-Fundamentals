#include<stdio.h>			// printf
#include<stdlib.h>			// malloc
#include<string.h>			// strlen
#define SIZE_OF_NAME 128

//TODO: Add user prompt for god sakes. It compiles and run but no one knows what to do.

typedef struct {
	char name[SIZE_OF_NAME];
	int number;
} Contact;

// FUNCTION PROTOTYPES
int get_greatest_strlen(Contact* contact, int LISTSIZE);
int print_header();

void main()
{
	int CONTACT_SIZE;
	printf("No. of contacts to add: ");
	scanf("%d", &CONTACT_SIZE);
	getchar();								// get rid of newline made by scanf

	Contact my_contact_list[CONTACT_SIZE];

	// Prompt user for info
	for(int i=0; i<CONTACT_SIZE; i++) {
		printf("Enter details for contact #%d\n", i+1);
		
		printf("    Name: ");
		fgets(my_contact_list[i].name, SIZE_OF_NAME, stdin);
		
		printf("    Phonenumber: ");
		scanf("%d", &my_contact_list[i].number);
		getchar();
		printf("\n");
	}

	// Find out greatest string length out of all the name of the entries
	int key_col_width = get_greatest_strlen(my_contact_list, CONTACT_SIZE) + 1;
	printf("Column width should be %d\n", key_col_width);
	printf("\n");
	printf("\n");
	
	// Print Results Header
	int header1_width = print_header();
	if (key_col_width < header1_width) {
		key_col_width = header1_width;
	}

	// Print key-value pairs
	for(int i=0; i<CONTACT_SIZE; i++) {
		for(int j=0; j<(strlen(my_contact_list[i].name) - 1); j++) {
			printf("%c", my_contact_list[i].name[j]);
		}

		if (strlen(my_contact_list[i].name) < key_col_width) {
			int numspaces = strlen(my_contact_list[i].name) - key_col_width;
			printf("%*c", numspaces, ' ');
		}
		
		printf(" | ");
		printf("%d", my_contact_list[i].number);
		printf("\n");
	}
}

int get_greatest_strlen(Contact* contact, int LISTSIZE) {
	int ret=4;

	for(int i=0; i<LISTSIZE; i++) {
		if (strlen(contact[i].name) > ret) { ret=strlen(contact[i].name); }
	}

	return ret;
}

int print_header() {
	char* header1 = malloc(128 * sizeof(char));
	char* header2 = malloc(128 * sizeof(char));
	strcpy(header1, "Name (Key)");
	strcpy(header2, "Phonenumber (Value)");
	header1 = realloc(header1, strlen(header1) * sizeof(char));
	header2 = realloc(header2, strlen(header2) * sizeof(char));

	printf("=============== RESULTS ===============\n");

	for(int i=0; i<strlen(header1); i++) {
		printf("%c", header1[i]);
	}

	printf(" | ");

	for(int i=0; i<strlen(header2); i++) {
		printf("%c", header2[i]);
	}

	printf("\n");

	int ret = strlen(header1) + 1;
	free(header1);
	free(header2);
	
	return ret;
}
