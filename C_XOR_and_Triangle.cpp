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

void solve(){
    int  x ; cin >> x;
    // int othery = -1;
    int y = x-1;
    while(y>0){
        int z = x ^ y;
        if( z > 0 && x + y > z && x + z > y && y+z >x ){
            //othery = y;
            //break;
            cout << y << nline;
            return;
        }
        y--;
    }
    cout << -1 << nline;
}


int main(){
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    //Let's Code
    int t;
    cin>>t;
    while(t--){
       solve();
    }
    return 0;

}