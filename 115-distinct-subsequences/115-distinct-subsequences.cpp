class Solution {
public:
    int prime = 1e9 + 7;
//     int helper(int i, int j, string &s, string &t, vector<vector<int>> &dp){
//        // Base case
//         if(j < 0) return 1;
//         if(i < 0) return 0;
        
//        // memoize
//         if(dp[i][j] != -1) return dp[i][j];
        
//        // Possibilities
//         if(s[i] == t[j]) // match
//         { 
//             int pick = helper(i-1, j-1, s, t, dp); // considered
//             int npick = helper(i-1, j, s, t, dp); // not cosidered
//             return dp[i][j] = pick + npick; 
//         } 
//         else 
//             return dp[i][j] = helper(i-1, j, s, t, dp); // no match
       
//        // Best Case - count all possibilities
//     }
    
    // int numDistinct(string s, string t) {
    //     int n = s.size();
    //     int m = t.size();
    //     vector<vector<int>> dp(n, vector<int> (m, -1));
    //     return helper(n-1, m-1, s, t, dp);
    // }
    
    //  Tabulation    
    
//     int numDistinct(string s, string t) {
//         int n = s.size();
//         int m = t.size();
//         vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
//         for(int i = 0; i < n+1; i++) dp[i][0] = 1;
        
//         for(int i = 1; i < m+1; i++) dp[0][i] = 0;
        
//         for(int i = 1; i < n+1; i++){
//             for(int j = 1; j < m+1; j++){
//                 if(s[i-1] == t[j-1]) // match
//                 { 
//                     int pick = dp[i-1][j-1]; // considered
//                     int npick = dp[i-1][j]; // not considered
//                     dp[i][j] = (pick + npick)%prime; 
//                 } 
//                 else 
//                     dp[i][j] = dp[i-1][j]; // no match
//             }
//         }
//         return dp[n][m];
        
        
    //   Space Optimization
        int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> prev(m+1, 0);
        
        for(int i = 0; i < n+1; i++) prev[0] = 1;
        
        // for(int i = 1; i < m+1; i++) dp[0][i] = 0;
        
        for(int i = 1; i < n+1; i++){
            for(int j = m; j >= 1; j--){
                if(s[i-1] == t[j-1]) // match
                { 
                    int pick = prev[j-1]; // considered
                    int npick = prev[j]; // not considered
                    prev[j] = (pick + npick)%prime; 
                } 
                else 
                    prev[j] = prev[j]; // no match
            }
        }
        return prev[m];
    }
};