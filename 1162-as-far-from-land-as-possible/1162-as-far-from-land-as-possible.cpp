class Solution
{
    int n;
    vector<vector < int>> dist;
    bool valid(int row, int col, int d, vector<vector < int>> &grid)
    {
        return (row >= 0 and row < n and col >= 0 and col < n and dist[row][col] > d and grid[row][col] == 0);
    }
    
    void dfs(vector<vector < int>> &grid, int i, int j, int d)
    {
        dist[i][j] = d;
        d++;
        
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        
        for(int k = 0; k < 4; k++)
        {
            int di = i + dx[k];
            int dj = j + dy[k];
            
            if(valid(di, dj, d, grid))
            {
                dfs(grid, di, dj, d);
            }
        }
        
        
//         if (i + 1 < n && grid[i + 1][j] == 0 && dist[i + 1][j] > d)
//             dfs(grid, i + 1, j, d);
        
//         if (i > 0 && grid[i - 1][j] == 0 && dist[i - 1][j] > d)
//             dfs(grid, i - 1, j, d);
        
//         if (j + 1 < n && grid[i][j + 1] == 0 && dist[i][j + 1] > d)
//             dfs(grid, i, j + 1, d);
        
//         if (j > 0 && grid[i][j - 1] == 0 && dist[i][j - 1] > d)
//             dfs(grid, i, j - 1, d);
    }
    public:
        int maxDistance(vector<vector < int>> &grid)
        {
            n = grid.size();
            dist = vector<vector < int>> (n, vector<int> (n, 1e3));

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == 1)
                        dfs(grid, i, j, 0);
                }
            }

            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    ans = max(ans, dist[i][j]);
                }
            }

            if (ans == 0 || ans == 1e3)
                return -1;
            return ans;
        }
};