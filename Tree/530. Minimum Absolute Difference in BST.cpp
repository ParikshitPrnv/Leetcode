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
    vector<int>v;
    void inorder(TreeNode* root){
        if(root)
        {
            inorder(root->left);
            v.push_back(root->val);
            inorder(root->right);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        if(!root)
            return 0;
        inorder(root);
        int min_diff=INT_MAX;
        for(int i=1;i<v.size();i++)
        {
            min_diff=min(min_diff,abs(v[i]-v[i-1]));
        }
        return min_diff;
    }
};
/*
Alternate: O(1)
void inorderTraverse(TreeNode* root, int& val, int& min_dif) {
    if (root->left != NULL) inorderTraverse(root->left, val, min_dif);
    if (val >= 0) min_dif = min(min_dif, root->val - val);
    val = root->val;
    if (root->right != NULL) inorderTraverse(root->right, val, min_dif);
}
int getMinimumDifference(TreeNode* root) {
    auto min_dif = INT_MAX, val = -1;
    inorderTraverse(root, val, min_dif);
    return min_dif;
}
*/