class Solution {
public:
    int helper(int i, int x, vector<int> & arr, vector<vector<int>> &dp){
        if(i == 0) {
            return (x % arr[i] == 0);
        }
        
        if(dp[i][x] != -1) return dp[i][x];
        
        int take = 0, ntake;
        ntake = 0 + helper(i - 1, x, arr, dp);
        if(x >= arr[i]) take = helper(i, x - arr[i], arr, dp);
        return dp[i][x] = take + ntake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount + 1, -1));
        return helper(n-1, amount, coins, dp);
    }
};