class Solution {
public:
    vector<string>output;
    string keypad[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits,int n=0) {
        if(n==digits.length())
            return output;
        string num=keypad[(digits[n]-'0')];
        if(output.size()==0)
        {
            for(int j=0;num[j];j++)
            {
                string s="";
                output.push_back(s+num[j]);
            }
            
        }
        else
        {
            int size=output.size();
            for(int i=0;i<size;i++)
            {
                string k=output[i];
                output[i]+=num[0];
                for(int j=1;num[j];j++)
                {
                    output.push_back(k+num[j]);
                }
            }
        }
        return letterCombinations(digits,n+1);
    }
};