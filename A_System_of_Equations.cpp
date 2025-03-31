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
    long long n,m; cin >> n >> m;
    int ans = 0;
    // a^2 + b now a can have max sqrt(a) value
    for( ll i = 0; i*i <=n; i++){
        for ( ll j = 0 ; j*j <=m ; j++){
            if( ((i*i+j) == n) && ((j*j+i)==m))
                ans++;
        }
    }
    cout << ans;

    return 0;

    
    

}