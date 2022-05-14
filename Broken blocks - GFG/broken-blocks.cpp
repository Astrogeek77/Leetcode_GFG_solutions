// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
    int MaxGold(vector<vector<int>>&matrix, int row, int col, vector<vector<long long>>& dp)
    {
        if (row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size())
            return 0;
        if (matrix[row][col] == -1)
            return 0;
        if (dp[row][col] != -1)
            return dp[row][col];
        int goldCoins = 0;
        goldCoins = max(goldCoins, MaxGold(matrix, row + 1, col, dp));
        goldCoins = max(goldCoins, MaxGold(matrix, row + 1, col-1, dp));
        goldCoins = max(goldCoins, MaxGold(matrix, row + 1, col+1, dp));
        goldCoins += matrix[row][col];
        return dp[row][col] = goldCoins;
    }
public:
    int MaxGold(vector<vector<int>>&matrix){
        if (matrix.empty())
            return 0;
        vector<vector<long long>> dp(matrix.size(), vector<long long>(matrix[0].size(), -1));
        int goldCoins = 0;
        for (int col = 0; col < matrix[0].size(); ++col)
            goldCoins = max(goldCoins, MaxGold(matrix, 0, col, dp));
        return goldCoins;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>matrix(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.MaxGold(matrix);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends