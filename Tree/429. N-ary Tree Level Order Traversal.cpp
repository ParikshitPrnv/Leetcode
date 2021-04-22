/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        if(!root)
            return ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int>v;
            for(int i=0;i<size;i++)
            {
                Node* temp=q.front();
                v.push_back(temp->val);
                q.pop();
                for(auto child:temp->children)
                    q.push(child);
            }
            ans.push_back(v);
        }
        
        return ans;
    }
};