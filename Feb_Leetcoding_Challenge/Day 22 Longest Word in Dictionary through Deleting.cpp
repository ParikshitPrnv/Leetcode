bool cmp(string &a,string &b)
{
    if(a.length()==b.length())
        return a<b;
    else
        return a.length()>b.length();
}
class Solution {
public:
    bool ispossible(string &s,string &t)
    {
        if(s.length()<t.length())
            return false;
        int i=0,j=0;
        while(s[i] && t[j])
        {
            if(s[i]==t[j])
            j++;
            i++;
        }
        if(j==t.length())
            return true;
        else
            return false;
    }
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(),d.end(),cmp);
        string ans="";
        for(auto i:d)
            cout<<i<<"\n";
        for(auto i:d)
        {
            if(ispossible(s,i) && i.length()>ans.length())
                ans=i;
        }
        return ans;
    }
};