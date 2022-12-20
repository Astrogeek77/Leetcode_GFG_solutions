class Solution
{
    public:
    void sortColors(vector<int> &nums)
    {
        int hi = nums.size() - 1;
        int lo = 0, mid = 0;

        while (mid <= hi)
        {
            if (nums[mid] == 1)
            {
                mid++;
            }
            else if (nums[mid] == 0)
            {
                swap(nums[lo], nums[mid]);
                lo++;
                mid++;
            }
            else if (nums[mid] == 2)
            {
                swap(nums[hi], nums[mid]);
                hi--;
            }
        }
    }
};