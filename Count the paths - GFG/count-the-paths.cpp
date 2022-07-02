// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	void dfs(vector<int>adj[], int source, int destination, int &count, vector<bool>&vis){
        if(source == destination){
            count++;
            return;
        }
        
        vis[source] = true;
        for(auto neighbour : adj[source]){
            if(!vis[neighbour]) 
                dfs(adj, neighbour, destination, count, vis);
        }
        //backtrack
        vis[source] = false;
        
        
    }

	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    //Creating adjacency list
	    vector<int>adj[n];
	    vector<bool>vis(n, false);
	    int count = 0;

	    for(int i = 0 ; i < edges.size() ; i++){
	        int x = edges[i][0];
	        int y = edges[i][1];
	        
	        adj[x].push_back(y);
	        
	    }
	    dfs(adj, s, d, count, vis);
	    
	    return count;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends