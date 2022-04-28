// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int helper(int i, int num[], int x, vector<vector<int>> &dp){
        if(i == 0) {
            if(x % num[0] == 0) return x / num[0];
            else return 1e9;
        }

        if(dp[i][x] != -1) return dp[i][x];

        int ntake = 0 + helper(i - 1, num, x, dp);
        int take = INT_MAX;
        if(num[i] <= x) take = 1 + helper(i, num, x - num[i], dp);
        return dp[i][x] = min(take, ntake);
    }
    
	int minCoins(int num[], int n, int x) 
	{ 
        vector<vector<int>> dp(n, vector<int> (x + 1, -1));
        int ans =  helper(n-1, num, x, dp);
        if(ans >= 1e9) return -1;
        return ans;
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends