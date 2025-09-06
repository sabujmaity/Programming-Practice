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
    int n,x; cin >> n >> x;
    vector<int> stops;
    stops.push_back(0);
    for( int i = 0; i < n; ++i){
        int stop; cin >> stop;
        stops.push_back(stop);
    }
    stops.push_back(x);
    n = stops.size();

    int max_dist = INT_MIN;
    for(int i = 1; i < n; ++i){
        if(i == n - 1){
            max_dist = max(max_dist, 2 *(stops[i] - stops[i-1]));
        }
        else{
            max_dist = max(max_dist, stops[i] - stops[i-1]);
        }
    }
    cout << max_dist << nline;
}

signed main(){
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


}