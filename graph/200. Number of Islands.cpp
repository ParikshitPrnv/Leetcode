class Solution {
public:
    vector<vector<int> >moves={{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(vector<vector<char>>& grid,vector<vector<bool>>& visited,int i,int j,int &n,int &m)
    {
        for(auto move:moves)
        {
            int row=i+move[0];
            int col=j+move[1];
            if(row>=0 && row<n && col>=0 && col<m && grid[row][col]=='1' && visited[row][col]==false)
            {
                visited[row][col]=true;
                dfs(grid,visited,row,col,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool> > visited(n,vector<bool>(m,false));
        int islands=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && visited[i][j]==false)
                {
                    visited[i][j]=true;
                    dfs(grid,visited,i,j,n,m);
                    islands++;
                }
            }
        }
        return islands;
    }
};