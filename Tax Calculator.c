//Daniel Hanson

#include <stdio.h>

int main(void){
	int ingroup,income,taxrate;
	float taxes,net;
	printf("Filing Status\n");
	printf("(1) Single\n");
	printf("(2) Married\n");
	printf("(3) Head of Household\n");
	printf("(0) Quit Program\n");
	printf("Please make selection: ");
	scanf("%d",&ingroup);

	//Checks what the user input and determines what to do next
	while(ingroup!=0){

		//Makes sure the input was a 1,2,or a 3
		//And if not prompts the user to enter another number
		while(ingroup!=1&&ingroup!=2&&ingroup!=3){
			printf("Invalid choice, make a selection again: ");
			scanf("%d",&ingroup);
		}
		
		//Switch statement for the marital status of the user
		switch(ingroup){
			//Single marital status
			case 1:
				//Prompts the user to input their annual income
				printf("\nEnter the annual income: ");
				scanf("%d",&income);
				
				//Calculates the tax data based on income
				if(income>=0&&income<20000){
					taxrate=10;
					taxes=(float) (income*10)/100;
					net=(float) income-((income*10)/100);
				}

				if(income>=20000&&income<50000){
					taxrate=20;
					taxes=(float) (income*20)/100;
					net=(float) income-((income*20)/100);
				}

				if(income>=50000&&income<100000){
					taxrate=30;
					taxes=(float) (income*30)/100;
					net=(float) income-((income*30)/100);
				}

				if(income>=100000&&income<250000){
					taxrate=35;
					taxes=(float) (income*35)/100;
					net=(float) income-((income*35)/100);
				}

				if(income>=250000){
					taxrate=40;
					taxes=(float) (income*40)/100;
					net=(float) income-((income*40)/100);
				}

				//Prints off the calculated data
				printf("Your tax rate is: %d%%\n",taxrate);
				printf("You pay $%.2f in taxes\n",taxes);
				printf("After taxes your net income is: $%.2f\n\n",net);
			break;
			
			//Married marital status
			case 2:
				//Prompts the user to input their annual income
				printf("\nEnter the annual income: ");
				scanf("%d",&income);

				//Calculates the tax data based on income
				if(income>=0&&income<30000){
					taxrate=10;
					taxes=(float) (income*10)/100;
					net=(float) income-((income*10)/100);
				}

				if(income>=30000&&income<60000){
					taxrate=20;
					taxes=(float) (income*20)/100;
					net=(float) income-((income*20)/100);
				}

				if(income>=60000&&income<125000){
					taxrate=30;
					taxes=(float) (income*30)/100;
					net=(float) income-((income*30)/100);
				}

				if(income>=125000&&income<300000){
					taxrate=35;
					taxes=(float) (income*35)/100;
					net=(float) income-((income*35)/100);
				}

				if(income>=300000){
					taxrate=40;
					taxes=(float) (income*40)/100;
					net=(float) income-((income*40)/100);
				}

				//Prints off the calculated data
				printf("Your tax rate is: %d%%\n",taxrate);
				printf("You pay $%.2f in taxes\n",taxes);
				printf("After taxes your net income is: $%.2f\n\n",net);
			break;

			//Head of household marital status
			case 3:
				//Prompts the user to input their annual income
				printf("\nEnter the annual income: ");
				scanf("%d",&income);

				//Calculates the tax data based on income
				if(income>=0&&income<50000){
					taxrate=10;
					taxes=(float) (income*10)/100;
					net=(float) income-((income*10)/100);
				}

				if(income>=50000&&income<100000){
					taxrate=20;
					taxes=(float) (income*20)/100;
					net=(float) income-((income*20)/100);
				}

				if(income>=100000&&income<25000){
					taxrate=30;
					taxes=(float) (income*30)/100;
					net=(float) income-((income*30)/100);
				}

				if(income>=250000&&income<500000){
					taxrate=35;
					taxes=(float) (income*35)/100;
					net-(float) income-((income*35)/100);
				}
				
				if(income>=500000){
					taxrate=40;
					taxes=(float) (income*40)/100;
					net=(float) income-((income*40)/100);
				}

				//Prints off the calculated data
				printf("Your tax rate is: %d%%\n",taxrate);
				printf("You pay $%.2f in taxes\n",taxes);
				printf("After taxes your net income is: $%.2f\n\n",net);
			break;
		}

		//Asks the user if they want to run the program again
		printf("Filing status\n");
		printf("(1) Single\n");
		printf("(2) Married\n");
		printf("(3) Head of Household\n");
		printf("(0) Quit Program\n");
		printf("Please make selection: ");
		scanf("%d",&ingroup);

		//Makes sure the input is 0,1,2,or 3
		//And if not prompts the user to enter another number
		while(ingroup!=0&&ingroup!=1&&ingroup!=2&&ingroup!=3){
			printf("Invalid choice, make a selection again: ");
			scanf("%d",&ingroup);
		}
	}

	printf("Exiting the tax calculator\n");
	return 0;
}
