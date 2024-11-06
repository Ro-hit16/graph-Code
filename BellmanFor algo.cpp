#include <iostream>
#include <vector>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    // Initialize distances: 10^8 for unreachable nodes, 0 for source
    int INF = 1e8;
    vector<int> distance(V, INF);
    distance[src] = 0;

    // Relax edges up to V-1 times
    for (int i = 0; i < V - 1; ++i) {
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            if (distance[u] != INF && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        if (distance[u] != INF && distance[u] + weight < distance[v]) {
            // Negative cycle detected
            return {-1};
        }
    }

    // Return the distances with unreachable nodes marked as INF (10^8)
    return distance;
}

int main() {
    int V = 3;  // Number of vertices
    vector<vector<int>> edges = {
        {0, 1, 5}, {1, 0, 3}, {1, 2, -1}, {2, 0, 1}
    };
    int src = 2;  // Source vertex

    vector<int> result = bellmanFord(V, edges, src);

    if (result.size() == 1 && result[0] == -1) {
        cout << "Graph contains a negative-weight cycle\n";
    } else {
        cout << "Shortest distances from source " << src << ":\n";
        for (int i = 0; i < V; ++i) {
            if (result[i] == 1e8) {
                cout << "INF ";
            } else {
                cout << result[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
