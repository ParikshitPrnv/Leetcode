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
class Solution {
public:
    int traverse(ListNode* root)
    {
        int size=0;
        ListNode* temp=root;
        while(temp)
        {
            temp=temp->next;
            size++;
        }
        return size;
    }
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*>ans;
        int size=traverse(root);
        if(size<k)
        {
            while(root)
            {
                ListNode* new_node=new ListNode(root->val);
                ans.push_back(new_node);
                root=root->next;
            }
            for(int i=0;i<k-size;i++)
            {
                //ListNode* new_node=new ListNode();
                ans.push_back(NULL);
            }
        }
        else
        {
            int list_size=size/k;
            int remaining_size=size-list_size*k;
           // cout<<"remaining size: "<<remaining_size;
            for(int i=0;i<k;i++)
            {
                ListNode* new_list=new ListNode();
                ListNode* current=new_list;
                for(int i=0;i<list_size;i++)
                {
                    current->next=new ListNode(root->val);
                    current=current->next;
                    root=root->next;
                }
                if(remaining_size)
                {
                    current->next=new ListNode(root->val);
                    current=current->next;
                    root=root->next;
                    remaining_size--;
                }
                ans.push_back(new_list->next);
            }
        }
        return ans;
    }
};