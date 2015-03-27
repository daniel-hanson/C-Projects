// Daniel Hanson

#include <stdio.h>
#include <stdlib.h>

int* readFile(char* inputFile);
int findMin(int* array);
int findMax(int* array);
int findAvg(int* array);
int findMedian(int* array); // BONUS
void writeOut(char* outFile, int min, int max, int avg, int median);

int main(int argc, char** argv) {
	// Initializing the variables
	int minimum, maximum = 0;
	int average, median = 0;

	// Reads the file, returns an integer pointer pointing to the ten numbers
	int* numArray = readFile(*(argv + 1));

	// Returns the minimum value in the array
	minimum = findMin(numArray);

	// Returns the maximum value in the array
	maximum = findMax(numArray);

	// Returns the average value in the array
	average = findAvg(numArray);

	// Returns the median value in the array
	median = findMedian(numArray);

	// Writes the calculated numbers to an output file
	writeOut(*(argv + 2), minimum, maximum, average, median);

	// Frees the dynamically allocated memory for the pointer
	free(numArray);
	return 0;
}

// Reads the file and returns an integer pointer with the data
int* readFile(char* inputFile) {
	// Initialzing the variables
	int i = 0;

	// Opens the file
	FILE *filePtr = fopen(inputFile, "r");

	// Dynamically allocates the array memory
	int* array = malloc(10 * sizeof(int));

	// Scans in the numbers from the text file and then closes the file
	if(filePtr == NULL) {
		fclose(filePtr);
		return 0;
	} else {
		for(i = 0; i < 10; i++) {
			fscanf(filePtr, "%d", (array + i));
		}
		fclose(filePtr);
	}

	// Returns the integer pointer with the data
	return array;
}

// Finds and returns the minimum value
int findMin(int* array) {
	// Initializing the variables
	int minimum, iter = 0;
	int i = 0;

	// Sets the initial minimum
	minimum = *(array + 0);

	// Iterates through the array and determines the minimum
	for(i = 1; i < 10; i++) {
		iter = *(array + i);

		if(iter < minimum) {
			minimum = iter;
		}
	}

	// Returns the minimum of the array
	return minimum;
}

// Finds and returns the maximum value
int findMax(int* array) {
	// Initializing the variables
	int maximum, iter = 0;
	int i = 0;

	// Sets the initial maximum
	maximum = *(array + 0);

	// Iterates through the array and determines the maximum
	for(i = 1; i < 10; i++) {
		iter = *(array + i);
		
		if(iter > maximum) {
			maximum = iter;
		}
	}

	// Returns the maximum of the array
	return maximum;
}

// Finds and returns the average of the array
int findAvg(int* array) {
	// Initializing the variables
	int average, total = 0;
	int i = 0;

	// Iterates through the array and keeps a total
	for(i = 0; i < 10; i++) {
		total = total + *(array + i);
	}

	// Calculates the average
	average = total/10;

	// Returns the average of the array
	return average;
}

/* BONUS
 * Finds and returns the median of the array */
int findMedian(int* array) {
	// Initializing the variables
	int i, median = 0;
	int middleLeft, middleRight = 0;

	// Bubble sort the array
	for(i = 0; i < 10; i++) {
		if(*(array + i - 1) > *(array + i)) {
			*(array + i - 1) = *(array + i);
		}
	}

	// Gets the middle two numbers to calculate the median
	middleLeft = *(array + 4);
	middleRight = *(array + 5);

	// Calculates the median
	median = (middleLeft + middleRight)/2;

	// Returns the median
	return median;
}

// Writes the calculated numbers to an output file
void writeOut(char* outFile, int min, int max, int avg, int median) {

	// Opens the file
	FILE *filePtr = fopen(outFile, "w");

	// Prints the data to the file
	fprintf(filePtr, "Minimum: %d\n", min);
	fprintf(filePtr, "Maximum: %d\n", max);
	fprintf(filePtr, "Average: %d\n", avg);
	fprintf(filePtr, "Median: %d\n", median);

	// Closes the file
	fclose(filePtr);
}
