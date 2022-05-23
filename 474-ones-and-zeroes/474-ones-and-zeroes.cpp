class Solution
{
    // 3 D dp vector, We will give it maximum size
    int dp[601][101][101];

    // count ones ans zeroes in the string
    pair<int, int> counter(string s)
    {
        int ones = 0, zeroes = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1') ones++;
            else zeroes++;
        }
        return {
            ones,
            zeroes
        };
    }
    
    // recursive function
    int helper(int i, int ones, int zeroes, int maxZeroes, int maxOnes, vector<string> &strs){
        // base case
        if(i >= strs.size()) return 0;
        if(ones > maxOnes or zeroes > maxZeroes) return 0;
        
        // memoize
        if(dp[i][ones][zeroes] != -1) return dp[i][ones][zeroes];
        
        // get the number of one and zeroes in ith index string
        auto p = counter(strs[i]);
        
        /* we declare three variables :-
        
        1) pick, If adding the count of ones and zeroes at ith index in arr,
        does not crosses our limit, then to include this in our answer.
        
        2) npick, If adding the count of ones and zeroes at ith index in arr,
        does not crosses our limit, then not to include this in our answer.
        
        3) nullpick, If adding the count of ones and zeroes at ith index in arr, crosses our    limit, then not to include this in our answer.
        */
        
        int pick = 0, npick = 0, nullpick = 0;
        
        if(ones + p.first <= maxOnes and zeroes + p.second <= maxZeroes){
            pick = 1 + helper(i+1, ones + p.first, zeroes + p.second, maxZeroes, maxOnes, strs);
            npick = helper(i+1, ones, zeroes,  maxZeroes, maxOnes, strs);
        }
        else nullpick = helper(i+1, ones, zeroes, maxZeroes, maxOnes, strs);
        
        return dp[i][ones][zeroes] = max({pick, npick, nullpick});
    }
    
    
    public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        // intially, putting -1 in dp
        memset(dp, -1, sizeof(dp)); 

        return helper(0, 0, 0, m, n, strs);
    }
};