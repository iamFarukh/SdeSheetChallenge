/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/

#include<bits/stdc++.h>

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    if(preOrder.size()==0) return NULL;
    TreeNode<int>* node=new TreeNode<int>(preOrder[0]);
    vector<int> lessThan;
    vector<int> greaterThan;
    for(int i=1; i<preOrder.size(); i++)
    {
        if(preOrder[i]<preOrder[0]) lessThan.push_back(preOrder[i]);
        else greaterThan.push_back(preOrder[i]);
    }
    node->left=preOrderTree(lessThan);
    node->right=preOrderTree(greaterThan);
    return node;
}
