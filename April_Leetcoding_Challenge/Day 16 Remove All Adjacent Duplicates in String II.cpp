class Solution {
public:
    int min(int a,int b)
    {
        return a<b?a:b;
    }
    string removeDuplicates(string s, int k) {
        //cout<<s<<endl;
        if(s.length()<k)
            return s;
        for(int i=0;i<=s.length()-k;i++)
        {
            int count=0;
            for(int j=i;min(k,s.length()-1);j++)
            {
                if(s[i]!=s[j])
                    break;
                else
                    count++;
            }
            if(count==k)
            {
                return removeDuplicates(s.substr(0,i)+s.substr(i+k,s.length()-1-i-k+1),k);
            }
        }
        return s;
    }
};

//Alternate approaches
//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/discuss/392867/C%2B%2B-3-approaches

/*
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int> >st;
        for(auto ch:s)
        {
            if(st.empty() || st.top().first!=ch)
                st.push({ch,0});
            if(++st.top().second==k)
                st.pop();
        }
        string ans;
        while(!st.empty())
        {
            ans+=string(st.top().second,st.top().first);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};*/
