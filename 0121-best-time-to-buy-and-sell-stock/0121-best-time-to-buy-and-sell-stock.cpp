class Solution
{
    public:
    int maxProfit(vector<int> &a)
    {
        // keep track of minimum cost price and maximum profit.
        int min_CP = INT_MAX, maxProfit = INT_MIN;

        for (auto x: a)
        {
            // for every element check for the minimum cost price
            min_CP = min(min_CP, x);
            // calculate profit and maximize it
            maxProfit = max(maxProfit, x - min_CP);
        }
        return maxProfit;
    }
};