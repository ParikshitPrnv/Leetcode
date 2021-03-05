class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>v=nums;
        sort(v.begin(),v.end());
        int n=nums.size();
        int count=0;
        int start=0;
        int end=-1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==v[i])
            {
               continue;
            }
            start=i;
            break;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]==v[i])
                continue;
            end=i;
            break;
        }
        return end-start+1;
    }
};