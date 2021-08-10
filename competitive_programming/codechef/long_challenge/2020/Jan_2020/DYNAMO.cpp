#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int t, n, temp;
    unsigned long long int a,b,c,d,e,s;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>a;
        s = a + (1 + 1) + 2*( pow(10,n) - 1);
        cout<<s<<endl;
        cin>>b;
        c = s - (a+b) - (1 + (pow(10,n) - 1));
        cout<<c<<endl;
        cin>>d;
        e = s - (a+b+c+d);
        cout<<e<<endl;
        cin>>temp;
        if(temp == 1){
            continue;
        }
        else if(temp == -1){
            exit(0);
        }
    }
	return 0;
}
