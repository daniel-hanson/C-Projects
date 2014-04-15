//Daniel Hanson

#include <stdio.h>
#include <math.h>

int main(){
	// Declaring the variables
	int x1,x2,x3,y1,y2,y3;
	double d1,d2,d3,sum;

	// Asks for the x1 coordinate and checks if it's valid
	printf("Enter the x coordinate of the first point: ");
	scanf("%d",&x1);
	if(x1<0){
		printf("Invalid coordinate enter the coordinate again: ");
		scanf("%d",&x1);
	}
	printf("\n");

	// Asks for the y1 coordinate and checks if it's valid
	printf("Enter the y coordinate of the first point: ");
	scanf("%d",&y1);
	if(y1<0){
		printf("Invalid coordinate enter the coordinate again: ");
		scanf("%d",&y1);
	}
	printf("\n");

	// Asks for the x2 coordinate and checks if it's valid
	printf("Enter the x coordinate of the second point: ");
	scanf("%d",&x2);
	if(x2<0){
		printf("Invalid coordinate enter the coordinate again: ");
		scanf("%d",&x2);
	}
	printf("\n");

	// Asks for the y2 coordinate and checks if it's valid
	printf("Enter the y coordinate of the second point: ");
	scanf("%d",&y2);
	if(y2<0){
		printf("Invalid coordinate enter the coordinate again: ");
		scanf("%d",&y2);
	}
	printf("\n");

	// Asks for the x3 coordinate and checks if it's valid
	printf("Enter the x coordinate of the third point: ");
	scanf("%d",&x3);
	if(x3<0){
		printf("Invalid coordinate enter the coordinate again: ");
		scanf("%d",&x3);
	}
	printf("\n");
	
	// Asks for the y3 coordinate and checks if it's valid
	printf("Enter the y coordinate of the third point: ");
	scanf("%d",&y3);
	if(y3<0){
		printf("Invalid coordinate enter the coordinate again: ");
		scanf("%d",&y3);
	}
	printf("\n");

	// Calculates the distances between the points
	d1=(double) sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
	d2=(double) sqrt(((x1-x3)*(x1-x3))+((y1-y3)*(y1-y3)));
	d3=(double) sqrt(((x2-x3)*(x2-x3))+((y2-y3)*(y2-y3)));

	// Prints out the distances between the points
	printf("Distance between point 1 and point 2 is %lf\n",d1);
	printf("Distance between point 1 and point 3 is %lf\n",d2);
	printf("Distance between point 2 and point 3 is %lf\n",d3);

	// Adding up and printing the distances
	sum = d1+d2+d3;
	printf("Sum of the distances is %lf\n\n",sum);

	// Bonus part
	printf("Bonus part\n\n");

	// Determines and prints which two points have the longest distance
	if(d1>d2 && d1>d3){
		printf("Longest distance is %lf between point 1 and point 2\n",d1);
	}else if(d2>d1 && d2>d3){
		printf("Longest distance is %lf between point 1 and point 3\n",d2);
	}else if(d3>d1 && d3>d2){
		printf("Longest distance is %lf between point 2 and point 3\n",d3);
	}

	// Determines and prints which two points have the shortest distance
	if(d1<d2 && d1<d3){
		printf("Shortest distance is %lf between point 1 and point 2\n",d1);
	}else if(d2<d1 && d2<d3){
		printf("Shortest distance is %lf between point 1 and point 3\n",d2);
	}else if(d3<d1 && d3<d2){
		printf("Shortest distance is %lf between point 2 and point 3\n",d3);
	}
	
	return 0;
}
