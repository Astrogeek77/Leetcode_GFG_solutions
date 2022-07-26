class Solution
{
    public:
        int dp[50001];
    int cal(int i, int e, vector<vector < int>> &mat)
    {
        if (i == mat.size()) return 0;
        if (dp[i] != -1) return dp[i];
        int ans = cal(i + 1, e, mat);
        if (mat[i][0] >= e)
        {
            int idx = i;
            while (idx < mat.size() && mat[idx][0] < mat[i][1]) idx++;
            ans = max(ans, mat[i][2] + cal(idx, mat[i][1], mat));
        }
        return dp[i] = ans;
    }
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector< int > &profit)
    {
        memset(dp, -1, sizeof(dp));
        int n = profit.size();
        vector<vector < int>> mat(n);
        for (int i = 0; i < n; i++)
        {
            mat[i] = { startTime[i],
                endTime[i],
                profit[i]
            };
        }
        sort(mat.begin(), mat.end());
        return cal(0, 0, mat);
    }
};