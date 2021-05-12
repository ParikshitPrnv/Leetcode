class CombinationIterator {
public:
    int i=0;
    int len;
    int k;
    vector<string>v;
    void backtrack(string& characters,string &s,int i,int k){
        
        if(s.length()>k)
            return ;
        if(s.length()==k)
        {
            v.push_back(s);
            return ;
        }
        if(i==characters.length()){
            return;
        }
        for(int l=i+1;l<characters.length();l++){
            s.push_back(characters[l]);
            backtrack(characters,s,l,k);
            s.pop_back();
        }
            
    }
    CombinationIterator(string characters, int k) {
        len=characters.length();
        this->k=k;
        string s="";
        for(int i=0;i<len;i++){
            s.push_back(characters[i]);
            backtrack(characters,s,i,k);
            s.pop_back();
        }
        //for(auto i:v)
          //  cout<<i<<endl;
    }
    
    string next() {
        string t=v[i];
        i++;
        return t;
    }
    
    bool hasNext() {
        return i<v.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */