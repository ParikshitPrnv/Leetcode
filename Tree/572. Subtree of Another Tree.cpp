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
    bool isidentical(TreeNode* s, TreeNode* t)
    {
        if((!s && t) || (s && !t))
            return false;
        else if(!s && !t)
            return true;
        if(s->val!=t->val)
            return false;
        else 
            return isidentical(s->left,t->left) && isidentical(s->right,t->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if((!s && t) || (s && !t))
            return false;
        else if(!s && !t)
            return true;
        if(s->val==t->val)
        {
            if(isidentical(s,t))
                return true;
        }
       return isSubtree(s->left,t)||isSubtree(s->right,t)
    }
};