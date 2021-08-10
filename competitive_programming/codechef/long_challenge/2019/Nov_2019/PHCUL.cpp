#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

#define MAX 5000

using namespace std;

double distance1(int a[], int b[]){
	double dist = pow((a[0] - b[0]), 2);
	dist += pow((a[1] - b[1]), 2);
	dist = pow(dist, 0.5);
	return dist;
}
double distance(int a[], int b[], int c[], int d[]){
	double dist = distance1(a, b);
	dist += distance1(b, c);
	dist += distance1(c, d);
	return dist;
}

int main(int argc, char const *argv[])
{
	int t, x[2], n, m, k, a1[MAX][2], a2[MAX][2], a3[MAX][2];
	double dmin, temp;
	cin >> t;
	while(t--){
		cin >> x[0] >> x[1];
		cin>> n >> m >> k;
		for(int i=0; i<n; i++){
			cin >> a1[i][0] >> a1[i][1];
		}
		for(int i=0; i<m; i++){
			cin >> a2[i][0] >> a2[i][1];
		}
		for(int i=0; i<k; i++){
			cin >> a3[i][0] >> a3[i][1];
		}
		dmin = distance(x, a1[0], a2[0], a3[0]);
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				for(int l=0; l<k; l++){
					temp = distance(x, a1[i], a2[j], a3[k]);
					if( dmin > temp){
						dmin = temp;
					}
					temp = distance(x, a2[j], a1[i], a3[k]);
					if( dmin > temp){
						dmin = temp;
					}
				}
			}
		}
		printf("%0.8f\n", dmin);
	}
	// int a[2] , b[2], c[2], d[2];
	// a[0] = 0;
	// b[0] = 0;
	// a[1] = 0;
	// b[1] = 1;
	// c[0] = 0;
	// c[1] = 2;
	// d[0] = 0;
	// d[1] = 3;
	// cout<< distance(a, b, c, d)<<endl;
	return 0;
}