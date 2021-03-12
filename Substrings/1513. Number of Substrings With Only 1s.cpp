class Solution {
public:
    int numSub(string s) {
        int mod=pow(10,9)+7;
        int curr_length=0;
        int ans=0;
        for(int i=0;s[i];i++)
        {
            ans=(ans%mod+curr_length%mod)%mod;
            if(s[i]=='0')
                curr_length=0;
            else
                curr_length++;
        }
        ans=(ans%mod+curr_length%mod)%mod;
        return ans;
    }
};