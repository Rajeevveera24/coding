#include <stdio.h>

unsigned int gcd(unsigned int a, unsigned int b){
	
	unsigned int r,opCount = 0;
	
	while(b!=0){
		opCount++;
		r = a%b;
		a = b;
		b = r;
	}
	printf("Operation Count: %d\n",opCount);
	return a;
}
int main(){

	unsigned int choice,num1,num2;

	do{
		printf("\n============MENU============\n\n");
		printf("1. Find GCD of two numbers\n");
		printf("2. Exit Program\n");
		printf("Enter your choice:\t");
		scanf("%d",&choice);

		switch(choice){
			case 1:{
				printf("Enter the two integers whose GCD needs to be found:\t");
				scanf("%d %d",&num1,&num2);
				printf("The GCD of %d and %d is %d\n",num1,num2,gcd(num1,num2));
			}
			break;
			case 2:{
				printf("\nGoodbye...\n\n");
			}
			break;
			default:{
				printf("You entered an invalid choice. Please enter a differet choice next time...\n");
			}
		}
	}while(choice != 2);
}
