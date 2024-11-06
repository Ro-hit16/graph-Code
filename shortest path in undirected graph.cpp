#include <unordered_map>
#include <list>
#include <queue>
#include<vector>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	// adj lst
	unordered_map<int,list<int>>adj;
	for(auto edge: edges){
		int u = edge.first;
		int v=edge.second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	

	// do bfs
	unordered_map<int,int>parent;
	unordered_map<int,bool>visited;
	queue<int>q;
	q.push(s);
	visited[s]=true;
	parent[s]= -1;

	while(!q.empty()){
		int front =q.front();
		q.pop();
		for(auto neighbour:adj[front]){
			if(!visited[neighbour]){
				visited[neighbour]=true;
				parent[neighbour]=front;
				q.push(neighbour);
			}
		}
		
	}


   //shortest path
   vector<int>ans;
   int currNode = t;
   ans.push_back(currNode);
   while(currNode != s){
     currNode = parent[currNode];
	 ans.push_back(currNode);
   }
   reverse(ans.begin(),ans.end());
   return ans;
}
