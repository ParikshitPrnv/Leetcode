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
    TreeNode* newroot=new TreeNode();
    TreeNode* current=newroot;
    void inorder(TreeNode* newroot)
    {
        if(newroot)
        {
            inorder(newroot->left);
            current->right=new TreeNode(newroot->val);
            current=current->right;
            inorder(newroot->right);
        }
    }
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        return newroot->right;
    }
};