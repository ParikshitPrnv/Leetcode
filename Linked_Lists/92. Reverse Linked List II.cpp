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
//can be solved using stack;
class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* current=head;
        while(current)
        {
            ListNode* next_node=current->next;
            current->next=prev;
            prev=current;
            current=next_node;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* first=head;
        for(int i=1;i<left;i++){
            first=first->next;
            //cout<<first->val<<" -> ";
        }
        while(left<right){
            ListNode* second=first;
            for(int i=left;i<right;i++)
            {
                second=second->next;
               // cout<<second->val<<" -> ";
            }
            second->val=first->val^second->val;
            first->val=first->val^second->val;
            second->val=first->val^second->val;
            first=first->next;
            left++;
            right--;
        }
        return head;
    }
};