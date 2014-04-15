// Daniel Hanson

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int check_input(int);
void initialize_array(int[], int);
void print_array(int[], int);
void display_menu();
int check_option(int);
int common_numbers(int[], int[], int);
int count_numbers(int[], int, int);
int mode(int[], int);
void print_histogram(int[], int[], int);

int main(void){
	srand(time(NULL));
	// Initialization of variables and array
	int size, menu, sizecheck, menucheck, common = 0;
	int array[100];
	int secondarray[100];

	// Prompts the user to enter the size of the array
	printf("Enter the size of the input: ");
	scanf("%d", &size);

	// Checks the user's input
	sizecheck = check_input(size);
	while(sizecheck==0){
		printf("Invalid input enter the size of the input again: ");
		scanf("%d", &size);
		sizecheck = check_input(size);
	}

	while(menu!=4){
		// Initialization of the array with random numbers
		initialize_array(array, size);
		initialize_array(secondarray, size);

		// Displays the menu
		display_menu();

		// Scans in the user's choice of operation
		scanf("%d", &menu);

		// Checks the user's input
		menucheck = check_option(menu);
		while(menucheck==0){
			printf("Invalid option enter the option again: ");
			scanf("%d", &menu);
			menucheck = check_option(menu);
		}

		// Selects the correct menu option
		if(menu==1){
			printf("\nInput arrays\n");
			print_array(array, size);
			print_array(secondarray, size);
			common = common_numbers(array, secondarray, size);
			printf("\nThere are %d common numbers between the two arrays\n", common);
			menu = 1;
		}else if(menu==2){
			printf("\nInput arrays\n");
			print_array(array, size);
			print_array(secondarray, size);
			printf("\nMode for the first array is %d\n", mode(array, size));
			printf("\nMode for the second array is %d\n", mode(secondarray, size));
			menu = 2;
		}else if(menu==3){
			printf("\nInput arrays\n");
			print_array(array, size);
			print_array(secondarray, size);
			print_histogram(array, secondarray, size);
		}
	}
}

int check_input(int size){
	if(size<=0||size>100){
		return 0;
	}else{
		return 1;
	}
}

void initialize_array(int array[], int size){
	int i = 0;
	array[size];
	for(i=size;i>0;i--){
		array[i-1] = rand()%10;
	}
}

void print_array(int array[], int size){
	int i,count = 0;
	for(i=size;i>0;i--){
		printf("%d ",array[count]);
		count++;
	}
	printf("\n");
}

void display_menu(){
	printf("\nArray operations, your options are:\n\n1: Common Numbers\n2: Mode\n3: Histogram\n4: Exit\n");
	printf("Enter the operation you want to perform: ");
}

int check_option(int menu){
	if(menu<1||menu>4){
		return 0;
	}else{
		return 1;
	}
}

int common_numbers(int array1[], int array2[], int size){
	int i,j,common = 0;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			if(array1[i]==array2[j]){
				common++;
			}
		}
	}
	return common;	
}

int count_numbers(int array[], int size, int number){
	int i,count = 0;
	for(i=0;i<size;i++){
		if(array[i]==number){
			count++;
		}
	}
	return count;
}

int mode(int array[], int size){
	int i = 0;
	int	mode = 0;
	int c0 = 0;
	int c1 = 0;
	int	c2 = 0;
	int	c3 = 0;
	int	c4 = 0;
	int	c5 = 0;
	int	c6 = 0;
	int c7 = 0;
	int c8 = 0;
	int c9 = 0;

	for(i=0;i<size;i++){
		if(array[i]==0){
			c0 = c0 + 1;	
		}
		if(array[i]==1){
			c1 = c1 + 1;
		}
		if(array[i]==2){
			c2 = c2 + 1;
		}
		if(array[i]==3){
			c3 = c3 + 1;
		}
		if(array[i]==4){
			c4 = c4 + 1;
		}
		if(array[i]==5){
			c5 = c5 + 1;
		}
		if(array[i]==6){
			c6 = c6 + 1;
		}
		if(array[i]==7){
			c7 = c7 + 1;
		}
		if(array[i]==8){
			c8 = c8 + 1;
		}
		if(array[i]==9){
			c9 = c9 + 1;
		}
	}
	
	if(c0>=c1&&c0>=c2&&c0>=c3&&c0>=c4&&c0>=c5&&c0>=c6&&c0>=c7&&c0>=c8&&c0>=c9){
		mode = 0;
	}
   	if(c1>=c0&&c1>=c2&&c1>=c3&&c1>=c4&&c1>=c5&&c1>=c6&&c1>=c7&&c1>=c8&&c1>=c9){
		mode = 1;
	}
  	if(c2>=c0&&c2>=c1&&c2>=c3&&c2>=c4&&c2>=c5&&c2>=c6&&c2>=c7&&c2>=c8&&c2>=c9){
		mode = 2;
	}
   	if(c3>=c0&&c3>=c1&&c3>=c2&&c3>=c4&&c3>=c5&&c3>=c6&&c3>=c7&&c3>=c8&&c3>=c9){
		mode = 3;
	}
   	if(c4>=c0&&c4>=c1&&c4>=c2&&c4>=c3&&c4>=c5&&c4>=c6&&c4>=c7&&c4>=c8&&c4>=c9){
		mode = 4;
	}
   	if(c5>=c0&&c5>=c1&&c5>=c2&&c5>=c3&&c5>=c4&&c5>=c6&&c5>=c7&&c5>=c8&&c5>=c9){
		mode = 5;
	}
   	if(c6>=c0&&c6>=c1&&c6>=c2&&c6>=c3&&c6>=c4&&c6>=c5&&c6>=c7&&c6>=c8&&c6>=c9){
		mode = 6;
	}
   	if(c7>=c0&&c7>=c1&&c7>=c2&&c7>=c3&&c7>=c4&&c7>=c5&&c7>=c6&&c7>=c8&&c7>=c9){
		mode = 7;
	}
   	if(c8>=c0&&c8>=c1&&c8>=c2&&c8>=c3&&c8>=c4&&c8>=c5&&c8>=c6&&c8>=c7&&c8>=c9){
		mode = 8;
	}
   	if(c9>=c0&&c9>=c1&&c9>=c2&&c9>=c3&&c9>=c4&&c9>=c5&&c9>=c6&&c9>=c7&&c9>=c8){
		mode = 9;
	}

	return mode;
}

void print_histogram(int array1[], int array2[], int size){
	int i = 0;
	int zeros = 0;
	int ones = 0;
	int twos = 0;
	int threes = 0;
	int fours = 0;
	int fives = 0;
	int sixes = 0;
	int sevens = 0;
	int eights = 0;
	int nines = 0;

	zeros = (count_numbers(array1, size, 0))+(count_numbers(array2, size, 0));
	ones = (count_numbers(array1, size, 1))+(count_numbers(array2, size, 1));
	twos = (count_numbers(array1, size, 2))+(count_numbers(array2, size, 2));
	threes = (count_numbers(array1, size, 3))+(count_numbers(array2, size, 3));
	fours = (count_numbers(array1, size, 4))+(count_numbers(array2, size, 4));
	fives = (count_numbers(array1, size, 5))+(count_numbers(array2, size, 5));
	sixes = (count_numbers(array1, size, 6))+(count_numbers(array2, size, 6));
	sevens = (count_numbers(array1, size, 7))+(count_numbers(array2, size, 7));
	eights = (count_numbers(array1, size, 8))+(count_numbers(array2, size, 8));
	nines = (count_numbers(array1, size, 9))+(count_numbers(array2, size, 9));

	printf("\nPrinting histogram\n\n");
	
	printf("0:");
	for(i=0;i<zeros;i++){
		printf("*");
	}
	printf("\n1:");
	for(i=0;i<ones;i++){
		printf("*");
	}
	printf("\n2:");
	for(i=0;i<twos;i++){
		printf("*");
	}
	printf("\n3:");
	for(i=0;i<threes;i++){
		printf("*");
	}
	printf("\n4:");
	for(i=0;i<fours;i++){
		printf("*");
	}
	printf("\n5:");
	for(i=0;i<fives;i++){
		printf("*");
	}
	printf("\n6:");
	for(i=0;i<sixes;i++){
		printf("*");
	}
	printf("\n7:");
	for(i=0;i<sevens;i++){
		printf("*");
	}
	printf("\n8:");
	for(i=0;i<eights;i++){
		printf("*");
	}
	printf("\n9:");
	for(i=0;i<nines;i++){
		printf("*");
	}
	printf("\n");
}
