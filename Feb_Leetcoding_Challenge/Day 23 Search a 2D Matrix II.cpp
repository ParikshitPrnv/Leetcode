class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        if(n==0)
            return false;
        int m=matrix[0].size();
        if(m==0)
            return false;
        for(int i=n-1;i>=0;i--)
        {
            if(matrix[i][0]>target)
                continue;
            if(matrix[i][0]<=target && matrix[i][m-1]>=target)
            {
                if(binary_search(matrix[i].begin(),matrix[i].end(),target))
                    return true;
            }
        }
        return false;
    }
};