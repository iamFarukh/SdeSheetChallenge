class TrieNode {
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    
    TrieNode(char x) {
        data = x;
        
        for(int i = 0; i<26; i++) {
            children[i] = NULL;
        }
        
        isTerminal = false;
    }
};
class Trie {

public:

    /** Initialize your data structure here. */
    TrieNode* root;
    Trie() {
        root = new TrieNode('\0');
    }

    /** Inserts a word into the trie. */
    
    void insertUtility(TrieNode* root, string word) {
        if(word.length() == 0) {
            root->isTerminal = true;
            return;
        }
        
        int index = word[0] - 'a';
        TrieNode* child;
        
        if(root->children[index] != NULL) {
            child = root->children[index];
        }
        
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        
        insertUtility(child,word.substr(1));
    }
    
    void insert(string word) {
        insertUtility(root,word);
    }

    /** Returns if the word is in the trie. */
    bool searchUtility(TrieNode* root, string word) {
        if(word.length() == 0) 
            return root->isTerminal;
        
        int index = word[0] - 'a';
        TrieNode* child;
        
        if(root->children[index] != NULL) {
            child = root->children[index];
        }
        
        else {
            return false;
        }
        
        return searchUtility(child,word.substr(1));
    }
    
    bool search(string word) {
        return searchUtility(root,word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startUtility(TrieNode* root, string word) {
        if(word.length() == 0) {
            return true;
        }
        
        int index = word[0] - 'a';
        TrieNode* child;
        
        if(root->children[index] != NULL) {
            child = root->children[index];
        }
        
        else {
            return false;
        }
        
        return startUtility(child,word.substr(1));
    }
    
    bool startsWith(string prefix) {
        return startUtility(root,prefix);
    }
};
