class Solution {
public:
    bool subset(vector<int>& nums,int target){
        int n=nums.size();
        vector<vector<bool>>dp(n+1,vector<bool>(target+1,false));
        for(int i=0;i<=n;i++)
            dp[i][0]=true;

        for(int i=1;i<=n;i++){
           // cout<<endl<<i<<"\n";
            for(int j=1;j<=target;j++)
            {
                
                if(nums[i-1]>j)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j-nums[i-1]]||dp[i-1][j];
              //  cout<<dp[i][j]<<" ";
            }
        }
        return dp[n][target];
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        //cout<<sum/2<<endl;
        if(sum%2!=0)
            return false;
        return subset(nums,sum/2);
    }
};