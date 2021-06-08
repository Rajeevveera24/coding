#include <stdio.h>

long int func(int a, int n);

int main(){
	int a, n;
	printf("Enter the values of a and n: ");
	scanf("%d %d", &a, &n);
	printf("%d^%d is %ld\n", a, n, func(a,n));
	return 0;
}

long int func(int a, int n){
	if(n == 0){
		return 1;
	}
	if(n == 1){
		return a;
	}
	if(n%2 == 0){
		return (func(a, n/2) * func(a, n/2));
	}
	return (func(a, (n-1)/2) * func(a, (n-1)/2));
}