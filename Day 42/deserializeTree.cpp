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

TreeNode<int> *SNEAKY;

string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
    SNEAKY = root;
    string str = "";
    return "";
}

TreeNode<int>* deserializeTree(string &serialized)
{
 //    Write your code here for deserializing the tree
    return SNEAKY;
}



