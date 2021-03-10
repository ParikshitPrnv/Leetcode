class Solution {
public:
    string intToRoman(int num) {
        vector<vector<char>>table;
        table.push_back({'I','V','X'});
        table.push_back({'X','L','C'});
        table.push_back({'C','D','M'});
        table.push_back({'M','M','M'});
        string ans="";
        int power=0;
        while(num>0)
        {
            int digit=num%10;
            if(digit<=3 )
            {
                for(int i=0;i<digit;i++)
                    ans.push_back(table[power][0]);
            }
            else if(digit==4)
            {
                ans.push_back(table[power][1]);
                ans.push_back(table[power][0]);
                
            }
            else if(digit==5)
                ans.push_back(table[power][1]);
            else if(digit==6)
            {
                ans.push_back(table[power][0]);
                ans.push_back(table[power][1]);
                
            }
            else if(digit<=8)
            {
                for(int i=6;i<=digit;i++)
                    ans.push_back(table[power][0]);
                ans.push_back(table[power][1]);
                
            }
            else if(digit==9)
            {
                ans.push_back(table[power][2]);
                ans.push_back(table[power][0]);
                
            }
           num/=10;
            power++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};