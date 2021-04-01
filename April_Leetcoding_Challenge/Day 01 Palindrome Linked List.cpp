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
    bool isPalindrome(ListNode* head) {
        int total_nodes=0;
        ListNode* temp=head;
        //cout<<"\nNodes: \n";
        while(temp)
        {
          //  cout<<temp->val<<" ";
            temp=temp->next;
            total_nodes++;
        }
        //cout<<"\nTotal_nodes "<<total_nodes<<endl;
        if(total_nodes<=1)
            return true;
        ListNode* mid=head;
        ListNode* end=head;
        for(int i=0;i<total_nodes/2-1;i++)
            mid=mid->next;
        if(total_nodes%2==0)
            end=mid->next;
        else
            end=mid->next->next;
        //cout<<"Mid,End: "<<mid->val<<" "<<end->val;
        mid->next=NULL;
        end=reverse(end);
        temp=head;
        for(int i=0;i<total_nodes/2;i++)
        {
            if(temp->val!=end->val)
                return false;
            temp=temp->next;
            end=end->next;
        }
        return true;
    }
};