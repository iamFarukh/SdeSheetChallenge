#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int>str;
    str.push(-1);
    vector<int>result(n);
    for(int i=n-1;i>=0;i--)
    {
        int current=arr[i];
        while(str.top()>=current)
        {
            str.pop();
        }
        result[i]=str.top();
        str.push(current);
    }
    return result;
}
