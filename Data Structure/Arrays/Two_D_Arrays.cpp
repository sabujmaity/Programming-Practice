#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

int great(unsigned int x,unsigned int y){
    if(x-y>0){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    int a[100][100];
    int row , col;
    cin >> row >> col;
    // Taking input 
    for ( int i = 0; i < row ; ++i){
        for ( int j = 0; j < col; ++j){
            cin >> a[i][j];
        }
    }

    
    

}