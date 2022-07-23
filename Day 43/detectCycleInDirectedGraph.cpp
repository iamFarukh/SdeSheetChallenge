#include<bits/stdc++.h>

bool detect_cycle(int src, vector<int> adj[], vector<int> &visit){
    visit[src] = 2;
    for(auto it: adj[src]){
        if(visit[it]==0){
            if(detect_cycle(it, adj, visit)) return true;
        }
        else if(visit[it] == 2) return true;
    }
    visit[src] = 1;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
     vector<int> adj[n+1];
    
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
    }
    vector<int> visit(n+1, 0);
    for(int i=1;i<n;i++){
        if(visit[i] == 0){
            if(detect_cycle(i,adj,visit)){
                return 1;
            }
        }
    }
     return 0;
}
