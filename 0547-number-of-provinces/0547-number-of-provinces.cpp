class Solution
{
    private:
        void dfs(int cur, vector<int> v[], vector<bool> &vis)
        {
            vis[cur] = true;

            for (auto nbr: v[cur])
            {
                if (!vis[nbr])
                {
                    dfs(nbr, v, vis);
                }
            }
        }
    public:
        int findCircleNum(vector<vector < int>> adj)
        {
            int n = adj.size();
            vector<int> v[n];
            int i = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (adj[i][j] == 1 and i != j)
                    {
                        v[i].push_back(j);
                        v[j].push_back(i);
                    }
                }
            }

            int count = 0;
            vector<bool> vis(n, false);
            for (int i = 0; i < n; i++)
            {
                if (!vis[i])
                {
                    dfs(i, v, vis);
                    count++;
                }
            }
            return count;
        }
};