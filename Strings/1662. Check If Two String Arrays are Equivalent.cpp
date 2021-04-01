class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n=word1.size();
        int m=word2.size();
        int id1=0,id2=0;
        int i=0,j=0;
        while(i<n && j<m)
        {
            if(word1[i][id1]!=word2[j][id2])
            {
                return false;
            }
            else
            {
                id1++;
                id2++;
                if(id1==word1[i].length())
                {
                    i++;
                    id1=0;
                }
                if(id2==word2[j].length())
                {
                    j++;
                    id2=0;
                }
            }
        }
        if(i==n && j==m)
            return true;
        else
            return false;
    }
};