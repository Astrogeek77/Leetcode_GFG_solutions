class Solution
{
    public:
        vector<vector < int>> updateMatrix(vector<vector < int>> &mat)
        {
            int m = mat.size(), n = mat[0].size();
            vector<vector < int>> matrix(m, vector<int> (n, 0));
            vector<vector < bool>> vis(m, vector<bool> (n, false));

            queue<pair<pair<int, int>, int>> q;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (mat[i][j] == 0)
                    {
                        matrix[i][j] = 0;
                        q.push({
		{
                                i,
                                j
                            },
                            0 });
                        vis[i][j] = true;
                    }
                    else
                        matrix[i][j] = mat[i][j];
                }
            }
            int adj_row[] = { -1,
                0,
                1,
                0
            };
            int adj_col[] = { 0,
                1,
                0,
                -1
            };

            while (!q.empty())
            {
                pair<int, int> cell = q.front().first;
                int dist = q.front().second;
                q.pop();

                matrix[cell.first][cell.second] = dist;

                for (int i = 0; i < 4; i++)
                {
                    int nrow = adj_row[i] + cell.first;
                    int ncol = adj_col[i] + cell.second;

                    if ((nrow >= 0 && nrow < m) && (ncol >= 0 && ncol < n) &&
                        (vis[nrow][ncol] == false))
                    {

                        vis[nrow][ncol] = true;
                        q.push({
		{
                                nrow,
                                ncol
                            },
                            dist + 1 });
                    }
                }
            }
            return matrix;
        }
};