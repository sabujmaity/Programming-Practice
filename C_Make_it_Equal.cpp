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
    int n, k;
    cin >> n >> k;
    map<int, int> ccounts;
    fo(i, n) {
        int val;
        cin >>val;
        int rem =val % k;
        ccounts[min(rem,k - rem)]++;
    }
    fo(i, n) {
        int val;
        cin >> val;
        int rem = val % k;
        ccounts[min(rem,k -rem)]--;
    }
    bool poss = true;
    for (auto const& pair :ccounts) {
        if (pair.second != 0) {
            poss = false;
            break;
        }
    }
    if (poss) {
        cout<<"YES"<< nline;
    } else {
        cout <<"NO"<< nline;
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