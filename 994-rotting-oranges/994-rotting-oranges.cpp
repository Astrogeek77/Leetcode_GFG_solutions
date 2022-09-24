class Solution
{
    int count = 0;
    void helper(vector<vector < int>> &grid, int i, int j, int time)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == 0 || (grid[i][j] > 1 && grid[i][j] < time)) return;
      
        grid[i][j] = time;
        helper(grid, i + 1, j, time + 1);
        helper(grid, i - 1, j, time + 1);
        helper(grid, i, j + 1, time + 1);
        helper(grid, i, j - 1, time + 1);
    }
    public:
        int orangesRotting(vector<vector < int>> &grid)
        {
            int time = 2;
            for (int i = 0; i < grid.size(); i++)
            {
                for (int j = 0; j < grid[i].size(); j++)
                {
                    if (grid[i][j] == 2)
                    {
                        helper(grid, i, j, time);
                    }
                }
            }
            int ans = 2;
            for (int i = 0; i < grid.size(); i++)
            {
                for (int j = 0; j < grid[i].size(); j++)
                {
                    if (grid[i][j] == 1)
                        return -1;
                    ans = max(ans, grid[i][j]);
                }
            }
            return ans - 2;
        }
};