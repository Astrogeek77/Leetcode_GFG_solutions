// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minColour(int N, int M, vector<int> mat[]) {
        vector<int> adj[N+1], indegree(N+1, 0);
        // BFS + Topological sort - Kahn's Algorithm
        
        for(int i = 0; i < M; i++)
        {
            adj[mat[i][1]].push_back(mat[i][0]);
            indegree[mat[i][0]]++;
        }
        
        queue<int> queue;
        for(int i = 1; i <= N; i++)
        {
            if(indegree[i] == 0) queue.push(i);
        }
        
        int ans = 0;
        while(!queue.empty())
        {
            ans++;
            int size = queue.size();
            
            while(size--)
            {
                int curr = queue.front();
                queue.pop();
                
                for(auto it: adj[curr])
                {
                    indegree[it]--;
                    if(indegree[it] == 0) queue.push(it);
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M, x, y;
        cin>>N>>M;
        vector<int> mat[M];
        for(int i = 0;i < M;i++){
            cin>>x>>y;
            mat[i].push_back(x);
            mat[i].push_back(y);
        }
        
        Solution ob;
        cout<<ob.minColour(N, M, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends