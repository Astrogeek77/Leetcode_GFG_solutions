class Solution {
public:
   
    int helper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& moveCost, vector<vector<int>>& dp){
        // base case
        if(i == grid.size() - 1) return grid[i][j];
        
        // Memoize
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        for(int col = 0; col < grid[0].size(); col++)
        {
            int next = helper(i+1, col, grid, moveCost, dp);
            ans =  min(ans, next + moveCost[grid[i][j]][col] + grid[i][j]);
        }
        return dp[i][j] = ans;
    }
    
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int res = INT_MAX;
        vector<vector<int>> dp(101, vector<int> (101, -1));
        
        for(int j = 0; j < grid[0].size(); j++)
        {
            res = min(res, helper(0, j, grid, moveCost, dp));
        }
        return res;
    }
};