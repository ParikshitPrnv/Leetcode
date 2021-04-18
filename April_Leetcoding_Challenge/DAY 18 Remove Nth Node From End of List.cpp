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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre=head;
        ListNode* prepre=head;
        ListNode* post=head;
        for(int i=0;i<n;i++)
        {
            if(post==NULL)
                return head;
            post=post->next;
        }
        while(post)
        {
            prepre=pre;
            pre=pre->next;
            post=post->next;
        }
        if(pre==head)
            return head->next;
        prepre->next=pre->next;
        //free(pre);
        cout<<pre->val<<endl;
        return head;
    }
};