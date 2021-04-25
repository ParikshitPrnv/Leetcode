class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>>graph;
    vector<int>vis;
    vector<int>lowlink;
    vector<int>id;
    int time=0;
    void dfs(int node,int parent){
        id[node]=lowlink[node]=time++;
        vis[node]=true;
        for(auto i:graph[node]){
            if(i==parent)
                continue;
            else if(!vis[i]){
                dfs(i,node);
                if(id[node]<lowlink[i])
                    ans.push_back({node,i});
            }
            lowlink[node]=min(lowlink[node],lowlink[i]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        graph.resize(n);
        vis.resize(n,false);
        lowlink.resize(n,0);
        id.resize(n,0);
        for(auto edge:connections){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i])
                dfs(i,i);
        }
        return ans;
    }
};