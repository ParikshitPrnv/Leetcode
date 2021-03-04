/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    int find_index(Node* head,Node* node)
    {
        int index=0;
        while(head!=node)
        {
            
            head=head->next;
            index++;
        }
        return index;
    }
    Node* find_node(Node* newhead,int index)
    {
        
        int i=0;
        while(i!=index)
        {
            i++;
           // cout<<newhead->val<<" ";
            newhead=newhead->next;
        }
        //cout<<endl;
        return newhead;
    }
    Node* copyRandomList(Node* head) {
       if(!head) return NULL;
        Node* newhead=new Node(0);
        Node* post=newhead;
        Node* temp=head;
        while(temp!=NULL)
        {
            post->next=new Node(temp->val);
            post=post->next;
            temp=temp->next;
        }
      
        temp=head;
        post=newhead->next;
        while(temp!=NULL)
        {
            int index=find_index(head,temp->random);
            cout<<index<<endl;
            post->random=find_node(newhead->next,index);
            temp=temp->next;
            post=post->next;
           
        }
        return newhead->next;
    }
};