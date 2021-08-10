#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main() {
	int t, n, a[100000], inc[100000], dec[100000], max, cnt1, cnt2, count;
	bool flag;
	
	scanf("%d", &t);
	
	while(t--){
	    scanf("%d", &n);
	    
	    memset(a,0,sizeof(a));
	    memset(inc, 0, sizeof(inc));
	    memset(dec, 0, sizeof(dec));
	    
	    for(int i=0; i<n; i++){
	        scanf("%d", &a[i]);
	    }
	    
	    sort(a, a+n);
	    
	    max = a[n-1];
	    
	    if(a[n-1] == a[n-2]){
	        printf("NO\n");
	        continue;
	    }
	    
	    flag = true;
	    
	    for(int i=0; i<n-1; i++){
	        if(a[i] == a[i+1]){
	            flag = false;
	            break;
	        }
	    }
	    
	    if(flag == true){
	        printf("YES\n");
	        for(int i=0; i<n; i++){
	            printf("%d ", a[i]);
	        }
	        printf("\n");
	        continue;
	    }
	    
	    count = 1;
	    
	    for(int i=1; i<n-1; i++){
	        if(a[i] == a[i-1]){
	            count++;
	            if(count == 3){
	                break;
	            }
	        }
	        else{
	            count = 1;
	        }
	    }
	    
	    if(count == 3){
	        printf("NO\n");
	        continue;
	    }
	    printf("YES\n");
	    
	    int i = 0;
	    cnt1 = cnt2 = 0;
	    
	    while(i<n-1){
	        if(a[i] == a[i+1]){
	            inc[cnt1++] = a[i];
	            dec[cnt2++] = a[i+1];
	            i += 2;
	        }
	        else{
	            inc[cnt1++] = a[i];
	            i++;
	        }
	    }
	    
	    inc[cnt1++] = a[n-1];
	    
	   // sort(dec, cnt2, greater<int>());
	    
	    for(int j=0; j<cnt1; j++){
	        printf("%d ", inc[j]);
	    }
	    
	    for(int j=cnt2-1; j>=0; j--){
	        printf("%d ", dec[j]);
	    }
	    printf("\n");
	}
	
	return 0;
}
