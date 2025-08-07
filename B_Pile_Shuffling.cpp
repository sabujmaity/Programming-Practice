#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define nline "\n" 
#define fo(i,n) for(int i = 0;i<n;i++)
#define int long long
#define pb push_back
#define F first
#define S second
typedef long double ld;
typedef vector<signed> vi;
typedef vector<vector<signed>> vvi;
typedef vector<int> vll;
typedef vector<vector<int>> vvll;
const int mod = 1e9+7;
long double pi = acos(-1.0);

void solve(){
    int n;
    cin >> n;

    int tot = 0;

    for (int i = 0; i < n; ++i) {
        int a, b, c, d;
        cin >>a >> b >>c >> d;
        if (b > d) {
            tot += a + (b - d);
        }
        
        else if (a > c) {
            tot += a-c;
        }
    }
    cout << tot << nline;
}

signed main(){
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    
    int t;
    cin>>t;
    while(t--){
        solve();

    }


}