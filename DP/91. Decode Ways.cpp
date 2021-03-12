class Solution {
public:
    int helper(string s,int index, vector<int> &memo)
    {
        if(s[index]=='0')
            return 0;
        if(index>=s.length()-1)
        {
            return 1;
        }
        if(memo[index]!=-1)
            return memo[index];
        
        if(((s[index]-'0')*10+(s[index+1]-'0'))<=26 && s[index]!='0')
            return memo[index]=helper(s,index+1,memo)+helper(s,index+2,memo);
        else
            return helper(s,index+1,memo);
    }
    int numDecodings(string s) {
       int n=s.length();
        vector<int>memo(n+1,-1);
        return helper(s,0,memo);
    }
};