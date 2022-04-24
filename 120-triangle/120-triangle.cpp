class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int n = tri.size();
        vector<int> next(n, -1);
        for(int j=0;j<n;j++) next[j] = tri[n-1][j];

        for(int i=n-2; i>=0; i--){
            vector<int> curr(n, 0);
            for(int j=i; j>=0; j--){

                int down = tri[i][j] + next[j];
                int diagonal = tri[i][j] + next[j+1];

                curr[j] = min(down, diagonal);
            }
            next = curr;
        }
        return next[0];
    }
};

// int helper(int i, int j, vector<vector<int>> &tri, int n, vector<vector<int>> &dp){
// 	if(i == n - 1) return tri[i][j];
// 	if(dp[i][j] != -1) return dp[i][j];
	
// 	int dn = tri[i][j] + helper(i+1, j, tri, n, dp);
// 	int diag = tri[i][j] + helper(i+1, j+1, tri, n, dp);
// 	return dp[i][j] = min(dn, diag);
// }

// int minimumPathSum(vector<vector<int>>& tri, int n){
// 	vector<vector<int>> dp(n, vector<int> (n, -1));
// 	return helper(0, 0, tri, n, dp);
// }

// Tabulation
// int minimumPathSum(vector<vector<int>>& tri, int n){
// 	vector<vector<int>> dp(n, vector<int> (n, -1));
// 	for(int j=0;j<n;j++) dp[n-1][j] = tri[n-1][j];
	
// 	for(int i=n-2; i>=0; i--){
//         for(int j=i; j>=0; j--){
            
//             int down = tri[i][j]+dp[i+1][j];
//             int diagonal = tri[i][j]+dp[i+1][j+1];
            
//             dp[i][j] = min(down, diagonal);
//         }
//     }
// 	return dp[0][0];
// }

// Space Optimization
// int minimumPathSum(vector<vector<int>>& tri, int n){
// 	vector<int> next(n, 0);
// 	for(int j=0;j<n;j++) next[j] = tri[n-1][j];
	
// 	for(int i=n-2; i>=0; i--){
// 		vector<int> curr(n, 0);
//         for(int j=i; j>=0; j--){
            
//             int down = tri[i][j] + next[j];
//             int diagonal = tri[i][j] + next[j+1];
            
//             curr[j] = min(down, diagonal);
//         }
// 		next = curr;
//     }
// 	return next[0];
// }
