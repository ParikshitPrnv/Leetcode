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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* current=head;
        while(current){
            ListNode* nextNode=current->next;
            current->next=prev;
            prev=current;
            current=nextNode;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* node=head;
        while(node){
            node->next=reverse(node->next);
            node=node->next;
        }
    }
};
/*********Better Solution*******

class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* current=head;
        while(current){
            ListNode* nextNode=current->next;
            current->next=prev;
            prev=current;
            current=nextNode;
        }
        return prev;
    }
    ListNode* middle(ListNode* head){
        ListNode* prev=NULL;
        ListNode* start=head;
        ListNode* end=head;
        while(end && end->next){
            prev=start;
            start=start->next;
            end=end->next->next;
        }
        prev->next=NULL;
        return start;
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* head=l1;
        while(l1 && l2){
            ListNode* temp=l1->next;
            l1->next=l2;
            l1=l2;
            l2=temp;
        }
        return head;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return;
        ListNode* mid=middle(head);
        ListNode* head2=reverse(mid);
         head=merge(head,head2);
    }
};
**************************************/