#include <stdio.h>
#include <stdlib.h>

int main()
{
 
    FILE *f;  
    char fName[80];
 
    printf("\nEnter file name to create :");
    scanf("%s",fName);

    f = fopen(fName,"w");

    if(f == NULL)
    {
        printf("Error: File not created...\n");
        printf("Goodbye...\n");
        exit(0); 
    }

    printf("File created successfully...\n");

    printf("Enter a srting to be written into the file:\t");

    scanf("%s",fName);

    fprintf(f,"%s",fName);

    fclose(f);
 
    return 0;
}