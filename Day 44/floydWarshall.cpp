#include<bits/stdc++.h>
void solution(int node,int src,int dest,int cost,vector<vector<int>> &mat,vector<int> adj[],vector<int>& res){
   if(node==dest){
       res.push_back(cost);
       return;
   }
   for(auto it:adj[node]){
       cost+=mat[node][it];
       solution(it,src,dest,cost,mat,adj,res);
       cost-=mat[node][it];
   }
   return;
}
int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
   // Write your code here.
   vector<int> adj[n+1];
   vector<vector<int>> mat(n+1,vector<int>(n+1,0));
   for(int i=0;i<m;i++){
       int u = edges[i][0];
       int v = edges[i][1];
       mat[u][v] = edges[i][2];
       adj[u].push_back(v);
   }
   vector<int> res;
   int cost=0,ans=1e9;
   solution(src,src,dest,cost,mat,adj,res);
   
   for(auto i:res){
       if(i<ans) ans=i;
   }
   return ans;
}
