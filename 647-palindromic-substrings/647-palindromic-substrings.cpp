class Solution
{
    public:
        int countSubstrings(string s)
        {
            int n = s.size();
            vector<vector < int>> dp(n, vector<int> (n, 0));

            int count = 0;	// final answer

           	// for length = 1 (no need to check)
            for (int i = 0; i < n; i++)
            {
                dp[i][i] = 1;
                count++;
            }

           	// for length = 2 
            for (int i = 0; i < n - 1; i++)
            {
                if (s[i] == s[i + 1])
                {
                    dp[i][i + 1] = 1;
                    count++;
                }
            }

           	// for length >= 3
            for (int k = 3; k <= n; k++)
            {
                for (int i = 0; i < n - k + 1; i++)
                {
                    // i ->start j ->end
                    int j = i + k - 1; 
                    
                    // using the previous checked palindromes to form bigger palindromes.
                    if (dp[i + 1][j - 1] and s[i] == s[j]) 
                    {
                        dp[i][j] = 1;
                        count++;
                    }
                }
            }
            return count;
        }
};