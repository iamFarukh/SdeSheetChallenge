#include <bits/stdc++.h>

struct TrieNode{
    TrieNode* child[2];
};

TrieNode* getNode()
{
    TrieNode* node = new TrieNode();
    node->child[0] = node->child[1] = NULL;
    return node;
}

void insert(TrieNode* root, int num)
{
    TrieNode* curr = root;
    for(int i=31; i>=0; i--)
    {
        int bit = (num>>i)&1;
        if(curr->child[bit] == NULL)
        {
            curr->child[bit] = getNode();
        }
        curr = curr->child[bit];
    }
}

int findMax(TrieNode* root, int num)
{
    TrieNode* curr = root;
    int mxAns = 0;
    for(int i=31; i>=0; i--)
    {
        int bit = (num>>i)&1;
        if(curr->child[1-bit] != NULL)
        {
            curr = curr->child[1-bit];
            mxAns = mxAns | ((1<<i));
        }
        else
        {
            curr = curr->child[bit];
        }
    }
    return mxAns;
}

int maximumXor(vector<int> arr)
{
    // Write your code here. 
    TrieNode* root = getNode();
    for(auto &it:arr)
        insert(root, it);
    
    int ans = 0;
    for(auto &it:arr)
        ans = max(ans, findMax(root, it));
    
    return ans;
}
