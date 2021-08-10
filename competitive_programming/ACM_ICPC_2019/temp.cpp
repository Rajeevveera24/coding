#include <iostream>
#include <string.h>

using namespace std;

int numofDigit(int num){
	int count = 0;
	while(num>0){
		count++;
		num/=10;
	}
	return count;
}

int main(int argc, char const *argv[]){
	
	//string name  = "Rajeev 1";
	cout<<numofDigit(1092379);
	//cout<<name.substr(0, name.length() - 3)<<endl;

	return 0;
}