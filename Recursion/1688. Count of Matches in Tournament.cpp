class Solution {
public:
    int numberOfMatches(int n) {
        if(n<=1)
            return 0;
        if(n%2==0)
            return (n/2)+numberOfMatches(n/2);
        else
            return floor(n/2)+numberOfMatches(n/2+1);
    }
};
/*
Basically, if a team plays a match and loses, then it is eliminated, so if there are n teams then n-1 teams should lose which should happen after n-1 matches.
So the answer can be simply said as n-1;
*/