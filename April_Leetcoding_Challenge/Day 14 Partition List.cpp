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
    ListNode* getnode(int value)
    {
        ListNode* newnode=new ListNode(value);
        return newnode;
    }
    ListNode* partition(ListNode* head, int x) {
       if(head==NULL)
           return head;
        ListNode* smaller=new ListNode();
        ListNode* larger=new ListNode();
        ListNode* temp=smaller;
        ListNode* temp2=larger;
        while(head!=NULL)
        {
            if(head->val<x)
            {
                ListNode* newnode=new ListNode(head->val);
                temp->next=newnode;
                temp=temp->next;
            }
            else
            {
                ListNode* newnode=new ListNode(head->val);
                temp2->next=newnode;
                temp2=temp2->next;
            }
            head=head->next;
        }
        if(smaller->next==NULL)
        {
            return larger->next;
        }
        else
        {
            if(larger->next==NULL)
            {
                return smaller->next;
            }
            else
            {
                temp->next=larger->next;
                return smaller->next;
            }
        }
    }
};