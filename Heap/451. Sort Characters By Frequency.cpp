#define pi pair<int,int>
class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pi,vector<pi>> pq;
        int ascii[256];
        memset(ascii,0,sizeof(ascii));
        for(auto i:s){
            ascii[i]++;
        }
        for(int i=0;i<256;i++){
            if(ascii[i]>0)
            pq.push({ascii[i],i});
        }
        string ans="";
        while(!pq.empty()){
            pi temp=pq.top();
            pq.pop();
            char c=temp.second;
            for(int i=0;i<temp.first;i++)
            {
                
                ans.push_back(c);
            }
        }
        return ans;
    }
};