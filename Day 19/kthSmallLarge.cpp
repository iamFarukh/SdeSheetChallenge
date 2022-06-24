#include <bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k){
    
    int kthLargest=0;
    int kthSmallest=0;
    priority_queue<int>maxh;
    priority_queue<int,vector<int>,greater<int>>minh;
    vector<int>ans(2);
    
    for(int i=0;i<n;i++){
        maxh.push(arr[i]);
        if(maxh.size()>k){
            maxh.pop();
        }
    }
    ans[0]=maxh.top();
    
    for(int i=0;i<n;i++){
        minh.push(arr[i]);
        if(minh.size()>k){
            minh.pop();
        }
    }
    ans[1]=minh.top();
    
    return ans;
}
