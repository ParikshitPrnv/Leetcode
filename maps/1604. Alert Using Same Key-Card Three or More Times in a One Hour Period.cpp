bool cmp(string &a,string &b)
{
    return a<b;
}
class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        
        unordered_map<string,vector<int> >mp; //map to bucket timings of each person
        vector<string>ans;
        for(int i=0;i<keyName.size();i++)
        {
                int hr=stoi(keyTime[i].substr(0,2));
                int min=stoi(keyTime[i].substr(3,2));
            mp[keyName[i]].push_back(hr*60+min);
        }
        for(auto i:mp)
        {
            if(i.second.size()<3)
                continue;
            sort(i.second.begin(),i.second.end());
            int start_min=i.second[0];
            int ind=0;
            int count=1;
            for(int j=1;j<i.second.size();j++)
            {
                
                int curr_min=i.second[j];
                //cout<<start_min<<" "<<curr_min<<endl;
                if(curr_min-start_min<0)
                {
                    start_min=curr_min;
                    count=1;
                    ind=j;
                }
                while(curr_min-start_min>60)
                {
                    ind++;
                    count--;
                   start_min=i.second[ind];
                }
                count=j-ind+1;
                if(count==3)
                {
                    ans.push_back(i.first);
                    break;
                }
            }
        }
        sort(ans.begin(),ans.end(),cmp);
        return ans;
    }
};