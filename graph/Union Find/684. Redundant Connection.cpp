class Solution {
public:
    vector<int>parent;
    int find(int i){
        if(parent[i]==-1)
            return i;
        else
            return find(parent[i]);
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n,-1);
        for(auto i:edges){
            int x=find(i[0]-1);
            int y=find(i[1]-1);
            if(x==y){
                return i;
            }
            else
                parent[x]=y;
        }
        return {-1,-1};
    }
};