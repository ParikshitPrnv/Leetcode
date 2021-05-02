class WordFilter {
public:
    unordered_map<char,WordFilter*>next;
    int index;
    void insert(string word,int index){
        WordFilter* node=this;
        for(auto i:word){
            if(!node->next[i])
                node->next[i]=new WordFilter();
            node=node->next[i];
            node->index=index;
        }
        node->index=index;
    }
    
    WordFilter(vector<string>& words) {
        int index=0;
        for(auto word:words){
            for(int i=0;i<=word.length();i++){
                string temp=word.substr(i,word.length()-i)+'|';
                temp+=word;
                
                insert(temp,index);
            }
            
            index++;
        }
    }
    
    WordFilter(){
    }
    
    int search(string word){
        WordFilter* node=this;
        for(auto i:word){
            if(!node->next[i])
                return -1;
            node=node->next[i];
        }
        return node->index;
    }
    
    int f(string prefix, string suffix) {
        string word=suffix+'|'+prefix;
       
        return search(word);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */