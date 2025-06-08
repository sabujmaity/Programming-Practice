#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g; //Global Adjacency list to store Graph
vector < int > vis; // maintainig the visited array to take a note of visited node

void DFS(int source){
    vis[source] = 1;
    for(auto v : g[source]){
        if(!vis[v])
            DFS(v);
    }
}

void solve(){
    int n,m;
    cin >> n >> m ;
    g.resize(n+1);
    for(int i = 0; i < m; ++i){
        int u,v; //Undirected Edge 
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for ( int i = 1; i <=n; ++i){
        vis.assign(n+1,0); // Default values set to = 0
        DFS(i);
        int count = 0;
        for( auto it: vis){
            count+=it;
            cout << count << '\n';
        }
    }

}

int main(){

}