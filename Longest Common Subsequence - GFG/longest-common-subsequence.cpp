// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Helper Function to find the length of longest common subsequence in two strings.
    int helper(int i, int j, string &s, string &t, vector<vector<int>> &dp){
    	if(i < 0 || j < 0) return 0;
    	if(dp[i][j] != -1) return dp[i][j];
    	if(s[i] == t[j]) return dp[i][j] = 1 + helper(i-1, j-1, s, t, dp);
    	else return dp[i][j] = 0 + max(helper(i-1, j, s, t, dp), helper(i, j-1, s, t, dp));
    }
    
    int lcs(int x, int y, string s, string t)
    {
       	vector<vector<int>> dp(x, vector<int> (y, -1));
    	return helper(x-1, y-1, s, t, dp);
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends