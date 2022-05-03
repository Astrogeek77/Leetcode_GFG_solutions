class Solution {
public:
    int helper(int i, int buy, vector<int> &prices, vector<vector<int>> &dp){
        if(i == prices.size()) return 0; 
        
        if(dp[i][buy] != -1) return dp[i][buy];
        
        int pick, npick;
        if(buy) {
            pick = (-prices[i] + helper(i+1, 0, prices, dp));
            npick = (0 + helper(i+1, 1, prices, dp));
            return dp[i][buy] = max(pick, npick);
        } 
        else 
        {
            pick = (prices[i] + helper(i+1, 1, prices, dp));
            npick = (0 + helper(i+1, 0, prices, dp)); 
            return dp[i][buy] = max(pick, npick);
        }
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return  helper(0, 1, prices, dp);
    }
};