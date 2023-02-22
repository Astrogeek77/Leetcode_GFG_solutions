class Solution
{
    bool check(vector<int> &weights, int days, int capacity)
    {
        int requireDays = 1;
        int currWeight = 0;
        for (int weight: weights)
        {
            if (currWeight + weight > capacity)
            {
                requireDays++;
                currWeight = 0;
            }
            currWeight += weight;
        }
        return !(requireDays > days);
    }
    public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int lo = 0, hi = 0;
        for (int weight: weights)
        {
            lo = max(lo, weight);
            hi += weight;
        }
        int ans = hi;
        // int mid;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (check(weights, days, mid))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return ans;
    }
};