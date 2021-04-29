class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=-1,end=-1;
        int low=0,high=nums.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            cout<<"\nlow: "+to_string(low)+" , high: "+to_string(high)+", mid: "+to_string(mid);
            if(nums[mid]==target)
            {
                start=mid;
                end=mid;
                low=mid;
                high=mid;
                while(low>=0)
                {
                    if(nums[low]!=target)
                        break;
                    start=low;
                    low--;
                }
                while(high<nums.size())
                {
                    if(nums[high]!=target)
                        break;
                    end=high;
                    high++;
                }
                break;
            }
            else if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        
            return {start,end};
        }
};