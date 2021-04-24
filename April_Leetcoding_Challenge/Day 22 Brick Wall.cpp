class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int,int>m;
        int n=wall.size();
        int ans=n;
        for(int i=0;i<wall.size();i++)
        {
            if(wall[i].size()!=1)
            m[wall[i][0]]++;
            for(int j=1;j<wall[i].size()-1;j++)
            {
                wall[i][j]+=wall[i][j-1];
                m[wall[i][j]]++;
            }
        }
        //cout<<m.size()<<endl;
        for(auto i:m)
        {
           // cout<<i.first<<" "<<n-i.second<<endl;
            
            ans=min(ans,n-i.second);
        }
        return ans;
    }
};