class Solution {
public:
    void dfs(int node, unordered_map<int, bool>& visited, stack<int>& s, unordered_map<int, list<pair<int, int>>>& adj) {
        visited[node] = true;
        for (auto neighbour : adj[node]) {
            if (!visited[neighbour.first]) {
                dfs(neighbour.first, visited, s, adj);
            }
        }
        s.push(node);
    }

    void getShortestPath(int src, vector<int>& dist, stack<int>& s, unordered_map<int, list<pair<int, int>>>& adj) {
        while (!s.empty()) {
            int top = s.top();
            s.pop();

            if (dist[top] != INT_MAX) {
                for (auto i : adj[top]) {
                    if (dist[top] + i.second < dist[i.first]) {
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Create adjacency list
        unordered_map<int, list<pair<int, int>>> adj;
        for (auto& i : edges) {
            int u = i[0];
            int v = i[1];
            int weight = i[2];
            adj[u].push_back({v, weight});
        }

       
        unordered_map<int, bool> visited;
        stack<int> s;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, s, adj);
            }
        }

        // Initialize distances
        int src = 0; // Change this to the appropriate source vertex
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Get shortest path distances
        getShortestPath(src, dist, s, adj);

        // Replace INT_MAX with -1 for unreachable nodes
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};