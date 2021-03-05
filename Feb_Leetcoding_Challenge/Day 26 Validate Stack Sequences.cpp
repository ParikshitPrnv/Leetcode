class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
     int n=pushed.size();
        int m=popped.size();
        stack<int>s;
        int i=0,j=0;
        while(i<n && j<m)
        {
            s.push(pushed[i]);
            while(!s.empty() && popped[j]==s.top())
            {
                s.pop();
                j++;
            }
            i++;
        }
        
       return j==m;
    }
};