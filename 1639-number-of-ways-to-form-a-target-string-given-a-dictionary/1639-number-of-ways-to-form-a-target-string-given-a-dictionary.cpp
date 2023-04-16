class Solution
{
    public:
        int cnt(vector<string> &words, string target, int i, int j, vector<vector< int>> &dp)
        {
            if (j == target.length()) return 1;
            if (words[0].length() - i < target.length() - j) return 0;
            if (dp[i][j] != 0) return dp[i][j];
            long long int ans = 0, cnt2 = 0;
            for (int k = 0; k < words.size(); k++)
            {
                if (words[k][i] == target[j]) cnt2++;
            }
            if (cnt2 != 0) ans += cnt2* cnt(words, target, i + 1, j + 1, dp);
            ans += cnt(words, target, i + 1, j, dp);
            dp[i][j] = ans % 1000000007;
            return ans % 1000000007;
        }
    int numWays(vector<string> &words, string target)
    {
        int n = words[0].length(), m = target.length();
        vector<vector < int>> dp(n, vector<int> (m, 0));
        return cnt(words, target, 0, 0, dp);
    }
};