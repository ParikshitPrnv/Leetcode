class Solution {
public:
    int brokenCalc(int X, int Y) {
        int count=0;
        while(Y>X)
        {
            count+=1+Y%2;
            Y+=Y%2;
            Y/=2;
        }
        return count+(X-Y);
    }
};