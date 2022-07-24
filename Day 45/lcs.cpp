#include<bits/stdc++.h>
int helper(int i,int j,string &str1,string &str2,vector<vector<int>> &dp){
    
    if(i<0 || j<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(str1[i]==str2[j]){
        return dp[i][j]=1+helper(i-1,j-1,str1,str2,dp);
    }
    int ans1=helper(i-1,j,str1,str2,dp);
    int ans2=helper(i,j-1,str1,str2,dp);
    int finalans=max(ans1,ans2);
    dp[i][j]=finalans;
    return dp[i][j];
}
int lcs(string str1, string str2)
{
    //Write your code here
    int n=str1.size();
    int m=str2.size();
//     vector<vector<int>> dp(n,vector<int>(m,-1));
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int j=0;j<=m;j++){
        dp[0][j]=0;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
            int ans1=dp[i-1][j];
            int ans2=dp[i][j-1];
            int finalans=max(ans1,ans2);
            dp[i][j]=finalans;  
            }
        }
    }
//     int ans=helper(n-1,m-1,str1,str2);
    return dp[n][m];
}
