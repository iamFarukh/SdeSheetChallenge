#include <bits/stdc++.h>
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    int N = arr.size();
        int len = 0, res = INT_MIN;
        if(N == 0)
            return 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < N; i++)
           mp[arr[i]]++;
        for(auto i : arr)
        {
            if(mp.find(i - 1) == mp.end())
            {
                int k = i;
                int len = 1;
                while(mp.find(k + 1) != mp.end())
                {
                    k++;
                    len++;
                }  
                res = max(res, len);
            }
        }
        return res > 0 ? res : 1;
}
