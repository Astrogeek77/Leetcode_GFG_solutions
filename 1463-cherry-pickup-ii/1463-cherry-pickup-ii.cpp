class Solution {
public:
        int helper(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e9;
        if(i == n-1) {
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int mx = INT_MIN;
        for(int di = -1; di <= 1; di++){
            for(int dj = -1; dj <= 1; dj++){
                int ans;
                if(j1 == j2){
                    ans = grid[i][j1] + helper(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
                } else {
                    ans = grid[i][j1] + grid[i][j2] + helper(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
                }
                mx = max(ans, mx);
            }
        }
        return dp[i][j1][j2] = mx;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (n, -1)));
        return helper(0, 0, n - 1, m, n, grid, dp);
    }
};