class Solution
{
    public:
        int longestPalindrome(string s)
        {
            vector count(52, 0);
            int ans = 0;
            for (char &ch: s)
            {
                if (ch > 'Z')
                {
                    count[ch - 'a' + 26]++;
                }
                else
                {
                    count[ch - 'A']++;
                }
            }
            
            int mxOdd = 0;
            for (int i = 0; i < 52; ++i)
            {
                if (count[i] % 2 == 0)
                {
                    ans += count[i];
                }
                else
                {
                    ans += count[i] - 1;
                    mxOdd = max(mxOdd, count[i]);
                }
            }
            if (mxOdd > 0) ans++;
            return ans;
        }
};