class Solution {
public:
    bool helper(int n,int power,long sum)
    {
        if(sum==n)
            return true;
        if(sum>n)
            return false;
        while(power<20)
        {
            if(helper(n,power+1,sum+pow(3,power)))
               return true;
               power++;
        }
               return false;
    }
    bool checkPowersOfThree(int n) {
        return helper(n,0,0);
    }
};