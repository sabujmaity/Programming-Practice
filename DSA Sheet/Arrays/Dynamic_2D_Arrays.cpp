#include<bits/stdc++.h>
using namespace std;

#define fo(i,n) for(i=0;i<n;i++)
#define pb push_back
#define F first
#define S second
typedef long long ll;
typedef long double ld;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif
    int row , col;
    cin >> row >> col;
    int * * arr = new int * [row];
    for ( int i = 0; i < row; i++ ){
        arr[i] = new int [col];
        for ( int j = 0; j < col; j++){
            cin >> arr[i][j];
        }
    }
    int i;
    fo(i,row){
        int j;
        fo(j,col){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    // Always deallocate the memory allocated dynamically
    int k;
    fo(k,row){
        delete [ ] arr[k];
    }
    delete arr;
    
    

}