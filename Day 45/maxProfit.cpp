int f(int n, int w, vector<int> &v, vector<int> &wt, vector<vector<int>> &dp){
    if(n == 0){
        if(w >= wt[0])    return v[0];
        else    return 0;
    }
    if(dp[n][w]!=-1)
        return dp[n][w];
    int notTake = f(n-1, w, v, wt, dp);
    int take = 0;
    if(w >= wt[n])
        take = v[n] + f(n-1, w-wt[n], v, wt, dp);
    return dp[n][w] = max(take, notTake);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w){
    vector<vector<int>> dp(n+1, vector<int> (w+1,-1));
    return f(n-1, w, values, weights, dp);
}
