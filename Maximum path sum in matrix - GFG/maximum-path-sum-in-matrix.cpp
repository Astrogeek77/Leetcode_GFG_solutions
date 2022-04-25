// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int helper(int i, int j, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp){
    	if(j < 0 || j >= m) return -1e9;
    	if(i == 0) return matrix[0][j];
    	
    	if(dp[i][j] != -1) return dp[i][j];
    	
    	int up = matrix[i][j] + helper(i - 1, j, m, matrix, dp);
    	int Rdiag = matrix[i][j] + helper(i - 1, j + 1, m, matrix, dp);
    	int Ldiag = matrix[i][j] + helper(i - 1, j - 1, m, matrix, dp);
    	
    	return dp[i][j] = max(up, max(Ldiag, Rdiag));
    }
    
    
    int maximumPath(int N, vector<vector<int>> matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
    	
    	vector<vector<int>> dp(n, vector<int> (m, -1));
    	
    	int maxi = -1e9;
        for(int j=0; j<N;j++){
            int ans = helper(n-1, j, m, matrix, dp);
            maxi = max(maxi,ans);
        }
    	return maxi;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends