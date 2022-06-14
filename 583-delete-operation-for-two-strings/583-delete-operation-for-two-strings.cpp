class Solution {
    int helper(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == t[j])
            return dp[i][j] = 1 + helper(i - 1, j - 1, s, t, dp);
        else
            return dp[i][j] = 0 + max(helper(i - 1, j, s, t, dp), helper(i, j - 1, s, t, dp));
    }

    int lcs(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(n - 1, m - 1, s, t, dp);
    }
public:
    int minDistance(string word1, string word2) {
        int len = lcs(word1, word2);
        return word1.size() + word2.size() - 2 * len;
    }
};