class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int> >dp(n,vector<int>(n,2));
        map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[arr[i]]=i;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(m.find(arr[i]-arr[j])!=m.end() && m[arr[i]-arr[j]]<j)
                {
                    dp[j][i]=max(dp[j][i],1+dp[m[arr[i]-arr[j]]][j]);
                }
            }
        }
        int ans=0;
        for (auto i:dp)
        {
            for(auto j:i)
            {
                ans=max(ans,j);
            }
        }
        return ans==2?0:ans;
            
       
    }
};