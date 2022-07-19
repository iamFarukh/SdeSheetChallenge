#include <bits/stdc++.h> 
int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
    unordered_map<int, int> mp; // Inorder Node value -> index in inorder array
    queue<vector<int>> q; // {start, end, height}
    
    for(int i = 0; i < inorder.size(); i++){
        mp[inorder[i]] = i;
    }
    
    if(mp.find(levelOrder[0]) != mp.end()){
        // root is the last element in inorder traversal then it has no right subtree
        if(mp[levelOrder[0]] == inorder.size()-1) 
            q.push({0, (int)inorder.size()-2, 1});
        // root is the first element in inorder traversal then it has no left subtree
        else if(mp[levelOrder[0]] == 0)
            q.push({1, (int)inorder.size()-1, 1});
        else
        {
            q.push({0, mp[levelOrder[0]]-1, 1});    // left subtree
            q.push({mp[levelOrder[0]]+1, (int)inorder.size()-1, 1});    // right subtree
        }
    }
    int k = 1;
    int ans = 0;
   while(!q.empty())
   {  
    auto temp = q.front();
    q.pop();
    ans = max(ans, temp[2]);
    if(mp.find(levelOrder[k]) != mp.end()){  
        // if it is the leaf node i.e. no left subtree and no right subtree 
        if(temp[0] == temp[1]) 
            ans = max(ans, temp[2] + 1);
        // root is the last element in inorder traversal then it has no right subtree
        else if(mp[levelOrder[k]] == temp[1])
            q.push({temp[0], temp[1]-1, temp[2]+1});
        // root is the first element in inorder traversal then it has no left subtree
        else if(mp[levelOrder[k]] == temp[0])
            q.push({temp[0]+1, temp[1], temp[2]+1});
        else
        {
            q.push({temp[0], mp[levelOrder[k]]-1, temp[2]+1}); // left subtree
            q.push({mp[levelOrder[k]]+1, temp[1], temp[2]+1});    // right subtree
        }
    }
    k++;
   }
   return ans-1;
}
