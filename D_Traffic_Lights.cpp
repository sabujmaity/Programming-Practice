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
const int INF = 1e18;
long double pi = acos(-1.0);

void solve(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> g[n + 1];
    vector<int> deg(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u>> v;
        deg[u]++;deg[v]++;
        g[u].push_back({v, deg[u]});
        g[v].push_back({u, deg[v]});
    }
    vector<vector<int>> dest(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (deg[i] > 0) {
            dest[i].resize(deg[i] + 1);
            for (auto const& edge : g[i]) {
                dest[i][edge.second] = edge.first;
            }
        }
    }

    vector<vector<pair<int,int>>> cst(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (deg[i] > 0) {
            cst[i].resize(deg[i], {INF, INF});
        }
    }
    priority_queue<tuple<int, int, int, int>,vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> q;
    if (n == 1){
        cout << "0 0" << nline;
        return;
    }
    if (deg[1] > 0) {
        cst[1][0] = {0, 0};
        q.push({0, 0, 1, 0});
    }

    while (!q.empty()) {
        auto [t, w, u, r] = q.top();
        q.pop();

        if (make_pair(t, w) > cst[u][r]) {
            continue;
        }
        int nxt = t + 1,nxt1 = w + 1,nxt2 = (r + 1) % deg[u];
        
        if (make_pair(nxt,nxt1) <cst[u][nxt2]) {
            cst[u][nxt2] = {nxt, nxt1};
            q.push({nxt, nxt1, u, nxt2});
        }

        int neigh = dest[u][r + 1];
        if (deg[neigh] > 0) {
            int mvt = t + 1,rmv = w,rmv1 = mvt % deg[neigh];

            if (make_pair(mvt, rmv) < cst[neigh][rmv1]) {
                cst[neigh][rmv1] = {mvt, rmv};
                q.push({mvt, rmv, neigh, rmv1});
            }
        }
    }
    pair<int, int> res = {INF, INF};
    if (deg[n] > 0) {
        for (const auto& cost : cst[n]) {
            res = min(res, cost);
        }
    }
    cout << res.first << " " << res.second << nline;
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