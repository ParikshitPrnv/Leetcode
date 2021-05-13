class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int close=0;
        for(int i=0;s[i];i++){
            if(s[i]=='(')
                st.push('(');
            else if(!st.empty())
                st.pop();
            else
                close++;                
        }
        return st.size()+close;
    }
};