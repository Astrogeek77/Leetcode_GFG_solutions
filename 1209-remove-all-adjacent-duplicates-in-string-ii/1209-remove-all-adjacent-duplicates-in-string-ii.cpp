class Solution
{
    private:
        stack<int> st;
    public:
        string removeDuplicates(string s, int k)
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (i == 0 || s[i] != s[i - 1]) st.push(1);  // push 1 to the stack for every new char
                else if (++st.top() == k) // if the count of character reaches k
                {
                    st.pop(); // pop off the stack
                    s.erase(i - k + 1, k); // erase that portion of string
                    i = i - k; // reset i
                }
            }
            return s;
        }
};