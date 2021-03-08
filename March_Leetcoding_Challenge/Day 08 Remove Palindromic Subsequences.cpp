class Solution {
public:
    bool isPalindrome(string &s)
    {
        for(int i=0,j=s.length()-1;i<j;i++,j--)
        {
            if(s[i]!=s[j])
                return false;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if(s=="")
            return 0;
        if(isPalindrome(s))
            return 1;
        int a,b;
        for(auto i:s)
        {
            if(i=='a')
                a++;
            else
                b++;
        }
        return a==0||b==0?1:2;
    }
};