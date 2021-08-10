#include <iostream>
#include <algorithm>
using namespace std;

int maxProfit, *sol, mat[4][4], size = 4;

void swap(int *x, int *y){
    int temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
}

void permute(int *a, int l, int r){
    int i, cost = 0; 
    if (l == r){ 
        for(int j=0;j<size;j++){
            // printf("%d ",a[j]+1);
            cost += mat[j][a[j]];
        }
        // printf("cost: %d\n", cost);
        if(cost > maxProfit){
            maxProfit = cost;
            for(int k=0; k<size; k++){
                sol[k] = a[k];
            }
        }
    }
    else{ 
        for (i = l; i <= r; i++){ 
            swap((a+l), (a+i)); 
            permute(a, l+1, r); 
            swap((a+l), (a+i));
        } 
    } 
}

int main() {
    
	int t, slot, n, profit, *p, count = 0;
	char m;
	
	cin>>t;
	p = (int*)malloc(sizeof(int) * t);
	while(t--){
	    
	    cin >> n;
	    
	    profit = 0;
	    maxProfit = -400;
	    
	    for(int i =0; i<4; i++){
	        for(int j=0; j<4; j++){
	            mat[i][j] = 0;
	        }
	    }
	    
	    for(int i=0; i<n; i++){
	        
	        cin >> m >>  slot;
	        
	       // printf("%d\t%d\n", m[0] - 'A', (slot[i] % 12) / 3)
	       
	        mat[m - 'A'][(slot % 12 ) / 3]++;
	    }
	   
	    for(int i=0; i<4; i++){
	       int flag = 0;
	       for(int j=0; j<4; j++){
	           if(mat[i][j] > 0){
	               flag = 1;
	               break;
	          }
	       }
	       if(flag == 0){
	           profit -= 100;
	       }
	   }
	   
	   if(profit == -400){
	       printf("%d\n", profit);
	       p[count++] = profit;
	       continue;
	   }
	   
    	   
    	int *Cost = (int*)malloc(4 * sizeof(int));
        sol = (int*)malloc(4 * sizeof(int));
        
        for(int i=0; i<4; i++){
            Cost[i] = i;
        }
    	  
    	permute(Cost, 0, 4-1);
    
        int arr[4];
        for(int i=0; i<4; i++){
            arr[i] = mat[i][sol[i]];
        }
        sort(arr, arr + 4);
        
        for(int i=0; i<4; i++){
            profit += 25*(i+1)*arr[i];
        }
        
        printf("%d\n", profit);
        p[count++] = profit;
        
        free(sol);
        free(Cost);
	   
	}
	long int p1 = 0;
	for(int i=0; i<count; i++){
	    p1 += p[i];
	}
	printf("%ld\n", p1);
	return 0;
}
