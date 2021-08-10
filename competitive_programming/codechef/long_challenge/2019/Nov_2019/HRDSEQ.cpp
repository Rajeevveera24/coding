#include <iostream>
using namespace std;
#define MAX 130

int seq[MAX];
// int count[MAX];

int isPresent(int a[], int num, int size){
    for(int i=size-1; i>=1; i--){
        if(a[i] == num){
            return i;
        }
    }
    return 0;
}

void generateSequence(){
    seq[1] = 0;
    seq[2] = 0;
    int i,j=1,l;
    // for(int i=0; i<=MAX; i++){
    //     count[i] = 0;
    // }
    // count[0] = 2;
    for(int i=2; i<MAX; i++){
        if( (l = isPresent(seq, seq[i] , i)) > 0){
            seq[i + 1] = i - l;
            // printf("Here");
        }
        else{
            seq[i + 1] = 0;
        }
    }
}

int count(int n){
    int c = 0;
    for(int i=1; i<=n; i++){
        if(seq[i] == seq[n]){
            c++;
        }
    }
    return c;
}

int main() {
    generateSequence();
    int n, t, x;
    cin >> t;
    while(t--){
        cin >> n;
        int x = count(n);
        cout << x << endl;
    }
	// for(int i=1; i<MAX; i++){
	//     cout<<seq[i]<<" ";
	// }
	// cout<<count[2]<<endl;
	return 0;
}