class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int e = adj.size();
        vector<int>dist(e);
        for(int i=0;i<e;i++){
            dist[i] = INT_MAX;
        }
        
        set<pair<int,int>>st;
        dist[src]=0;
        st.insert(make_pair(0,src));
        
        while(!st.empty()){
            auto top = *(st.begin());
            
            int nodeDist = top.first;
            int topNode = top.second;
            
            st.erase(st.begin());
            
            for(auto neighbour: adj[topNode]){
                if(nodeDist + neighbour.second < dist[neighbour.first]){
                    auto record =st.find (make_pair(dist[neighbour.first],neighbour.first));
                    
                    if(record != st.end()){
                        st.erase(record);
                    }
                    dist[neighbour.first] = nodeDist + neighbour.second;
                    
                    st.insert(make_pair(dist[neighbour.first],neighbour.first));
                }
            }
        }
        return dist;
    }
};