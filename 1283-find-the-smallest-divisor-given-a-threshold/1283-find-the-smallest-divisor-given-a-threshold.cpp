class Solution
{
    public:
        int smallestDivisor(vector<int> &nums, int &k)
        {
            int mn = 1, mx = 0, mid, sum;
            for (auto &i: nums) mx = max(mx, i);
            
            mx++;
            
            while (mn < mx)
            {
                mid = (mx - mn) / 2 + mn;
                sum = 0;
                
                for (auto &i: nums)
                {
                    if (i % mid) sum += ((i / mid) + 1);
                    else sum += i / mid;
                }
                if (sum <= k) mx = mid;
                else mn = mid + 1;
            }
            return mx;
        }
};