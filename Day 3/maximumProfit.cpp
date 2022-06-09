#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int maxProfit  = 0;
    int minPrice = INT_MAX;
    
    for(int i = 0;i<prices.size();i++){
        minPrice = min(minPrice, prices[i]);
        maxProfit = max(maxProfit, prices[i]-minPrice);
    }
    return maxProfit;
}
