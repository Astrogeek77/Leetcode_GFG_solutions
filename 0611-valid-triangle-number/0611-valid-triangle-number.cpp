class Solution
{
    public:
        int triangleNumber(vector<int> &nums)
        {
            sort(nums.begin(), nums.end());
            int n = nums.size(), ans = 0;
            
            for (int k = 2; k < n; ++k)
            {
                int i = 0, j = k - 1;
                while (i < j)
                {
                    if (nums[i] + nums[j] > nums[k])
                    {
                        // there will be j-1 valid pairs
                        ans += j - i;
                        j--;
                    }
                    else i++;
                }
            }
            return ans;
        }
};