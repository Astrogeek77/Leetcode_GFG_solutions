class Solution
{
    public:
        int findJudge(int n, vector<vector < int>> &trust)
        {
            // graph[trust-connection][number of people that trust i]
            vector<vector < int>> graph(n + 1, vector<int> (2, 0));

            for (int i = 0; i < trust.size(); i++)
            {
                graph[trust[i][0]][0] = 1;
                graph[trust[i][1]][1]++;
            }

            for (int i = 1; i <= n; i++)
            {
                // the town judge trusts nobody and every one trusts judge
                if (graph[i][0] == 0 and graph[i][1] == n - 1) return i;
            }
            return -1;
        }
};