class Solution
{
    public:
    vector<vector < int>> updateMatrix(vector<vector < int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int, pair<int, int>>> q;
        // visited and result matrix
        vector<vector < int>> res(n, vector<int> (m)), vis(n, vector<int> (m));

        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < m; j++) 
            {
                // push all zeroes pos 
                if(mat[i][j] == 0) 
                {
                    q.push({ 0, { i, j }});
                    vis[i][j] = 1;
                }
            }
        }

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!q.empty())
        {
            auto p = q.front();
            q.pop();

            int dist = p.first, x = p.second.first, y = p.second.second;
            res[x][y] = dist;

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 and ny >= 0 and nx < n and ny < m and !vis[nx][ny])
                {
                    q.push({ dist + 1, { nx, ny } });
                    vis[nx][ny] = 1;
                }
            }
        }

        return res;
    }
};