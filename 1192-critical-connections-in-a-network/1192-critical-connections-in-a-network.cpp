class Solution
{
    private:
        vector<int> low, tin;
    int timer = 0;
    vector<vector < int>> res;

    private:
        void dfs(int node, int parent, vector<int> adj[], vector<bool> &vis)
        {
            vis[node] = true;
            tin[node] = low[node] = timer++;	// for each dfs call timer increases

            for (auto &it: adj[node])
            {
                if (it == parent) continue;	// already visted

                if (!vis[it])	// if not visted
                {
                    dfs(it, node, adj, vis);	// call dfs for it

                    low[node] = min(low[node], low[it]);	// minimum of either the node or its neighbours

                    if (low[it] > tin[node])	// then we check for our main condition
                    {
                       	// we compare the time of insertion of our node with the low of nieghbour
                        res.push_back({ node,
                            it });
                    }
                }
                // if already visited
                else low[node] = min(low[node], tin[it]);
            }
        }

    public:
        vector<vector < int>> criticalConnections(int n, vector<vector < int>> &edges)
        {

            vector<int> adj[n];
            for (auto &it: edges)
            {
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
            }

            vector<bool> vis(n, false); // visited
            low = vector<int> (n);  // lowest time of insertion for all neighbour nodes of a node
            tin = vector<int> (n); // discovery (time of insertion) value

            for (int i = 0; i < n; i++) // dfs for multiple component graph
            {
                if (!vis[i])
                    dfs(i, -1, adj, vis);
            }

            return res;
        }
};