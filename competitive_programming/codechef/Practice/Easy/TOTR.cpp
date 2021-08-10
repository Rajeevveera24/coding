#include <iostream>
using namespace std;

int main() {
	int t;
	string byt, per;
	cin>>t>>per;
// 	cout<<per;
	while(t--){
	    cin>>byt;
	    string eng = byt;
	    for(int i=0; i<byt.length(); i++){
	       // cout<<byt;
	        if(isalpha(byt[i])){
	           // cout<<"here"<<endl;
	            if(isupper(byt[i])){
	                eng[i] = per[byt[i] - 65];
	                eng[i] = toupper(eng[i]);
	               // cout<<eng[i];
	            }
	            else{
	                eng[i] = per[byt[i] - 97];
	               // cout<<eng[i];
	            }
	        }
	        else if(byt[i] == '_'){
	            eng[i] = ' ';
	           // cout<<eng[i];
	        }
	        else{
	            eng[i] = byt[i];
	           // cout<<eng[i];
	        }
	    }
	    cout<<eng<<endl;
	}
	return 0;
}
