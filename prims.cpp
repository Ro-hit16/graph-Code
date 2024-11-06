#include <iostream>
#include <vector>
#include <set>
#include <utility> // for std::pair
#include <climits> // for INT_MAX

using namespace std;

int spanningTree(int V, vector<vector<int>> adj[]) {
    // Priority queue to select the edge with the minimum weight
    // Using a set to maintain the minimum edge cost
    set<pair<int, int>> st;
    
    // To keep track of the minimum cost for each vertex
    vector<int> minCost(V, INT_MAX);
    // To track if the vertex is included in the MST
    vector<bool> inMST(V, false);
    
    // Start from vertex 0
    minCost[0] = 0; // Starting node cost is 0
    st.insert({0, 0}); // {cost, vertex}
    
    int totalCost = 0; // Total cost of MST
    
    while (!st.empty()) {
        // Get the vertex with the minimum cost edge
        auto top = *(st.begin());
        int u = top.second; // Current vertex
        int cost = top.first; // Current cost
        
        st.erase(st.begin()); // Remove from the set
        
        // If the vertex is already included in MST, continue
        if (inMST[u]) {
            continue;
        }
        
        // Include this vertex in the MST
        inMST[u] = true;
        totalCost += cost; // Add the cost of the edge
        
        // Traverse all adjacent vertices
        for (auto &neighbour : adj[u]) {
            int v = neighbour[0]; // The adjacent vertex
            int edgeCost = neighbour[1]; // The cost of the edge
            
            // If the edge to v is cheaper and v is not in MST
            if (!inMST[v] && edgeCost < minCost[v]) {
                minCost[v] = edgeCost; // Update the cost
                st.insert({edgeCost, v}); // Add to the set
            }
        }
    }
    
    return totalCost; // Return the total cost of the MST
}

// Example usage
int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> adj[V];

    // Create a graph (adjacency list)
    // Example edges: (0-1, 2), (0-3, 6), (1-2, 3), (1-3, 8), (1-4, 5), (2-4, 7), (3-4, 9)
    adj[0] = {{1, 2}, {3, 6}};
    adj[1] = {{0, 2}, {2, 3}, {3, 8}, {4, 5}};
    adj[2] = {{1, 3}, {4, 7}};
    adj[3] = {{0, 6}, {1, 8}, {4, 9}};
    adj[4] = {{1, 5}, {2, 7}, {3, 9}};

    // Find the total cost of the MST
    int cost = spanningTree(V, adj);
    cout << "Total cost of Minimum Spanning Tree: " << cost << endl;

    return 0;
}

///class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        set<pair<int, int>> st;
        vector<int> min_cost(V, INT_MAX);
        vector<bool> mst(V, false);
        min_cost[0] = 0;
        int totalCost = 0;
        
        st.insert({0, 0});
        
        while (!st.empty()) {
            auto top = *(st.begin());
            int u = top.second;
            int cost = top.first;
            st.erase(st.begin());
            
            if (mst[u]) continue;
            
            mst[u] = true;
            totalCost += cost;
            
            for (auto &neighbour : adj[u]) {
                int vertex = neighbour[0];
                int edgecost = neighbour[1];
                
                if (!mst[vertex] && edgecost < min_cost[vertex]) {
                    min_cost[vertex] = edgecost;
                    st.insert({min_cost[vertex], vertex});
                }
            }
        }
        return totalCost;
    }
};
