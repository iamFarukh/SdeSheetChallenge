/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void inorder(TreeNode<int>* root,vector<int>&vec)
{
    if(!root) return;

    inorder(root->left,vec);
    vec.push_back(root->data);
    inorder(root->right,vec);
}
   
int kthSmallest(TreeNode<int> *root, int k)
{
    vector<int> vec;
    inorder(root,vec);
        
        for(int i=0;i<vec.size();i++)
        {
            if(i+1==k)
            {
                return vec[i];
            }
        }
        return 0;
}
