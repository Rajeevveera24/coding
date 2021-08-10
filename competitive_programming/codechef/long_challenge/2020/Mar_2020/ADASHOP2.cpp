#include <iostream>
using namespace std;

void gotomainDiagonal(int *r, int *c){
    int x = (*r + *c) /2;
    *r = *c = x;
}

int main() {
	int t, r, c;
	cin >> t;
	while(t--){
	    cin >> r >> c;
	    if(r == 1 && c==1){
	        cout << "25\n";
	        cout <<"2 2\n3 1\n1 3\n2 2\n3 3\n5 1\n1 5\n3 3\n4 4\n7 1\n1 7\n";
	        cout <<"4 4\n5 5\n8 2\n2 8\n5 5\n6 6\n8 4\n4 8\n6 6\n";
	        cout <<"7 7\n8 6\n6 8\n7 7\n8 8\n";
	    }
	    else{
	        int r1 = r, c1 = c;
	        gotomainDiagonal(&r, &c);
	        if(r1 == r && c1 == c){
	            cout << "26\n";
	        }
	        else{
	            cout << "27\n";
	            cout << c << " " << r <<"\n";
	        }
	        cout <<"1 1\n";
	        cout <<"2 2\n3 1\n1 3\n2 2\n3 3\n5 1\n1 5\n3 3\n4 4\n7 1\n1 7\n";
	        cout <<"4 4\n5 5\n8 2\n2 8\n5 5\n6 6\n8 4\n4 8\n6 6\n";
	        cout <<"7 7\n8 6\n6 8\n7 7\n8 8\n";
	    }
	}
	return 0;
}
