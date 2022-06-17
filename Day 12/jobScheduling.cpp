#include<bits/stdc++.h>
static bool cmp(vector<int> a,vector<int> b)
{
    return (a[1]>b[1]);
}
int jobScheduling(vector<vector<int>> &jobs)
{
    int n=jobs.size();
    sort(jobs.begin(),jobs.end(),cmp);
    int maxi=jobs[0][0];
    for(int i=0;i<n;i++)
    {
        maxi = max(maxi,jobs[i][0]);
    }
    vector<int> v(maxi+1,-1);
    int maxprofit=0;
    int njob=0;
    for(int i=0;i<n;i++)
    {
        for(int j=jobs[i][0];j>0;j--)
        {
            if(v[j]==-1)
            {
                v[j]=i;
                njob++;
                maxprofit+=jobs[i][1];
                break;
            }
        }
    }
    return maxprofit;
}
