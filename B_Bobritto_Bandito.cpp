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


signed main(){
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    //Let's Code
    int t;
    cin>>t;
    while (t--) {
        int n, m, l, r;
        cin >> n >> m >> l >> r;

        bool found = false;

        // Try l' from l to r - m
        for (int l_prime = l; l_prime <= r - m; ++l_prime) {
            int r_prime = l_prime + m;

            // Check 0 must be in [l', r']
            if (l_prime <= 0 && r_prime >= 0) {
                // And [l', r'] is inside [l, r]
                if (l_prime >= l && r_prime <= r) {
                    cout << l_prime << " " << r_prime << endl;
                    found = true;
                    break;
                }
            }
        }

        // This branch shouldn't hit due to constraints, but safe fallback
        if (!found) {
            cout << "0 0" << endl;
        }
    }

    return 0;
}