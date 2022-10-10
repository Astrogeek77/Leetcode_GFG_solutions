class Solution
{
    public:
        int numIslands(vector<vector < char>> &grid)
        {

            unordered_map<string, string> dsu;

            int M = grid.size();
            int N = grid[0].size();

            for (int i = 0; i < M; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (grid[i][j] == '1')
                    {
                        string a = to_string(i) + "," + to_string(j);
                        dsu[a] = a;
                       	// Check left
                        if (j - 1 >= 0 && grid[i][j - 1] == '1')
                        {
                            string b = to_string(i) + "," + to_string(j - 1);
                            Union(a, b, dsu);
                        }
                       	// Check Up
                        if (i - 1 >= 0 && grid[i - 1][j] == '1')
                        {
                            string b = to_string(i - 1) + "," + to_string(j);
                            Union(a, b, dsu);
                        }
                    }
                }
            }

            int numOfIslands = 0;
            for (auto &it: dsu)
            {
                if (it.second == it.first)
                {
                    numOfIslands++;
                }
            }

            return numOfIslands;
        }

    string find(string cur, unordered_map<string, string> &dsu)
    {
        if (dsu[cur] == cur)
        {
            return cur;
        }
        return find(dsu[cur], dsu);
    }

    void Union(string &a, string &b, unordered_map<string, string> &dsu)
    {
        string parent = find(a, dsu);
        string child = find(b, dsu);
        if (parent != child)
        {
            dsu[parent] = child;
        }
    }
};