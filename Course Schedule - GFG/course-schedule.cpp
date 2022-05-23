// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> p) 
    {
        vector<int> adj[n];
        for(int i = 0; i < m; i++) 
        {
            int u = p[i][1];
            int v = p[i][0];
            
            adj[u].push_back(v); // graph
        }
        
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++)
            for(int it: adj[i])
                indegree[it]++; // nodes pointing to it
        
        queue<int> q; // queue for BFS
        
        for(int i = 0; i < n; i++)
            if(indegree[i] == 0) q.push(i);
        
        vector<int> ans;
        while(q.empty() == false) 
        {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto it: adj[curr]) 
            {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        if(ans.size() == n) return ans;
        else return {};
    }
};

// { Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends