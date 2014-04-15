// Daniel Hanson

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int check_input(int size);
void initialiaze_array(int size);
int max(int size);
int min(int size);
float average(int size);
void compute_stats(int size);
int search(int size, int search);
void print_array(int size);
int count_numbers(int size, int number);
void sort(int size);

int array[100];

int main(){
	srand(time(NULL));
	// Initialzing the variables
	int size,sizecheck,index,number = 0;

	printf("Enter the size of the input: ");
	scanf("%d", &size);

	// Checks the size input
	sizecheck = check_input(size);
	while(sizecheck==0){
		printf("Invalid input enter the size of the input again: ");
		scanf("%d", &size);
		sizecheck = check_input(size);
	}

	// Initializing the array
	initialiaze_array(size);

	// Prints out the array
	printf("\nInput array\n");
	print_array(size);

	// Prints out the stats
	compute_stats(size);

	printf("\n\nEnter the number you want to search: ");
	scanf("%d", &number);
	index = search(size, number);
	if(index==(-1)){
		printf("\nThe number %d is not present in the array\n", number);
	}else{
		printf("\nThe number %d is present at the index %d\n", number, index);
	}

	printf("\nBonus part\n");
	printf("Array before sorting\n");
	print_array(size);
	printf("\nArray after sorting\n");
	print_array(size);
	printf("\n");

	return 0;
}

int check_input(int size){
	if(size<=0||size>100){
		return 0;
	}else{
		return 1;
	}
}

void initialiaze_array(int size){
	int i = 0;
	for(i=0;i<size;i++){
		array[i] = (rand()%10);
	}
}

int max(int size){
	int i = 0;
	int max = 0;
	for(i=0;i<size;i++){
		if(array[i]>max){
			max = array[i];
		}
	}
	return max;
}

int min(int size){
	int i = 0;
	int min = 9;
	for(i=0;i<size;i++){
		if(array[i]<min){
			min = array[i];
		}
	}
	return min;
}

float average(int size){
	int i = 0;
	int sum = 0;
	float ave = 0;
	for(i=0;i<size;i++){
		sum = sum + array[i];
	}
	ave = (float) sum/size;
	return ave;
}

void compute_stats(int size){
	int large, small = 0;
	float ave = 0;
	// Prints out the largest number
	large = max(size);
	printf("\n\nLargest number is %d", large);

	// Prints out the smallest number
	small = min(size);
	printf("\nSmallest number is %d", small);

	// Prints out the average of the numbers
	ave = average(size);
	printf("\nAverage of numbers is %.3f", ave);
}

int search(int size, int number){
	int i, index, count = 0;
	for(i=0;i<size;i++){
		if(number==array[i]){
			index = i;
		}else{
			count++;
		}
	}
	if(count==size){
		return -1;
	}else{
		return index;
	}
}

void print_array(int size){
	int i = 0;
	for(i=0;i<size;i++){
		printf("%d ", array[i]);
	}
}

void sort(int size){
	int i,j = 0;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			if(array[i]<array[j]){
				array[j] = array[i];
			}
		}
	}
}
