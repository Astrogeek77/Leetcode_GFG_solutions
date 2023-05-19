class Solution
{
    public:
        vector<int> vis, col;
    bool dfs(int i, int j, vector<vector < int>> &graph)
    {
       	// i -> vertex, j -> color
        vis[i] = 1;
        col[i] = j;

        for (auto child: graph[i])
        {
            if (vis[child] == 0)
            {
               	// j = 1 - j;
                if (dfs(child, j ^ 1, graph) == false) return false;
            }
            else
            {
                if (col[i] == col[child]) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector < int>> &graph)
    {
        int n = graph.size();
        vis.resize(n);
        col.resize(n);

        for (int i = 0; i < n; ++i)
        {
            if (vis[i] == 0 and(dfs(i, 0, graph) == false)) return false;
        }
        return true;
    }
};