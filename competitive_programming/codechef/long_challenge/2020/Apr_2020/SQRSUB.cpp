#include <iostream>

using namespace std;

long check(int a[], long s, long e){
    
    if(s >= e){
        return 0;
    }
    long start = s;
    long m = -1, end = -1;
    long count = 0;
    
    for(int i=s; i < e; i++){
        if(!(a[i] % 2 != 0 || a[i] % 4 == 0)){
            if(m == -1){
                m = i;
            }
            else{
                end = i;
                count += (m - (start - 1)) * (end - m);
                start = m + 1;
                m = end;
            }
        }
    }
    
    if(m == -1){
        return 0;
    }
    
    count += (m - (start - 1)) * (e - m);
    
    return count;
}

int main(){
    
    int t, a[100000];
    long n;
    long start, end;
    
    long count;
    
    scanf("%d", &t);
    
    while(t--){
        
        scanf("%ld", &n);
        
        for(int i=0; i<n; i++){
            scanf("%d", &a[i]);
            a[i] %= 4;
        }
        
        start = 0;
        end = -1;
        count = 0;
        
        for(int i = 0; i < n; i++){
            if(a[i] == 0){
                end = i;
                count += check(a, start, end);
                start = end + 1;
            }
        }
        
        count += check(a, start, n);
        
        count = n*(n+1) / 2 - count;
        
        cout << count << endl;
    }
    
    return 0;
}
// #include <iostream>

// using namespace std;

// bool checkDiffSquare(int a){
//     return (a % 4 != 2);
// }

// int main(){
//     int t, n, a[100000];
//     int count;
//     long long int prod;
//     scanf("%d", &t);
//     while(t--){
        
//         scanf("%d", &n);
        
//         for(int i=0; i<n; i++){
//             scanf("%d", &a[i]);
//             a[i] %= 4;
//         }
        
//         count = 0;
//         // count1 = 0;
        
//         for(int i=0; i <= n-1; i++){
//             prod = a[i];
//             if(prod %  2 != 0 || prod % 4 == 0){
//                 count++;
//             }
//             for(int j = i+1; j <= n-1; j++){
//                 prod = prod * a[j];
//                 prod %= 4;
//                 if(prod %  2 != 0 || prod % 4 == 0){
//                     count++;
//                 }
//             }
//         }
        
//         cout << count << endl;
//     }
//     return 0;
// }