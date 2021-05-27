class FindSumPairs {
public:
    vector<int>p,q;
    map<int,int> mp,mq;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        p=nums1;
        q=nums2;
        for(auto i:p)
            mp[i]++;
        for(auto i:q)
            mq[i]++;
    }
    
    void add(int index, int val) {
        mq[q[index]]--;
        q[index]+=val;
        mq[q[index]]++;
    }
    
    int count(int tot) {
        int count=0;
        for(auto i:mp)
        {
            count+=(mq[tot-i.first]*i.second);
        }
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */