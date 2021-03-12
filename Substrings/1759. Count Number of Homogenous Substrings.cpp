class Solution {
public:
    int countHomogenous(string s) {
        if(s.length()==0)
            return 0;
        char c=s[0];
        int mod=pow(10,9)+7;
        int curr_length=1;
        int ans=0;
        for(int i=1;s[i];i++)
        {
            ans=(ans%mod+curr_length%mod)%mod;
            if(s[i]!=c){
                curr_length=1;
                c=s[i];
            }
            else
                curr_length++;
        }
        ans=(ans%mod+curr_length%mod)%mod;
        return ans;
    }
};