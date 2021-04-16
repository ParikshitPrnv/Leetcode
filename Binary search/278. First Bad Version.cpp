// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n,int low=1,int high=INT_MAX) {
        if(isBadVersion(n-1)==false && isBadVersion(n)==true)
            return n;
        if(isBadVersion(n)==false)
            low=n+1;
        else
            high=n-1;
        return firstBadVersion(low+(high-low)/2,low,high);
    }
};