class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int m=pattern.length();
        vector<string>ans;
        
        for(auto word:words){
            int n=word.length();
            if(n!=m)
                continue;
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
                        break;
                    }
                    else if(mp2.find(word[i])!=mp2.end() && mp2[word[i]]!=pattern[i])
                        break;
                    else
                    {mp[pattern[i]]=word[i];
                     mp2[word[i]]=pattern[i];}
                }
                else
                    break;
            }
            if(i==n)
                ans.push_back(word);
        }
        return ans;
    }
};