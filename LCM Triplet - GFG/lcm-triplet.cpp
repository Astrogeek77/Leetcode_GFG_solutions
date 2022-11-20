//{ Driver Code Starts
// Initial Template for C++

// Initial Template for C++
// Back-end complete function Template for C++
// User function Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution 
{
  public:
    long lcmTriplets(long N) 
    {
        // trivial cases
        if(N == 1) return 1;
        if(N == 2) return 2;
        
        // if not divisble by 2
        if(N % 2 != 0) return N * (N-1) * (N-2);
        // if divisble by 3
        if(N % 3 == 0) return (N-1) * (N-2) * (N-3);
        
        return max(N * (N-1) * (N-3), (N-1) * (N-2) * (N-3));
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.lcmTriplets(N) << "\n";
    }
}
// } Driver Code Ends