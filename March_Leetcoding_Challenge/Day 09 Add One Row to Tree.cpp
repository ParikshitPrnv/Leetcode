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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1)
        {
            TreeNode* newroot=new TreeNode(v);
            newroot->left=root;
            return newroot;
        }
        int level=1;
        queue<TreeNode*>q;
        if(!root)
            return root;
        q.push(root);
        while(level!=d-1 && !q.empty())
        {
            
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
             level++;
           
        }
        if(level!=d-1)
            return root;
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            TreeNode *new_left_node=new TreeNode(v);
            new_left_node->left=temp->left;
            temp->left=new_left_node;
            TreeNode* new_right_node=new TreeNode(v);
            new_right_node->right=temp->right;
            temp->right=new_right_node;
        }
        return root;
    }
};