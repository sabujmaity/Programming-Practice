#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int node, int parent, const vector<vector<int>>& tree, vector<int>& depth, vector<int>& parent_arr) {
    for (int child : tree[node]) {
        if (child != parent) {
            depth[child] = depth[node] + 1;
            parent_arr[child] = node;
            dfs(child, node, tree, depth, parent_arr);
        }
    }
}

ll dfs_subtree(int node, int parent, const vector<vector<int>>& tree, const vector<int>& A, vector<ll>& subtree_sum) {
    ll sum = A[node];
    for (int child : tree[node]) {
        if (child != parent) {
            sum += dfs_subtree(child, node, tree, A, subtree_sum);
        }
    }
    subtree_sum[node] = sum;
    return sum;
}

ll solve(int N, int K, vector<int>& A, vector<pair<int,int>>& edges) {
    vector<vector<int>> tree(N);
    for (auto& e : edges) {
        int u = e.first - 1, v = e.second - 1;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // Find all leaves
    vector<int> leaves;
    for (int i = 1; i < N; ++i) { // skip root
        if (tree[i].size() == 1)
            leaves.push_back(i);
    }

    // Sort leaves by their value (smallest first)
    sort(leaves.begin(), leaves.end(), [&](int x, int y) {
        return A[x] < A[y];
    });

    // For up to K smallest leaves, reattach them to root
    int changes = min(K, (int)leaves.size());
    set<pair<int,int>> edge_set(edges.begin(), edges.end());
    for (int i = 0; i < changes; ++i) {
        int leaf = leaves[i];
        int prev_parent = -1;
        for (int nb : tree[leaf]) {
            prev_parent = nb;
        }
        // Remove old edge
        tree[leaf].erase(find(tree[leaf].begin(), tree[leaf].end(), prev_parent));
        tree[prev_parent].erase(find(tree[prev_parent].begin(), tree[prev_parent].end(), leaf));
        // Add new edge to root (node 0)
        tree[leaf].push_back(0);
        tree[0].push_back(leaf);
    }

    // Recalculate subtree sums
    vector<ll> subtree_sum(N, 0);
    dfs_subtree(0, -1, tree, A, subtree_sum);

    // The answer is the sum of all subtree sums
    ll total = accumulate(subtree_sum.begin(), subtree_sum.end(), 0LL);
    return total;
}

int main() {
    int T; cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        vector<pair<int,int>> edges;
        for (int i = 0; i < N-1; ++i) {
            int u, v; cin >> u >> v;
            edges.emplace_back(u, v);
        }
        cout << solve(N, K, A, edges) << endl;
    }
    return 0;
}
