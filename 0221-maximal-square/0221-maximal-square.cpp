// https://leetcode.com/problems/maximal-square/discuss/1632376/C%2B%2BPython-6-Simple-Solution-w-Explanation-or-Optimizations-from-Brute-Force-to-DP
class Solution
{
    public:
        int maximalSquare(vector<vector < char>> &M)
        {
            int m = size(M), n = size(M[0]), ans = 0;
            vector<vector < int>> dp(m + 1, vector<int> (n + 1)), onesRow(dp), onesCol(dp);
            for (int i = m - 1; ~i; i--)
                for (int j = n - 1; ~j; j--)
                    onesRow[i][j] = (M[i][j] == '1' ? 1 + onesRow[i][j + 1] : 0),
                    onesCol[i][j] = (M[i][j] == '1' ? 1 + onesCol[i + 1][j] : 0);

            for (int i = m - 1; ~i; i--)
                for (int j = n - 1; ~j; j--)
                    dp[i][j] = (M[i][j] == '1' ? 1 + min({ onesRow[i][j] - 1,
                        onesCol[i][j] - 1,
                        dp[i + 1][j + 1] }) : 0),
                    ans = max(ans, dp[i][j]);

            return ans * ans;
        }
};