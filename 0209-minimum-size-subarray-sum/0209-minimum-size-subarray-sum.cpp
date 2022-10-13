class Solution
{
    public:
        int minSubArrayLen(int target, vector<int> &nums)
        {
            int i = 0, j = 0, sum = 0, ans = nums.size() + 1;
            while (j < nums.size())
            {
                sum += nums[j++];
                while (sum >= target)
                {
                    ans = min(ans, j - i);
                    sum -= nums[i++];
                }
            }
            return ans % (nums.size() + 1);
        }
};