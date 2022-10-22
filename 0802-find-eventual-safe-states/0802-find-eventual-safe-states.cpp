class Solution
{
    bool dfs(int i, vector<vector < int>> &adj, vector<int> &vis)
    {
        vis[i] = 2;

        for (auto n: adj[i])
        {
            if (vis[n] == 0)
            {
                if (dfs(n, adj, vis)) return true;
            }
            else if (vis[n] == 2) return true;
        }

        vis[i] = 3;
        return false;
    }
    public:
        vector<int> eventualSafeNodes(vector<vector < int>> &adj)
        {
            int V = adj.size();
            /*
            0 -> unvisited node
            1 -> visited node
            2 -> visited previously in current path
            3 -> safe node
        */
            vector<int> vis(V, 0);
            vector<int> ans;

            for (int i = 0; i < V; i++)
            {
                if (vis[i] == 0)
                {
                    dfs(i, adj, vis);
                }
            }

            for (int i = 0; i < V; i++)
            {
                if (vis[i] == 3) ans.push_back(i);
            }

            return ans;
        }
};