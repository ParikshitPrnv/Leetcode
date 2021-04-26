class Solution {
public:
    void topological(vector<vector<int>>& adj,vector<bool>& v,vector<int>& ans,int i)
    {
        v[i]=true;
        for(auto node:adj[i])
        {
            if(!v[node])
            topological(adj,v,ans,node);
        }
        ans.push_back(i);
    }
    bool util(vector<vector<int>> &adj,vector<bool>& v,vector<bool>& rec,int i)
    {
        if(v[i]==false)
        {
            v[i]=true;
            rec[i]=true;
            for(auto node:adj[i])
            {
                if(!v[node] && util(adj,v,rec,node))
                    return true;
                if(rec[node])
                    return true;
            }
        }
        rec[i]=false;
        return false;
    }
    bool isCyclic(vector<vector<int>> &adj,int n)
    {
        vector<bool>v(n,false);
        vector<bool>rec(n,false);
        for(int i=0;i<n;i++)
        {
            if(util(adj,v,rec,i))
                return true;
        }
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int> >adj(n);
        
        for(auto edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
        }
        
        vector<int>ans;
        if(isCyclic(adj,n))
            return ans;
        
        vector<bool>v(n,false);
        for(int i=0;i<n;i++)
        {
            if(!v[i])
            topological(adj,v,ans,i);
        }
        return ans;
    }
};