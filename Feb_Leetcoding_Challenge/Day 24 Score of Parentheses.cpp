class Solution {
public:
    int helper(string &s,int low,int high)
    {
        //cout<<s.substr(low,high-low+1)<<endl;
        if(low>s.length())
            return 0;
        if(high-low+1==2 && s.substr(low,high-low+1)=="()")
            return 1;
        int depth=0;
        int start=low;
        int ans=0;
        for(int i=low;i<=high;i++)
        {
            //cout<<depth<<endl;
            if(s[i]=='(')
                depth++;
            else
                depth--;
            if(depth==0 && start!=i)
            {
                if(i-start+1==2)
                    ans+=1;
                else
                ans+=2*helper(s,start+1,i-1);
                
                start=i+1;
                
            }
        }
        return ans;
    }
    int scoreOfParentheses(string s) {
        return helper(s,0,s.length()-1);
    }
};