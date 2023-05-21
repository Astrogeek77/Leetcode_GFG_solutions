class Solution
{

    void find(vector<vector < int>> &grid, int i, int j, set< pair<int, int>> &isl)
    {
        if (min(i, j) < 0 || max(i, j) >= grid.size() || !grid[i][j] || isl.count({ i,
                j }))
            return;
        isl.insert({ i,
            j });
        grid[i][j] = 0;
        find(grid, i + 1, j, isl);
        find(grid, i - 1, j, isl);
        find(grid, i, j + 1, isl);
        find(grid, i, j - 1, isl);
    }

    public:
        int shortestBridge(vector<vector < int>> &grid)
        {
            set<pair<int, int>> isl1, isl2;
            bool isl = true;
            for (int i = 0; i < grid.size(); i++)
                for (int j = 0; j < grid.size(); j++)
                    if (grid[i][j])
                    {
                        if (isl) find(grid, i, j, isl1), isl = 0;
                        else find(grid, i, j, isl2);
                    }

            int ans = INT_MAX;
            for (auto[x1, y1]: isl1)
                for (auto[x2, y2]: isl2)
                    ans = min(ans, abs(x1 - x2) + abs(y1 - y2) - 1);
            return ans;
        }
};