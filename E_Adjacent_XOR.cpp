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
    int n;
    cin >>n;
    vll a(n), b(n);
    fo(i, n)cin >> a[i];
    fo(i, n) cin>>b[i];
    if (a[n -1]!= b[n- 1]){
        cout<< "NO"<< nline;
        return;
    }
    bool plr =true;
    for (int i = 0;i < n - 1;++i){
        if (b[i]!= a[i] && b[i] != (a[i] ^a[i+1])){
            plr = false;
            break;
        }
    }

    if(plr){
        cout <<"YES"<< nline;
        return;
    }
    bool prr= true;
    for (int i =n -2; i>= 0;--i) {
        if (b[i]!=a[i] &&b[i] !=(a[i] ^ b[i+1])){
            prr = false;
            break;
        }
    }
    if (prr) {
        cout <<"YES"<< nline;
    } else {
        cout <<"NO"<<nline;
    }
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