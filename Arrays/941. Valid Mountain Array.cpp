class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool flag=false;
        int n=arr.size();
        if(n<3)
            return false;
        for(int i=1;i<n;i++)
        {
            if(!flag)
            {
             if(arr[i-1]<arr[i])
                 continue;
                else if(arr[i-1]==arr[i])
                    return false;
                else{
                    if(i==1)
                        return false;
                    flag=true;
                }
            }
            else
            {
                if(arr[i-1]>arr[i])
                 continue;
                else
                    return false;
            }
        }
        return flag;
    }
};