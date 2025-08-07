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

int n,k;
vector<int> input;

bool check( int x){
    int lastleft = 0;
    int needed = 0;
    for( int i = 0; i < n ; ++i){
        if(lastleft>=input[i]){
            lastleft -=input[i];
        } else{
            needed++;
            lastleft = x-input[i];
        }
        if(needed>k) return 0;
    }
    if(needed > k ) return 0;
    else return 1;
}

void solve(){
    cin >> n >> k;
    input.resize(n);
    int lo = 0, hi = 0;
    for( int i = 0; i < n; ++i){
        cin >> input[i];
        lo = max(lo,input[i]);
        hi += input[i];
    }
    int ans = 0;
    while(lo <= hi){
        int mid = lo +(hi-lo)/2;
        if(check(mid)){
            ans = mid;
            hi = mid - 1;
        } else{
            lo = mid + 1;
        }
    }
    cout << ans ;
}

signed main(){
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    solve();
    
    
    

}