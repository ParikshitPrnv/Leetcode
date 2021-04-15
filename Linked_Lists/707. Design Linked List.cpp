class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList* head=NULL;
    MyLinkedList* tail=NULL;
    MyLinkedList* next=NULL;
    int val;
    
    MyLinkedList(int x=0,MyLinkedList* n=NULL) {
        val=x;
        next=n;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int i=0;
        MyLinkedList* node=head;
        while(i!=index && node)
        {
            node=node->next;
            i++;
        }
        if(i!=index || !node)
            return -1;
        else 
            return node->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        MyLinkedList* newnode=new MyLinkedList(val);
        if(!head)
        {
            head=newnode;
            tail=head;
        }
        else
        {
            newnode->next=head;
            head=newnode;
        }
        
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if(!head)
        {
            addAtHead(val);
        }
        else
        {
            MyLinkedList* newnode=new MyLinkedList(val);
            tail->next=newnode;
            tail=tail->next;
        }
        
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        int i=0;
        if(index==0)
        {
            addAtHead(val);
            return ;
        }
        MyLinkedList* node=head;
        while(i!=index-1 && node)
        {
            node=node->next;
            i++;
        }
        if(i!=index-1)
            return;
       if(node==tail)
       {
           addAtTail(val);
           return;
       }
        MyLinkedList* newnode=new MyLinkedList(val);
        newnode->next=node->next;
        node->next=newnode;
        
        
        
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index==0)
        {
            head=head->next;
            return ;
        }
        int i=0;
        MyLinkedList* node=head;
        while(i!=index-1 && node)
        {
            node=node->next;
            i++;
        }
        if(i!=index-1 || !node || !node->next)
            return;
        if(node->next==tail)
        {
            node->next=NULL;
            tail=node;
            return ;
        }
        if(node->next && node->next->next)
        node->next=node->next->next;
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */