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
long double pi = acos(-1.0); const double EPS = 1e-9;

int myceil(int a , int b){return (a+b-1)/b;}
int myround(int a , int b){return (2*a+b)/(2*b);}

void solve(){
    int n; cin >> n;
    vll a(n);
    map<int, vll> input;
    fo(i, n){
        cin >>a[i];
    }
    vll dp(n + 1, 0);
    for (int i = 1; i <= n; i++){
        dp[i] = dp[i-1]; int val = a[i-1];
        if (val > 0){
            input[val].pb(i-1);
            if (input[val].size()>= val){
                int start = input[val].size() - val;
                int starti = input[val][start];
                int prev =(starti > 0)?dp[starti] : 0;
                dp[i] = max(dp[i],prev + val);
            }
        }
    }
    cout << dp[n] << nline;
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