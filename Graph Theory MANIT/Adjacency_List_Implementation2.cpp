#include <iostream>
#include <vector>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
      adj[v].push_back(u);
}

void displayAdjList(vector<vector<int>>& adj) {
    for (int i = 0; i < adj.size(); i++) {
        cout << i << ": "; 
        for (int j : adj[i]) {
            cout << j << " "; 
        }
        cout << endl; 
    }
}

int main() {
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif
  
    
    int V = 3;
    vector<vector<int>> adj(V); 

    addEdge(adj, 1, 0);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);

    cout << "Adjacency List Representation:" << endl;
    displayAdjList(adj);

    return 0;
}