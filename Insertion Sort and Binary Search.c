// Daniel Hanson

#include <stdio.h>
#include <stdlib.h>

int* load_array(char* file, int* length);
void insertion_sort(int array[], int length);
int binary_search(int array[], int low, int high, int key);
int fib(int n);
int range(int array[], int length, int low, int high);

int main(int argc, char** argv) {
	// Initializing the variables
	int length, i = 0;
	int input, result = 0;
	int low, high = 0;
	int* array;

	// Error checking for the file name
	FILE* filePtr = fopen(argv[1], "r");
	if(filePtr == NULL) {
		printf("You entered an invalid file name!\n");
		return 0;
	}

	// Loads the data into the array
	array = load_array(argv[1], &length);

	// Insertion sorts the array
	insertion_sort(array, length);

	// Replace the old number with the fibonacci number
	for(i = 0; i < length; i++) {
		array[i] = fib(array[i]);
	}

	// Prints out the array
	for(i = 0; i < length; i++) {
		printf("%d\n", *(array + i));
	}

	// Prompts the user to enter a number to search for
	printf("Enter a number to search for: \n");
	scanf("%d", &input);

	result = binary_search(array, 0, length - 1, input);

	// Prints out an error if the number input is not in the array
	if(result == -1) {
		printf("The number you entered is not in the array!");
	} else {
		printf("%d was found at index %d\n", input, result);
	}

	// BONUS
	printf("Bonus: Enter a range to search for\n");
	scanf("%d %d", &low, &high);
	printf("There are %d numbers between %d and %d inclusively\n", range(array, length, low, high), low, high);

	// Frees the allocated memory
	free(array);

	return 0;
}

int* load_array(char* file, int* length) {
	// Initializing the variables
	int i = 0;
	int* array;

	// Creating the file pointer
	FILE* filePtr = fopen(file, "r");
	
	// Gets the length of the input file 
	fscanf(filePtr, "%d", length);

	// Dynamically allocates memory for the array and loads the data into the array
	array = malloc(*length * sizeof(int));
	for(i = 0; i < *length; i++) {
		fscanf(filePtr, "%d", (array + i));
	}

	return array;
}

void insertion_sort(int array[], int length) {
	// Initializing the variables
	int i, j = 0;
	int num, temp = 0;

	// Insertion sorts the array
	for(i = 1; i < length; i++) {
		j = i;

		while(j > 0 && array[j] < array[j - 1]) {
			temp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = temp;

			j--;
		}
	}
}

int binary_search(int array[], int low, int high, int key) {
	// Initalizing the variables
	int half = 0;

	// Return zero if the key is not found
	if(low > high) {
		return -1;
	}

	half = (low + high)/2;

	// Return if the key is found
	if(array[half] == key) {
		return half;
	} else if(array[half] > key) {
		binary_search(array, low, half - 1, key);
	} else if(array[half] < key) {
		binary_search(array, half + 1, high, key);
	}
}

int fib(int n) {
	// Calculates the fibonacci number for the given integer
	if(n <= 0) {
		return 0;
	} else if(n == 1) {
		return 1;
	} else {
		return fib(n - 1) + fib(n - 2);
	}
}

int range(int array[], int length, int low, int high) {
	// Initializing the variables
	int count = 0;
	int lowindex, highindex = 0;

	lowindex = binary_search(array, 0, length, low);
	highindex = binary_search(array, 0, length, high);

	// Counts how many elements are between the two locations
	while(lowindex <= highindex) {
		lowindex++;
		count++;
	}

	return count;
}
