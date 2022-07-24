#include<bits/stdc++.h>
int maximumProduct(vector<int> &arr, int n)
{
// Write your code here
   int minP = 1;
   int maxP = 1;
   int res = INT_MIN;
   for(int i = 0; i<n;i++)
   {
       if(arr[i]<0)
       {
           swap(minP,maxP);
       }
       minP = min(arr[i], minP*arr[i]);
       maxP = max(arr[i], maxP*arr[i]);
       res = max(res,maxP);
   }
   return res;
}
