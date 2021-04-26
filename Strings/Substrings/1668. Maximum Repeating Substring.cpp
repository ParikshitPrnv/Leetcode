class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int max_count=0;
        if(word.length()>sequence.length())
            return 0;
        for(int i=0;i<=sequence.length()-word.length();i++)
        {
            int j=i;
            if(sequence[i]==word[0] && sequence.substr(i,word.length())==word)
            {
                
                int count=1;
                i+=word.length();
                while(i<=sequence.length()-word.length() && sequence[i]==word[0] && sequence.substr(i,word.length())==word){
                    count++;
                    i+=word.length();
                }
                
                max_count=max(max_count,count);
            }
            i=j;
        }
        return max_count;
    }
};

/* Better Solution
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int count=0;
        string temp=word;
        while(sequence.find(temp)!=string::npos)
        {
            count++;
            temp+=word;
        }
        return count;
    }
};
*/