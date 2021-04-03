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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp=head;
        ListNode* list=new ListNode();
        ListNode* current=list;
        int i=1;
        while(temp)
        {
            if(i%2!=0)
            {
                current->next=new ListNode(temp->val);
                current=current->next;
            }
            temp=temp->next;
            i++;
        }
        temp=head;
        i=1;
         while(temp)
        {
            if(i%2==0)
            {
                current->next=new ListNode(temp->val);
                current=current->next;
            }
            temp=temp->next;
             i++;
        }
        return list->next;
    }
};