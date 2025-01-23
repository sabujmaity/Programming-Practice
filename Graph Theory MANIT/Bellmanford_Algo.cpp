#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n" 
#define fo(i,n) for(i=0;i<n;i++)
#define pb push_back
#define F first
#define S second
typedef long long ll;
typedef long double ld;

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> result(V, 1e8);
        result[S] = 0;
        for(int c = 1; c<=V-1; c++) {
            for(auto &edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                if(result[u] != 1e8 && result[u] + w < result[v]) {
                    result[v] = result[u] + w;
                } 
            }
        }
        for(auto &edge : edges) {
            int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(result[u] != 1e8 && result[u] + w < result[v]) {
                    return {-1};
                }
        }
        return result;
    }
int main(){
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif

    int V, E;
    cin >> V >> E;
    vector<vector<int>> edges;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    int S;
    cin >> S;
    vector<int> result = bellman_ford(V, edges, S);
    if (result.size() == 1 && result[0] == -1) {
        cout << "Negative weight cycle detected in the graph.\n";
    } else {
        for (int i = 0; i < V; i++) {
            if (result[i] == 1e8)
                cout << "Node " << i << ": INF\n";
            else
                cout << "Node " << i << ": " << result[i] << "\n";
        }
    }
    return 0;

    
    
}