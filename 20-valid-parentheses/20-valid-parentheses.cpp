class Solution
{
    public:
        bool isValid(string s)
        {
            stack<char> result;
            for (int i = 0; i < s.size(); i++)
            {
                if (result.empty()) result.push(s[i]);
                else if (result.top() == '('
                    and s[i] == ')'
                    or result.top() == '['
                    and s[i] == ']'
                    or result.top() == '{'
                    and s[i] == '}')
                {
                    result.pop();
                }
                else result.push(s[i]);
            }
            return (result.empty() ? true : false);
        }
};