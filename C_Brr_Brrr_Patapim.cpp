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
        cin >> n;

        vector<vector<int>> mat(n + 1, vector<int>(n + 1));
        vector<int> seq(2 * n + 1, -1);
        unordered_set<int> used;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                int x;
                cin >> x;
                mat[i][j] = x;
                int pos = i + j;
                if (pos <= 2 * n && seq[pos] == -1) {
                    seq[pos] = x;
                    used.insert(x);
                }
            }
        }

        int missing = -1;
        for (int i = 1; i <= 2 * n; ++i) {
            if (used.find(i) == used.end()) {
                missing = i;
                break;
            }
        }
        for (int i = 1; i <= 2 * n; ++i) {
            if (seq[i] == -1) {
                seq[i] = missing;
                break;
            }
        }
        for (int i = 1; i <= 2 * n; ++i) {
            cout << seq[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
