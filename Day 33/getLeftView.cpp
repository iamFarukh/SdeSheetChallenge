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

void solve(TreeNode<int> *root, int level, int &maxlevel, vector<int>&v)

{

    if(root==NULL) return;

    if(level>maxlevel)

    {

        v.push_back(root->data);

        maxlevel=level;

        

    }

    solve(root->left,level+1,maxlevel,v);

    solve(root->right,level+1,maxlevel,v);

}

vector<int> getLeftView(TreeNode<int> *root)

{

    int maxlevel=0;

    

    vector<int> ans;

    solve(root,1,maxlevel,ans);

    return ans;

}

    //    Write your code here
