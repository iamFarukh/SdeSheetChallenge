/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void helper(TreeNode *root,vector<int> &ans){
    
    if(root==NULL){
        return;
    }
    helper(root->left, ans);
    ans.push_back(root->data);
    helper(root->right, ans);
    
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    
    helper(root, ans);
    
    return ans;
}
