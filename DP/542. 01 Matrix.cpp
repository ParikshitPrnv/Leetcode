//can be solved using bfs as well
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int ax=pow(10,5);
        vector<vector<int>>ans(n,vector<int>(m,ax));
        
        //first pass checking top and left
        for(int i=0;i<n;i++)
        {
            
            for(int j=0;j<m;j++)
            {
                //cout<<"here ";
                if(mat[i][j]==0)
                {
                    ans[i][j]=0;
                    continue;
                }
                if(j-1>=0)
                {
                    ans[i][j]=min(ans[i][j],1+ans[i][j-1]);
                }
                if(i-1>=0)
                    ans[i][j]=min(ans[i][j],1+ans[i-1][j]);
            }
        }
        
        //second pass checking bottom and right
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(mat[i][j]==0)
                {
                    ans[i][j]=0;
                    continue;
                }
                if(j+1<m)
                {
                    ans[i][j]=min(ans[i][j],1+ans[i][j+1]);
                }
                if(i+1<n)
                    ans[i][j]=min(ans[i][j],1+ans[i+1][j]);
            }
        }
        return ans;
    }
};