class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.length();
        int ascii[26];
        memset(ascii,0,sizeof(ascii));
        transform(s.begin(),s.end(),s.begin(),::tolower);
        ascii['a'-'a']=1;
        ascii['e'-'a']=1;
        ascii['i'-'a']=1;
        ascii['o'-'a']=1;
        ascii['u'-'a']=1;
        int v1=0,v2=0;
        for(int i=0,j=s.length()/2;s[j];i++,j++)
        {
            if(ascii[s[i]-'a']==1)
                v1++;
            if(ascii[s[j]-'a']==1)
                v2++;
        }
        return v1==v2;
    }
};