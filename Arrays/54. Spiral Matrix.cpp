class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int>ans;
        if(n==0)
            return ans;
        int m=matrix[0].size();
        int rowbegin=0,rowend=n-1;
        int colbegin=0,colend=m-1;
        while(rowbegin<=rowend && colbegin<=colend)
        {
            for(int col=colbegin;col<=colend;col++)
                ans.push_back(matrix[rowbegin][col]);
            rowbegin++;
            if(!(rowbegin<=rowend && colbegin<=colend))
                break;
            for(int row=rowbegin;row<=rowend;row++)
                ans.push_back(matrix[row][colend]);
            colend--;
            if(!(rowbegin<=rowend && colbegin<=colend))
                break;
            for(int col=colend;col>=colbegin;col--)
                ans.push_back(matrix[rowend][col]);
            rowend--;
            if(!(rowbegin<=rowend && colbegin<=colend))
                break;
            for(int row=rowend;row>=rowbegin;row--)
                ans.push_back(matrix[row][colbegin]);
            colbegin++;
        }
        return ans;
    }
};