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
const int mod = 1e9+7;

vll primes;
bool isprime[90000001]; // as it is a global array so by default false values
// Why using bool ? - It takes one Byte rather than int so the processing will be faster is online judges
void sieve(){
    int maxN = 90000000;
    isprime[0]=isprime[1] = true;
    for( int i = 2; i*i<= maxN; i++ ){
        if(!isprime[i]){
            for(int j = i*i; j <=maxN; j+=i){
                isprime[j] = true;
            }
        }
    }
    for( int i = 2; i<=maxN; i++){
        if(!isprime[i]){
            primes.push_back(i);
        }
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
    sieve();
    while(t--){
        int n; cin >> n;
        cout << primes[n-1] << nline;
    }


}