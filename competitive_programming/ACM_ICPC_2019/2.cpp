#include <iostream>
#include <math.h>

using namespace std;

int removeIndex(int num, int index){
	int temp = num, array[10], count=0, newNumber = 0;
	for(int i=0; temp>0; i++){
		array[i] = temp % 10;
		temp /= 10;
		count++;
	}
	for(int i = index; i< count -1; i++){
		array[i] = array[i+1];
	}	
	count--;
	// for(int i=0; i<count; i++){
	// 	cout<<array[i]<<" ";
	// }
	// cout<<endl;
	for(int i=0; i<count;i++){
		newNumber += array[i]*(pow(10,i));
	}
//	cout<<"newNumber : "<<newNumber<<"\n";
	return newNumber;
}

int numofDigit(int num){
	int count = 0;
	while(num>0){
		count++;
		num/=10;
	}
	return count;
}

int main(){
	int t, n, temp;
	int numDigit;
	cin>>t;
	while(t--){
		cin>>n;
		numDigit = numofDigit(n);
		int min = n;
		for(int i=0; i<numDigit; i++){
			temp = removeIndex(n, i);
			//cout<<temp<<endl;
			if(temp < min){
				min = temp;
			}
		}
		cout<<min<<endl;
	}
}
