#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define nline '\n'

char func( int i , int j , int r , int c){
    if(i<r/2)
    return '*';
    else return '.';
}
signed main(){
    int r, c;
    cin >> r >> c;
    for( int i = 0; i < r; ++i){
        for ( int j = 0; j < c; ++j){
            cout << func(i, j , r, c);
        }
        cout << nline;
    }
    return 0;
}

