class Solution
{
    private:
    void dfs1(vector<int> adj[], vector<int> &child, int length, int node, vector<int> &visited, vector<int> &ans)
    {
        visited[node] = 1;
        ans[0] += length;
        length++;
        for (auto &x: adj[node])
        {
            if (visited[x]) continue;
            dfs1(adj, child, length, x, visited, ans);
            child[node] += child[x];
        }
        child[node] += 1;
    }

    void dfs2(vector<int> adj[], vector<int> &child, int node, vector<int> &visited, int n, vector< int > &ans)
    {
        visited[node] = 1;
        for (auto &x: adj[node])
        {
            if (visited[x]) continue;
            ans[x] = ans[node] - child[x] + n - child[x];
            dfs2(adj, child, x, visited, n, ans);
        }
    }
    public:
        vector<int> sumOfDistancesInTree(int n, vector<vector < int>> &edges)
        {
            // adjancey list
            vector<int> adj[n];
            for (auto &edge: edges)
            {
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }
            
            vector<int> ans(n), child(n), visited(n);
            dfs1(adj, child, 0, 0, visited, ans);
            for (int i = 0; i < n; i++) visited[i] = 0;

            dfs2(adj, child, 0, visited, n, ans);
            return ans;
        }
};


/*
  Approach
-> Count the number of child nodes of each node(inclusive of itself.
-> Count the distance of every node from the 0th node.
-> Distance of child node can be given by
    dist[child] = dist[parent] - (Number of nodes that came closer by one unit) + (Number of nodes that went farther by one unit)
    =>dist[child] = dist[parent] - count[child] + (Total nodes - count[child])

Complexity
Time complexity: O(N)
Space complexity: O(N)

*/