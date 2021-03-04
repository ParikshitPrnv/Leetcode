/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        if(!root)
            return v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            v.push_back(q.front()->val);
            for(int i=0;i<size;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                 if(temp->right)
                    q.push(temp->right);
                if(temp->left)
                    q.push(temp->left);
               
            }
        }
        return v;
    }
};