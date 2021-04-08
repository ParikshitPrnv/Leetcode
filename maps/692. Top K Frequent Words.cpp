bool cmp(vector<string> &a,vector<string> &b)
{
    if(stoi(a[1])==stoi(b[1]))
        return a<b;
    else
        return stoi(a[1])>stoi(b[1]);
}
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        for(auto word:words)
            mp[word]++;
        vector<vector<string> > v;
        for(auto i:mp)
        {
            v.push_back({i.first,to_string(i.second)});
        }
        vector<string>ans;
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<k && i<v.size();i++)
        {
            ans.push_back(v[i][0]);
        }
        
        return ans;
    }
};