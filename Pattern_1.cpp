#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define nline "\n" 
#define fo(i,n) for(int i = 0;i<n;i++)
#define pb push_back
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;

void print_pattern( int i , int  j , int row, int col){
    if(i+j == 5){
        cout << "*";
    }
    else{
        cout <<" ";
    }

}

int main(){
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    int row, col;
    cin >> row >> col;
    for ( int i = 0; i < row ; i++){
        for ( int j = 0; j < col; j++){
            print_pattern( i , j , row, col);
        }
        cout << nline;
    }

    
    

}