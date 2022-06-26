#include<bits/stdc++.h>

struct Node
{
    int visits;
    char ch;
    int wordEnd;
    Node* links[26];
    
    Node(char c = ' ')
    {
        visits = 0;
        ch = c;
        wordEnd = 0;
        memset( links , 0 , sizeof(links) );
    }
};

class Trie{
    Node* root;
    stack<Node*> stk;
    public:

    Trie(){
        root = new Node();
    }
    
    ~Trie()
    {
        deleteTrie(root);
    }
    
    void deleteTrie(Node* root)
    {
        if(root == NULL) return;
        for(int i=0;i<26;i++)
        {
            deleteTrie(root->links[i]);
        }
        delete root;
    }
    
    void insert(string &word){
        Node *curr = root;
        int n = word.length();
        int i=0;
        while(i < n)
        {
            int index = word[i] - 'a';
            if(curr->links[index] == NULL)
            {
                curr->links[index] = new Node(word[i]);
            }
            curr = curr->links[index];
            curr->visits = curr->visits + 1;
            i++;
        }
        curr->wordEnd = curr->wordEnd + 1;
    }

    void clearStack()
    {
        while(!stk.empty()) stk.pop();
    }
    
    Node* Search(string &word , bool erase = false)
    {
        if(erase) 
        {
            stk.push(root);
            clearStack();
        }
        
        Node *curr = root;
        int n = word.length();
        int i=0;
        while(i < n)
        {
            int index = word[i] - 'a';
            if(curr->links[index] == NULL)
            {
                return NULL;
            }
            curr = curr->links[index];
            if(erase) stk.push(curr);
            i++;
        }
        return curr;
    }
    
    int countWordsEqualTo(string &word){
        Node *curr = Search(word);
        if(curr) return curr->wordEnd;
        return 0;
    }

    int countWordsStartingWith(string &word){
        Node *curr = Search(word);
        if(curr) return curr->visits;
        return 0;
    }

    void erase(string &word){
        
        int n = word.length();
        
        Node *curr = Search(word,true);
        curr->wordEnd = curr->wordEnd - 1;

        bool delete_prev = false;

        while(n--)
        {
            curr = stk.top();
            stk.pop();
            curr->visits = curr->visits - 1;

            if(delete_prev)
            {
                int index = word[n+1]-'a';
                delete curr->links[index];
                curr->links[index] = NULL;
            }
           
           if(curr->visits == 0) delete_prev = true;
           else delete_prev = false;
        }
    }
    
    
};
