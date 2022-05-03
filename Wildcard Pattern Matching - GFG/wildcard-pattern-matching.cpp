// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    bool helper(int i, int j, string &s, string &t, vector<vector<int>> &dp){
    	// base cases
    	if(i < 0 and j < 0) return true;
    	if(i < 0 and j >= 0) return false;
    	if(j < 0 and i >= 0) {
    		for(int k = 0; k <= i; k++)
    			if(s[k] != '*') return false;
    		return true;
    	}    
    	
    	// memoize
    	if(dp[i][j] != -1) return dp[i][j];
    
    	// all possibilties
    	if(s[i] == t[j] || s[i] == '?')
    		return dp[i][j] = helper(i-1, j-1, s, t, dp);
    	else if(s[i] == '*')
    		return dp[i][j] = helper(i-1, j, s, t, dp) | helper(i, j-1, s, t, dp);
    	else return dp[i][j] = false;
    
    	// take the best - > poosibilities
    }

/*You are required to complete this method*/
    int wildCard(string s, string t)
    {
        int n = s.size();
        int m = t.size();
    	vector<vector<int>> dp(n, vector<int> (m, -1));
        return helper(n-1, m-1, s, t, dp);
    }
};

// { Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}
  // } Driver Code Ends