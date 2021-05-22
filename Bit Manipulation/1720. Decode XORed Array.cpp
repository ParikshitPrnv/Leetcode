class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int>ans;
        ans.push_back(first);
        for(auto i:encoded)
            ans.push_back(i^ans.back());
        return ans;
    }
};
// A^B=C implements:
//A^C=B;
//B^C=A