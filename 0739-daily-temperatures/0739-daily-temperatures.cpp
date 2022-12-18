class Solution
{
    public:
        vector<int> dailyTemperatures(vector<int> &T)
        {
            stack<int> s;
            vector<int> ans(size(T));
            for (int cur = 0; cur < size(T); cur++)
            {
                while (size(s) and T[cur] > T[s.top()])
                {
                    ans[s.top()] = cur - s.top();	
                    s.pop();
                }
                s.push(cur);
            }
            return ans;
        }
};