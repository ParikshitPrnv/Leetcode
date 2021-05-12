class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left=0,right=0;
        int ans=0;
        for(int i=0;i<k;i++)
            left+=cardPoints[i];
        ans=max(ans,left);
        int n=cardPoints.size();
        for(int i=1;i<=k;i++)
        {
            left-=cardPoints[k-i];
            right+=cardPoints[n-i];
            ans=max(ans,left+right);
        }
        return ans;
    }
};