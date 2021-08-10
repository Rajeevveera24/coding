#include <iostream>

using namespace std;

bool intersect(int x1, int x2, int y, int x3, int x4, int y3, int y4){	//assumption: x3 < x4, x1 < x2 ...
	
	if(y3 <= y4){
		if(!(y3 <= y && y <= y4)){
			return false;
		}
	}
	else{
		if(!(y4 <=y && y <= y3)){
			return false;
		}
	}

	if(x2 < x3 || x4 < x1){
		return false;
	}

	if(((x1 == x4) && (y == y4)) || ((x2 == x3) && (y == y3)) ){
		return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int x1, x2, y, x3, x4, y3, y4;
	while(true){
		
		printf("Enter x1, x2, y, i, A[i], i+1, A[i+1]: ");
		cin >> x1 >> x2 >> y >> x3 >> y3 >> x4 >> y4;
		
		if(intersect(x1, x2, y, x3, x4, y3, y4)){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
	return 0;
}

