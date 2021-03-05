bool cmp(pair<int,int> &a,pair<int,int> &b)
{
    if(a.first==b.first)
        return a.second<b.second;
    else
        return a.first<b.first;
}
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int> >v;
        for(int i=0;i<mat.size();i++)
        {
            int sum=0;
            for(auto j:mat[i])
            {
                if(j==0)
                    break;
                sum++;
            }
            v.push_back(make_pair(sum,i));
        }
        sort(v.begin(),v.end(),cmp);
        vector<int>ans;
    for(int i=0;i<k && i<v.size();i++)
    {
        ans.push_back(v[i].second);
    }
        return ans;
    }
};