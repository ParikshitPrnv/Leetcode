class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==0)
            return 0;
        
        sort(intervals.begin(),intervals.end(), [](vector<int> &a, vector<int> &b){
            if(a[0]==b[0])
                return a[1]>b[1];
            else
                return a[0]<b[0];
        });
       // for(auto i:intervals)
         //   cout<<i[0]<<" "<<i[1]<<endl;
        int count=0;
        int start=intervals[0][0],end=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=end){
                start=intervals[i][0];
                end=intervals[i][1];
            }
            else{
                if(start<=intervals[i][0] && end>=intervals[i][1]){
                    start=intervals[i][0];
                    end=intervals[i][1];
                }
                
                count++;
            }
        }
        return count;
    }
};