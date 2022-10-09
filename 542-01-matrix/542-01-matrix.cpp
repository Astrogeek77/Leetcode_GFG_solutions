class Solution {
public:
    int m = 0, n = 0;
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) 
    {
        m = matrix.size();
        n = matrix[0].size();
      
        queue<pair<int,int>> q;
        vector<pair<int,int>> adj = {{1,0}, {0,1}, {-1,0}, {0, -1}};
      
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX-10000));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    dp[i][j] = 0;
                }else{
                    if(i > 0){
                        dp[i][j] = min(1 + dp[i-1][j], dp[i][j]); 
                    }
                    if(j > 0){
                        dp[i][j] = min(1 + dp[i][j-1], dp[i][j]);
                    }
                }
            }
        }
                
        
        for(int r = m-1; r >= 0; r--)
        {
            for(int c = n-1; c >= 0; c--)
            {
                if(r < m-1)
                {
                    dp[r][c] = min(1+dp[r+1][c], dp[r][c]);
                }
                if(c < n-1)
                {
                    dp[r][c] = min(1+dp[r][c+1], dp[r][c]);
                }
            }
        }
        return dp;
    }
};