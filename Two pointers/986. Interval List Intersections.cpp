class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n=firstList.size();
        int m=secondList.size();
        int i=0,j=0;
        vector<vector<int>>ans;
        while(i<n && j<m){
           // cout<<i<<" "<<j<<endl;
            if(firstList[i][0]>secondList[j][1]){
                j++;
            }
            else if( firstList[i][1]<secondList[j][0])
                i++;
            else{
                int start=max(firstList[i][0],secondList[j][0]);
                int end=min(firstList[i][1],secondList[j][1]);
                ans.push_back({start,end});
                if(end==secondList[j][1])
                    j++;
                if(end==firstList[i][1])
                    i++;
            }
        }
       /* while(i++<n){
            ans.push_back(firstList[i]);}
        while(j++<m){
            ans.push_back(secondList[j]);}*/
        return ans;
    }
};