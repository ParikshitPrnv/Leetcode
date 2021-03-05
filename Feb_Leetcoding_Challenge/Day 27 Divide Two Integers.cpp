class Solution {
public:
    int divide(int dividend, int divisor) {
       long t= (long)dividend/divisor;
        if(t>=INT_MIN && t<=INT_MAX)
            return dividend/divisor;
        else if( t<INT_MIN)
            return INT_MIN;
        else
            return INT_MAX;
    }
};