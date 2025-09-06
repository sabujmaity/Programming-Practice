#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nline '\n'

void func( int i , int j, int c, int r){
    if(i + j>=(c/2) && i>= j-(c/2))
    cout << '*';
    //else if(i == j-3) cout << "*";
    else cout << " ";
}

signed main(){
    int r,c; cin >> r >> c;
    for( int i =0; i < r; ++i){
        for( int j = 0 ; j < c; ++j){
            func(i,j,r,c);
        }
        cout << nline;
    }
    return 0;
} 