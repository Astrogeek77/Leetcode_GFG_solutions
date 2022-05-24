class Solution
{
    public:
        int longestValidParentheses(string s)
        {
            stack<int> stack; // stack for merging parentheses
            stack.push(-1); // default value for a starting close parenthesis

            int ans = 0; // result

            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '(') stack.push(i); // if ( push index to stack
                else
                {
                    stack.pop(); // else pop the top
                    if (stack.empty()) stack.push(i); // push again
                    else ans = max(ans, i - stack.top()); // get the max length till index i
                }
            }
            return ans;
        }
};