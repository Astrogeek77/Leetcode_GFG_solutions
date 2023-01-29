//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{

private:
    int solve(int root, int par, int cam, vector<vector<int>>&adjl, map<pair<int, int>, int>&dp)
    {
        if(dp.find({root, cam}) != dp.end())
            return dp[{root, cam}];
        
        int ans = 1e8;
        if(cam)
        {
            ans = 1;
            for(auto it: adjl[root])
            {
                if(it != par)
                    ans += min(solve(it, root, 0, adjl, dp), solve(it, root, 1, adjl, dp));
            }
        }
        
        else
        {
            ans = 0;
            for(auto it : adjl[root])
            {
                if(it != par)
                    ans += solve(it, root, 1, adjl, dp);
            }
        }
        
        
        return dp[{root, cam}] = ans;
    }
    
public:
    int countVertex(int n, vector<vector<int>>edges){
        vector<vector<int>>adjl(n + 1);
        for(auto edge : edges)
        {
            adjl[edge[0]].push_back(edge[1]);
            adjl[edge[1]].push_back(edge[0]);
        }
        
        map<pair<int, int>, int>dp;
        return min(solve(1, 0, 0, adjl, dp), solve(1, 0, 1, adjl, dp));
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
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends