class Solution {
public:
    int findLHS(vector<int>& nums) {
     map<int,int>m;
        int n=nums.size();
        for(auto i:nums)
            m[i]++;
        int big=0;
        int sum=0;
        for(auto i:m)
        {
            if(m[i.first-1]==0)
                continue;
            sum=i.second+m[i.first-1];
            cout<<i.first<<" "<<sum<<endl;
            big=max(big,sum);
        }
        return big;
    }
};