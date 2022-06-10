class Solution
{
    public:
        int ans = 0;
    double dp[105][30][30];

    int dx[8] = { -1,
        -1,
        1,
        1,
        -2,
        -2,
        2,
        2
    };
    int dy[8] = { -2,
        2,
        -2,
        2,
        -1,
        1,
        -1,
        1
    };

    double func(int n, int m, int k, int r, int c)
    {

        if (k == 0)
        {
            return 1.0;
        }

        if (dp[k][r][c] != -1)
        {
            return dp[k][r][c];
        }

        double val = 0;
        for (int i = 0; i < 8; i++)
        {
            int x = r + dx[i];
            int y = c + dy[i];

            if (x >= 0 && y >= 0 && x < n && y < m)
            {
                val += ((double) 1 / (double) 8) *(func(n, m, k - 1, x, y));
            }
        }

        return dp[k][r][c] = val;
    }

    double knightProbability(int n, int k, int r, int c)
    {

        for (int i = 0; i < 105; i++)
        {
            for (int j = 0; j < 30; j++)
            {
                for (int idx = 0; idx < 30; idx++)
                    dp[i][j][idx] = -1;
            }
        }

        double temp = func(n, n, k, r, c);

        return temp;
    }
};