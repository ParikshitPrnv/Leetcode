class Solution {
public:
    int minPartitions(string n) {
        int max_val=0;
        for(auto i:n)
        {
            max_val=max(max_val,i-'0');
        }
        return max_val;
    }
};