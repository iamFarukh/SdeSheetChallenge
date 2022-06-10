#include <bits/stdc++.h>
vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    int candidate1 = -1, candidate2 = -1, count1 = 0, count2 = 0, i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == candidate1)
            count1++;
        else if (arr[i] == candidate2)
            count2++;
        else if (count1 == 0)
        {
            candidate1 = arr[i];
            count1 = 1;
        }
        else if (count2 == 0)
        {
            candidate2 = arr[i];
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    vector<int> ans;
    count1 = count2 = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == candidate1)
            count1++;
        else if (arr[i] == candidate2)
            count2++;
    }
    if (count1 > n / 3)
        ans.push_back(candidate1);
    if (count2 > n / 3)
        ans.push_back(candidate2);
    return ans;
}
