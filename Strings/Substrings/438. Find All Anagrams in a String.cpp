class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.length(),m=p.length();
        
        vector<int>f(26,0), g(26,0),ans;
        for(int i=0;i<m;i++)
            f[p[i]-'a']++;
        
        for(int i=0;i<n;i++){
            g[s[i]-'a']++;
            if(i>=m)
                g[s[i-m]-'a']--;
            if(f==g)
                ans.push_back(i-m+1);
        }
        return ans;
    }
};