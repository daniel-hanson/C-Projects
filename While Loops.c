//Daniel Hanson

#include <stdio.h>
#include <math.h>

int main(void){
	//Initializing variables
	int a,b,c;
	float p,area;
	int q=0;

	//Keeps looping the program unless -1 was entered at the end
	while(q!=-1){
		//Prompts for entering data and loops to check for valid inputs
		printf("Enter the first number: ");
		scanf("%d", &a);
		while(a<=0){
			printf("Invalid number enter the number again: ");
			scanf("%d", &a);
		}

		printf("Enter the second number: ");
		scanf("%d", &b);
		while(b<=0){
			printf("Invalid number enter the number again: ");
			scanf("%d", &b);
		}

		printf("Enter the third number: ");
		scanf("%d", &c);
		while(c<=0){
			printf("Invalid number enter the number again: ");
			scanf("%d", &c);
		}

		//Calculates semi perimeter
		p = (float) (a+b+c)/2;
		
		//Calculates  area
		area = (float) sqrt(p*(p-a)*(p-b)*(p-c));

		printf("\nArea of the triangle is %f\n\n", area);

		//Bonus Part
		printf("Bonus part\n\n");
		
		//Determines what type of triangle it is
		if(a==b&&b==c){
			printf("Triangle is an equilateral triangle\n\n");
		}else if(a==b||b==c||a==c){
			printf("Triangle is an isosceles triangle\n\n");
		}else{
			printf("Triangle is a scalene triangle\n\n");
		}

		//Determines and prints off the longest side of the triangle
		if(a>b&&a>c){
			printf("Length of the longest side of the triangle is %d\n\n",a);
		}
	   	if(b>a&&b>c){
			printf("Length of the longest side of the triangle is %d\n\n",b);
		}
	   	if(c>a&&c>b){
			printf("Length of the longest side of the triangle is %d\n\n",c);
		}
		if(a<b&&b==c){
			printf("Length of the longest side of the triangle is %d\n\n",b);
		}
		if(b<a&&a==c){
			printf("Length of the longest side of the triangle is %d\n\n",a);
		}
		if(c<a&&a==b){
			printf("Length of the longest side of the triangle is %d\n\n",a);
		}
		if(a==b&&b==c){
			printf("Length of the longest side of the triangle is %d\n\n",a);
		}

		//Determines and prints off the shortest side of the triangle
		if(a<b&&a<c){
			printf("Length of the shortest side of the triangle is %d\n\n",a);
		}
		if(b<a&&b<c){
			printf("Length of the shortest side of the triangle is %d\n\n",b);
		}
		if(c<a&&c<b){
			printf("Length of the shortest side of the triangle is %d\n\n",c);
		}
		if(a>b&&b==c){
			printf("Length of the shortest side of the triangle is %d\n\n",b);
		}
		if(b>a&&a==c){
			printf("Length of the shortest side of the triangle is %d\n\n",a);
		}
		if(c>a&&a==b){
			printf("Length of the shortest side of the triangle is %d\n\n",a);
		}
		if(a==b&&b==c){
			printf("Length of the shortest side of the triangle is %d\n\n",a);
		}

		printf("Enter (-1 to quit otherwise continue)\n");
		scanf("%d", &q);
	}
	return 0;
}
