/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
#include<bits/stdc++.h>
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<vector<int>> temp;
    vector<int> ans;
    
    if(root==NULL) return ans;
    map<int, vector<int>> m;
    queue<pair<TreeNode<int> *,int>> q;
    q.push({root,0});
    
    while(!q.empty()){
        
        auto it = q.front();
        q.pop();
        TreeNode<int>* node = it.first;
        int line = it.second;
        m[line].push_back(node->data);
        
        if(node ->left!=NULL){
            q.push({node->left, line-1});
        }
        if(node->right!=NULL){
            q.push({node->right,line+1});
        }
    }
    
    for(auto it:m){
        temp.push_back(it.second);
    }
    
    for(int i = 0;i<temp.size();i++){
         for(int j = 0;j<temp[i].size();j++){
             ans.push_back(temp[i][j]);
         }   
    }
    
    return ans;
}

















