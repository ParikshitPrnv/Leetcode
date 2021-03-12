class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char>m;
         unordered_map<char,string>m2;
        vector<string>v;
        int start=0;
        for(int i=0;s[i];i++)
        {
            if(s[i]==' ')
            {
               // cout<<s.substr(start,i-start).length()<<endl;
                v.push_back(s.substr(start,i-start));
                start=i+1;
            }
        }
        v.push_back(s.substr(start,s.length()-start));
        //cout<<s.substr(start,s.length()-start).length()<<endl;
        
        if(pattern.length()!=v.size())
            return false;
        
        for(int i=0;i<v.size();i++)
        {
            if(m.find(v[i])==m.end() && m2.find(pattern[i])==m2.end())
            {
                m[v[i]]=pattern[i];
                m2[pattern[i]]=v[i];
            }
            else if (m.find(v[i])!=m.end() && m2.find(pattern[i])!=m2.end())
            {
                   if(m[v[i]]!=pattern[i])
                       return false;
                if(m2[pattern[i]]!=v[i])
                    return false;
            }
            else
                return false;
                
        }
        
        return true;
    }
};