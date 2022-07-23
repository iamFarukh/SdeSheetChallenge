#include<bits/stdc++.h>
int kthLargest(vector<int>& arr, int size, int k){
    priority_queue<int> pq;
    for(int i=0; i<size; i++){
        pq.push(arr[i]);
    }
    while(k){
        if(k==1) return pq.top();
        pq.pop();
        k--;
    }
    return 0;
}
