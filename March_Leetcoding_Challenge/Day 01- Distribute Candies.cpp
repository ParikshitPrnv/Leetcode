class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
     int n=candyType.size();
        int count=0;
        int current=INT_MIN;
        sort(candyType.begin(),candyType.end());
        for(auto i:candyType)
        {
            if(count>=n/2)
                return n/2;
            
            if(i==current)
                continue;
            current=i;
            count++;
            
        }
        return count;
    }
};