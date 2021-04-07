class Solution {
public:
    bool unordered(string &first,string &second,map<char,int> &mp)
    {
        int i=-1,j=-1,n=first.length(),m=second.length();
        while(++i<n && ++j<m)
        {
            if(mp[first[i]]>mp[second[j]])
                return false;
            else if(mp[first[i]]<mp[second[j]])
                return true;
        }
        if(i!=n && j==m)
            return false;
        return true;
        
    }
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int>mp;
        for(int i=0;order[i];i++)
            mp[order[i]]=i;
        for(int i=0;i<words.size()-1;i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if(!unordered(words[i],words[j],mp))
                    return false;
            }
        }
        return true;
    }
};