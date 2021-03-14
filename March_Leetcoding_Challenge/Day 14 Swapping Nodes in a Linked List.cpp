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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* begin=head;
        ListNode* post=head;
        ListNode* pre=head;
        for(int i=1;i<k;i++){
            post=post->next;
            begin=begin->next;
        }
        while(post->next)
        {
            pre=pre->next;
            post=post->next;
        }
        cout<<begin->val<<" " <<pre->val;
        int t=pre->val;
        pre->val=begin->val;
        begin->val=t;
        return head;
    }
};