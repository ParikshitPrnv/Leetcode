struct Trie{
    bool isword;
    Trie* next[26];
    Trie():isword(false) { 
        memset(next,NULL,sizeof(next)); 
    }
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    Trie* root;
    WordDictionary() {
        root=new Trie();
    }
    
    void addWord(string word) {
        Trie* node=root;
        for(auto letter:word)
        {
            if(!node->next[letter-'a'])
            {
                node->next[letter-'a']=new Trie();
            }
            node=node->next[letter-'a'];
        }
        node->isword=true;
    }
    
    bool helper(string word, Trie* node)
    {
        
        for(int i=0;word[i];i++)
        {
            if(word[i]=='.')
            {
                for(int j=0;j<26;j++)
                {
                    if(node->next[j] && helper(word.substr(i+1),node->next[j]))
                        return true;
                }
                return false;
            }
            else
            {
                if(!node->next[word[i]-'a'])
                    return false;
                else
                    node=node->next[word[i]-'a'];
            }
        }
        return node->isword;
    }
    bool search(string word) {
        return helper(word,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */