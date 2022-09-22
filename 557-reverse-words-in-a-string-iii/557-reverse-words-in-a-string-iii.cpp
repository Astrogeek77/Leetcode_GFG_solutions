class Solution
{
    public:
        string reverseWords(string s)
        {
            int n = s.length();
            int j = 0;

            for (int i = 0; i <= n; i++)
            {
                if (s[i] == ' ' || s[i] == '\0')
                {
                    reverse(s.begin() + j, s.begin() + i);
                    j = i + 1;
                }
            }
            return s;
        }
};