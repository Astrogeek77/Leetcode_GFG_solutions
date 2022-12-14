class Solution
{
    public:
        int rob(vector<int> &nums)
        {
            int prev = nums[0], prev2 = 0, curr = 0;
            int n = nums.size();

            for (int i = 1; i < n; i++)
            {
                int pick = nums[i];
                if (i > 1) pick += prev2;
                int npick = 0 + prev;

                curr = max(pick, npick);
                prev2 = prev;
                prev = curr;
            }
            return prev;
        }
};