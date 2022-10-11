class Solution
{
    public:
        bool increasingTriplet(vector<int> &nums)
        {
            int n = nums.size();

            if (n < 3) return false;

            int left = INT_MAX;
            int mid = INT_MAX;

            for (int i = 0; i < n; i++)
            {
                if (nums[i] > mid) return true;

                else if (nums[i] > left && nums[i] < mid)
                    mid = nums[i];
                else if (nums[i] < left)
                    left = nums[i];
            }
            return false;
        }
};