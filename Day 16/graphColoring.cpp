bool isPossible(int node,vector<int>&color,
                int n,vector<vector<int>>&mat,int col)
{
    for(int k=0;k<n;k++){
        if(k!=node && mat[node][k]==1 && color[k]==col){
            return false;
        }
    }
    return true;
}
bool solve(int node,vector<int>&color,vector<vector<int>>&mat,int n,int m){
    
    if(node==n){
        return true;
    }
    for(int i=1;i<=m;i++){
        if(isPossible(node,color,n,mat,i)){
            color[node]=i;
            if(solve(node+1,color,mat,n,m)){
                return true;
            }
            color[node]=0;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int n=mat.size();
    vector<int>color(n,0);
    if(solve(0,color,mat,n,m)){
        return "YES";
    }
    return "NO";
}
