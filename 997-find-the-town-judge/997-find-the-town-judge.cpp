class Solution
{
    public:
        int findJudge(int n, vector<vector < int>> &trust)
        {

            vector<vector < int>> g(n+1, vector<int> (2, 0));

                for (int i = 0; i < trust.size(); i++)
                {
                    g[trust[i][0]][0] = 1;
                    g[trust[i][1]][1]++;
                }

                for (int i = 1; i <= n; i++)
                {
                    if (g[i][0] == 0 and g[i][1] == n - 1) return i;
                }
                return -1;
            }
        };