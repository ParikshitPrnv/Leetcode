
#define pi pair<int,int>
class Solution {
public:
    
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(auto i:nums)
            freq[i]++;
        sort(nums.begin(),nums.end(), [&freq](int &a,int &b){
           if(freq[a]==freq[b])
               return a>b;
            else
                return freq[a]<freq[b];
        });
        return nums;
    }
};