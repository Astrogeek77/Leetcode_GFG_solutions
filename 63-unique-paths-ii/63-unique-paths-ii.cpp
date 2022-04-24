// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& grid) {
//         int n = grid.size(), m = grid[0].size();
//         vector<vector<int>> dp(n, vector<int> (m, 0));
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 if(i == 0 and j == 0 and grid[i][j] != 1) {
//                     dp[i][j] = 1;
//                     continue;
//                 }
//                 if(grid[i][j] == 1) {
//                     dp[i][j] = 0;
//                     continue;
//                 }
//                 int up = 0, left = 0;
//                 if(i>0) up = dp[i - 1][j];
//                 if(j>0) left = dp[i][j-1];
//                 dp[i][j] = (up + left);
//             }
//         }
//         return dp[n-1][m-1];
//     }
// };

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> prev(n, 0);
        for (int i = 0; i < n; i++)
        {
            vector<int> curr(m, 0);
            for (int j = 0; j < m; j++)
            {
                if (i == 0 and j == 0 and grid[i][j] != 1)
                {
                    curr[j] = 1;
                    continue;
                }
                if (grid[i][j] == 1)
                {
                    curr[j] = 0;
                    continue;
                }
                int up = 0, left = 0;
                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = curr[j - 1];
                curr[j] = (up + left);
            }
            prev = curr;
        }
        return prev[m - 1];
    }
};