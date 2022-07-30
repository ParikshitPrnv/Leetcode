/*
Brute Force:

n = s1.length();
for i=0 to s2.length()-n
substring from i to n in s2
sort the substring and compare it with sorted s1

TC: O((N^3)*logN)
SC: O(n)

Optimized
we can create a map of frequencies of all the characters in the s1 -> lookup map
we can create another map which can create frequencies of the window -> currentFreqs
variable start = 0 to keep track of the starting index of the substring being considered currently

for i =0 to s2.length()
currentChar = s2[i]
Include current character in the substring:  currentFreqs[currentChar]++;
If the frequency of current character in the substring is more than the s1, we need to discard the part of substring which contains the first occurence of the current character
So, if lookup[currentChar]<currentFreqs[currentChar]
    while(s2[start]!=currentChar)
    {
        currentFreqs[s2[start]]--;
        start++;
    }
    currentFreqs[s2[start]]--;
    start++;

compare the current window length to the n [current window size is i-start+1]
if i-start+1==n 
  return true

return false

*/


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length())
            return false;
        unordered_map<char, int> lookup, currentFreqs;
        
        for(auto i:s1)
            lookup[i]++;
        
        int start = 0;
        for(int i=0;i<s2.length();i++)
        {
            char currentChar = s2[i];
            currentFreqs[currentChar]++;
            if(lookup[currentChar]<currentFreqs[currentChar])
            {
                while(s2[start]!=currentChar)
                {
                    currentFreqs[s2[start]]--;
                    start++;
                }
                currentFreqs[s2[start]]--;
                start++;
                
            }
            
            if(i-start+1==s1.length())
                return true;
            
        }
        return false;
        
        
    }
};

