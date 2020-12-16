#include<stdio.h>
#include<stdlib.h>

// Function Prototypes
void pointer_to_an_int();
void pointer_to_an_array();
void passing_pointer_as_an_argument();
void pointer_to_another_pointer();


int main()
{
	pointer_to_an_int();
	pointer_to_an_array();

	int *foo;
	int bar = 42;
	foo = &bar;
	// Notice that we only need to pass the value stored in the pointer 
	// (which is an address to somewhere, in this case to just a regular integer)
	passing_pointer_as_an_argument(foo);

	pointer_to_another_pointer();

	return 0;
}


void pointer_to_an_int() {
	// Declaring a pointer to an integer
	int sample_int = 2;
	int *ptr;

	// Store the address of sample_int to the memory space allocated for ptr
	ptr = &sample_int;

	// Print what is stored in ptr. It should be equal to address of sample_int
	printf("What is stored in ptr:          0x%x\n", ptr);
	printf("What is memaddr of sample_int:  0x%x\n", &sample_int);
	printf("\n");
}


void pointer_to_an_array() {
	int SIZE = 5;
	int sample_array[5] = {3, 5, 8, 11, 19};
	int *ptr;

	// store first address of first index in memory space allocated for ptr
	ptr = &sample_array;

	// ptr behaving as though it is sample_array
	// this is useful for calling memory address in external drives
	for(int i=0; i<SIZE; i++) {
		if (i==0) { 
			printf("[ %d, ", ptr[i]);
		}
		else if (i == SIZE - 1) {
			printf("%d ]\n", ptr[i]);
		}
		else {
			printf("%d, ", ptr[i]);
		}
	}

	printf("\n");
}


void passing_pointer_as_an_argument(int *ptr) {
	printf("Pointer Value:    %d\n", *ptr);
	printf("Pointer Address:  0x%x\n", ptr);
	printf("\n");
}


void pointer_to_another_pointer() {
	#include<string.h>

	int *ptr1;
	int **ptr2;
	int sample_int = 4;

	ptr1 = &sample_int;		// ptr1 points to address of sample_int
	ptr2 = &ptr1;			// ptr2 copies value stored in ptr1 (which is an address to somewhere)

	if (*(*ptr2) == sample_int && *ptr2 == ptr1) {
		printf("True: Ptr2 is a pointer to another pointer (ptr1).\n");
	}
	else {
		printf("False: Ptr2 is not a pointer to another pointer (ptr1).\n");
	}

	printf("\n");
}
