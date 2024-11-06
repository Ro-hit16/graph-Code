class Solution
{
    public:
    //Function to find number of strongly connected components in the graph.
    void Dfs1(int node, vector<bool>& visited, vector<vector<int>>& adj, stack<int>& st) {
        visited[node] = true;
        // traverse neighbour
        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                Dfs1(neighbour, visited, adj, st);
            }
        }
        st.push(node);
    }
    
    // for transadj
    void Dfs2(int node, vector<bool>& visited, vector<vector<int>>& adj) {
        visited[node] = true;
        // traverse neighbour
        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                Dfs2(neighbour, visited, adj);
            }
        }
    }
    
    int kosaraju(int V, vector<vector<int>>& adj) {
        stack<int> st;
        vector<bool> visited(V, false);
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                Dfs1(i, visited, adj, st);
            }
        }
        
        // transpose graph
        vector<vector<int>> transadj(V);
        for (int i = 0; i < V; i++) {
            for (int neighbour : adj[i]) {
                transadj[neighbour].push_back(i);
            }
        }
        
        // refill visited with false
        fill(visited.begin(), visited.end(), false);
        int sccCount = 0;
        
        while (!st.empty()) {
            int top = st.top();
            st.pop();
            
            if (!visited[top]) {
                Dfs2(top, visited, transadj);
                sccCount++;
            }
        }
        
        return sccCount;
    }
};
