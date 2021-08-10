#include <iostream>
using namespace std;

int main() {
    
	int t, m, n, *f, *p, minPrice, price;
	
	cin >> t;
	
	while(t--){
	    cin >> n >> m;
	    
	    minPrice = 0;
	    
	    f = (int*)malloc(sizeof(int) * n);
	    p = (int*)malloc(sizeof(int) * n);
	    
	    for(int i=0; i<n; i++){
	        cin >> f[i];
	    }
	    for(int i=0; i<n; i++){
	        cin >> p[i];
	        minPrice += p[i];
	    }
	    
	    if(minPrice == 0){
	        cout << 0 << endl;
	        continue;
	    }
	    
	   //  if (m == 2){
	         
	   //     int p1 = 0, p2 = 0;
	        
	   //     for(int i=0; i<n; i++){
	   //         if(f[i] == 1){
	   //             p1 += p[i];
	   //         }
	   //         else{
	   //             p2 += p[i];
	   //         }
	   //     }
	        
	   //     (p1<p2)?(cout << p1 << endl):(cout << p2 << endl);
	        
	   //     continue;
	   // }
	    
	    
	    for(int i=1; i<= m; i++){
	        price = 0;
	        int basket = 0;
	        for(int j=0; j<n; j++){
	            if(f[j] == i){
	                price += p[j];   
	                basket++;
	            }
	        }
	        if(price < minPrice && basket > 0){
	            minPrice = price;
	        }
	    }
	    
	    cout << minPrice << endl;
	    
	    free(f);
	    free(p);
    }
	
	return 0;
}
