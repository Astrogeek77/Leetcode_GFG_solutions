// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/2652623/c%2B%2B-(4)approachororrecursion-greatermemoisation-greatertabulation-greaterspace-optimsation

class Solution
{
    public:
        int stock(vector<int> &v, int buy, int index, vector<vector< int>> &dp, int fee)
        {
            if (index == v.size()) return 0;
            if (dp[index][buy] != -1) return dp[index][buy];

            int profit = 0;
            if (buy)
            {

                int not_buy = stock(v, 1, index + 1, dp, fee);
                int buy = -v[index] + stock(v, 0, index + 1, dp, fee);
                profit = max(buy, not_buy);
            }
            else
            {

                int sell = v[index] - fee + stock(v, 1, index + 1, dp, fee);
                int not_sell = stock(v, 0, index + 1, dp, fee);
                profit = max(sell, not_sell);
            }
            return dp[index][buy] = profit;
        }
    int maxProfit(vector<int> &prices, int fee)
    {

        vector<vector < int>> dp(prices.size(), vector<int> (2, -1));
        return stock(prices, 1, 0, dp, fee);
    }
};