#include<bits/stdc++.h>
vector<int> nsr(vector<int>&arr)
{
    vector<int> ans;
    stack<pair<int,int>> s;
    
    for(int i=arr.size()-1;i>=0;--i)
    {
        if(s.empty())
            ans.push_back(arr.size());
        else
        {
            while(!s.empty()&&s.top().first>=arr[i])
                s.pop();
            if(s.empty())
                ans.push_back(arr.size());
            else
                ans.push_back(s.top().second);
        }
        s.push({arr[i],i});
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
vector<int> nsl(vector<int>&ar)
{
    vector<int> res;
    stack<pair<int,int>> s;
    for(int i=0;i<ar.size();i++)
    {
        if(s.empty())
            res.push_back(-1);
        else
        {
            while(!s.empty()&&s.top().first>=ar[i])
                s.pop();
            if(s.empty())
                res.push_back(-1);
            else
                res.push_back(s.top().second);
        }
        s.push({ar[i],i});
    }
    return res;
}
int largestRectangle(vector < int > & arr) {
    vector<int> NSR = nsr(arr);
    vector<int> NSL = nsl(arr);
    vector<int> width;
    for(int i=0;i<arr.size();i++)
        width.push_back((NSR[i]-NSL[i])-1);
    int mx = INT_MIN;
    for(int i=0;i<arr.size();i++)
    {
        mx = max(mx,(arr[i]*width[i]));
    }
    return mx;
 }
