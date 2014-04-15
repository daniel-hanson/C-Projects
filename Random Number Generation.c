// Daniel Hanson

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateNumber();
void displayMenu();
int errorCheck(int guess);
int checkGuess(int guess, int answer);
void printResult(int result, int answer);

int main(void){
	int playagain = 1;
	int correct, tries = 0;
	float winning = 0;

	while(playagain==1){
		// Initialization of the variables
		int guess, answer, result = 0;

		// Getting the answer from the generate number function
		answer = generateNumber();

		// Displaying the menu and prompting the user to put in their guess
		displayMenu();
		scanf("%d", &guess);

		// Error checking the users guess
		errorCheck(guess);

		// Sets result to whether or not the user is correct with their guess
		result = checkGuess(guess, answer);

		// Prints the result
		printResult(result, answer);

		printf("Do you want to play again? (1 yes, 0 no)\n");
		scanf("%d", &playagain);

		// Counters for the number of correct guesses and number of tries
		if(result==1){
			correct++;
		}
		tries++;
	}

	// Calculating winning percentage
	winning = (float) correct/tries/0.01;

	printf("You made %d correct guesses in %d tries\n", correct, tries);
	printf("Your winning percentage is %.2f%\n", winning);
}

int generateNumber(){
	int randomnum=0;
	srand(time(NULL));
	randomnum = (rand())%2;
	return randomnum;
}

void displayMenu(){
	printf("Please take a guess\n");
	printf("0 : Head\n");
	printf("1 : Tail\n");
	printf("Enter your guess: ");
}

int errorCheck(int guess){
	while(guess<0||guess>1){
		printf("Invalid guess enter your choice again: ");
		scanf("%d", &guess);
	}
}

int checkGuess(int guess, int answer){
	if(guess==answer){
		return 1;
	}else{
		return 0;
	}
}

void printResult(int result, int answer){
	if(result==0&&answer==0){
		printf("Your choice was tail and it is an incorrect guess.\n");	
	}else if(result==0&&answer==1){
		printf("Your choice was head and it is an incorrect guess.\n");
	}else if(result==1&&answer==0){
		printf("Your choice was head and it is a correct guess.\n");
	}else if(result==1&&answer==1){
		printf("Your choice was tail and it is a correct guess.\n");
	}
}
