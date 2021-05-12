class Solution {
public:
    int lps(string s,string s2){
        int n=s.length();
        int m=s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       
        cout<<s<<" "<<s2<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        cout<<dp[n][m]<<"\n";
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        //reverse(word2.begin(),word2.end());
        
        return word1.length()+word2.length()-2*lps(word1,word2);
    }
};