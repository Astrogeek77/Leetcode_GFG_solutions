// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int lcs(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = 0 + max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[m];
    }
    int longestPalindromeSubsequence(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        return lcs(s, t);
    }
     
    int countMin(string str){
        int n = str.size();
    	int m = longestPalindromeSubsequence(str);
    	return n - m;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}

  // } Driver Code Ends