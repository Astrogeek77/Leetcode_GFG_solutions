class MyStack {
public:
    queue<int> queue;
    MyStack() {
        
    }
    
    void push(int x) 
    {
        int n = queue.size();
        queue.push(x);
        while(n-->0)
        {
            queue.push(queue.front());
            queue.pop();
        }
    }
    
    int pop() 
    {
        if(!queue.empty())
        {
            int top = queue.front();
            queue.pop();
            return top;
        }
        else return 0;
    }
    
    int top() {
        if(!queue.empty()){
            int top = queue.front();
            return top;
        }
        else return 0;
    }
    
    bool empty() {
        return queue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */