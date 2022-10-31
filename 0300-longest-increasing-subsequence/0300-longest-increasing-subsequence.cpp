class Solution
{
    public:
        int lengthOfLIS(vector<int> &nums)
        {
            int n = nums.size();
            int *dp = new int[n];
            dp[0] = 1;
            for (int i = 1; i < n; i++)
            {
                dp[i] = 1;
                for (int j = i - 1; j >= 0; j--)
                {
                    if (nums[j] >= nums[i])
                    {
                        continue;
                    }
                    int possible = dp[j] + 1;
                    if (possible > dp[i])
                    {
                        dp[i] = possible;
                    }
                }
            }
            int best = 0;
            for (int i = 0; i < n; i++)
            {
                if (best < dp[i])
                {
                    best = dp[i];
                }
            }
            return best;
        }
};