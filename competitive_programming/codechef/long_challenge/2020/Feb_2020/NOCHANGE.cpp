#include <iostream>
// #include <stdbool.h>
#include <algorithm>

using namespace std;

struct tNum{
    int pos, val;
    long int num;
};

// struct tNum t;

int findpos(long int d[1000], long int d1,int n){
    for(int i=0; i<n; i++){
        if(d[i] == d1){
            return i;
        }
    }
    return 0;
}

int findNext(long int d[1000], int x){
    long int max = d[x];
    
    for(int i=x; i>=0; i--){
        if(d[i] < max){
            return i;
        }
    }
    return -1;
}

int main() {
    bool flag;
	int t, n, pos;
	long int p, *d, *d1;
	cin>>t;
	while(t--){
	    flag =  true;
	    cin >> n >> p;
	    
	    d = (long int *)malloc(n * sizeof(long int));
	    d1 = (long int *)malloc(n * sizeof(long int));
	    
	    for(int i=0; i<n; i++){
	        cin >> d[i];
	        d1[i] = d[i];
	        if(p % d[i] != 0){
	            flag = false;
	            pos = i;
	        }
	    }
	    
	    if(flag == true){
	        sort(d1, d1+n);
	        for(int i=0; i<n-1; i++){
	            if(d1[i + 1] % d1[i] != 0){
	                flag = false;
	                break;
	            }
	        }
	        if(flag == true){
	            cout << "NO" << endl;
	            continue;
	        }
	        else{
	            struct tNum tn[n];
	            for(int i=0; i<n; i++){
	                tn[i].val = 0;
	                tn[i].pos = i;
	                tn[i].num = d1[i];
	            }
	            
	            long int rem = p;
	           // int i = tn[n-1].pos;
	            rem = tn[n-1].num;
	            tn[n-1].val = p / tn[n-1].num - 1; //cout << tn[n-1].val<<" ";
	            int i = n-1;
	            while(rem > 0){
	                
	               // i = findNext(d1, i);
	               i--;
	               // cout << d1[i] << endl;
	                
	                if(rem % tn[i].num == 0){
	                    tn[i].val = rem / tn[i].num - 1;
	                    rem = tn[i].num;
	                   // cout << tn[i].val <<" ";
	                }
	                else{
	                    tn[i].val = rem / tn[i].num + 1;
	                    rem = rem % tn[i].num - tn[i].num;
	                   // cout << tn[i].val << " ";
	                }
	            }
	           // printf("Here\n");
	           cout << "YES";
	           for(int i=0; i<n; i++){
	               cout << " " << tn[i].val;
	           }
	            printf("\n");
	            continue;
	        }
	    }
	    
	   // pos = 0;
	    p = p / d[pos];
	    p++;
	    cout << "YES";
	    
	    for(int i=0; i<pos; i++){
	        cout << " 0";
	    }
	    cout << " " << p;
	    for(int i=pos+1; i<n; i++){
	        cout << " 0";
	    }
	    cout << endl;
	    free(d);
	    free(d1);
	}
	return 0;
}
