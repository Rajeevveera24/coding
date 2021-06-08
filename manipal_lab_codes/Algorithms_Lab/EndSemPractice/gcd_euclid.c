#include <stdio.h>

int count = 0;

void swap(int *x, int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int gcd(int m, int n){
	if(m<n){
		swap(&m, &n);
	}
	int rem;
	while(n>0){
		rem = m%n;
		m = n;
		n = rem;
		count = count + 1;
	}
	return m;
}

int main(){
	int m,n;
	scanf("%d %d", &m, &n);
	int g = gcd(m,n);
	printf("gcd:%d\tcount:%d\n", g, count);
	return 0;
}
