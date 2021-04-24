class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.length();
        int count=0;
        int i=0;
        while(i<n)
        {
            //cout<<i<<" ";
            int zeros=0,ones=0;
            int j=i;
            while(j<n && s[i]==s[j]){
                j++;
                if(s[i]=='0')
                    zeros++;
                else
                    ones++;
            }
            while(j<n && s[i]!=s[j])
            {
                j++;
                if(s[i]=='0')
                    ones++;
                else
                    zeros++;
            }
            //cout<<zeros<<" "<<ones<<endl;
            if(zeros==0 || ones==0)
            {
                i+=zeros+ones;
            }
            else
            {
                count+=min(zeros,ones);
                if(s[i]=='0')
                    i+=zeros;
                else
                    i+=ones;
            }
        }
        return count;
    }
};