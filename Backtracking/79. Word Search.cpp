class Solution {
public:
    vector<vector<char>> board;
    int n,m;
    vector<vector<bool>> vis;
    vector<vector<int>> moves={{0,1},{0,-1},{1,0},{-1,0}};
    string word;
    int len;
    int count=0;
    bool backtrack(int i,int j,int index){
        count++;
        if(index==len)
            return true;
        for(auto move:moves){
            int row=i+move[0],col=j+move[1];
            if(row>=0 && row<n && col>=0 && col<m && vis[row][col]==false && board[row][col]==word[index]){
                vis[row][col]=true;
                if(backtrack(row,col,index+1))
                    return true;
                vis[row][col]=false;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        this->board=board;
        n=board.size();
        m=board[0].size();
        this->word=word;
        len=word.length();
        unordered_map<char,int>mp;
        for(auto i:board)
            for(auto j:i)
                mp[j]++;
        unordered_map<char,int>mp2;
        for(auto i:word)
            mp2[i]++;
        for(auto i:mp2)
            if(mp[i.first]<i.second)
                return false;
        vis.resize(n,vector<bool>(m,false));
                    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0])
                {
                    //memset(vis,false,sizeof(vis));
                  //  cout<<count<<endl;
                    vis[i][j]=true;
                    if(backtrack(i,j,1))
                        return true;
                    vis[i][j]=false;
                }
            }
        }
        return false;
    }
};