struct Node {
    Node *links[26];
    int end = 0;
};

void insert(Node *root, string &s) {
    
    Node *node = root;
    for(auto x : s) {
        if(node->links[x - 'a'] == nullptr)
            node->links[x - 'a'] = new Node();
        node = node->links[x - 'a'];
    }
    node->end = 1;
}

int getCount(Node *root, string &s) {
    Node *node = root;
    int cnt = 0;
    for(auto x : s) {
        node = node->links[x - 'a'];
        cnt += node->end;
    }
    return cnt;
}

string completeString(int n, vector<string> &a){
    // Write your code here.
    Node *root = new Node();
    
    for(auto x : a)
        insert(root, x);
    
    int mx = 0;
    string ans = "";
    for(int i = 0; i < 100003; i++)
        ans.push_back('z');
    
    for(auto x : a) {
        int count = getCount(root, x);
        
//         cout << x << " : " << count << endl;
        if(count == x.size()) {
            if(count > mx) {
                mx = count;
                ans = x;
            }
            else if(count == mx) {
                if(x < ans) ans = x;
            }
        }
    }
    return ans.size() > 100001 ? "None" : ans;
}

