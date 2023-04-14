class Solution
{
    public:
    int helper(string &s, string &t, int i, int j, vector<vector < int>> &dp)
    {
        if (i < 0 or j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int ans;

        if (s[i] == t[j]) 
            ans = 1 + helper(s, t, i - 1, j - 1, dp);
        else 
            ans = max(helper(s, t, i - 1, j, dp), helper(s, t, i, j - 1, dp));

        return dp[i][j] = ans;
    }

    int longestPalindromeSubseq(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();
        vector<vector < int>> dp(n + 1, vector<int> (n + 1, -1));
        return helper(s, t, n - 1, n - 1, dp);
    }
};