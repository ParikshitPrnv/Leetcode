class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int>ans;
        int i=0;
        for(auto query :queries){
           // cout<<"query: "<<i++;
            int r=query[2];
            int count=0;
            for(auto point:points){
                double distance=pow((point[0]-query[0]),2)+pow((point[1]-query[1]),2);
                distance=sqrt(distance);
             //   cout<<"\nr,distance: "<<r<<" "<<distance;
                if(distance<=(double)r)
                    count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};