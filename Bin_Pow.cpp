#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define nline "\n" 
#define fo(i,n) for(int i = 0;i<n;i++)
#define pb push_back
#define F first
#define S second
#define int long long
typedef long double ld;
typedef vector<signed> vi;
typedef vector<vector<signed>> vvi;
typedef vector<int> vll;
typedef vector<vector<int>> vvll;
const int MOD = 1e9+7;

int binpow( int a, int b, int mod){
    if( b == 0){
        return 1;
    } else if( b % 2 == 1){
        return (a*binpow(a,b-1,mod)) % mod;
    } else {
        int temp =  a*a % mod;
        return binpow( temp, b/2, mod) % mod;
    }
}

int inverse( int b, int mod ){
    return binpow( b % mod, mod-2,mod);
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
        int a , b;
        cout << binpow(a % MOD,b,MOD) << nline; // dont take mod of b i.e power blatanly dont take mod
    }


}