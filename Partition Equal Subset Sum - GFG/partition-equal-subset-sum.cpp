// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int helper(int i, int k, int arr[], vector<vector<int>> &dp){
		if(k == 0) return 1;
		if(i == 0) return (k == arr[0]);

		if(dp[i][k] != -1) return dp[i][k];

		bool take = 0, ntake;
		ntake = helper(i - 1, k, arr, dp);
		if(k >= arr[i]) take = helper(i - 1, k - arr[i], arr, dp);
		return dp[i][k] = (take || ntake);
	}

    int equalPartition(int n, int arr[])
    {
        int sum = 0;
        for(auto i = 0; i < n; i++) sum += arr[i];

        if(sum % 2 != 0) return 0;
        else {
            int k = sum / 2;
            vector<vector<int>> dp(n, vector<int> (k+1, -1));
            return helper(n - 1, k, arr, dp);
        }
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends