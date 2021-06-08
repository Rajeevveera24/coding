#include<stdio.h>
typedef struct
{
	int rollno;
}student;

int main()
{
	int i,j;
	student stud[10],temp;
	printf("Enter the roll numbers of 10 students\n");
	for(i=0;i<10;i++)
		scanf("%d",&stud[i].rollno);
	for(i=0; i<10;i++)
		for(j=0; j<10-i-1;j++)
			if(stud[j].rollno > stud[j+1].rollno)
			{
				temp = stud[j];
				stud[j]=stud[j+1];
				stud[j+1]=temp;
			}
	printf("The roll numbers in ascending order are:\n");
	for(i=0;i<10;i++)
		printf("%d\n",stud[i].rollno);
	return 0;
}
