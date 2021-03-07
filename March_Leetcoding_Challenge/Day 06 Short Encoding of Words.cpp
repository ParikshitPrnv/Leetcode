class Solution {
public:
    bool ispresent(string &outer,string &inner)
    {
        for(int i=outer.length()-inner.length(),j=0;outer[i];i++,j++)
        {
            if(outer[i]!=inner[j])
                return false;
        }
        return true;
    }
    int minimumLengthEncoding(vector<string>& words) {
        int length=0;
        vector<int>v(words.size(),-1);
        for(int i=0;i<words.size();i++)
        {
            if(words[i].length()==0)
                continue;
            bool flag=false;
            for(int j=0;j<words.size();j++)
            {
                if(words[j].length()==0 || words[j].length()<words[i].length())
                continue;
                if(v[j]==1)
                    continue;
                if(i==j)
                    continue;
                if(ispresent(words[j],words[i]))
                {
                    v[i]=1;
                    flag=true;
                    break;
                }
            }
            if(!flag)
            {
                length+=words[i].length()+1; 
            }
           
        }
                   return length;
    }
};