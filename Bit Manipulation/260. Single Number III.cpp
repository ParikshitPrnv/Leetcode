class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor1=0;
        for(auto i:nums)
        {
            xor1=xor1^i;
        }
        int lastbit;
        for(int i=0;i<32;i++)
        {
            if(xor1&(1<<i))
            {
                lastbit=(1<<i);
             break;}
        }
        int first=0,second=0;
        for(auto i:nums)
        {
            if(i&lastbit)
                first=first^i;
            else
                second=second^i;
        }
        return {first,second};
    }
};