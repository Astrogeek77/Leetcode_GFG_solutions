#define ll long long

class Solution
{
    public:
        int numberOfArithmeticSlices(vector<int> &nums)
        {
            // using long long as per contraints
            int n = nums.size();
            int ans = 0;
            // we use a vector of map or pair per choice to memoize solution
            // dp[i][d] dp[i][d] denotes the number of subsequences (have at least 2 numbers) that ends with nums[i] and its common difference is d.
            vector<unordered_map <ll, int>> dp(n);
            
            for (int i = 1; i < n; i++)
            {
                // we check for other numbers till i
                for (int j = 0; j < i; j++)
                {
                    // calculate difference
                    ll diff = (ll) nums[i] - nums[j];
                    // we check the count at index j  for a diffrence and 
                    // decide whether prev subsequence can be continued or not.
                    int cnt = dp[j].count(diff) ? dp[j][diff] : 0;
                    // update diff at index i
                    dp[i][diff] += cnt + 1;
                    // and update ans;
                    ans += cnt;
                }
            }
            // return answer.
            return ans;
        }
};