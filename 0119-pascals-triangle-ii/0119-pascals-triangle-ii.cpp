class Solution
{
    public:
        vector<int> getRow(int rowIndex)
        {
            vector<int> dp(rowIndex + 1, 1);
            if (rowIndex <= 1) return dp;
            for (int i = 2; i <= rowIndex; i++)
            {
                for (int j = i - 1; j >= 1; j--)
                {
                    dp[j] = dp[j] + dp[j - 1];
                }
            }
            return dp;
        }
};