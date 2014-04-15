// Daniel Hanson

#define MAX 100
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int check_error(int);
void initialize_2Darray(int x[][MAX], int size);
void print_2Darray(int x[][MAX], int size);
int check_index(int index, int size);
int find_rowmax(int x[][MAX], int r, int size);
float calculate_rowaverage(int x[][MAX], int r, int size);
int find_colmin(int x[][MAX], int c, int size);
void sort_2Darray(int x[][MAX], int size);

int main(){
	srand(time(NULL));
	// Initialization of the variables
	int size, checksize = 0;
	int index, checkindex = 0;
	int large, minimum, i = 0;
	float average = 0;
	int twod[MAX][MAX];

	// Prompts the user to enter the size of the array
	printf("Enter the size of the 2D array: ");
	scanf("%d", &size);
	checksize = check_error(size);
	while(checksize==0){
		printf("Invalid input enter the size of the array again: ");
		scanf("%d", &size);
		checksize = check_error(size);
	}
	
	// Initialization of the array
	initialize_2Darray(twod, size);

	// Printing out the array
	printf("\n2D arrays\n");
	print_2Darray(twod, size);

	// Prompts the user to enter the index
	printf("\nEnter the row: ");
	scanf("%d", &index);
	checkindex = check_index(index, size);
	while(checkindex==0){
		printf("Invalid row index enter the row again: ");
		scanf("%d", &index);
		checkindex = check_index(index, size);
	}

	// Finds the largest number in the selected row
	large = find_rowmax(twod, index, size);
	printf("\nThe largest number present in the row %d is %d", index, large);

	// Finds the average of the numbers in the selected row
	average = calculate_rowaverage(twod, index, size);
	printf("\n\nThe average of numbers present in the row %d is %.2f", index, average);
	
	// Prints out the minimum of each column
	for(i=0;i<size;i++){
		minimum = find_colmin(twod, i, size);
		printf("\nMinimum number present in column %d is %d", i, minimum);
	}

	// Bonus Part
	printf("\n\nBonus part\n");
	printf("Array before sorting\n");
	printf_2Darray(twod, size);
	printf("\n\nArray after sorting");
	sort_2Darray(twod, size);
	printf_2Darray(twod, size);

	return 0;
}

int check_error(int size){
	if(size>0&&size<=100){
		return 1;
	}else{
		return 0;
	}
}

void initialize_2Darray(int x[][MAX], int size){
	int i,j = 0;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			x[i][j] = rand()%10;
		}
	}	
}

void print_2Darray(int y[][MAX], int size){
	int i,j = 0;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			printf("%d ", y[i][j]);
		}
		printf("\n");
	}
}

int check_index(int index, int size){
	if(index>=0&&index<size){
		return 1;
	}else{
		return 0;
	}
}

int find_rowmax(int x[][MAX], int r, int size){
	int i,large = 0;
	for(i=0;i<size;i++){
		if(x[r][i]>large){
			large = x[r][i];
		}
	}
	return large;
}

float calculate_rowaverage(int x[][MAX], int r, int size){
	int i = 0;
	int sum = 0;
	float average = 0;
	for(i=0;i<size;i++){
		sum = sum + x[r][i];
	}
	average = (float) sum/size;
	return average;
}

int find_colmin(int x[][MAX], int c, int size){
	int i = 0;
	int small = 9;
	for(i=0;i<size;i++){
		if(x[i][c]<small){
			small = x[i][c];
		}
	}
	return small;
}

void sort_2Darray(int x[][MAX], int size){
	return 0;
}
