class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
       int n=nums.size();
        bool modified=false;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i])
            {
                if(modified)
                    return false;
                else{
                    modified=true;
                    if(i-2>=0 && nums[i-2]>nums[i])
                        nums[i]=nums[i-1];
                }
            }
        }
        return true;
    }
};