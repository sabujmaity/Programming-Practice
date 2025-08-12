#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

const int INF = 1e9 + 7;
vector<int> adj[100005];
int n;

vector<int> down_paths[100005];
int up_path[100005];
int dp_small[100005];
int dp_big[100005];
bool found_path;

// DFS to compute longest downward paths from each node's children
void dfs_down(int u, int p) {
    down_paths[u].clear();
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs_down(v, u);
        down_paths[u].push_back(1 + down_paths[v][0]);
    }
    sort(down_paths[u].rbegin(), down_paths[u].rend());
    if (down_paths[u].empty()) {
        down_paths[u].push_back(0);
    }
}

// DFS to compute the longest upward path from each node
void dfs_up(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        int u_d1 = down_paths[u][0];
        // If v is on the longest downward path from u, use the second-longest
        if (1 + down_paths[v][0] == u_d1) {
            up_path[v] = 1 + max(up_path[u], (down_paths[u].size() > 1 ? down_paths[u][1] : 0));
        } else { // Otherwise, use the longest
            up_path[v] = 1 + max(up_path[u], u_d1);
        }
        dfs_up(v, u);
    }
}

// DP on Tree to check if a valid path exists for diameter K
void dfs_check(int u, int p, int k) {
    // 1. Gather depths of all branches from node u
    vector<int> branches;
    if (p != 0) branches.push_back(up_path[u]);
    for (int val : down_paths[u]) {
        branches.push_back(val);
    }
    sort(branches.rbegin(), branches.rend());
    while (branches.size() < 4) branches.push_back(0);

    // 2. Determine if u can act as a "small" or "big" node in different roles
    // As an internal node, off-path radius is b_3, diameter is b_3 + b_4
    bool is_small_internal = (branches[2] <= k / 2) && (branches[2] + branches[3] <= k);
    // As an endpoint, off-path radius is b_2, diameter is b_2 + b_3
    bool is_big_endpoint = (branches[1] <= k) && (branches[1] + branches[2] <= k);

    // 3. Recurse on children
    vector<int> small_children, big_children;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs_check(v, u, k);
        if (dp_small[v] != -INF) small_children.push_back(dp_small[v]);
        if (dp_big[v] != -INF) big_children.push_back(dp_big[v]);
    }
    sort(small_children.rbegin(), small_children.rend());
    sort(big_children.rbegin(), big_children.rend());

    // 4. Calculate DP states for u
    dp_small[u] = dp_big[u] = -INF;

    // A small path can start at u only if u can be an endpoint of a small path
    // which isn't explicitly checked, but a small internal node is a stricter condition.
    // Let's assume for a path of one node, it needs to be a "big endpoint"
    if (is_big_endpoint) {
        if (is_small_internal) dp_small[u] = 1;
        dp_big[u] = 1;
    }

    if(is_small_internal) {
         if (dp_small[u] == -INF) dp_small[u] = 1;
         dp_small[u] = max(dp_small[u], 1 + (small_children.empty() ? 0 : small_children[0]));
         dp_big[u] = max(dp_big[u], 1 + (big_children.empty() ? 0 : big_children[0]));
    }
    if (is_big_endpoint) {
        dp_big[u] = max(dp_big[u], 1 + (small_children.empty() ? 0 : small_children[0]));
    }


    // 5. Check if a full valid path can be formed through u
    if (dp_small[u] > 0 || dp_big[u] > 0) found_path = true;
    
    int s1 = small_children.empty() ? 0 : small_children[0];
    int s2 = small_children.size() < 2 ? 0 : small_children[1];
    int b1 = big_children.empty() ? 0 : big_children[0];

    if (is_small_internal && (s1 + s2 + 1 > 1 || (s1 > 0 && p != 0))) found_path = true;
    if (is_big_endpoint && (s1 + s2 + 1 > 1 || (s1 > 0 && p != 0))) found_path = true;
    if (is_small_internal && (s1 + b1 + 1 > 1 || (b1 > 0 && p != 0))) found_path = true;
    if (s1 > 0 && is_big_endpoint && p==0) found_path = true;
}


bool check(int k) {
    if (k < 0) return false;
    found_path = false;
    up_path[1] = 0;
    dfs_down(1, 0);
    dfs_up(1, 0);
    dfs_check(1, 0, k);
    return found_path;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) adj[i].clear();
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    
    dfs_down(1, 0);
    up_path[1] = 0;
    dfs_up(1, 0);
    int initial_diam = 0;
    for(int i = 1; i <= n; ++i) {
        initial_diam = max(initial_diam, up_path[i] + down_paths[i][0]);
    }

    int low = 0, high = initial_diam, ans = initial_diam;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
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