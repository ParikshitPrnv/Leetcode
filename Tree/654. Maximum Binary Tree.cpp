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
    TreeNode* root=NULL;
    
    int n;
    TreeNode* tree(vector<int>& nums,int start,int end){
        if(start>end)
            return NULL;
        int index=0,element=INT_MIN;
        for(int i=start;i<=end;i++){
            if(element<nums[i]){
                index=i;
                element=nums[i];
            }
        }
       TreeNode* current=new TreeNode(element);
        current->left=tree(nums,start,index-1);
        current->right=tree(nums,index+1,end);
        return current;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        n=nums.size();
        root=tree(nums,0,n-1);
        return root;
    }
};
/*
This is also called a Cartesian Tree. One interesting property is that if we do an in-order traversal, we get the array back which we used to create it.
*/