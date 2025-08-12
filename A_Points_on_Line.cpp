#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define nline "\n" 
#define int long long
#define fo(i,n) for(int i = 0;i<n;i++)
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
    int n, d;
    cin >> n >> d;
    int input[n];
    //vi input(n);
    for( int i = 0; i < n; ++i){
        /* int x; cin >> x;
        input.emplace_back(x); */
        cin >> input[i];
    }

    int ans = 0;
    for( int i = 0; i < n-2 ; ++i){
        int feasible = (upper_bound(input, input+n,input[i]+d)-input)-(i+1);
        ans += feasible * (feasible-1)/2;
    }
    cout << ans << nline;
}


signed main(){
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif
    
    solve();
    
    

}