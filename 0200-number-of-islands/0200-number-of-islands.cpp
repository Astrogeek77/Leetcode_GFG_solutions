class Solution
{
    public:

        void turn_to_dust(vector<vector < char>> &grid, int i, int j, int m, int n)
        {
            if (i < 0 || j < 0 || i == m || j == n || grid[i][j] == '0') return;
            
            grid[i][j] = '0';
            
            int di[4] = {1, -1, 0, 0};
            int dy[4] = {0, 0, 1, -1};

            for(int k = 0; k < 4; k++)
            {
                int x = i + di[k];
                int y = j + dy[k];

                turn_to_dust(grid, x, y, m, n);
            }          
        }

    int numIslands(vector<vector < char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    res++;
                    turn_to_dust(grid, i, j, m, n);
                }
            }
        }
        return res;
    }
};