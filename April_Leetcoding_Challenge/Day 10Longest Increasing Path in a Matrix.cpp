class Solution {
public:
    vector<vector<int>>moves={{0,1},{1,0},{-1,0},{0,-1}};
    vector<vector<int>>vis;
    vector<vector<int>>mat;
    int n,m;
    int calculate(int i,int j){
        //cout<<i<<" "<<j<<endl;
        if(vis[i][j]!=-1)
            return vis[i][j];
        int ans=0;
        for(auto move:moves){
            int r=i+move[0];
            int c=j+move[1];
            if(r>=0 && r<n && c>=0 && c<m &&  mat[r][c]<mat[i][j]){
                if(vis[r][c]==-1)
                    calculate(r,c);
                ans=max(ans,vis[r][c]+1);
            }
        }
        vis[i][j]=ans;
        return ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans=0;
        mat=matrix;
         n=matrix.size();
         m=matrix[0].size();
        vis.resize(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==-1)
                    calculate(i,j);
                ans=max(ans,vis[i][j]+1);
            }
        }
        return ans;
    }
};