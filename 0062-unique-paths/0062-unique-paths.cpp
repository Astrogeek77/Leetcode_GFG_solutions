class Solution
{
    public:
    int dp[101][101];
    int solve(int m, int n)
    {
        // invalid move
        if (m < 0 || n < 0) 
            return 0;
        // border moves
        if (m == 0 || n == 0) 
            return 1;
        // memoize
        if (dp[m][n] > 0) 
            return dp[m][n];
        // bottom-up traversal
        else 
            return dp[m][n] = solve(m - 1, n) + solve(m, n - 1);
    }

    int uniquePaths(int m, int n)
    {
        return solve(m - 1, n - 1);
    }
};