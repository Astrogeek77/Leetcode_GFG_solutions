class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> prev(n, 0);
        for(int i = 0; i < n; i++){
            vector<int> curr(m, 0);
            for(int j = 0; j < m; j++){
                if(i == 0 and j == 0) curr[j] = grid[i][j];
                else {
                    int up = grid[i][j], left = grid[i][j];
                    up += (i > 0) ? prev[j] : 1e9;
                    left += (j > 0) ? curr[j-1] : 1e9;
                    curr[j] = min(up, left);
                }	
            }
            prev = curr;
        }
        return prev[m-1];
    }
};


// int helper(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
// 	if(i == 0 and j == 0) return grid[0][0];
// 	if(i < 0 || j < 0) return 1e9;
	
// 	if(dp[i][j] != -1) return dp[i][j];
// 	int up, left;
// 	up = grid[i][j] + helper(i - 1, j, grid, dp);
// 	left = grid[i][j] + helper(i, j - 1, grid, dp);
// 	return dp[i][j] = min(up, left);
// }


// int minSumPath(vector<vector<int>> &grid) {
// 	int n = grid.size(), m = grid[0].size();
// 	vector<vector<int>> dp(n, vector<int> (m, -1));
//     return helper(n - 1, m - 1, grid, dp);
// }



// int minSumPath(vector<vector<int>> &grid) {
// 	int n = grid.size(), m = grid[0].size();
// 	vector<vector<int>> dp(n, vector<int> (m, -1));
    
// 	for(int i = 0; i < n; i++){
// 		for(int j = 0; j < m; j++){
// 			dp[0][0] = grid[0][0];
// 			int up = grid[i][j], left = grid[i][j];
// 			up += (i > 0) ? dp[i-1][j] : 1e9;
// 			left += (j > 0) ? dp[i][j-1] : 1e9;
// 			dp[i][j] = min(up, left);
// 		}
// 	}
// 	return dp[n-1][m-1];
// }

// int minSumPath(vector<vector<int>> &grid) {
// 	int n = grid.size(), m = grid[0].size();
// 	vector<int> prev(n, 0);
// 	for(int i = 0; i < n; i++){
// 		vector<int> curr(m, 0);
// 		for(int j = 0; j < m; j++){
// 			if(i == 0 and j == 0) curr[j] = grid[i][j];
// 			else {
// 				int up = grid[i][j], left = grid[i][j];
// 				up += (i > 0) ? prev[j] : 1e9;
// 				left += (j > 0) ? curr[j-1] : 1e9;
// 				curr[j] = min(up, left);
// 			}	
// 		}
// 		prev = curr;
// 	}
// 	return prev[m-1];
// }