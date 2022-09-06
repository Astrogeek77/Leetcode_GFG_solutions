class Solution
{
    public:
        int helper(string s, string t, int i, int j, vector<vector < int>> &dp)
        {
            if (i == 0 || j == 0) return 0;

           	// memoize
            if (dp[i][j] != -1) return dp[i][j];

            if (s[i - 1] == t[j - 1]) dp[i][j] = 1 + helper(s, t, i - 1, j - 1, dp);
            else dp[i][j] = helper(s, t, i, j - 1, dp);

            return dp[i][j];
        }

    bool isSubsequence(string s, string t)
    {
        int m = s.size();
        int n = t.size();

        if (m > n) return false;

       	// dp vector
        vector<vector < int>> dp(m + 1, vector<int> (n + 1, -1));

        return helper(s, t, m, n, dp) == m ? true : false;
    }
};