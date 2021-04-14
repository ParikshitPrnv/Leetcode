class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        for(int i=1;i<=groupSizes.size();i++)
        {
            vector<int>temp;
            for(int j=0;j<groupSizes.size();j++)
            {
                if(groupSizes[j]==i)
                {
                    temp.push_back(j);
                }
                if(temp.size()==i)
                {
                    ans.push_back(temp);
                    temp={};
                }
            }
        }
        return ans;
    }
};