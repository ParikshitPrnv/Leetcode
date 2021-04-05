class Solution {
public:
   
    int countInversions(vector<int> &A,int n)
    {
        multiset<int>mset;
        mset.insert(A[0]);
        int inversions=0;
        for(int i=1;i<n;i++)
        {
            mset.insert(A[i]);
            auto pos=mset.upper_bound(A[i]);
            inversions+=distance(pos,mset.end()); //mset.end() should be at the end        
        }
        return inversions;
    }
    int countLocalInversions(vector<int> &temp,int n)
    {
        int count=0;
        for(int i=0;i<n-1;i++)
        {
            if(temp[i]>temp[i+1])
                count++;
        }
        return count;
    }
    bool isIdealPermutation(vector<int>& A) {
        int GlobalInversions=countInversions(A,A.size());
        int localInversions=countLocalInversions(A,A.size());
        return localInversions==GlobalInversions;
    }
};