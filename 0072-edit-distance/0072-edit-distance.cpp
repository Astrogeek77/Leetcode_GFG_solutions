class Solution
{
    private:
        int helper(int i, int j, string &s, string &t, vector<vector < int>> &dp)
        {
           	// base case
            if (j < 0) return i + 1;
            if (i < 0) return j + 1;

           	// memoization
            if (dp[i][j] != -1) return dp[i][j];

           	// possibilities

           	// if Match, do nothing and shrink the strings
            if (s[i] == t[j]) return dp[i][j] = 0 + helper(i - 1, j - 1, s, t, dp);

            else	// no match => 
            {

               	// insert
                int ins = 1 + helper(i, j - 1, s, t, dp);

               	// delete
                int del = 1 + helper(i - 1, j, s, t, dp);

               	// replace
                int rep = 1 + helper(i - 1, j - 1, s, t, dp);

               	// best case
                return dp[i][j] = min(ins, min(del, rep));
            }
        }

    public:
        int minDistance(string s, string t)
        {
            int n = s.size();
            int m = t.size();
            vector<vector < int>> dp(n, vector<int> (m, -1));
            return helper(n - 1, m - 1, s, t, dp);
        }
};