#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, a[100000];
	bool flag;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		sort(a, a+n);
		flag = false;
		for(int i=0; i<n-1; i++){
			if(a[i] == a[i+1]){
				flag = true;
			}
		}
		flag == false ? cout << "Yes" : cout<<"No";
		cout<<endl;
	}
	return 0;
}
