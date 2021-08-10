#include <iostream>
using namespace std;

// void perm(int size, int a[], int p[]){
//     for(int i=0; i<)
// }
int main() {
	int n,a[100000],per[100000];
	while(true){
	    cin>>n;
	    if(n==0){
	        break;
	    }
	    for(int i=0; i<n; i++){
	        cin>>a[i];
	        a[i]--;
	        per[a[i]] = i;
	    }
	    //perm(n,a,per);
	    bool flag = true;
	    for(int i=0; i<n; i++){
	        if(a[i] != per[i]){
	            flag = false;
	            break;
	        }
	    }
	    (flag == true) ? (cout<<"ambiguous"<<endl) : (cout<<"not ambiguous"<<endl);
	}
	return 0;
}