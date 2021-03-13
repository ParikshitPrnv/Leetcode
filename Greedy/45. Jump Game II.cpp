class Solution {
public:
    int helper(vector<int>& nums,int n,int i,vector<int> &memo)
    {
        if(i>=n-1)
            return 0;
        if(nums[i]==0)
            return 1005;
        if(memo[i]!=-1)
            return memo[i];
        int ans=INT_MAX;
        for(int j=1;j<=nums[i];j++)
        {
            ans=min(ans,1+helper(nums,n,i+j,memo));
        }
        memo[i]=ans;
        return ans;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>memo(n,-1);
        memo[n-1]=0;
        return helper(nums,n,0,memo);
    }
};