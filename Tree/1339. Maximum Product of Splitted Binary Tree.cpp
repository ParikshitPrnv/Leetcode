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
    long long max_product=INT_MIN,mod=1e9+7;
    void traverse(TreeNode* root,int totalsum)
    {
        if(!root)
            return ;
        int num1=root->val;
        int num2=(totalsum-num1);
        long long output=(1LL*num1*num2);
        //output%=mod;
        max_product=max(max_product,output);
        traverse(root->left,totalsum);
        traverse(root->right,totalsum);
    }
    int SubtreeSum(TreeNode* root)
    {
        if(root)
        {
            
            int leftsum=SubtreeSum(root->left);
            int rightsum=SubtreeSum(root->right);
            root->val=(root->val+leftsum+rightsum);
            return root->val;
        }
        return  0;
    }
    void preorder(TreeNode* root)
    {
        if(root)
        {
            cout<<root->val<<",";
            preorder(root->left);
            preorder(root->right);
        }
    }
    long long maxProduct(TreeNode* root) {
        SubtreeSum(root);
        //cout<<"[";
        //preorder(root);
        //cout<<"]";
        int totalsum=root->val;
        traverse(root,totalsum);
        return max_product%mod;
    }
};
//Lesson learnt, "Don't perform MOD early