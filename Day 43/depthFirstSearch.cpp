void prepareAdj(unordered_map<int, list<int>> &adj, vector<vector<int>> edges){
    for(int i=0; i<edges.size(); i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int node, vector<int> &ans){
    visited[node]=true;
    ans.push_back(node);
    
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(adj, visited, i, ans);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adj;
    vector<vector<int>> ans;
    unordered_map<int, bool> visited;
    prepareAdj(adj, edges);
    
    for(int i=0; i<V; i++){
        if(!visited[i]){
            vector<int> temp;
            dfs(adj, visited, i, temp);
            ans.push_back(temp);
        }
    }
    return ans;
}
