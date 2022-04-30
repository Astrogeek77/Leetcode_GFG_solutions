// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int helper(int i, int x, int arr[], vector<vector<long long int>> &dp){
        if(i == 0) {
            return (x % arr[i] == 0);
        }
        
        if(dp[i][x] != -1) return dp[i][x];
        
        long long int take = 0, ntake;
        ntake = 0 + helper(i - 1, x, arr, dp);
        if(x >= arr[i]) take = helper(i, x - arr[i], arr, dp);
        return dp[i][x] = take + ntake;
    }
    
    long long int count(int S[], int m, int n) {
        vector<vector<long long int>> dp(m, vector<long long int> (n + 1, -1));
        return helper(m-1, n, S, dp);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends