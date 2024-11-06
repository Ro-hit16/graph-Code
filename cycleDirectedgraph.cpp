  bool dfsCycle(int node, unordered_map<int, bool>& visited,
              unordered_map<int, bool>& Dfsvisited, vector<vector<int>>& adj) {
    visited[node] = true;
    Dfsvisited[node] = true;
    
    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            bool cycledfs = dfsCycle(neighbour, visited, Dfsvisited, adj);
            if (cycledfs) {
                return true;
            }
        } else if (Dfsvisited[neighbour]) {
            return true;
        }
    }
    
    Dfsvisited[node] = false; 
    return false;
}

bool isCyclic(int V, vector<vector<int>> adj) {
    unordered_map<int, bool> visited;
    unordered_map<int, bool> Dfsvisited;
    
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            bool cycle = dfsCycle(i, visited, Dfsvisited, adj);
            if (cycle) {
                return true;
            }
        }
    }
    return false;
}
