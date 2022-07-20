/************************************************************

    Following is the TreeNode class structure:

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
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *root, int X){
     int prev = -1;
    while(root)
    {
        if(root->data==X)
        {
            return root->data;
        }
        else if(root->data>X)
        {
            prev = root->data;
            root = root->left;
        }
        else if(root->data<X)
        {
            root = root->right;
        }
    }
    return prev;
   
}
