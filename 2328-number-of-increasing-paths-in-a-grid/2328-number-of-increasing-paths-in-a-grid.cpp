class Solution {
    public:
    int solve(int i,int j,int &m,int &n,vector<vector<int>> &g,vector<vector<int>> &dp,int &mod){
        if(i<0||j<0||i>=m||j>=n)return 0;
        if(dp[i][j]>0)return dp[i][j];
        int a = 0, b = 0, c = 0, d = 0;
        if(i+1<m && g[i][j] < g[i+1][j]){
            a = solve(i+1,j,m,n,g,dp,mod);
        }
        if(i-1>=0 && g[i][j] < g[i-1][j]){
            b = solve(i-1,j,m,n,g,dp,mod);
        }
        if(j+1<n && g[i][j] < g[i][j+1]){
            c = solve(i,j+1,m,n,g,dp,mod);
        }
        if(j-1>=0 && g[i][j] < g[i][j-1]){
            d = solve(i,j-1,m,n,g,dp,mod);
        }
        return dp[i][j] = ((((a+b)%mod+c)%mod+d)%mod+1)%mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        int i = 0, j = 0, m = grid.size(), n = grid[0].size();
        int ans = 0, mod = 1e9+7;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                if(dp[i][j]<0){
                    solve(i,j,m,n,grid,dp,mod);
                }
                ans = (ans+dp[i][j])%mod;
            }
        }
        return ans;
    }
};