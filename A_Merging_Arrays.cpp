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


int main(){
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    int size1, size2;
    cin >> size1 >> size2;
    int input[size1], input2[size2];

    for( int i = 0 ; i < size1; i++){
        cin >> input[i];
    }

    for( int j = 0; j < size2; j++){
        cin >> input2[j];
    }

    int left = input[0], right = input2[0];
    

    
    

}