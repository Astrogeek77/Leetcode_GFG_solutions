class Solution 
{
    vector<bool> vis, dfsvis;
    int n , ans = -1;

    void dfs(int node , vector<int> &edges)
    {
        //Mark visited current Node 
        vis[node] = 1;
        //Mark path/dfs visited current Node 
        dfsvis[node] = 1;

        //Next Node
        int next = edges[node];
        if(next == -1 )
        dfsvis[node] = 0;
        else if(!vis[next])
        dfs(next, edges);
        else if(dfsvis[node])
        {
            int cnt = 0;

            for(int i = 0 ; i<n ; i++)
                if(dfsvis[i]) cnt++;

            ans = max(ans, cnt);
        }

        dfsvis[node] = 0;
    }
public:
    int longestCycle(vector<int>& edges) {
        // Number Of Nodes
        n = edges.size();
        vis = vector<bool> (n, 0); 
        dfsvis = vector<bool> (n, 0); 
        vector<int> inDegree(n, 0);

        //Calculate Indegree of Each Node 
        for(int i = 0 ; i<n ; i++)
        if(edges[i] != -1) inDegree[edges[i]]++;
        
        queue<int> q;

        // Push the Nodes into q having Indegree as 0 and mark them visited
        for(int i = 0 ; i<n ; i++){
        if(inDegree[i] == 0) {
            q.push(i) ; 
            vis[i] = 1;
            }
        }

        // Topological Sort Using Kahn's Algo 
        while(!q.empty())
        {
            // Current Node
            int node = q.front();
            q.pop();
            // Next Node
            int next = edges[node];
            
            if(next != -1)
            {
              // Check If Next Node Indegree became 0 or not 
              // If yes Then Go to Next Node i.e. Mark it Visited 
                if(--inDegree[next] == 0)
                {
                    q.push(next) ; 
                     vis[next] = 1;
                }
            }
        }

        // Cycle Detection Technique
       for(int i = 0; i <n  ; i++)
       {
           if(!vis[i] )
              dfs(i, edges);
       }
       
       return ans; 
    }
};