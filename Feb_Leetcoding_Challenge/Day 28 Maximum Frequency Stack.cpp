class FreqStack {
public:
    unordered_map<int,int>freq;
    int max_freq=0;
    unordered_map<int,stack<int>>f_stack;
    FreqStack() {
        
    }
    
    void push(int x) {
        int temp=freq[x];
        freq[x]+=1;
        max_freq=max(max_freq,temp+1);
        f_stack[temp+1].push(x);
    }
    
    int pop() {
        int ans=f_stack[max_freq].top();
        f_stack[max_freq].pop();
        freq[ans]--;
        while(f_stack[max_freq].empty() && max_freq>0)
        { 
            max_freq--;
        }
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */