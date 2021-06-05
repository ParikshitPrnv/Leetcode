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
    int height(TreeNode* root){
        if(!root)
            return -1;
        return 1+max(height(root->left),height(root->right));
        
    }
    
    int leavesAtMaxHeight(TreeNode* root,int maxHeight,int currentHeight){
        if(!root)
            return 0;
        if(!root->left && !root->right){
            if(currentHeight==maxHeight)
                return 1;
            return 0;
        }
        return leavesAtMaxHeight(root->left,maxHeight,currentHeight+1)+leavesAtMaxHeight(root->right,maxHeight,currentHeight+1);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root)
            return NULL;
        TreeNode* ans=root;
        int maxHeight=height(root);
        int n=leavesAtMaxHeight(root,maxHeight,0);
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(leavesAtMaxHeight(temp,maxHeight,level)==n){
                    ans=temp;
                    if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                }
                
            }
            level++;
        }
        return ans;
    }
};