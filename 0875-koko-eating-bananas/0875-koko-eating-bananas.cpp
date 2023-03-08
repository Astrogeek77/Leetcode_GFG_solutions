class Solution
{
    public:
    int minEatingSpeed(vector<int> &piles, int H)
    {
        int lo = 1, hi = 1e9;
        while (lo < hi)
        {
            int mid = (lo + hi) / 2, total = 0;
            
            for (int banana: piles)
                total += (banana + mid - 1) / mid;
            
            if (total > H) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};