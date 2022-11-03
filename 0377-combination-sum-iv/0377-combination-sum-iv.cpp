class Solution
{
    vector<int> dp;
    int helper(vector<int> &nums, int T, int n)
    {
       	// base case: if target is 0, we found a combination then return 1
        if (T == 0) return 1;
        int ans = 0;

       	// memoisation
        // T -> Target
        if (dp[T] != -1) return dp[T];

       	// picking up each elements less than target and 
       	// calling this function recursively
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= T)
            {
                // pick the num[i]
                ans += helper(nums, T - nums[i], n);
            }
        }
        return dp[T] = ans;
    }
    
    public: 
    int combinationSum4(vector<int> &nums, int target)
    {
        int n = nums.size();
       	// resizing the dp array to store values from 0 to target
        dp.resize(target + 1, -1);
        return helper(nums, target, n);
    }
};