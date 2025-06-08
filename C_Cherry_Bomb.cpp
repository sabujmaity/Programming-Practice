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


signed main() {
    IOS;
    
    int t;
    cin >> t;
    
    while (t--) { 
        int n;
        int k;
        cin >> n >> k;
        
        vector<int> a(n); 
        vector<int> b(n); 
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        int min_x = 0;      
        int max_x = 2 * k;  
        
        int fixed_x = -1; 
        bool possible = true; 

        for (int i = 0; i < n; ++i) {
            int current_min_x = a[i];
            int current_max_x = a[i] + k;
            
            min_x = max(min_x, current_min_x);
            max_x = min(max_x, current_max_x);

            if (b[i] != -1) {
                int x_req = a[i] + b[i];
                
                if (fixed_x == -1) {
                    fixed_x = x_req;
                } 
                else if (fixed_x != x_req) {
                    possible = false;
                }
            }
        }

        if (!possible) {
            cout << 0 << nline;
        } 
        else {
            if (fixed_x != -1) {
                if (fixed_x >= min_x && fixed_x <= max_x) {
                    cout << 1 << nline;
                } else {
                    cout << 0 << nline;
                }
            } 
            else { 
                if (min_x > max_x) {
                    cout << 0 << nline;
                } else {
                    cout << max_x - min_x + 1 << nline;
                }
            }
        }
    }
    return 0;
}
