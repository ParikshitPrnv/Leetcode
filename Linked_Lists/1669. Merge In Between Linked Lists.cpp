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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* start=list1;
        ListNode* end=list1;
        for(int i=0;i<a-1;i++)
            start=start->next;
        for(int i=0;i<=b;i++)
            end=end->next;
        ListNode* end_list2=list2;
        while(end_list2->next)
        {
            end_list2=end_list2->next;
        }
        start->next=list2;
        end_list2->next=end;
        return list1;
    }
};