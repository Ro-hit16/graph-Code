//DAG  -> directed Acyclic Graph



void topoSort(int node,unordered_map<int,bool>&visited,stack<int>&s,vector<vector<int>>& adj){
        visited[node]=1;
        
        for( int neighbour:adj[node]){
           
           if(!visited[neighbour]){
               topoSort(neighbour,visited,s,adj);
           } 
        }
        s.push(node);
        
        
        
    }
    vector<int> topologicalSort(vector<vector<int>>& adj) {
         unordered_map<int,bool>visited;
         stack<int>s;
         
        int v = adj.size();
        for(int i=0;i<v;i++){
            if(!visited[i]){
                topoSort(i,visited,s,adj);
            }
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
            
        }
       return ans;
      
    }