/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/

#include<map>
void mapping(map<int, int> &inOrderToIndex, vector<int> &postOrder){
   for(int i =0; i< postOrder.size(); i++){
       inOrderToIndex[postOrder[i]] = i;
   }
}
TreeNode<int>* createTree(vector<int>& postOrder, vector<int>& inOrder, map<int,int> &inOrderToIndex, int &index, int start, int end){
   // base case
   if(start > end || index <0){
       return NULL;
   }
   
   int data = inOrder[index--];
   TreeNode<int>* root = new TreeNode<int>(data);
   int pos = inOrderToIndex[data];
   
   root -> right = createTree(postOrder, inOrder, inOrderToIndex, index, pos +1, end );
   root -> left = createTree(postOrder, inOrder, inOrderToIndex, index, start, pos -1 );
   
   return root;
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
int postIndex = inOrder.size() -1;
   map<int, int> inOrderToIndex;
   mapping(inOrderToIndex, inOrder);
   
   TreeNode<int>* ans = createTree(inOrder, postOrder, inOrderToIndex, postIndex, 0, inOrder.size() -1);
   return ans;
}
