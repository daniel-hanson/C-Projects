//Daniel Hanson

#include <stdio.h>

int main(){
	
	// Declares the variables
	int x,y,z,sum;

	// Prompts the user to enter numbers and scans in the numbers
	printf("\n Enter the first number: ");
	scanf("%d", &x);

	printf("\n Enter the second number: ");
	scanf("%d", &y);

	printf("\n Enter the third number: ");
	scanf("%d", &z);

	// Calculates the sum
	sum = x+y+z;

	// Prints out the answers
	printf("\n Sum of the three numbers is %d\n", sum);

	// Lab Bonus
	int u,a,t;
	float s;

	// Prompts the user to enter numbers and scans in the numbers
	printf("\nBonus Part\n");

	printf("Enter the initial speed of the vehicle in miles/hour: ");
	scanf("%d",&u);
	
	printf("Enter the acceleration of the vehicle in miles/square hour: ");
	scanf("%d",&a);

	printf("Enter the time in seconds: ");
	scanf("%d",&t);

	// Calculates the equation and converts
	s = u*t/3600;
	s = a*t*t/2/3600/3600;

	// Prints out the final answer
	printf("The total distance travelled by the vehicle in %d seconds is %d miles or %d meters.\n", t, s, s*3600); 

	return 0;
}
