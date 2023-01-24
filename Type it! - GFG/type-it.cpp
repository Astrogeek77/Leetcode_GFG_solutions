//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        int n = s.size();

        for (int i = (n/2-1); i >= 0; i--)
        {
            // compare two parts of string and return acc. to formula if same are found.
            if (s.substr(0, i+1) == s.substr(i+1, i+1))
            {
                return (i + 1) + 1 + (n - 2 * (i + 1));
            }

        }
        return n;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends