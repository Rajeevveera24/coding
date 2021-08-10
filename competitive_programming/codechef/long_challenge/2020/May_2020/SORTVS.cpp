#include<bits/stdc++.h> 
  
using namespace std; 
  
int minSwaps(int arr[], int n) { 
    
    pair<int, int> arrPos[n]; 
    
    for (int i = 0; i < n; i++) { 
        arrPos[i].first = arr[i]; 
        arrPos[i].second = i; 
    } 
  
    sort(arrPos, arrPos + n); 
  
    vector<bool> vis(n, false); 
  
    int ans = 0; 
    
    for (int i = 0; i < n; i++) { 
 
        if (vis[i] || arrPos[i].second == i){
            continue; 
        }
            
        int cycle_size = 0; 
        int j = i; 
        while (!vis[j]){ 
            vis[j] = 1; 
            j = arrPos[j].second; 
            cycle_size++; 
        } 
        if (cycle_size > 0){ 
            ans += (cycle_size - 1); 
        } 
    } 
    return ans; 
} 

int main() { 
    int t, p[18], x[18], y[18], n, m;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        memset(p, 0, sizeof(p));
        
        for(int i=0; i<n; i++){
            scanf("%d", &p[i]);
        }
        for(int i=0; i<m; i++){
            scanf("%d %d", &x[i], &y[i]);
        }
        
        if(m == 0){
            cout << minSwaps(p, n) << endl;
        }
        else{
            cout << minSwaps(p, n) << endl;
        }
    }
    return 0; 
}