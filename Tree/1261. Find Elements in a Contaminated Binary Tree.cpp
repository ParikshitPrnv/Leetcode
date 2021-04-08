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
class FindElements {
public:
    TreeNode* root;
    map<int,bool>mp;
    void fillTree(TreeNode* root,int val)
    {
        if(!root)
            return ;
       // root->val=val;
        mp[val]=true;
        fillTree(root->left,2*val+1);
        fillTree(root->right,2*val+2);
    }
    FindElements(TreeNode* root) {
        this->root=root;
        fillTree(root,0);
    }
    
    bool find(int target) {
        return mp[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
 /*=================Alternative using queue======
 class FindElements {
public:
    TreeNode* root;
    void fillTree(TreeNode* root,int val)
    {
        if(!root)
            return ;
        root->val=val;
        fillTree(root->left,2*val+1);
        fillTree(root->right,2*val+2);
    }
    FindElements(TreeNode* root) {
        this->root=root;
        fillTree(root,0);
    }
    
    bool find(int target) {
        if(!root)
            return false;
        TreeNode* temp=root;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            temp=q.front();
            q.pop();
            if(temp->val==target)
                return true;
            if(temp->left && temp->val<target)
                q.push(temp->left);
            if(temp->right && temp->val<target)
                q.push(temp->right);
        }
        return false;
    }
};
*/