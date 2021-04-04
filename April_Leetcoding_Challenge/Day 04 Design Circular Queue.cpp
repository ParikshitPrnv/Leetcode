class MyCircularQueue {
public:
    vector<int>v;
    int front,rear;
    int current_size,max_size;
    MyCircularQueue(int k) {
        v.resize(k);
        front=0;
        rear=-1;
        current_size=0;
        max_size=k;
    }
    
    bool enQueue(int value) {
       if(current_size==max_size)
           return false;
        current_size++;
        if(++rear==max_size)
            rear=0;
        v[rear]=value;
        return true;
    }
    
    bool deQueue() {
        if(current_size==0)
            return false;
        if(++front==max_size)
            front=0;
        current_size--;
        return true;
    }
    
    int Front() {
        if(current_size==0)
            return -1;
        return v[front];
    }
    
    int Rear() {
        if(current_size==0)
            return -1;
        return v[rear];
    }
    
    bool isEmpty() {
        if(current_size==0)
            return true;
        else
            return false;
    }
    
    bool isFull() {
        if(current_size==max_size)
            return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */