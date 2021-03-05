class Solution {
public:
    int romanToInt(string s) {
        int num=0;
        unordered_map<char,int>m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        
        string t="IVXLCDM";
        if(s.length()==1)
            return m[s[0]];
        for(int i=0;s[i];i++)
        {
            num+=m[s[i]];
            if(i==0)
                continue;
            int found=t.find(s[i]);
                int found2=t.find(s[i-1]);
            if(found>found2)
                num-=2*m[s[i-1]];
        }
        
        //if(s.length()%2!=0)
          //  num+=m[s[s.length()-1]];
        return num;
    }
};