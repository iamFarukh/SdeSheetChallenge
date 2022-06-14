int findMinimumCoins(int amount) 
{
    // Write your code here
    int ans = 0;
    vector<int> v = {1000, 500, 100, 50,20,10,5,2,1};
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        ans += amount / v[i];
        amount -= amount / v[i] * v[i];
    }
    return ans;   
}
