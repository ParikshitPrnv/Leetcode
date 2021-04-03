class Solution {
public:
    int memo( vector<vector<int>>& counts,int*** dp,int i,int m,int n)
    {
        if(i==counts.size())
        {
            return 0;
        }
        if(dp[i][m][n]!=-1)
            return dp[i][m][n];
        if(counts[i][0]<=m && counts[i][1]<=n)
        {
            int output1=1+memo(counts,dp,i+1,m-counts[i][0],n-counts[i][1]);
            int output2=memo(counts,dp,i+1,m,n);
            dp[i][m][n]=max(output1,output2);
        }
        else
            dp[i][m][n]=memo(counts,dp,i+1,m,n);
        return dp[i][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int> >counts(strs.size(),vector<int>(2,0));
        for(int i=0;i<strs.size();i++)
        {
            for(int j=0;strs[i][j];j++)
            {
                counts[i][strs[i][j]-'0']++;
            }
        }
        
        int ***dp=new int**[strs.size()];
        for(int i=0;i<strs.size();i++)
        {
            dp[i]=new int*[m+1];
            for(int j=0;j<=m;j++)
            {
                dp[i][j]=new int[n+1];
                for(int k=0;k<=n;k++)
                    dp[i][j][k]=-1;
            }
        }
        
        int ans= memo(counts,dp,0,m,n);
        for(int i=0;i<strs.size();i++)
        {
            for(int j=0;j<=m;j++)
            {
                delete[] dp[i][j];
            }
            delete[] dp[i];
        }
        delete[] dp;
        return ans;
    }
};