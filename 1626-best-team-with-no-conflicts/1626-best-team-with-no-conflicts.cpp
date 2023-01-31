class Solution
{
    public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        int n = scores.size();
        vector<pair<int, int>> players;

        for (int i = 0; i < n; i++)
        {
            players.push_back({ ages[i], scores[i] });
        }

        sort(players.begin(), players.end());

        int maxi = INT_MIN;
        vector<int> dp(n); // for memoization
        for (int i = 0; i < n; i++)
        {
            // score of player i
            dp[i] = players[i].second;
            for (int j = 0; j < i; j++)
            {
                // since the player ds is sorted wrt age we can easily look for max score
                if (players[j].second <= players[i].second)
                {
                    dp[i] = max(dp[i], dp[j] + players[i].second);
                }
                    
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};