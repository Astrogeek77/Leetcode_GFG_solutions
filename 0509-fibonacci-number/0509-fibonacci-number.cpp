class Solution
{
    public:
    int helper(int n, vector<int> &dp)
    {
        if (n == 0 || n == 1) return dp[n] = n;
        if (dp[n] != -1) return dp[n];
        return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
    }
    
    int fib(int n)
    {
        vector<int> dp(n + 1, -1);
        return helper(n, dp);
    }
};