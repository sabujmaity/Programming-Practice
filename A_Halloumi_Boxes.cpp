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
    int n, k; cin >> n >> k;
    vector<int> input(n);
    for( int i = 0; i < n; ++i){
        cin >> input[i];
    }

    int flag = 1;
    for( int i = 1 ; i < n; ++i){
        if(input[i]<input[i-1] && k < 2){
            flag = 0;
            break;
        }
    }
    if(flag) cout << "YES" <<nline;
    else cout <<"NO" << nline;
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