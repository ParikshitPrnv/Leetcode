
class Solution {
public:
    int max(int a,int b)
    {
        return a>b?a:b;
    }
    int maxDepth(string s) {
        stack<char>st;
        int d=0;
        for(int i=0;s[i];i++)
        {
            if(s[i]=='(')
                st.push(s[i]);
            else if(s[i]==')')
            {
                st.pop();
            }
            d=max(d,st.size());
        }
        d=max(d,st.size());
        return d;
    }
};