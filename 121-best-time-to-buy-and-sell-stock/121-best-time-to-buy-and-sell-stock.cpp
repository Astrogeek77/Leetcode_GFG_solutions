class Solution
{
    public:
        int maxProfit(vector<int> &a)
        {

            int min_cp = INT_MAX;
            int profit = INT_MIN;

           	// logic 
            for (auto x: a)
            {
               	// if (x < min_cp) min_cp = x;
                min_cp = min(x, min_cp);
               	// if (x - min_cp > profit) profit = x - min_cp;
                profit = max(x - min_cp, profit);
            }

            return profit;
        }
};