/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/
void inOrder(BinaryTreeNode<int> *root, vector<int> &temp){
    if(root==NULL){
        return;
    }
    inOrder(root->left, temp);
    temp.push_back(root->data);
    inOrder(root->right, temp);
   
}

void  preOrder(BinaryTreeNode<int> *root, vector<int> &temp){
    if(root==NULL){
        return;
    }
    temp.push_back(root->data);
    preOrder(root->left, temp);
    preOrder(root->right, temp);
}

void postOrder(BinaryTreeNode<int> *root, vector<int> &temp){
    if(root==NULL){
        return;
    }
    postOrder(root->left, temp);
    postOrder(root->right, temp);
    temp.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>> ans;
    
    vector<int> temp1;
    inOrder(root, temp1);
    ans.push_back(temp1);
    
    vector<int> temp2;
    preOrder(root, temp2);
    ans.push_back(temp2);
    
    vector<int> temp3;
    postOrder(root, temp3);
    ans.push_back(temp3);
    
    return ans;
}
