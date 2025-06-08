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


const long long MAX_POSSIBLE_K = numeric_limits<long long>::max(); 

signed main() {
    IOS;
    
    int t; 
    std::cin >> t;
    while (t--) {
        int n; 
        int M; 
        cin >> n >> M;
        
        
        vector<long long> a(n + 1); 
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        
        std::vector<long long> b(M + 1); 
        for (int i = 1; i <= M; ++i) {
            cin >> b[i];
        }
        
        vector<int> L(M + 1);
        L[0] = 0;
        int current_a_idx = 1; 
        
        for (int i = 1; i <= M; ++i) {
            bool found = false;
            while (current_a_idx <= n) {
                if (a[current_a_idx] >= b[i]) {
                    L[i] = current_a_idx;
                    found = true;
                    current_a_idx++; 
                    break; 
                }
                current_a_idx++; 
            }
            if (!found) {
                for (int j = i; j <= M; ++j) {
                    L[j] = n + 1; 
                }
                break; 
            }
        }

        if (L[M] <= n) {
            cout << 0 << nline; 
            continue; 
        }
        
        vector<int> R(M + 2); 
        R[M + 1] = n + 1; 
        current_a_idx = n; 
        
        for (int i = M; i >= 1; --i) {
            bool found = false;
            while (current_a_idx >= 1) {
                if (a[current_a_idx] >= b[i]) {
                    R[i] = current_a_idx;
                    found = true;
                    current_a_idx--; 
                    break; 
                }
                 current_a_idx--; 
            }
            if (!found) {
                 for (int j = i; j >= 1; --j) {
                     R[j] = 0; 
                 }
                 break;
            }
        }
        
       
        long long min_k = MAX_POSSIBLE_K; 
        bool possible = false; 
        for (int i = 1; i <= M; ++i) {
             if (L[i-1] < R[i+1]) {
                 min_k = min(min_k, b[i]); 
                 possible = true; 
             }
        }
        
        if (possible) {
            cout << min_k << nline; 
        } else {
            cout << -1 << nline;
        }
    }
    return 0;
}