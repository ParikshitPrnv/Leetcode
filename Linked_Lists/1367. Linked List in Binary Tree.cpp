/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool helper(ListNode* head, TreeNode* root){
        
        if(!head)
            return true;
        if(!root)
            return false;
        //cout<<"\n... head->val: "<<head->val;
        //cout<<"\n ...root->val: "<<root->val;
        if(head->val==root->val){
          //  cout<<"\n same value";
            return helper(head->next,root->left) || helper(head->next,root->right);
        }
        else
        return false;
    }
    bool traverse(ListNode* head,TreeNode* root){
        if(!root)
            return false;
        //cout<<"\nroot->val: "<<root->val;
        if(head->val==root->val && helper(head,root)){
          //  cout<<" found";
            return true;
        }   
        return traverse(head,root->left) || traverse(head,root->right);
            
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return traverse(head,root);
            
    }
};