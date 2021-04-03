class Solution {
public:
    vector<vector<int> >ans;
    void dfs(vector<vector<int>>& graph,vector<int>& temp,vector<int>& visited,int current_vertex,int last_vertex)
    {
     if(current_vertex==last_vertex)
     {
         ans.push_back(temp);
         return ;
     }
        for(auto vertex:graph[current_vertex])
        {
            if(!visited[vertex])
            {
                temp.push_back(vertex);
                visited[vertex]=true;
                dfs(graph,temp,visited,vertex,last_vertex);
                temp.pop_back();
                visited[vertex]=false;
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>temp;
        vector<int>visited(n,false);
        visited[0]=true;
        temp.push_back(0);
        dfs(graph,temp,visited,0,n-1);
        return ans;
    }
};