class Solution {
public:
    int numTrees(int n) {
        if(n<=1)
            return n;
        vector<int>dp(n+1,0);
        dp[1]=1,dp[2]=2;
        for(int i=3;i<=n;i++){
            for(int j=0;j<i;j++){
                dp[i]+=(dp[j]*dp[i-j-1]==0?dp[j]+dp[i-j-1]:dp[j]*dp[i-j-1]);
            }
        }
        return dp[n];
    }
};