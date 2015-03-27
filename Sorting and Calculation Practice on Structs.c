// Daniel Hanson
// Lab 2
// djhybf

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point {
	int x;
	int y;
};

struct point* read_file(char* file_name, int size);
double distance(struct point first, struct point second);
struct point* sort(struct point* array, int size);
void print_points(struct point* array, int size);
struct point intersection(struct point p1, struct point p2, struct point p3, struct point p4);

int main(int argc, char** argv){
	// Initializing the variables
	int size = 0;
	size = atoi(*(argv + 1));
	struct point intersect;

	// Reads the file and returns a pointer to the array with the data points
	struct point* array = NULL; 
	array =	read_file(*(argv + 2), size);

	// Sorts the array
	sort(array, size);

	// Prints out the array of structs
	print_points(array, size);

	// Prints out the bonus
	printf("Bonus\n");
	intersect = intersection(*(array + 0), *(array + 1), *(array + 2), *(array + 3));
	printf("(%d, %d)\n", intersect.x, intersect.y);
	
	// Frees the dynamically allocated memory
	free(array);
	
	return 0;
}

struct point* read_file(char* file_name, int size){
	// Initializing the variables
	int i = 0;

	// Creating the file pointer
	FILE* filePtr = fopen(file_name, "r");

	// Dynamically allocating space for the array
	struct point* array = malloc(size * sizeof(struct point));

	// Iterating through the file and putting the data in the array
	for(i = 0; i < size; i++) {
		fscanf(filePtr, "%d %d", &(array + i)->x, &(array + i)->y);
	}

	// Closes the file
	fclose(filePtr);

	return array;
}

double distance(struct point first, struct point second) {
	// Initializing the variables
	double distance = 0;

	// Calculates the distance
		distance = sqrt(pow((first.x - second.x), 2) + pow((first.y - second.y), 2));

	// Returns the answer
	return distance;
}

struct point* sort(struct point* array, int size) {
	// Initializing the variables
	int i, j = 0;
	struct point temp;
	struct point origin;
	origin.x = 0;
	origin.y = 0;

	// Bubble sorting the array of structures
	for(i = 0; i < size; i++) {
		for(j = 0; j < size - 1; j++) {
			if(distance(*(array + j), origin) > distance(*(array + j + 1), origin)) {
				temp = *(array + j);
				*(array + j) = *(array + j + 1);
				*(array + j + 1) = temp;
			}
		}
	}

	// Returns the sorted array
	return array;
}

void print_points(struct point* array, int size) {
	// Initializing the variables
	int i = 0;

	// Prints out the points in the array
	for(i = 0; i < size; i++) {
		printf("(%d, %d)\n", (array + i)->x, (array + i)->y);
	}
}

struct point intersection(struct point p1, struct point p2, struct point p3, struct point p4) {
	// Initializing the variables
	struct point intersection;

	// Calculates the intersection point
	intersection.x = (((p1.x * p2.y) - (p1.y * p2.x)) * (p3.x - p4.x)) - ((p1.x - p2.x) * (p3.x * p4.y - p3.y * p4.x))/
		(((p1.x - p2.x) * (p3.y - p4.y)) - ((p1.y - p2.y) * (p3.x - p4.x)));

	intersection.y = (((p1.x * p2.y) - (p1.y * p2.x)) * (p3.y - p4.y)) - ((p1.y - p2.y) * (p3.x * p4.y - p3.y * p4.x))/
		(((p1.x - p2.x) * (p3.y - p4.y)) - ((p1.y - p2.y) * (p3.x - p4.x)));

	// Returns the intersection
	return intersection;
}
