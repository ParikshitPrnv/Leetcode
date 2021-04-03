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
    int findGreater(ListNode* head,int val)
    {
        int ans=0;
        while(head)
        {
            if(head->val>val)
            {
                return head->val;
            }
            head=head->next;
        }
        return ans;    
    }
    vector<int> nextLargerNodes(ListNode* head) {
       vector<int>ans;
        ListNode* temp=head;
        while(temp)
        {
            int current=findGreater(temp,temp->val);
            ans.push_back(current);
            temp=temp->next;
        }
        return ans;
    }
};