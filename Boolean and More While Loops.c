//Daniel Hanson

#include <stdio.h>
#include <stdbool.h>

//Prototype of the bonus function
int error_check(int input);

int main(){
	int n=0;
	int input=0;
	int counter=0;
	int large=0;
	int small=0;
	int sum;
	float mean;
	bool check;

	//Prompts the user to enter the input size
	printf("Enter the input size: ");
	scanf("%d", &n);

	//Checks to make sure the input is greater than zero
	while(n<=0){
		printf("Invalid input enter the input size again: ");
		scanf("%d", &n);
	}

	printf("\n");

	//While loop to get input from the user
	while(counter<n){
		printf("Enter a positive integer: ");
		scanf("%d", &input);

		//First error check	
		error_check(input);

		//Error checking function
		while(check=false){
			printf("Invalid number, number should be positive (>=0)\n");
			printf("Enter a positive integer: ");
			scanf("%d", &input);
			error_check(input);
		}
		
		//Formulas for the largest number smallest number and mean
		if(input>large){
			large = input;
		}

		if(input<small){
			small = input;
		}

		sum = sum+input;

		printf("\n");
		counter++;
	}

	//Calculates the mean
	mean = (float) sum/n;

	//Prints off the values calculated
	printf("Mean of numbers is %.2f\n", mean);
	printf("Largest number is %d\n", large);
	printf("Smallest number is %d\n", small);

	//Bonus Part
	printf("Attempting bonus part\n");

	return 0;
}

//Error check bonus function
int error_check(int input){
	bool check;
	if(input<0){
		check = false;
	}

	check = true;
}
