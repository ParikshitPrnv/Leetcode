class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int min_distance=INT_MAX;
        int index=-1;
        int j=0;
        for(auto i:points)
        {
            if(i[0]!=x && i[1]!=y)
            {
                j++;
                continue;
            }
            int distance=abs(i[0]-x)+abs(i[1]-y);
            if(distance<min_distance)
            {
                min_distance=distance;
                index=j;
            }
                                 j++;
        }
        return index;
    }
};