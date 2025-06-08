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

struct DSU {
    vector<int> parent;
    vector<long long> sz;

    DSU(int count) {
        parent.resize(count + 1);
        iota(parent.begin(), parent.end(), 0); 
        sz.assign(count + 1, 0);
    }

    int find(int p) {
        if (parent[p] == p) {
            return p; 
        }
        return parent[p] = find(parent[p]);
    }

    void unite(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        
        if (rootP != rootQ) {
            if (sz[rootP] < sz[rootQ]) {
                swap(rootP, rootQ);
            }
            parent[rootQ] = rootP; 
            sz[rootP] += sz[rootQ]; 
        }
    }
};

signed main() {
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        DSU dsu(2 * n);
        
        vector<bool> is_one(n + 1, false); 
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                is_one[i + 1] = true;
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (is_one[i]) {
                dsu.sz[i] = 1; 
            } else {
                if (i > 1) {
                    dsu.sz[i] = (long long)i - 1;
                }
                if (i < n) {
                     dsu.sz[i + n] = (long long)n - i;
                }
            }
        }

        for (int j = 1; j < n; ++j) {
            int j_plus_1 = j + 1;
            bool j_is_one = is_one[j];
            bool j_plus_1_is_one = is_one[j_plus_1];

            if (!j_is_one && !j_plus_1_is_one) { 
                 if (j > 1) {
                     int root_j_up = dsu.find(j);
                     int root_j1_up = dsu.find(j_plus_1);
                     if(dsu.sz[root_j_up] > 0 && dsu.sz[root_j1_up] > 0) {
                         dsu.unite(j, j_plus_1);
                     }
                 }
                 if (j_plus_1 < n) {
                     int root_j_down = dsu.find(j + n);
                     int root_j1_down = dsu.find(j_plus_1 + n);
                     if (dsu.sz[root_j_down] > 0 && dsu.sz[root_j1_down] > 0) {
                        dsu.unite(j + n, j_plus_1 + n);
                     }
                 }
            } else if (j_is_one && !j_plus_1_is_one) { 
                 int root_j_diag = dsu.find(j);
                 int root_j1_up = dsu.find(j_plus_1);
                 if(dsu.sz[root_j_diag] > 0 && dsu.sz[root_j1_up] > 0) {
                    dsu.unite(j, j_plus_1);
                 }
            } else if (!j_is_one && j_plus_1_is_one) { 
                 int root_j_down = dsu.find(j + n);
                 int root_j1_diag = dsu.find(j_plus_1);
                 if(dsu.sz[root_j_down] > 0 && dsu.sz[root_j1_diag] > 0) {
                    dsu.unite(j + n, j_plus_1);
                 }
            } 
        }

        long long max_size = 0;
        for (int i = 1; i <= 2 * n; ++i) {
            if (dsu.parent[i] == i && dsu.sz[i] > 0) {
                max_size = max(max_size, dsu.sz[i]);
            }
        }

        cout << max_size << nline;
    }
    return 0;
}
