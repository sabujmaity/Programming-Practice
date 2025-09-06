#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

long long power(long long base, long long exp) {
    long long res = 1;
    long long mod = 998244353;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

void solve() {
    int n;
    long long m, V;
    cin >> n >> m >> V;

    vector<long long> a(n + 1);
    int unknown_count = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == -1) {
            unknown_count++;
        }
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (m == n - 1) {
        cout << power(V, unknown_count) << endl;
        return;
    }

    bool is_bipartite = true;
    vector<int> color(n + 1, 0); // 0: uncolored, 1: color 1, 2: color 2
    bool possible = true;

    function<void(int, int)> bipartite_check_dfs = [&](int u, int c) {
        color[u] = c;
        for (int v : adj[u]) {
            if (color[v] == 0) {
                bipartite_check_dfs(v, 3 - c);
            } else if (color[v] == color[u]) {
                is_bipartite = false;
            }
        }
    };

    for (int i = 1; i <= n; ++i) {
        if (color[i] == 0) {
            bipartite_check_dfs(i, 1);
        }
    }

    if (is_bipartite) {
        long long c_val = -1;
        bool conflict = false;
        for (int i = 1; i <= n; ++i) {
            if (a[i] != -1) {
                if (c_val == -1) {
                    c_val = a[i];
                } else if (c_val != a[i]) {
                    conflict = true;
                    break;
                }
            }
        }
        if (conflict) {
            cout << 0 << endl;
        } else {
            if (c_val != -1) {
                cout << 1 << endl;
            } else {
                cout << V % 998244353 << endl;
            }
        }
    } else { // Not bipartite
        bool conflict = false;
        for (int i = 1; i <= n; ++i) {
            if (a[i] != -1 && a[i] != 0) {
                conflict = true;
                break;
            }
        }
        if (conflict) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}