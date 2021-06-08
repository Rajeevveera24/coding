#include <stdio.h>

int gcd(int a, int b);

int main(){
	int choice, num1, num2;
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

int gcd(int a, int b){
	int hcf,min = a>b?b:a;
	for(int i=1; i<=min;i++){
		if(a%i == 0 && b%i == 0){
			hcf = i;
		}
	}
	return hcf;
}