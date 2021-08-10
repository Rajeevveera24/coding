#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

long long int f(long long int x, long long int y, long long int z){
    return (x&z)*(y&z);
}

int convert(long long int x, int a[]){
    int len = 0;
    while(x != 0){
        a[len] = x%2;
        x /= 2;
        len++;
    }
    return len;
}

long long int reConvert(int a[], int len){
    long long int x = 0;
    for(int i=0; i<len; i++){
        x += a[i]*pow(2,i);
    }
    return x;
}

long long int findNum(int a[], int len, int b[]){
    int c[50];
    for(int i=0; i<len; i++){
        if(a[i] == 1 || b[i] == 1){
            c[i] = 1;
        }
        else{
            c[i] = 0;
        }
    }
    return reConvert(c, len);
}

int main(){
    int t, a[50], b[50], len1, len2, len;
    long long int x, y, z, l, r;
    scanf("%d", &t);
    while(t--){
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        
        cin >> x >> y >> l >> r;
        
        if(x == 0 || y == 0){
            cout << l << endl;
            continue;
        }
        
        len1 = convert(x, a);
        len2 = convert(y, b);
        
        len = (len1 > len2)? (len1):(len2);
        
        long long int z = findNum(a, len, b);
        
        cout << z << endl; 
        
    }
    return 0;
}