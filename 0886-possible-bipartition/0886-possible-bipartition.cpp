#define WHITE 0
#define RED 1
#define BLUE 2

class Solution
{
    public:
        bool possibleBipartition(int N, vector<vector < int>> &edges)
        {
            vector<vector < int>> adj(N + 1);
            vector<int> color(N + 1, WHITE);	
            // visited vector
            vector<bool> explored(N + 1, false);	
            
            for (auto &edge: edges)
            {
                int u = edge[0];
                int v = edge[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }

           	// print adjacency list (comment out before submitting)
            // for (int i = 0; i <= N; ++i)
            // {
            //     cout << "adj[" << i << "]: ";
            //     for (int j = 0; j < adj[i].size(); ++j)
            //     {
            //         cout << adj[i][j] << " ";
            //     }
            //     cout << "\n";
            // }

           	// queue to perform BFS over each connected component in the graph
           	// while performing BFS, we check if we encounter any conflicts while
           	// coloring the vertices of the graph
           	// conflicts indicate that bi-partition is not possible
            queue<int> q;

            for (int i = 1; i <= N; ++i)
            {
                if (!explored[i])
                {
                   	// this component has not been colored yet
                   	// we color the first vertex RED and push it into the queue
                    color[i] = RED;
                    q.push(i);

                    while (!q.empty())
                    {
                        int u = q.front();
                        q.pop();

                        if (explored[u]) continue;

                        explored[u] = true;

                        for (auto v: adj[u])
                        {
                           	// checking if there's any conflict in coloring
                            if (color[v] == color[u]) return false;

                           	// we color v with the opposite color of u
                            if (color[u] == RED)
                            {
                                color[v] = BLUE;
                            }
                            else
                            {
                                color[v] = RED;
                            }

                            q.push(v);
                        }
                    }
                }
            }
            return true;
        }
};