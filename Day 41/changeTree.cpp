/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void solve (BinaryTreeNode<int> *root, int &ma) {
    if (!root) return ;
    
    solve (root->left, ma);
    solve (root->right, ma);
    if (root->left || root->right) // If there are children 
        root->data = 0;
    if (!root->left && !root->right) // If root is leaf change it's value to max val
        root->data = ma;
    if (root->right) // if right exist add it to root->data
        root->data += root->right->data;
    if (root->left) // If left exist add it to root->data
        root->data += root->left->data; 
    return;
}
void findMax (BinaryTreeNode<int> *root, int &ma) {
    if (!root) return ;
    findMax (root->left, ma);
    ma = max (ma, root->data);
    findMax (root->right, ma);
    return;
}
void changeTree(BinaryTreeNode < int > * root) {
    int ma = 0;
       findMax (root, ma);
    solve (root, ma);
    return;
}   
