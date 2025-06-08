#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int spanningTree(int V, vector<vector<int>> adj[]) {
		priority_queue<pair<int, int>,
		               vector<pair<int, int>>, greater<pair<int, int>>> pq;

		vector<int> vis(V, 0);
		vector<int> parent(V, -1); // To track MST edges
		pq.push({0, 0}); // {weight, node}

		int sum = 0;

		while (!pq.empty()) {
			auto it = pq.top();
			pq.pop();
			int node = it.second;
			int wt = it.first;

			if (vis[node]) continue;

			vis[node] = 1;
			sum += wt;

			// Print the edge if it's not the starting node
			if (parent[node] != -1) {
				cout << "Edge: " << parent[node] << " - " << node << " with weight " << wt << endl;
			}

			for (auto adjIt : adj[node]) {
				int adjNode = adjIt[0];
				int edgeWeight = adjIt[1];
				if (!vis[adjNode]) {
					pq.push({edgeWeight, adjNode});
					// Only update parent if not visited to preserve MST structure
					if (parent[adjNode] == -1 || edgeWeight < pq.top().first)
						parent[adjNode] = node;
				}
			}
		}

		return sum;
	}
};

int main() {
	int V = 5;
	vector<vector<int>> edges = {
		{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, 
		{2, 3, 2}, {3, 4, 1}, {4, 2, 2}
	};

	vector<vector<int>> adj[V];

	for (auto it : edges) {
		vector<int> tmp(2);
		tmp[0] = it[1];
		tmp[1] = it[2];
		adj[it[0]].push_back(tmp);

		tmp[0] = it[0];
		tmp[1] = it[2];
		adj[it[1]].push_back(tmp);
	}

	Solution obj;
	int sum = obj.spanningTree(V, adj);
	cout << "The sum of all the edge weights: " << sum << endl;

	return 0;
}
