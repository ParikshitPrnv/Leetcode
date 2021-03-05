class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        string ans="";
        int i=0;
        while(i<n)
        {
            //cout<<s[i]<<" ";
            if(s[i]==')')
            {i++; continue;}
            else if(s[i]=='(')
            {
             int level=1;
                int j=i+1;
                while(j<n)
                {
                    if(s[j]=='(')
                        level++;
                    else if(s[j]==')')
                        level--;
                    if(level==0)
                    {
                        break;
                    }
                    j++;
                }
                if(level!=0)
                {
                    i++;
                    continue;
                }
                else
                    ans+=s.substr(i,j-i+1);
                i=j+1;
            }
            else
            {
            ans+=s[i];
            i++;
            }
        }
        //cout<<i<<" "<<s[i];
        return ans;
    }
};