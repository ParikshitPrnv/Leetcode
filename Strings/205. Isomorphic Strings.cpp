class Solution {
public:
    bool isIsomorphic(string word, string pattern) {
         int n=word.length();
        int m=pattern.length();
            if(n!=m)
                return false;
            map<char,char>mp;
            map<char,char>mp2;
            int i=0;
            for(i=0;i<n;i++){
                if(i==0){
                    mp[pattern[i]]=word[i];
                    mp2[word[i]]=pattern[i];
                    continue;
                }
                if(pattern[i]==pattern[i-1] && word[i]==word[i-1])
                    continue;
                else if(pattern[i]!=pattern[i-1] && word[i]!=word[i-1]){
                    if(mp.find(pattern[i])!=mp.end() && mp[pattern[i]]!=word[i]){
                        return false;
                    }
                    else if(mp2.find(word[i])!=mp2.end() && mp2[word[i]]!=pattern[i])
                        return false;
                    else
                    {mp[pattern[i]]=word[i];
                     mp2[word[i]]=pattern[i];}
                }
                else
                    return false;
            }
            return true;
    }
};