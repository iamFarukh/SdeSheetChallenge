struct Node{
    
    Node* children[26];
    
    //returns,  child present or not
    bool containsKey(char ch){
        return ( children[ch - 'a'] != NULL);
    } 
    
    //return child node(reference child node)
    
    Node* get(char ch){
        return (children[ch - 'a']);
    }
    
    //set the chilld 
    void set(Node* node , char ch){
        children[ch - 'a'] = node;
    }
    
};

class Trie{
    Node *root ;
    public:
    Trie(){
        root = new Node();
    }
    
    public:
    void insert(string word,int &ans){
        Node* node = root;
        
        for(int i=0;i<word.length();i++){
            //if child is not present set the value ans increment ans
            if(!node->containsKey(word[i])){
                node->set(new Node(), word[i]);
                ans++;
            }
            //get child node 
            node = node->get(word[i]);
            
        }
    }
};
int distinctSubstring(string &word) {
    int ans=0;
    Trie trie;
    
    for(int i=0;i<word.length();i++){
        string st ="";
        
        for(int j=i;j<word.length();j++){
            st += word[j];
            trie.insert(st,ans);
        }
    }
    return ans;
}
