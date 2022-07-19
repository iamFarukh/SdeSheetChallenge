/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int height(BinaryTreeNode<int>*root)
{
    if(root==NULL) return 0;
    
    return (max(height(root->left),height(root->right)) + 1);
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    if(root==NULL) return true;
    
    int lh = height(root->left);
    int rh = height(root->right);
    
    if(abs(lh-rh)<=1 && isBalancedBT(root->left) && isBalancedBT(root->right))return true;
    
    
    return false;
}
