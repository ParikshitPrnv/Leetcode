class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        
        unordered_map<int,int>mp;
        vector<int>ans;
        int n=T.size();
        for(int i=n-1;i>=0;i--)
        {
           // cout<<T[i]<<"\n";
            mp[T[i]]=i;
            int j=T[i]+1;
            int min_diff=INT_MAX;
            for(auto j:mp)
            {
                
                    //cout<<mp[j]<<" ";
                if(j.first>T[i])
                    min_diff=min(min_diff,abs(j.second-i));
                
            }
            //cout<<endl;
            if(min_diff==INT_MAX)
                ans.push_back(0);
            else
                ans.push_back(min_diff);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};