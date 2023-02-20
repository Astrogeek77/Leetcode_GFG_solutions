//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution {
private:
    int mod = 1e9 + 7;
    int solveRec(int index, int option, int N)
    {
        if (index >= N) 
        {
            if (option == 0) 
                return 1;
            else
                return 0;
        }

        int ans = 0;
        for (int i = 0; i < 4; i++) 
        {
            if (i != option) 
            {
                ans += solveRec(index + 1, i, N);
            }
        }
        return ans;
    }

    int solveMem(int index, int option, int N, vector<vector<int> >& dp)
    {
        if (index == N) {
            if (option == 0)
                return 1;
            return 0;
        }

        if (dp[index][option] != -1)
            return dp[index][option];

        int ans = 0;

        for (int i = 0; i < 4; i++)
            if (i != option)
                ans = (ans + solveMem(index + 1, i, N, dp)) % mod;

        dp[index][option] = ans % mod;

        return dp[index][option] % mod;
    }

    int solveTab(int N)
    {
        vector<vector<int> > dp(N + 1, vector<int>(4, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= N; i++) 
        {
            for (int j = 0; j < 4; j++) 
            {
                for (int k = 0; k < 4; k++) 
                {
                    if (j != k) 
                    {
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
                    }
                }
            }
        }

        return dp[N][0];
    }

    int solveSO(int N)
    {
        vector<int> prev(4, 0), curr(4, 0);
        prev[0] = 1;

        for (int i = 1; i <= N; i++) 
        {
            for (int j = 0; j < 4; j++) 
            {
                for (int k = 0; k < 4; k++) 
                {
                    if (j != k) 
                    {
                        curr[j] = (curr[j] + prev[k]) % mod;
                    }
                }
            }
            for (int j = 0; j < 4; j++) 
            {
                
                prev[j] = curr[j];
                curr[j] = 0;
            }
        }

        return prev[0];
    }

public:
    int countPaths(int N)
    {
        // return solveRec(0, 0, N);

        // vector<vector<int>> dp(N, vector<int> (4, -1));
        // return solveMem(0, 0, N, dp);

        // return solveTab(N);

        return solveSO(N);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends