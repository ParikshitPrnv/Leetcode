class Solution {
public:
        
    vector<vector<int>>moves={{0,1},{0,-1},{1,0},{-1,0}};
    int count=0;
    
    bool ispossible(vector<vector<int>>& grid,vector<vector<bool>>& visited,int i,int j,int n,int m)
    {
        if(i<0 || i>=n || j<0 || j>=m)
                    return false ;
        if(grid[i][j]==-1)
                    return false;
        if(visited[i][j]==true)
            return false;
        return true;
    }
    void backtrack(vector<vector<int>>& grid,vector<vector<bool>>& visited,int i,int j,int n,int m,int nobstacles)
    {
     //cout<<i<<","<<j<<"->";       
            if(grid[i][j]==2)
            {
                //cout<<"\n";
                if(nobstacles==-1)
                    count++;
                    return;
            }
            for(auto move:moves)
            {
                    if(ispossible(grid,visited,i+move[0],j+move[1],n,m))
                    {
                        visited[i+move[0]][j+move[1]]=true;
                        backtrack(grid,visited,i+move[0],j+move[1],n,m,nobstacles-1);
                        visited[i+move[0]][j+move[1]]=false;
                    }
            }
    }
            
            
    int uniquePathsIII(vector<vector<int>>& grid) {
            
        int n=grid.size();
        int m=grid[0].size();
            
        vector<vector<bool> >visited(n,vector<bool>(m,false));
        
        int nobstacles=0;
        for(auto i:grid)
        {
            for(auto j:i)
            {
                if(j==0)
                    nobstacles++;
            }
        }
        cout<<nobstacles;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    
                    visited[i][j]=true;
                    backtrack(grid,visited,i,j,n,m,nobstacles);
                }
            }
        }
            
        return count;
    }
};