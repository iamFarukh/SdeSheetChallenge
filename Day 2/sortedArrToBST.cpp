TreeNode<int> *helper(vector<int> &arr, int l, int h)
{
    if(l > h)
        return NULL;
    int mid = l + (h-l)/2;
    TreeNode<int> *curr = new TreeNode<int> (arr[mid]);
    
    curr->left = helper(arr, l, mid-1);
    curr->right = helper(arr, mid+1, h);
    return curr;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    if(n==0)
        return NULL;
    return helper(arr, 0, n-1);
}
