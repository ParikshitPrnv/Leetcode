class Solution {
public:
    int count;
    int n;
    bool isPossible(int row,int col,vector<string> &current){
        //cout<<"entered isPossible\n";
         //cout<<"row,col check\n";
        for(int i=0;i<n;i++){
            if(current[row][i]=='Q' || current[i][col]=='Q')
                return false;
        }
        //cout<<"upper right diagnol check\n";
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(current[i][j]=='Q')
                return false;
        }
        //cout<<"upper left diagnol check\n";
        for(int i=row,j=col;j<n && i>=0;i--,j++){
            if(current[i][j]=='Q')
                return false;
        }
        return true;
    }
    void helper(int i,vector<string> &current){
        //cout<<"\nrow: "<<i<<endl;
        if(i==n)
        {
            count++;
          //  cout<<"solution_found\n";
            //for(auto i:current)
              //  cout<<i<<"\n";
            return;
        }
        for(int j=0;j<n;j++){
           // cout<<"col check: "<<j<<"\n";
            if(isPossible(i,j,current))
            {
             //   cout<<"passed:\n";
                current[i][j]='Q';
                helper(i+1,current);
                current[i][j]='.';
            }
           // cout<<"loop out";
        }
    }
    int totalNQueens(int n) {
        this->n=n;
        count=0;
        vector<string>current;
        for(int i=0;i<n;i++){
            string x="";
            for(int j=0;j<n;j++)
                x.push_back('.');
            current.push_back(x);
            //cout<<x<<endl;
        }
        helper(0,current);
        return count;
    }
};