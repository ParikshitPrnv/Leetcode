class Solution {
public:
    int minStartValue(vector<int>& nums) {
       int sum=0;
        int min_start_value=1;
        for(auto i:nums)
        {
            sum+=i;
            min_start_value=max(min_start_value,1-sum);
        }
        return min_start_value;
    }
};
/*
We need to find a start value that needs to be big enough 
so that for any number in the input array the sum of the start value 
and all further numbers up to that number is at least one. 
To find such a number we need to sum up all the numbers 
and at each step check if the current prefix sum is a new minimum. 
Our start value needs to make up for that minimum prefix sum 
and we also need to add one so we are at least at 1 (start_value = -min_prefix_sum + 1).

Here is the calculation using the sample input:

num                 -3   2  -3   4   2
prefix sum          -3  -1  -4   0   2
min prefix sum      -3  -3  -4  -4  -4
min start value      4   4   5   5   5
*/