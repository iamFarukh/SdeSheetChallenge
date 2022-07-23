#include<bits/stdc++.h>

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {
    vector<pair<int, int>> adj[n+1];
    for(int i=0; i<g.size(); ++i) {
        adj[g[i].first.first].push_back({g[i].first.second, g[i].second});
        adj[g[i].first.second].push_back({g[i].first.first, g[i].second});
    }
    
    vector<int> parent(n+1, -1);
    vector<int> dist(n+1, INT_MAX);
    vector<bool> mstDone(n+1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    dist[1] = 0;
    parent[1] = -1;
    
    while(!q.empty()) {
        int node = q.top().second;
        int nodeDist = q.top().first;
        mstDone[node] = true;
        q.pop();
        
        for(auto &it : adj[node]) {
            int n = it.first;
            int d = it.second;
            
            if(!mstDone[n] && dist[n] > d) {
                parent[n] = node;
                dist[n] = d;
                q.push({dist[n], n});
            }
        }
    }
    
    vector<pair<pair<int, int>, int>> ans;
    for(int i=2; i<=n; ++i) ans.push_back({{parent[i], i}, dist[i]});
    
    return ans;
}
