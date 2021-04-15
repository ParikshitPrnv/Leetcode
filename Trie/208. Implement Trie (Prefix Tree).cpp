class Trie {
public:
    /** Initialize your data structure here. */
    Trie* root=NULL;
    char val;
    map<char,Trie*> next_alpha;
    bool isword=false;
    Trie(int val='0') {
       this->val=val;
    }
    
    /** Inserts a word into the trie. */
    void insert(string s) {
        if(!root)
        {
            root=new Trie();
        }
        Trie* current=root;
        int i=0;
        for(i=0;s[i];i++)
        {
            if(current->next_alpha[s[i]])
            {
                current=current->next_alpha[s[i]];
                continue;
            }
            Trie* newnode=new Trie(s[i]);
            current->next_alpha[s[i]]=newnode;
            current=current->next_alpha[s[i]];
        }
       current->isword=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(!root)
            return false;
        Trie* current=root;
        for(int i=0;i<word.length();i++)
        {
            //cout<<current->val<<" ";
            if(!current->next_alpha[word[i]])
                return false;
            current=current->next_alpha[word[i]];
        }
        return current->isword;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(!root)
            return false;
        Trie* current=root;
        for(int i=0;i<prefix.length();i++)
        {
           // cout<<current->val<<" ";
            if(!current->next_alpha[prefix[i]])
                return false;
            current=current->next_alpha[prefix[i]];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */