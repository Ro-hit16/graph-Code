id bfs(vector<vector<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans, int node) {
    queue<int> q;
    q.push(node);  // Use push instead of insert for the queue
    visited[node] = true;
    
    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();
        
        ans.push_back(frontNode);  // Use push_back for the vector
        
        for (auto i : adj[frontNode]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> bfsOfGraph(vector<vector<int>> &adj) {
    int n = adj.size();
    vector<int> ans;
    unordered_map<int, bool> visited;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(adj, visited, ans, i);  // Correct parameter order
        }
    }
    
    return ans;
}