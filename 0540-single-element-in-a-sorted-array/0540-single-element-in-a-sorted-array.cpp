class Solution
{
    public:
        int singleNonDuplicate(vector<int> &nums)
        {
            int n = nums.size(), start = 0, end = n - 1, mid, next, prev;
            if (n == 1) return nums[0];
            while (start <= end)
            {
                mid = start + (end - start) / 2;
                next = (mid + 1) % n;
                prev = (mid + n - 1) % n;
                if (nums[mid] != nums[prev] && nums[mid] != nums[next]) return nums[mid];
                else if ((mid % 2 && nums[mid] == nums[prev]) || (!(mid % 2) && nums[mid] == nums[next])) start = mid + 1;
                else end = mid - 1;
            }
            return -1;
        }
};