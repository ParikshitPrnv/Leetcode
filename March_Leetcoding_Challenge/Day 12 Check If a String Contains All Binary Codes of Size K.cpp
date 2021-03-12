class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length()<k) //In case if length of string is less than k we can't make any substring of size k
            return false;
        long long max_value=pow(2,k)-1;
        vector<bool>v(max_value+1,false);
        for(int i=0;i<=s.length()-k;i++)
        {
            bitset<20>b(s.substr(i,k)); 
            v[b.to_ullong()]=true; //convert substring to its corresponding decimal value and mark the same                                    //in boolean vector
        }
        //Loop to check if all values are created 
        for(int i=0;i<=max_value;i++)
        {
            if(v[i]==false)
                return false;
        }
        return true;
    }
};