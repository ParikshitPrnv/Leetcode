class Solution {
public:
    int minOperations(int n) {
        long long sum=0;
        int i=1;
        int t=n;
        while(t)
        {
            sum+=i;
            i+=2;
            t--;
        }
        long long total=sum/n;
        i=1;
        t=n;
        long long ans=0;
        while(t--)
        {
            ans+=abs(total-i);
            i+=2;
        }
        return ans/2;
    }
};