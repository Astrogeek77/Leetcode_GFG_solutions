//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
#define ll long long
class Solution{
    public:
    bool wifiRange(int n, string s, int range)
    {
        ll rangeMini = -1, rangeMaxi = -1, i, currRangeMini, currRangeMaxi;
        
        for(i = 0; i < n; i++)
        {
            if(s[i] == '0')
                continue;
            
            currRangeMini = i - range;
            currRangeMaxi = i + range;
            
            if(currRangeMini > rangeMaxi + 1)
                return false;
            
            rangeMaxi = currRangeMaxi;
        }
        
        if(rangeMaxi >= n - 1)
            return true;
        
        return false;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends