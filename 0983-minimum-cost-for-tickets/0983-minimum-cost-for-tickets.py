# class Solution
# {
#     int helper(int idx, vector<int> &days, vector<int> &costs, vector<int> &dp)
#     {
#         // base condition
#         if (idx >= days.size())
#             return 0;
#         // memoize
#         if (dp[idx] != -1)
#             return dp[idx];
        
#         int pass_days[] = {1, 7, 30};
#         int min_cost = INT_MAX;
        
#         for(int i = 0; i < 3; i++)
#         {
#             int day = pass_days[i];
#             int pass_idx = upper_bound(days.begin(), days.end(), days[idx] + day - 1) - days.begin();
#             int cost = helper(pass_idx, days, costs, dp) + costs[i];
            
#             if(cost < min_cost) min_cost = cost;
#         }
#         return dp[idx] = min_cost;
#     }
#     public:
#     int mincostTickets(vector<int> &days, vector<int> &costs)
#     {
#         vector<int> dp(days.size() + 1, -1);
#         return helper(0, days, costs, dp);
#     }
# };

class Solution:
    def helper(self, idx: int, days: List[int], costs: List[int], dp: List[int]) -> int:
        if idx >= len(days):
            return 0
        if(dp[idx] != -1):
            return dp[idx]
        
        pass_days = [1, 7, 30]
        min_cost = 10000000
        
        for i in range(3):
            day = pass_days[i]
            pass_idx = bisect.bisect_right(days, days[idx] + day - 1, lo = 0, hi = len(days))
            cost = self.helper(pass_idx, days, costs, dp) + costs[i]
            
            if cost < min_cost:
                min_cost = cost
        
        dp[idx] = min_cost
        return dp[idx]
            
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        dp = [-1] * len(days)
        ans = self.helper(0, days, costs, dp)
        return ans
        