class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        if(n==0)
            return 0;
        vector<vector<int> >dp(n);
        for(int i=0;i<n;i++)
        {
            dp[n-1].push_back(triangle[n-1][i]);
        }
        for(int i=n-2,k=0;i>=0;i--,k++)
        {
            vector<int>v;
            for(int j=0;j<dp[i+1].size()-1;j++)
            {
               
                dp[i].push_back(triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]));
            }
            
        }
        for(auto i:dp)
        {
            for(auto j:i)
                cout<<j<<" ";
            cout<<endl;
        }
        return dp[0][0];
    }
};