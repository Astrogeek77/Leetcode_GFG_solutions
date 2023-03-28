class Solution
{
    int helper(int idx, vector<int> &days, vector<int> &costs, vector<int> &dp)
    {
        // base condition
        if (idx >= days.size())
        {
            return 0;
        }
        // memoize
        if (dp[idx] != -1)
        {
            return dp[idx];
        }
        
        int pass_days[] = {1, 7, 30};
        int min_cost = INT_MAX;
        
        for(int i = 0; i < 3; i++)
        {
            int day = pass_days[i];
            int pass = upper_bound(days.begin(), days.end(), days[idx] + day - 1) - days.begin();
            int cost = helper(pass, days, costs, dp) + costs[i];
            
            if(cost < min_cost) min_cost = cost;
        }
        
        
//         int pass1 = upper_bound(days.begin(), days.end(), days[idx] + 1 - 1) - days.begin();
//         int cost1 = helper(pass1, days, costs, dp) + costs[0];
        
//         int pass7 = upper_bound(days.begin(), days.end(), days[idx] + 7 - 1) - days.begin();
//         int cost7 = helper(pass7, days, costs, dp) + costs[1];
        
//         int pass3 = upper_bound(days.begin(), days.end(), days[idx] + 30 - 1) - days.begin();
//         int cost3 = helper(pass3, days, costs, dp) + costs[2];

        // return dp[idx] = min(min(cost1, cost7), cost3);
        return dp[idx] = min_cost;
    }
    public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        vector<int> dp(days.size() + 1, -1);
        return helper(0, days, costs, dp);
    }
};