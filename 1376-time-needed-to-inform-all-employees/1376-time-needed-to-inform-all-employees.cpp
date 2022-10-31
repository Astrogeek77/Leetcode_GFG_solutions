class Solution
{
    int n1, headID1;
    vector<int> informTime1;
    vector<vector < int>> graph;

    int dfs(int i, vector<int> &vis)
    {
        vis[i] = 1;

        int time = 0;
        for (auto j: graph[i])
        {
            if (vis[j] == 0) time = max(time, dfs(j, vis));
        }

        time += informTime1[i];
        return time;
    }

    public:
        int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
        {
            n1 = n, headID1 = headID, informTime1 = informTime;

            graph = vector<vector < int>> (n);
            for (int i = 0; i < n; i++)
            {
                if (i != headID)
                    graph[manager[i]].push_back(i);
            }
           	// End

            vector<int> vis(n, 0);
            return dfs(headID, vis);
        }
};