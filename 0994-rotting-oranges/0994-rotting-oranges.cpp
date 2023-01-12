class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        // {{row, col}, time}
        queue<pair<pair<int, int>, int>> q;
        
        int vis[n][m];
        
        // for all rotten oranges mark visited as 2
        // and push to queue with zero time.
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                    q.push({{i, j}, 0}),
                    vis[i][j] = 2;
                
                else 
                    vis[i][j] = 0;
            }
        }
        
        // configs 
        int time = 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        // BFS Traversal
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            
            q.pop();
            
            if(t > time) time = t;
            
            for(int i = 0; i < 4; i++)
            {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                
                // validation check
                if(nrow >= 0 and ncol >= 0 and
                   nrow < n and ncol < m and grid[nrow][ncol] == 1 and vis[nrow][ncol] == 0)
                {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2; // mark rotten
                }
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1 and vis[i][j] != 2) 
                    return -1;
            }
        }
        
        return time;
    }
};