class Solution
{
    public:
    ;
    void dfs(int node, vector<vector < int>> &edges, unordered_map<int, bool> &visited)
    {
        visited[node] = 1;

        for (auto it: edges[node])
        {
            if (!visited[it])
            {
                dfs(it, edges, visited);
            }
        }
    }
    bool validPath(int n, vector<vector < int>> &edges, int source, int destination)
    {
        vector<vector<int>> graph(n); // adjency list
        unordered_map<int, bool> visited; // visited record
        for (int i = 0; i < edges.size(); i++)
        {
            // bi-directional
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(source, graph, visited);
        return visited[destination] == true;
    }
};