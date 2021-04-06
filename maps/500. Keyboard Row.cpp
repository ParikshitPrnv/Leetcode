class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string>ans;
        vector<string>m={"qwertyuiopQWERTYUIOP","asdfghjklASDFGHJKL","zxcvbnmZXCVBNM"};
        //cout<<m[0]<<endl<<m[1]<<endl<<m[2];
        
        for(auto word:words)
        {
            int id;
            if(m[0].find(word[0])!=string::npos)
                id=0;
            else if(m[1].find(word[0])!=string::npos)
                id=1;
            else
                id=2;
            //cout<<"\n id: "<<id;
            bool flag=true;
            for(auto i:word)
            {
                if(!(m[id].find(i)!=string::npos))
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
                ans.push_back(word);
        }
        return ans;
    }
};