#include <iostream>
using namespace std;

typedef struct{
    int score;
}sub;
sub s[11];

int main() {
	int t, n, pNum, score;
	cin>>t;
	while(t--){
	    for(int i=0; i<8; i++){
	        s[i].score = 0;
	    }
	    cin>>n;
	    for(int i=0; i<n; i++){
	        cin>>pNum>>score;
	        if(s[pNum - 1].score < score){
	            s[pNum - 1].score = score;
	        }
	    }
	    score = 0;
	    for(int i=0; i<8; i++){
	        score += s[i].score; 
	    }
	    cout<<score<<endl;
	}
	return 0;
}
