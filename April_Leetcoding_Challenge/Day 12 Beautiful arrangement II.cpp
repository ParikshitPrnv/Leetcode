class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int>ans;
        int beg=1,end=beg+k;
        unordered_map<int,bool>mp;
        while(beg<end)
        {
            ans.push_back(beg);
            ans.push_back(end);
            mp[beg]=true;
            mp[end]=true;
            beg++;
            end--;
        }
        for(int i=1;i<=n;i++)
        {
            if(mp[i]==false)
            ans.push_back(i);
        }
        return ans;
    }
};