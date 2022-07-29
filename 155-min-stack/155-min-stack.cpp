class MinStack
{
    stack<long long> s;
    long long minEle;
    
    public:
        MinStack() {}

    /*returns min element from stack*/
    long long getMin()
    {
        if (s.size() == 0) return -1;
        return minEle;
    }

    /*returns poped element from stack*/
    long long pop()
    {
        if (s.size() == 0) return -1;
        else
        {
            if (s.top() >= minEle)
            {
                long long ans = s.top();
                s.pop();
                return ans;
            }
            else
            {
                long long ans = minEle;
                minEle = ((long long)(2 *minEle) - s.top());
                s.pop();
                return ans;
            }
        }
    }

    /*push element x into the stack*/
    void push(long long x)
    {
        if (s.size() == 0)
        {
            s.push(x);
            minEle = x;
        }
        else
        {
            if (x >= minEle) s.push(x);
            else
            {
                s.push((long long)(2 *x) - minEle);
                minEle = x;
            }
        }
    }

    long long top()
    {
        if (s.size() == 0) return -1;
        else
        {
            if (s.top() >= minEle)
            {
                long long ans = s.top();
                return ans;
            }
            else
            {
                long long ans = minEle;
                return ans;
            }
        }
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