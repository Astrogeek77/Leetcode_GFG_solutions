class Solution {
public:
    int numTilings(int n) 
    {
        int mod = 1e9 + 7;
        // dynamic Programming approach
        // for n = 1, ans => 1;
        // for n = 2, ans => 2;
        // for n > 2, 
        
        // dp[n] = dp[n-1] + dp[n-2] + 2dp[n-3] + 2dp[n-4] + ... + 2*dp[0].
        
        // for n-1
        // dp[n-1] = dp[n-2] + dp[n-3] + 2dp[n-4] + 2dp[n-5] + ... + 2dp[0] + 2dp[-1].
        
        // assuming dp[neg] = 0
        
        // which gives us
        // => dp[i] = 2 * dp[i-1] + dp[i-3];
        
        vector<long long> dp(1000, -1);
        
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        
        for(long long i = 3; i <= n; i++)
        {
            dp[i] = (2 * dp[i-1] + dp[i-3]) % mod;
        }
         
        return dp[n] % mod;
    }
};