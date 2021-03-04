class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
         int n=graph.size();
        vector<int>color(n,-1);
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++)
        {
            if(visited[i])
                continue;
            
        queue<int>q;
        color[i]=1;
        q.push(i);
        while(!q.empty())
        {
            
            int u=q.front();
            q.pop();
            visited[u]=true;
            for(auto j:graph[u])
            {
                if(color[j]==-1)
                {
                    color[j]=1-color[u];
                    q.push(j);
                }
                else if(color[j]==color[u])
                    return false;
            }
        }
        }
        return true;
    }
};