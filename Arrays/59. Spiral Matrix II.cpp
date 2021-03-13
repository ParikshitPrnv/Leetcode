class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int rowbegin=0,rowend=n-1,colbegin=0,colend=n-1;
        vector<vector<int> >spiral(n,vector<int>(n,0));
        int count=1;
        while(rowbegin<=rowend && colbegin<=colend)
        {
           // if(colbegin<=colend)
            {
               for(int i=colbegin;i<=colend;i++,count++)
               {
                   spiral[rowbegin][i]=count;
               }
                rowbegin++;
            }
           // if(rowbegin<=rowend)
            {
                for(int i=rowbegin;i<=rowend;i++,count++)
                    spiral[i][colend]=count;
                colend--;
            }
          //  if(colbegin<=colend)
            {
                for(int i=colend;i>=colbegin;i--,count++)
                    spiral[rowend][i]=count;
                rowend--;
            }
           // if(rowbegin<=rowend)
            {
                for(int i=rowend;i>=rowbegin;i--,count++)
                    spiral[i][colbegin]=count;
                colbegin++;
            }
        }
        return spiral;
    }
};