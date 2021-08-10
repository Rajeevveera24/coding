#include<iostream>
//#include<math.h>
#include <algorithm>
#include <string.h>

using namespace std;

int max(int a, int b){
	return (a>b)?a:b;
}
int main(){
	int t,n, count0, count1, count = 0;
	cin>>t;
	while(t--){
		count = 0;
		cin>>n;
		string val[n];
		string comb[n];
		int bln[n];
		for(int i=0; i<n; i++){
			cin>>val[i]>>bln[i];
			comb[i] = val[i] + " " + (char)(bln[i]+48);
		}
		sort(comb, comb+n);
		sort(val, val+n);
		// for(int i=0; i<n; i++){
		// 	cout<<comb[i]<<endl;
		// }
		int i = 0, j;

		while(i<n){
			count0 = count1 = 0;
			j = i;
			while(j<n){
				int temp_len = comb[i].length();
				if(val[i] == comb[j].substr(0, temp_len -2)){
					if(comb[j].substr(temp_len - 1, temp_len) == "0"){
						count0++;
					}
					else{
						count1++;
					}
				}
				else{
					//cout<<count0<<" "<<count1<<endl;
					i = j;
					break;
				}
				j++;
			}
			i = j;
			count += max(count0, count1);
			cout<<count<<endl;
			//cout<<val[j];
		}

		// while(i<n){
		// 	int temp_len = comb[i].length();
		// 	cout<<temp_len<<endl;
		// 	while( val[i] == comb[i].substr(0, temp_len -2)){
		// 		if(comb[i].substr(temp_len - 1, temp_len) == "0"){
		// 			count0++;
		// 			cout<<"here"<<endl;
		// 		}
		// 		else{
		// 			count1++;
		// 			cout<<"here1"<<endl;
		// 		}
		// 		i++;
		// 	}
		// 	count += max(count0, count1);
		// 	count0 = count1 = 0;
		//}
		cout<<count<<endl;
	}
}

