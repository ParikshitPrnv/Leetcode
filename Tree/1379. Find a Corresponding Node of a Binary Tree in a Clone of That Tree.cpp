/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original || original==target)
            return cloned;
        TreeNode* output1=getTargetCopy(original->left,cloned->left,target);
        if(output1!=NULL)
            return output1;
        else
            return getTargetCopy(original->right,cloned->right,target);
            
    }
};