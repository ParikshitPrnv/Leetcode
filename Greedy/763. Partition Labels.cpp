class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>>intervals;
        vector<int>first(26,-1);
        vector<int>last(26,-1);
        int n=s.length();
        for(int i=0,j=n-1;s[i];i++,j--){
            if(first[s[i]-'a']==-1){
                first[s[i]-'a']=i;
            }
            if(last[s[j]-'a']==-1){
                last[s[j]-'a']=j;
            }
        }
        
        for(int i=0;i<26;i++){
            if(first[i]==-1)
                continue;
            else
                intervals.push_back({first[i],last[i]});
        }
        
        sort(intervals.begin(),intervals.end(), [this](vector<int>& a,vector<int>& b){
           return a[0]<b[0]; 
        });
        
        vector<int>ans;
        int start=-1,end=-1;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]>end){
                start=intervals[i][0];
                end=intervals[i][1];
                ans.push_back(end-start+1);
            }
            else{
                int current=ans.back();
                if(end<intervals[i][1]){
                    ans.pop_back();
                    ans.push_back(current+abs(end-intervals[i][1]));
                    end=intervals[i][1];
                }
                
            }
        }
        return ans;
    }
};