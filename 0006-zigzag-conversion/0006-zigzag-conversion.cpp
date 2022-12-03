class Solution
{
    public:
        string convert(string s, int numsRows)
        {
            if (s.size() < 1 or numsRows == 1) return s;

            string ans = "";

            for (int i = 0; i < numsRows; i++)
            {
                for (int j = i; j < s.size(); j += numsRows + (numsRows - 2))
                {
                    ans += s[j];

                    int diag = 2 * (numsRows - i - 1);
                    if (i != 0 and i != numsRows - 1 and j + diag < s.size())
                    {
                        ans += s[j + diag];
                    }
                }
            }
            return ans;
        }
};