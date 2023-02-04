//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{

public: 

 // calculate the maximum sum with out adjacent

 int findMaxSum(int *arr, int n) {

     vector<pair<int,int>> dp(n+1);

     dp[0].first=0;

     dp[0].second=0;

     for(int i=0;i<n;i++)

     {

         //out

         dp[i+1].first=max(dp[i].first,dp[i].second);

         dp[i+1].second=arr[i]+dp[i].first;

     }

     return max(dp[n].first,dp[n].second);

 }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends