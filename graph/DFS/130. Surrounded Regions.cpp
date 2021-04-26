class Solution {
public:
    vector<vector<int>>moves={{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<bool>>vis;
    vector<vector<char>>obj;
    int n,m;
    void dfs(int i,int j){
        vis[i][j]=true;
        if(obj[i][j]=='X')
            return;
        for(auto move:moves){
            int row=move[0]+i;
            int col=move[1]+j;
            if(row>=0 && row<n && col>=0 && col<m && !vis[row][col]){
                dfs(row,col);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        
        n=board.size();
        if(n<=1)
            return;
        m=board[0].size();
        obj=board;
        vis.resize(n,vector<bool>(m,false));
        
        for(int i=0;i<m;i++)
        {
            if(!vis[0][i]){
                dfs(0,i);
            }
            if(!vis[n-1][i])
            {
                dfs(n-1,i);
            }
        }
       // cout<<"here";
        for(int i=0;i<n;i++){
            if(!vis[i][0])
                dfs(i,0);
            if(!vis[i][m-1])
                dfs(i,m-1);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};