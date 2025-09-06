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
typedef vector<int> vll; 
typedef vector<vector<int>> vvll; 
const int mod = 1e9+7; 
long double pi = acos(-1.0); const double EPS = 1e-9; 

int myceil(int a , int b){return (a+b-1)/b;} 
int myround(int a , int b){return (2*a+b)/(2*b);} 

void solve(){ 
    int n, k;
    cin >> n >> k; 
    string s; cin >> s;
    
    vll p(n + 1, 0);
    set<int> bnd;
    bnd.insert(0);
    bnd.insert(n + 1);
    set<int> cd;
    vector<int> op;
    for(int i = 0; i < n; ++i){
        if(s[i] == '0'){
            cd.insert(i + 1);
        }else {
            op.push_back(i + 1);
        }
    }
    if (n < k) {
        for(int pos : op) {
            cd.insert(pos);
        }
    }
    for(int v = n; v >= 1; --v) {
        if (cd.empty()) {
            cout << "NO" <<nline;
            return;
        }
        int x = *cd.begin();
        cd.erase(cd.begin());
        p[x] = v;
        auto itr = bnd.lower_bound(x);
        int R = *itr;
        int L = *(--itr);
        bnd.insert(x);
        if (R - L - 1 >= k) {
            if (x - L - 1 < k) {
                auto sit = upper_bound(op.begin(), op.end(), L);
                auto eit = lower_bound(op.begin(), op.end(), x);
                for(auto it = sit; it != eit; ++it) {
                    cd.insert(*it);
                }
            }
            if (R -x - 1 < k) {
                auto sit = upper_bound(op.begin(), op.end(), x);
                auto eit = lower_bound(op.begin(), op.end(), R);
                for(auto it = sit; it != eit; ++it) {
                    cd.insert(*it);
                }
            }
        }
    }
    cout << "YES" << nline;
    for(int i = 1; i <= n; ++i) {
        cout << p[i] << " ";
    }
    cout << nline;
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
    return 0;
}