#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    int ans=INT_MIN;
    int l=0,r=0;
    set<char>s;
    if(input.size()==0){
        return 0;
    }
    while(r<input.size()){
        auto it=s.find(input[r]);
        if(it==s.end()){
            ans=max(ans,r-l+1);
            s.insert(input[r]);
            r++;
        }
        else{
            s.erase(input[l]);
            l++;
        }
    }
    return ans;  
}
