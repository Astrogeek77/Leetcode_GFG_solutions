class Solution
{
    public:
        int maxSubArray(vector<int> &nums)
        {
           	// kadane's
            int n = nums.size();
            long long maxSum = INT_MIN, currSum = 0;

            for (long long x: nums)
            {
                currSum = max(x, currSum + x);
                maxSum = max(maxSum, currSum);
            }
            return maxSum;
        }
};