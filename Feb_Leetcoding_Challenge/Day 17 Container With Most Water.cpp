class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int max_vol=INT_MIN;
        while(i<j)
        {
            max_vol=max(min(height[i],height[j])*abs(i-j),max_vol);
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return max_vol;
    }
};