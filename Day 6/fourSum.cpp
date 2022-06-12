#include <bits/stdc++.h> 
string fourSum(vector<int> arr, int target, int n)
{
    unordered_map<int, pair<int, int>> mp;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];
            mp[sum] = {i, j};
        }
    }
    
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int left = target - (arr[i] + arr[j]);
            
            if(mp.find(left) != mp.end())
            {
                pair<int, int> it = mp[left];
                    int k = it.first;
                    int l = it.second;
                    
                    if(i != k && i != l && j != k && j != l)
                        return "Yes";
            }
        }
    }
    
    return "No";
}
