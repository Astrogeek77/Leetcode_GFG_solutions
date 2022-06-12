// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    int helper(string &s, int i, int sum, vector<vector<int>> &dp)
    {
        if(i == s.size()) return 1;
        if(dp[i][sum] != -1) return dp[i][sum];
        
        int ans = 0, currSum = 0;
        for(int k = i; k < s.size(); k++){
            currSum += s[k] - '0';
            if(currSum >= sum) ans += helper(s, k+1, currSum, dp);
        }
        return dp[i][sum] = ans;
    }
	public:
	int TotalCount(string s)
	{
	    vector<vector<int>> dp(s.size(), vector<int> (901, -1));
	    return helper(s, 0, 0, dp);
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends