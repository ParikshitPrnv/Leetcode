class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
            vector<unsigned>dp(target+1,0);
        dp[0]=1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<=target;i++)
        {
            for(auto j:nums)
            {
                if(j>i)
                    break;
                dp[i]+=dp[i-j];
            }
        }
        return dp[target];
    }
};