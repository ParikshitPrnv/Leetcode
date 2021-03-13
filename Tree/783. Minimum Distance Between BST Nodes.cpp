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
    int val=-1,min_diff=INT_MAX;
    int minDiffInBST(TreeNode* root) {
        if(root->left)
            minDiffInBST(root->left);
        if(val>=0)
            min_diff=min(min_diff,abs(root->val-val));
        val=root->val;
        if(root->right)
            minDiffInBST(root->right);
        return min_diff;
    }
};