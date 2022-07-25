int cutRod(vector<int> &price, int n)
{
    // Write your code here
    vector<int>prev(n+1,0);
    vector<int>curr(n+1,0);
    
    
    for(int l=0;l<=n;l++){
        prev[l]=price[0]*l;
    }
    for(int ind =1;ind<n;ind++){
        for(int len=0;len<=n;len++){
            int notTake=prev[len];
            int take=INT_MIN;
            int rodLength=ind+1;
            if(rodLength<=len) take=price[ind]+curr[len-rodLength];
            curr[len]=max(take,notTake);
            
        }
        prev=curr;
    }
    return prev[n];
}
