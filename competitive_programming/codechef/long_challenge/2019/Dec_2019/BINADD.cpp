#include <iostream>
#include <stdlib.h>

using namespace std;

int max(int a, int b){
    return (a>b)?a:b;
}

bool greta(char b[], int len){
    for(int i=len-1; i>=0; i--){
        if(b[i] == '1'){
            return true;
        } 
    }
    return false;
}

int main() {
    int t, n, len;
    string a,b;
    char a1[200000], b1[200000], v[200000];
    cin>>t;
    while(t--){
        cin>>a;
        cin>>b;
        int len = max(a.length(), b.length());
        int k=0;
        if(len > a.length()){
            int dif = len - a.length();
            for(int i=0; i<dif; i++){
                a1[i] = '0';
            }
            k = 0;
            for(int i=dif; i<len; i++){
                a1[i] = a[k++];
            }
            for(int i=0; i<len; i++){
                b1[i] = b[i];
            }
        }
        else{
            int dif = len - b.length();
            for(int i=0; i<dif; i++){
                b1[i] = '0';
            }
            k = 0;
            for(int i=dif; i<len; i++){
                b1[i] = b[k++];
            }
            for(int i=0; i<len; i++){
                a1[i] = a[i];
            }
        }
        k = 0;
        while(greta(b1, len)){
            k++;
            for(int i=0; i<len; i++){
                if((a1[i] == b1[i]) && (a1[i] == '1')){
                    v[i] = '1';
                }
                else{
                    v[i] = '0';
                }
            }
            for(int i=0; i<len; i++){
                if(a1[i] == b1[i]){
                    a1[i] = '0';
                }
                else{
                    a1[i] = '1';
                }
            }
            // for(int i=0; i<len; i++){
            //     if((a1[i] == b1[i]) && (a1[i] == '1')){
            //         v[i] = '1';
            //     }
            //     else{
            //         v[i] = '0';
            //     }
            // }
            // for(int i=0; i<len; i++){
            //     // v[i] = ((a1[i] & b1[i]) == 1) ? '1' : '0';
            //     a1[i] = u[i];
            // }
            len++;
            b1[len-1] = '0';
            for(int i=0; i<len-1; i++){
                b1[i] = v[i];
            }
            for(int i=len-1; i>=0; i--){
                a1[i+1] = a1[i];   
            }
            a1[0] = '0';
            // for(int i=0; i<len; i++){
            //     cout<<a1[i];
            // }
            // cout<<'\t';
            // for(int i=0; i<len; i++){
            //     cout<<b1[i];
            // }
            // cout<<'\t';
            // for(int i=0; i<len; i++){
            //     cout<<u[i];
            // }
            // cout<<'\t';
            // for(int i=0; i<len; i++){
            //     cout<<v[i];
            // }
            // // cout<<'\t';
            // cout<<endl;
        }
        cout<<k<<endl;
    }
    return 0;
}