class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(n==0)
            return -1;
        vector<vector<int> >dp(n+1,vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++)
        {
            dp[0][i]=INT_MAX-1;
            if(i%coins[0]==0)
                dp[1][i]=i/coins[0];
            else
                dp[1][i]=INT_MAX-1;
        }
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(coins[i-1]>j)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
            }
        }
        return dp[n][amount]!=INT_MAX-1?dp[n][amount]:-1;
    }
};