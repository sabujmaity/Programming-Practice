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
    int a, b, c, d; cin>> a >>b >>c >> d;
    int r1 = a,k1 =b;
    int r2 = c- a,k2 =d - b;

    bool fposs = (r1<= 2* (k1 + 1))&& (k1 <=2 * (r1 + 1));
    bool secposs = (r2 <= 2 * (k2 + 1)) &&(k2<= 2 *(r2 + 1));

    if (fposs && secposs) {
        cout << "YES"<< nline;
    }else{
        cout <<"NO" << nline;
    }
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