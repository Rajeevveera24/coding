//Wrong solution - This checks for substrings, while question required programmer to check for sub sequences...
#include <iostream>
using namespace std;

int main() {
	int t, n, kmax;
	string s;
	bool cont;
	cin>>t;
	while(t--){
	    cin>>n;
	    cin>>s;
	    kmax = 0;
	    for(int i=0; i<s.length()-1; i++){
	        cont = false;
	        int k = 0;
	        for(int j=i+1; j<s.length(); j++){
	            if(s[i+k] == s[j]){
	                cont = true;
	                k++;
	                // cout<<"Here"<<endl;
	                if((j == s.length() - 1)  && (cont == true)){
	                    if(kmax < k){
	                        kmax = k;
	                    }  
	                }
	            }
	            else{
	                cont = false;
	               // e2 = j-1;
	                if (kmax < k){
	                    kmax = k;
	                }
	                k = 0;
	                if(s[j] == s[i]){
	                    j--;
	                }
	            }
	        }
	    }
	    cout<<kmax<<endl;
	}
	return 0;
}