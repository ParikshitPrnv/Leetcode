class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>dp(num+1,0);
        
        for(int i=1;i<=num;i++)
        {
            int n=i;
            int count=0;
            while(n>0)
            {
                n=n&(n-1);
                count++;
            }
            dp[i]=count;
        }
return dp;
    }
};