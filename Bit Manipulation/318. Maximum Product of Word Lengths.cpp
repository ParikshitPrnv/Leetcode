class Solution {
public:
    int maxProduct(vector<string>& words) {
        if(words.size()==0)
            return 0;
        vector<int>v;
        for(auto word:words)
        {
            int num=0;
            for(int letter=0;word[letter];letter++)
            {
                num=num|(1<<(word[letter]-'a'));
            }
            v.push_back(num);
        }
        int ans=0;
        
        for(int i=0;i<v.size()-1;i++)
        {
            for(int j=i+1;j<v.size();j++)
            {
                if((v[i]&v[j])==0)
                {
                    int p=(words[i].length()*words[j].length());
                    ans=max(ans,p);
                }
            }
        }
        return ans;
    }
};