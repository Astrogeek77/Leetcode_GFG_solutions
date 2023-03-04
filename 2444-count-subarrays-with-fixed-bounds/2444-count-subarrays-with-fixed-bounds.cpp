class Solution
{
    public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        int n = nums.size();
        int leftBound = -1;
        int lastMin = -1, lastMax = -1;
        long long count = 0;

        for (int i = 0; i < n; i++)
        {
            // check if nums[i] is within the range[minK, maxK]
            if (nums[i] >= minK && nums[i] <= maxK)
            {
                // if nums[i] is equal to minK, update lastMin to the current index i
                lastMin = (nums[i] == minK) ? i : lastMin;
                // if nums[i] is equal to maxK, update lastMax to the current index i
                lastMax = (nums[i] == maxK) ? i : lastMax;
                // update the count by the number of valid subarrays between leftBound and the 
                // smaller of lastMin and lastMax
                count += max(0, min(lastMin, lastMax) - leftBound);
            }
            else
            {
                // if nums[i] is not within the range[minK, maxK], update leftBound to i
                leftBound = i;
                // reset lastMin and lastMax to -1
                lastMin = -1;
                lastMax = -1;
            }
        }

        // return the final count of valid subarrays
        return count;
    }
};