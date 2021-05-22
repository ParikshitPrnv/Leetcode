class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string prev="1";
        string current="";
        for(int i=2;i<=n;i++){
            current.clear();
            for(int j=0;j<prev.length();j++){
                int count=1;
                
                while(j+1<prev.length() && prev[j+1]==prev[j]){
                    count++;
                    j++;
                }
                current.append(to_string(count)+prev[j]);
            }
            prev=current;
        }
        return prev;
    }
};