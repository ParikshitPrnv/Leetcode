/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n,int low=0,int high=INT_MAX) {
        if(guess(n)==0)
        {
            return n;
        }
        else if(guess(n)==-1)
        {
            high=n-1;
        }
        else
            low=n+1;
        return guessNumber(low+(high-low)/2,low,high);
    }
};