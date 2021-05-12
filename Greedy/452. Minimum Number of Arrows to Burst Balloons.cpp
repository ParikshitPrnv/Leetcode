class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0)
            return 0;
        int n=points.size();
        sort(points.begin(),points.end(),[](vector<int>& a,vector<int>& b){
            if(a[0]==b[0])
                return a[1]>b[1];
            else
                return a[0]<b[0];
        });
       // for(auto i:points)
         //   cout<<i[0]<<" "<<i[1]<<endl;
        int count=1;
        int start=points[0][0],end=points[0][1];
        for(int i=1;i<n;i++){
            if(points[i][0]>end ){
                start=points[i][0];
                end=points[i][1];
                count++;
                //cout<<"\nnew arrow at "<<start<<" "<<end;
            }
            else{
                start=max(start,points[i][0]);
                end=min(end,points[i][1]);
            }
            
        }
        return count;
    }
};