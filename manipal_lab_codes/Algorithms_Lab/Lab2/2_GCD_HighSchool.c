#include <stdio.h>

int gcd(int a, int b);
int isPrime(int num);

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
	int hcf = 1,min = a>b?b:a;
	for(int i=2; i<=min;i++){
		if(isPrime(i)){
			if(a%i == 0 && b%i == 0){
				hcf *= i;
			}
		}
	}
	return hcf;
}

int isPrime(int num){

	if (num <= 1){
		return 0;
	} 
    if (num <= 3){
    	return 1;
    } 

    if (num%2 == 0 || num%3 == 0){
    	return 0;
    } 
  
    for (int i=5; i*i<=num; i+=6){
        if (num%i == 0 || num%(i+2) == 0){ 
           return 0;
        }
    } 
  
    return 1; 
}