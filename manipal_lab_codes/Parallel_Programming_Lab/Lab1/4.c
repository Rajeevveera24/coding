#include<stdio.h>
#include<string.h>
 
int main(){
    FILE *fp;
    int a=0, check=0, b=0, x=0;
    char str[2], supertext[500];
    char man[50];
    char* filename = "/home/student/Desktop/mukukijaiho.txt";
    fp = fopen(filename, "r");
    while (fgets(str, 2, fp) != NULL){
        if(str[0]=='<'){
            check=1;
            a=0;
        }
        if(check==1){
            man[a++]=str[0];
            man[a]='\0';
        }
        if(str[0]=='>'){
            man[a]='\0';
            a=0;
            check=0;
        }
        if(strcmp(man, "<TEXT>")==0)
            b=1;
        if(strcmp(man, "/<TEXT>")==0)
            b=0;
        if(b==1)
            supertext[x++]=str[0];
    }
    for(int i=1; i<x-8; i++)
        printf("%c", supertext[i]);
    fclose(fp);
    return 0;
}                                  