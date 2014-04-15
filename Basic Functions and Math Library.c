// Daniel Hanson

#include <stdio.h>
#include <math.h>

int check_number(float x);
int check_exponent(int n);
float compute_power(float x, int n);

int main(void){
	// Initializing the variables
	float x,myanswer,powanswer;
	int n,numbercheck,exponentcheck;

	// Using the number checking function
	printf("Enter a number: ");
	scanf("%f", &x);
	while(x<0||x>100){
		printf("Number should be between 0 & 100 enter the number again: ");
		scanf("%f", &x);
	}
	numbercheck = check_number(x);
	while(numbercheck==0){
		check_number(x);
	}

	// Using the exponent checking function
	printf("Enter a exponent: ");
	scanf("%d", &n);
	while(n<-5||n>5){
		printf("Exponent should be between -5 & 5 enter the exponent again: ");
		scanf("%d", &n);
	}
	exponentcheck = check_exponent(n);
	while(exponentcheck==0){
		check_exponent(n);
	}

	// Calculates using my function
	myanswer = compute_power(x,n);

	// Calculates using the pow function
	powanswer = pow(x,n);

	printf("pow(%f,%d)=%f using compute_power function\n",x,n,myanswer);
	printf("pow(%f,%d)=%f using pow function from the library\n",x,n,powanswer);

	return 0;
}

float compute_power(float x, int n){
	float answer=1;
	int exponent=0;
	exponent = n;

	if(exponent==0){
		return 1;
	}else if(exponent<0){
		for(exponent=n;exponent<0;exponent++){
			answer = answer*x;
		}
		return (float) 1/answer;
	}else if(exponent>0){
		for(exponent=n;exponent>0;exponent--){
			answer = answer*x;
		}
		return answer;
	}
}

int check_number(float x){
	while(x<0||x>100){
		printf("Number should be between 0 & 100 enter the number again: ");
		scanf("%f", &x);
	}	
	return 1;
}

int check_exponent(int n){
	while(n<-5||n>5){
		printf("Exponent should be between -5 & 5 enter the number again: ");
		scanf("%d", &n);
	}
	return 1;
}
