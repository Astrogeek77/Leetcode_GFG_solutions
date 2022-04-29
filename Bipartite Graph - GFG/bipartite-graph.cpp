// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool isBipartiteUtil(int node,vector<int>adj[],vector<int>&color,int prev)
       {
               if(prev!=-1)
               color[node]=1-color[prev];
               else
                color[node]=1;
             vector<int>::iterator itr;
               for(itr=adj[node].begin();itr!=adj[node].end();itr++)
               {
                   if(color[*itr]==-1)
                   {
                       if(!isBipartiteUtil(*itr,adj,color,node))
                       {
                           return 0;
                       }
                   }
                   else if(color[*itr]==color[node])// not this imp(color[*itr]==color[prev])
                   return 0;
               }
           return 1;
       }
       
    bool isBipartite(int V, vector<int>adj[]){
        // Code here
        vector<int> color(V,-1);
        int prev=-1;
         for(int i=0;i<V;i++)
         {
             if(color[i]==-1)
             {
                 if(!isBipartiteUtil(i,adj,color,prev))
                 return 0;
             }
         }
         return 1;
    }

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends