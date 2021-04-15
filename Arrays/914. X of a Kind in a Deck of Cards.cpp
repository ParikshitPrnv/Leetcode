//Alternative: USE GCD
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int,int>m;
        int max_freq=0;
        for(auto i:deck)
        {
            m[i]++;
            max_freq=max(max_freq,m[i]);
        }
        for(int i=2;i<=max_freq;i++)
        {
            bool flag=true;
            for(auto j:m)
            {
                if(j.second<i)
                    return false;
                if(j.second%i!=0)
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
                return true;
            
        }
        return false;
    }
};