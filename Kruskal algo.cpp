#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find(int u) {
        if (u != parent[u]) parent[u] = find(parent[u]);
        return parent[u];
    }
    
    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) parent[rootV] = rootU;
            else if (rank[rootU] < rank[rootV]) parent[rootU] = rootV;
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

int spanningTree(int V, vector<vector<int>> adj[]) {
    vector<pair<int, pair<int, int>>> edges;
    
    for (int u = 0; u < V; u++) {
        for (auto &neighbor : adj[u]) {
            int v = neighbor[0];
            int weight = neighbor[1];
            if (u < v) edges.push_back({weight, {u, v}});
        }
    }
    
    sort(edges.begin(), edges.end());
    DSU dsu(V);
    int mstWeight = 0;
    
    for (auto &edge : edges) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        
        if (dsu.find(u) != dsu.find(v)) {
            mstWeight += weight;
            dsu.unite(u, v);
        }
    }
    
    return mstWeight;
}
