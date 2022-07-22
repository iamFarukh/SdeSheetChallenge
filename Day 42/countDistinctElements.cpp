#include<bits/stdc++.h>
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    vector<int>ans;
    unordered_map<int,int>mpp;
    for(int i=0;i<k;i++){
        mpp[arr[i]]++;
    }
    ans.push_back(mpp.size());
    int n = arr.size();
    for(int i =k;i<n;i++){
        mpp[arr[i-k]]--; 
        if(mpp[arr[i-k]]==0)mpp.erase(arr[i-k]);
        mpp[arr[i]]++;
        ans.push_back(mpp.size());
    }
    return ans;
    // Write your code here
	
}
