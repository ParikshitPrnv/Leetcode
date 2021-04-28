class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       int n=obstacleGrid.size();
        if(n==0)
            return 0;
        int m=obstacleGrid[0].size();
        vector<vector<int> >dp(n+1,vector<int>(m+1,0));
        //int dp[n+1][m+1];
      dp[0][1]=1;
        
        for(int i=1;i<=n;i++)
        {
            
            for(int j=1;j<=m;j++)
            {
                if(!obstacleGrid[i-1][j-1])
                {
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[n][m];
        
    }
};