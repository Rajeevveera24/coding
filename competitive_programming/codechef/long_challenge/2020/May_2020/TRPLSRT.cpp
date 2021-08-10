#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, n, p[2000000], k, out;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i=0; i<n; i++){
            scanf("%d", &p[i]);
        }
        if((n - ((n-1)/2 + 1)) % 2 != 0){
            cout << -1 << endl;
            continue;
        }
        out = (n-1)/2 + ( ( n - ( (n-1)/2 + 1) ) / 2 );
        cout << out << endl;
        
        int  i = 0;
        
        for(; i < (n-1)/2 ; i++){
            printf("%d %d %d\n", i+1, i+2, n-i);
        }
        
        while(i < n-1){
            printf("%d %d %d\n", i+2, i+1, i+3);
            i += 2;
        }
    }
    return 0;
}