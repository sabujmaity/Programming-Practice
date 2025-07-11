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

void solve(){
    int a,b,x,y;
    cin >>a >> b>> x>> y;

    int mnode = max(a, b)*2 +5;
    
    vll dist(mnode, 1e18); 
    
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>>pq;

    dist[a] = 0;
    pq.push({0, a});

    int min_cost = -1;

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) {
            continue;
        }
        if (u==b) {
            min_cost =d;
            break;
        }
        int v1 = u + 1;
        if (v1 < mnode) {
            if (dist[u] + x < dist[v1]){
                dist[v1] = dist[u] + x;
                pq.push({dist[v1], v1});
            }
        }
        int v2 = u ^1;
        if (v2>= 0 && v2 < mnode) {
             if (dist[u] +y < dist[v2]){
                dist[v2]= dist[u] + y;
                pq.push({dist[v2],v2});
            }
        }
    }

    cout << min_cost <<nline;
}

signed main(){
    IOS;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}