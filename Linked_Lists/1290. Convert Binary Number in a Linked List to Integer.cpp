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
    int getDecimalValue(ListNode* head,int sum=0) {
        if(head==NULL)
            return 0;
        ListNode* prev=NULL;
        ListNode* current=head;
        while(current)
        {
            ListNode* next_node=current->next;
            current->next=prev;
            prev=current;
            current=next_node;
        }
        int i=0;
        while(prev)
        {
            if(prev->val==1)
                sum+=pow(2,i);
            i++;
            prev=prev->next;
        }
        return sum;
    }
};