class Solution {
  public:
    int numEnclaves(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if((i == 0 or i == n-1 or j == 0 or j == m-1) and grid[i][j] == 1)
                {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
        
        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};
        
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++)
            {
               int nr = r + delRow[i];
                int nc = c + delCol[i];
                
                if(nr >= 0 and nr < n and nc >= 0 and nc < m 
                        and grid[nr][nc] == 1 and !vis[nr][nc])
                {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                } 
            }
        }
        
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1 and !vis[i][j])
                {
                    vis[i][j] = 1;
                    count++;
                }
            }
        }
        return count;
    }
};