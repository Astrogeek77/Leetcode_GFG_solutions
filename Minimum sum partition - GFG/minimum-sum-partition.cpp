// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];
    
        int k = sum;

// tabulation
        vector<vector<int>> dp(n, vector<int> (k+1, false));
        for(int i = 0; i < n; i++) dp[i][0] = true;
        if(arr[0] <= k) dp[0][arr[0]] = true;
        
        for(int i = 1; i < n; i++){
            for(int t = 1; t <= k; t++){
                int take = false, ntake;
                ntake = dp[i-1][t];
                if(arr[i] <= t) take = dp[i-1][t-arr[i]];
                dp[i][t] = take || ntake;
            }
        }
        int mn = 1e9;
        for(int s1 = 0; s1 <= sum/2; s1++){
            if(dp[n-1][s1] == true) mn = min(mn, abs((sum - s1) - s1));
        }
        return mn;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends