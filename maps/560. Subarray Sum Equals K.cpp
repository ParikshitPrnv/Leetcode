class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>freq;
        freq[0]=1;
        int ans=0;
        int curr_sum=0;
        for(int i=0;i<n;i++){
            curr_sum+=nums[i];
            if(freq.find(curr_sum-k)!=freq.end())
            {
                ans+=freq[curr_sum-k];
            }
            freq[curr_sum]++;
        }
        return ans;
    }
};