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
    map<pair<TreeNode*,bool>,int>mp;
    int helper(TreeNode* root,bool isRight,int length){
        if(!root)
            return length-1;
        if(mp.find({root,isRight})!=mp.end())
            return mp[{root,isRight}];
        if(isRight)
            mp[{root,isRight}]= max(helper(root->left,false,length+1),helper(root->right,true,1));
        else
            mp[{root,isRight}]= max(helper(root->right,true,length+1),helper(root->left,false,1));
        return mp[{root,isRight}];
        
    }
    int longestZigZag(TreeNode* root) {
        return max(helper(root->right,true,1),helper(root->left,false,1));
    }
};