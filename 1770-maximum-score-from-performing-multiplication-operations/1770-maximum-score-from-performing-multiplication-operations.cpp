class Solution
{

    int helper(int l, int r, int n, vector<int> &nums, vector<int> &mul, vector<vector < int>>  &dp)
    {
        if (r == mul.size()) return 0;

       	// memoize
        if (dp[l][r] != INT_MIN) return dp[l][r];

        int left = helper(l + 1, r + 1, n, nums, mul, dp) + (nums[l] *mul[r]);
        int right = helper(l, r + 1, n, nums, mul, dp) + (nums[(n - 1) - (r - l)] *mul[r]);

        return dp[l][r] = max(left, right);
    }

    public:

        int maximumScore(vector<int> &nums, vector<int> &mul)
        {
            int n = nums.size();
            int m = mul.size();

            vector<vector < int>> dp(m + 1, vector<int> (m + 1, INT_MIN));

            return helper(0, 0, n, nums, mul, dp);
        }
};