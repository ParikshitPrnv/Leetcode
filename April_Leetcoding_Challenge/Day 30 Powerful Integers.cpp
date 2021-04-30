class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int>v1;
        vector<int>v2;
        for(int i=0;pow(x,i)<bound;i++){
            v1.push_back(pow(x,i));
            if(x==1)
                break;
        }
        for(int i=0;pow(y,i)<bound;i++){
            v2.push_back(pow(y,i));
            if(y==1)
                break;
            
        }
        vector<int>ans;
        set<int>s;
        for(int i=0;i<v1.size();i++){
            for(int j=0;j<v2.size();j++){
                if(v1[i]+v2[j]>bound)
                    break;
                else
                  s.insert(v1[i]+v2[j]);  
            }
        }
        ans=vector<int>(s.begin(),s.end());
        return ans;
    }
};