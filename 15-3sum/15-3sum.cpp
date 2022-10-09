class Solution
{
    public:
        vector<vector < int>> threeSum(vector<int> &nums)
        {
            sort(nums.begin(), nums.end());

            if (nums.size() < 3) return {};

            vector<vector < int>> ans;

            for (int i = 0; i < nums.size() - 2; i++)
            {
                if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
                {
                    int lo = i + 1, hi = nums.size() - 1;

                    while (lo < hi)
                    {
                        int sum = nums[i] + nums[lo] + nums[hi];

                        if (sum == 0)
                        {
                            ans.push_back({ nums[i],
                                nums[lo],
                                nums[hi] });

                            while (lo < hi && nums[lo] == nums[lo + 1]) lo++;
                            while (lo < hi && nums[hi] == nums[hi - 1]) hi--;

                            lo++;
                            hi--;
                        }
                        else if (sum < 0) lo++;
                        else hi--;
                    }
                }
            }
            return ans;
        }
};