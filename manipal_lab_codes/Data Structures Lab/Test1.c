#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generates and prints 'count' random
// numbers in range [lower, upper].
void printRandoms(int lower, int upper,int count)
{
	int i,j,num,counter[100];
	for(j=0;j<100;j++)
        counter[j]=0;
	for (i = 0; i < count; i++)
    {
        {
            num = (rand() % (upper - lower + 1)) + lower;
            for(j=1;j<=100;j++)
                if(j==num)
                    counter[j-1]++;
        }

	}
	for(j=0;j<100;j++)
        printf("%d : %d \n",j+1,counter[j]);
}

// Driver code
int main()
{
	int lower = 0, upper = 100, count = 10000;

	// Use current time as
	// seed for random generator
	srand(time(0));

	printRandoms(lower, upper, count);

	return 0;
}
