#include<bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
    // Write your code here.
    // brute force approach also possible but this is 
    // giving more efficient code
    
   priority_queue<int> pq;
   for(int i = 0; i<n; i++)
   {
     for(int j = 0; j<n; j++)
     {
         int sum = a[i] + b[j];
         pq.push(sum);
     }
   }
   vector<int> ans;
   while(k--)
   {
       ans.push_back(pq.top());
       pq.pop();
   }
   return ans;
}
