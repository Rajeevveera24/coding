#include <iostream>
using namespace std;

int main() {
	int a,b;
	cin>>a>>b;
	(a-b)%10 == 9 ? cout<<(a-b)-1 : cout << (a-b) + 1; 
	return 0;
}