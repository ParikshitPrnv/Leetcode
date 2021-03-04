/* By marking the element (setting them as negative)*/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int duplicate=-1,missing=-1;
        {
            for(auto i:nums)
            {
                if(nums[abs(i)-1]<0) //means already marked index and present more than once
                    duplicate=abs(i); //duplicate number
                else
                    nums[abs(i)-1]*=-1;
            }
            for(int i=0;i<nums.size();i++)
            {
                // nums[i]>0 means index is not marked 
                //so the number equal to this index is missing
                if(nums[i]>0)
                {missing=i+1;
                break;
                }
            }
        }
        return {duplicate,missing};
    }
};