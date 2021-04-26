class Solution {
public:
    int maxPower(string s) {
        int max_length=1;
        int current_length=1;
        char c=s[0];
        for(int i=1;s[i];i++)
        {
            max_length=max(max_length,current_length);
            if(s[i]!=c)
            {
                current_length=1;
                c=s[i];
            }
            else
            current_length++;
        }
        max_length=max(max_length,current_length);
        return max_length;
    }
};