class Solution {
public:
    inline bool isnext(char &a,char &b)
    {
        return a=='z'?b=='a':a+1==b;
    }
    int findSubstringInWraproundString(string p) {
       unordered_map<char,int>m;
        int max_length=1;
        for(int i=0;p[i];i++)
        {
            if(m[p[i]]==0)
            {
                m[p[i]]=max_length;
            }
            else
                m[p[i]]=max(max_length,m[p[i]]);
            if( i+1<p.length() && isnext(p[i],p[i+1]))
                max_length++;
            else
                max_length=1;
        }
        int sum=0;
        for(auto i:m)
            sum+=i.second;
        return sum;
    }
};