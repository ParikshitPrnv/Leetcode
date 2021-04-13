class Solution {
public:
    int backtrack(vector<int> &visited,int current_element,int current_index,int n)
    {
        if(current_index==n+1)
            return 1;
        if(current_element%current_index!=0 && current_index%current_element!=0)
            return 0;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(visited[i]==false)
            {
                visited[i]=true;
                ans+=backtrack(visited,i,current_index+1,n);
                visited[i]=false;
            }
        }
        return ans;
    }
    int countArrangement(int n) {
        vector<int>visited(n+1,false);
        return backtrack(visited,1,1,n);
    }
};