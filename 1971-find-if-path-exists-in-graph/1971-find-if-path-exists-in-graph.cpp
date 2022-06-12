// class Solution
// {
//    void DFS(vector<vector < int>> &adj, int source, vector<int> &visited)
//     {
//         visited[source] = true;
//         for (auto x: adj[source])
//         {
//             if (!visited[x])
//             {
//                 DFS(adj, x, visited);
//             }
//         }
//     }
//     public:
//         bool validPath(int n, vector<vector < int>> &edges, int source, int destination)
//         {
//             vector<int> visited(n, false);
//             vector<vector < int>> adj(n);

//             for (int i = 0; i < edges.size(); i++)
//             {
//                 int u = edges[i][0];
//                 int v = edges[i][1];

//                 adj[u].push_back(v);
//                 adj[v].push_back(u);
//             }

//             DFS(adj, source, visited);
//             return visited[destination];
//         }
// };
class Solution
{

    public:
        bool validPath(int n, vector<vector < int>> &edges, int src, int dest)
        {
            vector<int> visited(n, false);

            vector<vector < int>> adj(n);

            for (int i = 0; i < edges.size(); i++)
            {
                int u = edges[i][0];
                int v = edges[i][1];

                adj[u].push_back(v);
                adj[v].push_back(u);
            }

            queue<int> q;
            q.push(src);

            while (!q.empty())
            {
                for (int i = 0; i < q.size(); i++)
                {
                    int node = q.front();
                    q.pop();

                    if (node == dest) return true;

                    visited[node] = true;
                    for (auto x: adj[node])
                    {
                        if (!visited[x])
                        {
                            q.push(x);
                        }
                    }
                }
            }
            return false;
        }
};