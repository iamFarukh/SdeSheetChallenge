/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
#include<bits/stdc++.h>
bool solve(BinaryTreeNode<int> *root ,int k,unordered_set<int>&s){
    if(!root)return 0;
    
    if(s.find(k-root->data)!=s.end())return true;
    s.insert(root->data);
    return solve(root->left,k,s) or solve(root->right,k,s);
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    unordered_set<int>s;
    return solve(root,k,s);
    // Write your code here
}
