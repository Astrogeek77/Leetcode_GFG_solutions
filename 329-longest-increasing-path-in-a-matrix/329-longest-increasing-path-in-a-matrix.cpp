class Solution
{
    public:
       	// check limits for i and j (func)
        bool checkSafe(int i, int j, vector<vector < int>> &matrix)
        {
            int n = matrix.size();	// rows
            int m = matrix[0].size();	// columns
            return (i >= 0 and i < n and j >= 0 and j < m);
        }
   	// helper recursive func
    int helper(int i, int j, vector<vector < int>> &matrix, vector<vector < int>> &dp, int n, int m)
    {
        if(!checkSafe(i, j, matrix)) return 0; // base case
        if(dp[i][j] != -1) return dp[i][j]; // Tabulate
        
        int up = 0, down = 0, left = 0, right = 0;
        
        // up
        if(checkSafe(i-1, j, matrix) and matrix[i-1][j] > matrix[i][j])
            up = helper(i-1, j, matrix, dp, n, m);
        
        // down
        if(checkSafe(i+1, j, matrix) and matrix[i+1][j] > matrix[i][j])
            down = helper(i+1, j, matrix, dp, n, m);
        
        // left
        if(checkSafe(i, j-1, matrix) and matrix[i][j-1] > matrix[i][j])
            left = helper(i, j-1, matrix, dp, n, m);
        
        // right
        if(checkSafe(i, j+1, matrix) and matrix[i][j+1] > matrix[i][j])
            right = helper(i, j+1, matrix, dp, n, m);
        
        return dp[i][j] = 1 + max(up, max(down, max(left, right)));
    }

    int longestIncreasingPath(vector<vector < int>> &matrix) {
        int n = matrix.size();	// rows
        int m = matrix[0].size();	// columns
        
        int result = 1; // answer
        vector<vector<int>> dp(n, vector<int> (m, -1));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // if(dp[i][j] == -1)
                    result = max(result, helper(i, j, matrix, dp, n, m));
            }
        }
        return result;
    }
};