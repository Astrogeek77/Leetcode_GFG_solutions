// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int maxd = 0;
    void dfs(int ind, vector<vector<int>> &adj, vector<int> &vis, int d)
    {
        // d -> depth / distance of each house from house(i)
        vis[ind] = 1;
        maxd = max(maxd, d); // max depth to which a node goes
        for (int i : adj[ind])
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, d + 1);
            }
        }
    }

    int partyHouse(int N, vector<vector<int>> &adj)
    {

        int ans = INT_MAX;
        // int house = -1;

        for (int i = 1; i <= N; i++)
        {
            vector<int> vis(N + 1, 0);
            maxd = 0;
            dfs(i, adj, vis, 0); // for each find maxdeptht to which it goes and finally find min of it

            ans = min(ans, maxd);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, x, y;
        cin>>N;
        vector<vector<int>> adj(N+1);
        for(int i = 0;i < N-1;i++){
            cin>>x>>y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        
        Solution ob;
        cout<<ob.partyHouse(N, adj)<<"\n";
    }
    return 0;
}  // } Driver Code Ends