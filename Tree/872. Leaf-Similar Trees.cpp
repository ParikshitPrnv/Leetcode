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
   
    void findLeaves(TreeNode* root,vector<int> &v)
    {
        if(!root)
        {
            return ;
        }
        if(!root->left && !root->right)
        {
            v.push_back(root->val);
            return ;
        }
        findLeaves(root->left,v);
        findLeaves(root->right,v);
        
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
         vector<int>v;
        findLeaves(root1,v);
        vector<int> v1=v;
        v.clear();
        findLeaves(root2,v);
        return v1==v;
    }
};