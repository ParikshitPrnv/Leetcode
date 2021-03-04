class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int>v;
        vector<int>ans;
        for(int i=0;s[i];i++)
            if(s[i]==c)
                v.push_back(i);
        for(int i=0;s[i];i++)
        {
            if(s[i]==c)
            { ans.push_back(0);
             continue;
            }
            int closest=INT_MAX;
            for(auto j:v)
            {
                closest=min(closest,abs(j-i));
            }
            ans.push_back(closest);
        }
        return ans;
    }
};