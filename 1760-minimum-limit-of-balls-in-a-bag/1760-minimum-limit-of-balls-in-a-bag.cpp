class Solution
{
    public:
        bool check(int x, int k, vector<int> &nums)
        {
            int total = 0;
            for (auto i: nums)
            {
               	// adding the minimum number of moves required to divide the current
               	// element into parts whose value is equal to or less than x

               	// for minimum moves we are dividing the current element into parts equal
               	// to x and if some part is left which cannot be equal to x we leave it as it is

               	// example
               	// i = 16, x = 3
               	// 16 -> 3, 13 -> 3, 3, 10 -> 3, 3, 3, 7 -> 3, 3, 3, 3, 4 -> 3, 3, 3, 3, 3, 1
               	// 16/3 - (0) = 5

               	// i = 18, x = 3
               	// 18 -> 3, 15 -> 3, 3, 12 -> 3, 3, 3, 9 -> 3, 3, 3, 3, 6 -> 3, 3, 3, 3, 3, 3
               	// 18/3 - (1) = 6 - 1 = 5
                total += i / x - (i % x == 0);
            }

            return (total <= k);
        }

    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int low = 1, ans = 1, high = *max_element(nums.begin(), nums.end());

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

           	// if this is possible then we are trying for lower value
           	// otherwise we increase the mid value
            if (check(mid, maxOperations, nums))
            {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};