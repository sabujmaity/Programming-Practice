#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define nline '\n'

void func( int i, int j, int r, int c){
    if(i+j==5)
    cout << '*';
    /* else if ( j == 2) cout << "."; */
    else cout << ".";
}
signed main(){
    int r, c; cin >> r >> c;
    for( int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            func(i,j,r,c);
        }
        cout << nline;
    }
}