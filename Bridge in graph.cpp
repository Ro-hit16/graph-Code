#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int u, int parent, vector<int> adj[], vector<int>& visited, vector<int>& discovery, vector<int>& low, int& time, bool& isBridge, int c, int d) {
        visited[u] = 1;
        discovery[u] = low[u] = ++time;
        
        for (int v : adj[u]) {
            if (v == parent) continue; // Skip the parent to avoid backtracking
            if (!visited[v]) {
                dfs(v, u, adj, visited, discovery, low, time, isBridge, c, d);
                low[u] = min(low[u], low[v]);
                
                // Check if edge (u, v) is a bridge
                if (low[v] > discovery[u]) {
                    if ((u == c && v == d) || (u == d && v == c)) {
                        isBridge = true;
                    }
                }
            } else {
                // Update low[u] for back edges
                low[u] = min(low[u], discovery[v]);
            }
        }
    }

    int isBridge(int V, vector<int> adj[], int c, int d) {
        vector<int> visited(V, 0), discovery(V, -1), low(V, -1);
        int time = 0;
        bool isBridge = false;
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1, adj, visited, discovery, low, time, isBridge, c, d);
            }
        }
        
        return isBridge ? 1 : 0;
    }
};
