//Solved partially (10/100 points) after the completion of the contest...

#include <iostream>
using namespace std;
# define ll unsigned long long int

long c[10000][10000];

int min(int a, int b){
	if(a>b){
		return b;
	}
	else{
		return a;
	}
}

void binomial(int n, int k){
	for(int i=0; i<=n; i++){
		for(int j=0; j<=min(i,k); j++){
			if( i==0 || j==0){
				c[i][j] = 1;
			}
			else{
				c[i][j] = (c[i-1][j-1] + c[i-1][j] );
			}
		}
	}
}

int main() {
	int t, n, a1, b1, min1, max1;
	ll count;
	string a, b;
	
	binomial(2000, 2000);
	cout<<c[1000][500];
	cin>>t;
    
    while(t--){
        cin>>n;
        cin>>a;
        cin>>b;
        a1 = b1 = count = 0;
        
        for(int i=0; i<n; i++){
            if(a[i] == '1'){
                a1++;
            }
            if(b[i] == '1'){
                b1++;
            }
        }
        
        min1 = abs(a1 - b1);
        max1 = min(min(n, 2*n - (a1 + b1)), a1+b1);
        count = 0;
        // min1 = 1;
        // max1 = 999;
        // n = 1000;
        for(int i=min1; i<=max1; i+=2){
            count += c[n][i];
        }
        cout<<count % 1000000007<<endl;
    }	
	return 0;
}
