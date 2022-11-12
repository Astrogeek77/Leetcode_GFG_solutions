
#define mod 1000000007
class Solution
{
    public:
        int score(int target, vector<int> &dp, int one, int zero)
        {
           	// if target is 0 that means this target can be made so return 1
            if (target == 0) return 1;
           	// target < 0 cannot be made 
            if (target < 0) return 0;
           	// if already computed eturn the value
            if (dp[target] != -1) return dp[target];
            
            long long sum;
           	// target - a is adding 'a' 0's to the string
           	// target - b is adding 'b' 1's to string 
            sum = score(target - one, dp, one, zero) + score(target - zero, dp, one, zero);
            return dp[target] = (sum % (mod));
        }
    int countGoodStrings(int low, int high, int zero, int one)
    {
        vector<int> dp(high + 1, -1);

        int ans = 0;
       	// run a loop from low to high for every i get total number of ways to make that length
        for (int i = low; i <= high; i++)
        {
            ans = ((ans % mod) + (score(i, dp, one, zero) % mod)) % mod;
        }
        return ans;
    }
};