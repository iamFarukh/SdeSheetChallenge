void helper(int index,int sum,vector<int>&num,int N,vector<int>&ans)
{
    if(index==N)
    {
        ans.push_back(sum);
        return;
    }
    helper(index+1,sum,num,N,ans); 
    helper(index+1,sum+num[index],num,N,ans);
}

vector<int> subsetSum(vector<int> &num)
{
   vector<int>ans;
   int N = num.size();
   helper(0,0,num,N,ans);
   sort(ans.begin(),ans.end());
   return ans;
}
