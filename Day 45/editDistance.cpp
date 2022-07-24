int tabuso(string &s1,string &s2)
{
    int n=s1.size(),m=s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    vector<int> prev(m+1,0),curr(m+1,0);
    for(int j=0;j<=m;j++)
    {
        prev[j]=j;
    }
    
    for(int i=1;i<=n;i++)
    {
        curr[0]=i;
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1]) curr[j]=prev[j-1];
            else curr[j]=1+min(prev[j],min(prev[j-1],curr[j-1]));
        }
        prev=curr;
    }
    return prev[m];
}

int editDistance(string str1, string str2)
{
    //write you code here
    int n=str1.size(),m=str2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
//     return recur(str1,str2,n-1,m-1);
//     return memo(str1,str2,n-1,m-1,dp);
//     return tabu(str1,str2);
    return tabuso(str1,str2);

}
