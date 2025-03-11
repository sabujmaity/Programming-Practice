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

    vector < ll > freq(14,0);
    for( int i = 0 ; i < 5; i++){
        ll x ; cin >> x;
        freq[x]++;
    }
    // Checking all the pairs whether these two values exist
    for( int i = 1; i <=13; i++){
        for(int j = 1; j<=13; j++){
            if(freq[i]==2 && freq[j]==3){
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";

    
    

}