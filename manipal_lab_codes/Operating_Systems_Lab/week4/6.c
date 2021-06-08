                                                                                                                                                                                                                  #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
 
    int f1,f2;

    char *file1 = "temp.txt", *file2 = "temp2.txt",buff[80];

    f1 = open(file1,0);
    f2 = creat(file2,1);

    if(f1 == -1 || f2 == -1){
        printf("Error opening files...\n");
        exit(1);
    }

    while(read(f1,buff,80)){
        write(f2,buff,80);
    }

    close(f1);
    close(f2);

    return 0;
}