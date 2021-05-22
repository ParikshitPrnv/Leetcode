class Solution {
public:
    string interpret(string command) {
     string ans="";
        for(int i=0;command[i];i++){
            if(command[i]=='G')
                ans.push_back(command[i]);
            else if(command[i]=='(' && command[i+1]==')')
                ans.push_back('o');
            else if(command[i]=='(' && command[i+1]=='a')
                ans.append("al");
        }
        return ans;
    }
};