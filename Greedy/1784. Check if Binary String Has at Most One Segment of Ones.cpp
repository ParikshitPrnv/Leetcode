class Solution {
public:
    bool checkOnesSegment(string s) {
        int i=0;
        for(i=0;s[i];i++)
        {
            if(s[i]=='0')
                break;
        }
        if(i==s.length())
            return true;
        for(;s[i];i++)
        {
            if(s[i]=='1')
                return false;
        }
        return true;
    }
};