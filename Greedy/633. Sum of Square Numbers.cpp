class Solution {
public:
    bool judgeSquareSum(int c) {
        long long low=0,high=sqrt(c)+1;
        while(low<=high)
        {
            if(low*low+high*high<c)
            {
                low++;
            }
            else if(low*low+high*high==c)
            {
                //cout<<"True: "<<low<<" "<<high<<endl;
                return true;
            }
            else
                high--;
        }
        return false;
    }
};