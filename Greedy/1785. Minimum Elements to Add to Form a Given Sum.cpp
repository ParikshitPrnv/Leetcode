class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long sum=0;
        for(auto i:nums)
            sum+=i;
        long des=goal;
        long diff=abs(sum-des);
        long times=diff/limit;
        if(limit*times==diff)
            return times;
        else
            return times+1;
        
    }
};