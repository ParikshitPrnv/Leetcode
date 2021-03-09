class Solution {
public:
    
    int helper(vector<int>& nums, int S,int size,int idx,int sum,map<pair<int,int>,int> &memo)
    {
        if(idx==size)
        {
            if(sum==S)
                return 1;
            else
                return 0;
        }
        if(memo.find(make_pair(idx,sum))!=memo.end())
                return memo[make_pair(idx,sum)];        memo[make_pair(idx,sum)]=helper(nums,S,size,idx+1,sum+nums[idx],memo)+helper(nums,S,size,idx+1,sum-nums[idx],memo);
        return memo[make_pair(idx,sum)];
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        map<pair<int,int>,int>memo;
        return helper(nums,S,nums.size(),0,0,memo);
        
    }
};