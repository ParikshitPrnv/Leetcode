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
    int height(TreeNode* root)
    {
        if(root)
        {
         return 1+max(height(root->left),height(root->right));
        }
        else
            return 0;
    }
    int sum_at_height(TreeNode* root,int max_height,int current_height)
    {
        if(!root)
            return 0;
        if(current_height==max_height)
        {
            if(root && root->left==NULL && root->right==NULL)
                return root->val;
            else
                return 0;
        }
        return sum_at_height(root->left,max_height,current_height+1)+sum_at_height(root->right,max_height,current_height+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        int max_height=height(root);
        //cout<<"max_height: "<<max_height;
        return sum_at_height(root,max_height,1);
    }
};