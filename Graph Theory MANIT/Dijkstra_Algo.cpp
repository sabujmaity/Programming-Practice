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

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		vector<int> result(V, INT_MAX);
		result[S] = 0;
		pq.push({0, S});
		while(!pq.empty()) {
		    int d  = pq.top().first;
		    int node = pq.top().second;
		    pq.pop();
		    for(auto &vec : adj[node]) {
			int adjNode = vec[0];
			int dist = vec[1];
			if(d + dist < result[adjNode]) {
			    result[adjNode] = d + dist;
			    pq.push({d+dist, adjNode});
			}
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
    vector<vector<int>> adj[V];
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    int S;
    cin >> S;
    vector<int> result = dijkstra(V, adj, S);
    for (int i = 0; i < V; i++) {
        if (result[i] == INT_MAX)
            cout << "Node " << i << ": INF\n";
        else
            cout << "Node " << i << ": " << result[i] << "\n";
    }

    return 0;

    

    
    

}