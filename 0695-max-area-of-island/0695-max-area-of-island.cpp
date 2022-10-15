class Solution
{
    private:
    int n, m;
    int trav(int i, int j, vector<vector < int>> &grid)
    {
        if (i < 0 || j < 0 || i >= n || j >= m || !grid[i][j]) return 0;
        grid[i][j] = 0;
        
        int up = trav(i - 1, j, grid);
        int down = trav(i + 1, j, grid);
        int left = trav(i, j - 1, grid);
        int right = trav(i, j + 1, grid);
        
        return 1 + up + down + left + right; 
    }
    
    public:
        int maxAreaOfIsland(vector<vector < int>> &grid)
        {
            int ans = 0;
            n = grid.size(), m = grid[0].size();
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (grid[i][j] == 1) ans = max(ans, trav(i, j, grid));
            return ans;
        }
    
};