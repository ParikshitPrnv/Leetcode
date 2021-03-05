class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size=nums.size();
        for(int i=0;i<size;i++)
            nums[i]++;
        for(auto i:nums)
        {
            if(abs(i)-1>size-1)
                continue;
            else
                nums[abs(i)-1]*=-1;
        }
         
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
                return i;
        }
        return size;
    }
};