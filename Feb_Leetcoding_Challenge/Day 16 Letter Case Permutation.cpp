class Solution {
public:
    vector<string>v;
    void helper(string s,int index,int& size)
    {
       // cout<<s<<endl;
        if(index==size)
        { v.push_back(s);
         return;}
        if(s[index]>='0' && s[index]<='9')
            helper(s,index+1,size);
        else
        {
           s[index]= tolower(s[index]);
            helper(s,index+1,size);
         s[index]=toupper(s[index]);
            helper(s,index+1,size);
            
        }
    }
    vector<string> letterCasePermutation(string S) {
        
        int n=S.length();
        helper(S,0,n);
        return v;
        
    }
};