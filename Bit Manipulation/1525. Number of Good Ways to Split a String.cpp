class Solution {
public:
    int numSplits(string s) {
        //count freq
        //set bit lookup for first 
        //total freq
        int n=s.length();
        vector<int>freq(26,0);
        for(int i=0;i<n;i++)
            freq[s[i]-'a']++;
        int right_distincts=26-count(freq.begin(),freq.end(),0);
        int ans=0;
        bitset<26>lookup(0);
        int left_distincts=0;
      //   cout<<left_distincts<<" "<<right_distincts<<endl;
        for(int i=0;i<n-1;i++){
            if(lookup[s[i]-'a']!=1)
            {lookup[s[i]-'a']=1;
             left_distincts++;}
            if(freq[s[i]-'a']!=0){
                freq[s[i]-'a']--;
                if(freq[s[i]-'a']==0)
                    right_distincts--;
            }
        //    cout<<left_distincts<<" "<<right_distincts<<endl;
            if(left_distincts==right_distincts)
                ans++;
        }
        return ans;
    }
};