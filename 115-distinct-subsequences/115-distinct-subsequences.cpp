class Solution {
public:
    int helper(int i, int j, string &s, string &t, vector<vector<int>> &dp){
       // Base case
        if(j < 0) return 1;
        if(i < 0) return 0;
        
       // memoize
        if(dp[i][j] != -1) return dp[i][j];
        
       // Possibilities
        if(s[i] == t[j]) // match
        { 
            int pick = helper(i-1, j-1, s, t, dp); // considered
            int npick = helper(i-1, j, s, t, dp); // not cosidered
            return dp[i][j] = pick + npick; 
        } 
        else 
            return dp[i][j] = helper(i-1, j, s, t, dp); // no match
       
       // Best Case - count all possibilities
    }
    
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return helper(n-1, m-1, s, t, dp);
    }
};