class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int count=0;
        int zeros,ones;
        for(int i=0;i<32;i++)
        {
            zeros=0,ones=0;
            for(auto num:nums)
            {
                if((num&(1<<i)))
                    ones++;
                else
                    zeros++;
            }
            
            count+=(zeros*ones);
        }
        return count;
    }
};