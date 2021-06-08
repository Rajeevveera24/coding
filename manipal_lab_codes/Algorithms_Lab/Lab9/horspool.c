#include <stdio.h>
#include <string.h>
#define MAX 500
//int t[MAX];
int count=0;
void shifttable(char p[],int t[]){
	int i,j,m;
	m=strlen(p);
	for (i=0;i<MAX;i++){
	  t[i]=m;
	}
	for (j=0;j<m-1;j++){
	  t[p[j]]=m-1-j;
	}
}
int horspool(char src[],char p[],int t[]){
	int i,j,k,m,n;
	n=strlen(src);
	m=strlen(p);
	printf("\nLength of text=%d",n);
	printf("\nLength of pattern=%d",m);
	i=m-1;
	while(i<n){
		k=0;
		while(++count && (k<m)&&(p[m-1-k]==src[i-k])){
		   k++;
		}
		if(k==m){
		   return(i-m+1);
		} 
		else{
		   i+=t[src[i]];
		}
	}
	return -1;
}
int main() {
	char src[100],p[100];
	int t[MAX];
	int pos;
	printf("Enter the text in which pattern is to be searched:\n");
	gets(src);
	printf("Enter the pattern to be searched:\n");
	gets(p);
	shifttable(p,t);
	pos=horspool(src,p,t);
	if(pos>=0){
	  printf("\nThe pattern was found from position %d\n",pos+1);
	}
	else{
	  printf("\nThe pattern was not found in the given text\n");
	}
	printf("Count=%d\n",count);
	return 0;
}