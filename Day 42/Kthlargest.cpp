#include<bits/stdc++.h>
class Kthlargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;// min heap
    int k;
    Kthlargest(int k, vector<int> &arr) {
       // Write your code here.
       this->k = k;
       for(auto &e : arr){
           pq.push(e);
           if(pq.size()>k){
               pq.pop();
           }
       }
    }

    void add(int num) {
        // Write your code here.
        pq.push(num);
        if(pq.size()>k){
               pq.pop();
       }
    }

    int getKthLargest() {
       // Write your code here.
       return pq.top();
    }

};
