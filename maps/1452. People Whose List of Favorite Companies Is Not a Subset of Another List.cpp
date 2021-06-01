class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int id=0;
        //Lookup creation
        unordered_map<string,int>lookup;
        for(auto choice:favoriteCompanies){
            for(auto company:choice){
                if(lookup.find(company)==lookup.end())
                    lookup[company]=id++;
            }
        }
        
        //vector transformation
        int n=favoriteCompanies.size();
        vector<unordered_map<int,bool>>companies(n);
        for(int i=0;i<n;i++){
            for(auto company:favoriteCompanies[i])
                companies[i][lookup[company]]=true;
        }
        
        //traversal
        vector<int>ans;
        for(int i=0;i<n;i++){
            bool flag=true;
            for(int j=0;j<n && flag;j++){
                if(i==j || companies[j].size()<companies[i].size())
                    continue;
                int count=0;
                for(auto name:companies[i]){
                    if(companies[j].find(name.first)!=companies[j].end())
                        count++;
                    else
                        break;
                }
                if(count==companies[i].size())
                    flag=false;
            }
            if(flag)
                ans.push_back(i);
        }
        return ans;
        
    }
};