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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root)
            return root;
        TreeNode* leftroot=removeLeafNodes(root->left,target);
        TreeNode* rightroot=removeLeafNodes(root->right,target);
        root->left=leftroot;
        root->right=rightroot;
        if(leftroot==NULL && rightroot==NULL && root->val==target)
        {
           return NULL;
        }
        return root;
    }
};