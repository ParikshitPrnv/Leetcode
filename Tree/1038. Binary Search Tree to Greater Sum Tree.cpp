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
    int sum=0;
    
    void inorder(TreeNode* root)
    {
        if(root)
        {
            inorder(root->left);
            sum+=root->val;
            inorder(root->right);
        }
       
    }
    void inorder2(TreeNode* root)
    {
        if(root)
        {
            //cout<<"ROOT->val: "<<root->val<<endl;
            inorder2(root->left);
            int temp=root->val;
            root->val=sum;
            sum=sum-temp;
           // cout<<sum<<endl;
            inorder2(root->right);
            
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL)
            return root;
        inorder(root);
       // cout<<sum<<endl;
        inorder2(root);
        return root;
    }
};