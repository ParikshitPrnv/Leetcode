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
    int diff=0;
    int sum(TreeNode* root)
    {
        if(root)
        {
            int leftsum=sum(root->left);
            int rightsum=sum(root->right);
            diff+=abs(leftsum-rightsum);
            return leftsum+rightsum+root->val;
        }
        else
            return 0;
    }
    int findTilt(TreeNode* root) {
        sum(root);
        return diff;
       
    }
};