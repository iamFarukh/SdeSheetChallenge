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

class BSTiterator
{
    public: 
    int prev;
    TreeNode<int>* roott;
    BSTiterator(TreeNode<int> *root)
    {
        prev = -1;
        roott = root;
    }

    int next()
    {
        int suc = -1;
        TreeNode<int>* cur = roott;
        while (cur)
        {
            if (cur->data <= prev)
                cur = cur->right;
            else
            {
                suc = cur->data;
                cur = cur->left;
            }
        }
        prev = suc;
        return suc;
    }

    bool hasNext()
    {
        bool hasNext = false;
        int suc = -1;
        TreeNode<int>* cur = roott;
        while (cur)
        {
            if (cur->data <= prev)
                cur = cur->right;
            else if (cur->data > prev)
            {
                suc = cur->data;
                cur = cur->left;
            }
        }
        return (suc != -1);
    }
};

/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/
