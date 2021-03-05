class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n=A.size();
        if(n<3)
            return 0;
        vector<int>v;
        for(int i=1;i<n;i++)
            v.push_back(A[i]-A[i-1]);
        int count=0;
        int i=0;
        //cout<<v.size()<<" ";
        while(i<v.size())
        {
            int size=1;
            int j=i;
            while(j<v.size() && v[j]==v[i]){
                j++;
                size++;
            }
            cout<<size<<endl;
            if(size<3)
            {
                i++;
                continue;
            }
            count+=size-2;
            i++;
        }
        return count;
    }
};