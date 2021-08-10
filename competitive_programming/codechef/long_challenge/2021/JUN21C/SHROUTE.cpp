#include <iostream>
using namespace std;

int main() {
	int t,m,n, *a, *b, *c, prev;
	scanf("%d", &t);
	while(t--){
	    scanf("%d %d", &n, &m);
	    a = (int*)calloc(sizeof(int), n);
	    b = (int*)calloc(sizeof(int), m);
	    c = (int*)calloc(sizeof(int), n);
	    for(int i=0; i<n; i++){
	        scanf("%d", &a[i]);
	    }
	    for(int i=0; i<m; i++){
	        scanf("%d", &b[i]);
	    }
	    prev = -1;
	    c[0] = -1;
	    for(int i=0; i<n; i++){
	        if(a[i] == 1) {
	            c[i] = -1;
	            prev = i+1;
	        }
	        else if(a[i] == 2){
	            c[i] = -1;
	        }
	        else{
	            if(prev != -1){
	                c[i] = (i+1) - prev;
	            }
	        }
	    }
	    prev = -1;
	    for(int i=n-1; i >= 0; i--){
	        if (a[i] == 2) {
	            prev = i+1;
	            continue;
	        }
	        if(c[i] == -1) {
	            continue;
	        }
	        else {
	            if(prev != -1){
	                if(c[i] == 0){
	                    c[i] = prev - (i+1);
	                }
	                else {
	                    c[i] = min(c[i], prev - (i+1));
	                }
	            }
	        }
	    }
	   // for(int i=0; i<n; i++){
	   //     printf("%d ", c[i]);
	   // }
	   // printf("\n");
	    for(int i=0; i<m; i++){
	        if(c[b[i]-1] == -1) {
	            b[i] = 0;
	        }
	        else if(c[b[i]-1] == 0) {
	            b[i] = -1;
	        }
	        else {
	            b[i] = c[b[i]-1];
	        }
	    }
	    
	    for(int i=0; i<m-1; i++) {
	        printf("%d ", b[i]);
	    }
	    printf("%d\n", b[m-1]);
	}
	return 0;
}
