class MinStack
{
    stack<int> s;
    stack<int> ss;
    public:
        MinStack() {}

    /*returns min element from stack*/
    int getMin()
    {
        if (ss.size() == 0) return -1;
        return ss.top();
    }

    /*returns poped element from stack*/
    int pop()
    {
        if (s.size() == 0) return -1;

        int ans = s.top();
        s.pop();
        if (ans == ss.top()) ss.pop();
        return ans;
    }

    /*push element x into the stack*/
    void push(int x)
    {
        s.push(x);
        if (ss.size() == 0 or x <= ss.top()) ss.push(x);
        return;
    }

    int top()
    {
        return s.top();
    }
};

/**
 *Your MinStack object will be instantiated and called as such:
 *MinStack* obj = new MinStack();
 *obj->push(val);
 *obj->pop();
 *int param_3 = obj->top();
 *int param_4 = obj->getMin();
 */