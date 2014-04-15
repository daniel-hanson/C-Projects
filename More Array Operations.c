// Daniel Hanson

#define MAX 100
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_menu();
int check_option(int);
int check_size(int);
void initialize_2Darray(int x[][MAX], int size);
void print_2Darray(int x[][MAX], int size);
void initialize_1Darray(int y[], int size);
void print_1Darray(int y[], int size);
int search_max(int x[][MAX], int r, int c, int size);
int count_diagonal(int x[][MAX], int i, int size);
int closest_row(int x[][MAX], int y[], int size1, int size2);
void sort_1Darray(int y[], int size);
void sort_2Darray(int x[][MAX], int size);

int main(){
	srand(time(NULL));
	// Initializing the variables
	int size, checksize = 0;
	int option, checkoption = 0;
	int row, col = 0;
	int large, max = 0;
	int i, diagonal = 0;
	int twod[MAX][MAX];
	int oned[MAX];

	// Prompts the user to enter the size of the array
	printf("Enter the size: ");
	scanf("%d", &size);
	checksize = check_size(size);
	while(checksize==0){
		printf("Invalid input enter the size of the array again: ");
		scanf("%d", &size);
		checksize = check_size(size);
	}

	while(option!=6){
		// Initialization of the arrays
		initialize_2Darray(twod, size);
		initialize_1Darray(oned, size);

		// Displays the menu
		display_menu();

		// Prompts the user to input the array operation option
		printf("Enter the operation you want to perform: ");
		scanf("%d", &option);
		checkoption = check_option(option);
		while(checkoption==0){
			printf("Invalid option enter the option again: ");
			scanf("%d", &option);
			checkoption = check_option(option);
		}

		// Handles the menu option input and performs the corresponding operation
		if(option==1){
			printf("\n2D array\n");
			print_2Darray(twod, size);
			printf("\nEnter the row: ");
			scanf("%d", &row);
			printf("Enter the col: ");
			scanf("%d", &col);
			max = search_max(twod, row, col, size);
			printf("\nThe largest number present in row %d and col %d is %d\n", row, col, max);
		}else if(option==2){
			printf("\n2D array\n");
			print_2Darray(twod, size);
			for(i=0;i<size;i++){
				diagonal = count_diagonal(twod, i, size);
				printf("\nDiagonal element %d is present %d more times in the row %d and col %d", twod[i][i], diagonal, i, i);
			}
			printf("\n");
		}else if(option==3){
			printf("\n2D array\n");
			print_2Darray(twod, size);
			printf("\n1D array\n");
			print_1Darray(oned, size);
			printf("\nRow %d in the 2D array is closest to the 1D array\n", closest_row(twod, oned, size, size));
		}else if(option==4){
			printf("\n1D array before sorting\n");
			print_1Darray(oned, size);
			sort_1Darray(oned, size);
			printf("\n1D array after sorting\n");
			print_1Darray(oned, size);
		}else if(option==5){
			printf("\n2D array before sorting\n");
			print_2Darray(twod, size);
			sort_2Darray(twod, size);
			printf("\n2D array after sorting\n");
			print_2Darray(twod, size);
		}
	}

	return 0;
}

void display_menu(){
	printf("\nArray operation, your options are:\n\n");
	printf("1: Search Max\n2: Count Diagonal Number\n3: Closest Row\n4: Sort 1D Array\n5: Sort 2D Array\n6: Exit\n");
}

int check_option(int option){
	if(option>=1&&option<=6){
		return 1;
	}
	return 0;
}

int check_size(int size){
	if(size>0&&size<=100){
		return 1;
	}
	return 0;
}

void initialize_2Darray(int x[][MAX], int size){
	int i,j = 0;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			x[i][j] = rand()%10;
		}
	}
}

void print_2Darray(int x[][MAX], int size){
	int i,j = 0;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			printf("%d ", x[i][j]);
		}
		printf("\n");
	}
}

void initialize_1Darray(int y[], int size){
	int i = 0;
	for(i=0;i<size;i++){
		y[i] = rand()%10;
	}
}

void print_1Darray(int y[], int size){
	int i = 0;
	for(i=0;i<size;i++){
		printf("%d ", y[i]);
	}
	printf("\n");
}

int search_max(int x[][MAX], int r, int c, int size){
	int i, large = 0;
	for(i=0;i<size;i++){
		if(x[r][i]>large){
			large = x[r][i];
		}
		if(x[i][c]>large){
			large = x[i][c];
		}
	}
	return large;
}

int count_diagonal(int x[][MAX], int i, int size){
	int diagonal, count = 0;
	int j = 0;
	diagonal = x[i][i];
	for(j=0;j<size;j++){
		if(diagonal==x[i][j]){
			count++;
		}
		if(diagonal==x[j][i]){
			count++;
		}
	}
	return count-2;
}

int closest_row(int x[][MAX], int y[], int size1, int size2){
	int i, j = 0;
	int count, index = 0;
	int close = 900; // The maximum for a 100 size array
	for(i=0;i<size1;i++){
		for(j=0;j<size1;j++){
			count = count + abs(x[i][j]-y[j]);	
		}
		if(count<close){
			close = count;
			index = i;
		}
		count = 0;
	}
	return index;
}

void sort_1Darray(int y[], int size){
	int i, j = 0;
	int carry = 0;
	for(i=0;i<size;i++){
		for(j=i+1;j<size;j++){
			if(y[i]>y[j]){
				carry = y[i];
				y[i] = y[j];
				y[j] = carry;
			}
		}
	}
}

void sort_2Darray(int x[][MAX], int size){
	int i, j = 0;
	int k = 0;
	int carry[MAX];
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			carry[j] = x[i][j];
		}
		sort_1Darray(carry, size);
		for(k=0;k<size;k++){
			x[i][k] = carry[k];
		}
	}
}
