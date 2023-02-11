class Solution
{
    public:
        vector<int> shortestAlternatingPaths(int n, vector<vector < int>> &redEdges, vector< vector< int>> &blueEdges)
        {
            vector<int> dist(n, -1);
            vector<vector<pair<int, int>>> adj(n);
            for (auto it: redEdges)
            {
                adj[it[0]].push_back({ it[1], 0 });	// 0 -> red
            }
            for (auto it: blueEdges)
            {
                adj[it[0]].push_back({ it[1], 1 });	// 1 -> blue
            }
            
            
            dist[0] = 0;
            queue<vector < int>> q;
           	//2 is only for the src / first node
            q.push({ 0, 0, 2 });	//node, dist and color(Here color is 2 just for the source)
            
            bool vis[101][3];
            memset(vis, false, sizeof(vis));
            
            while (!q.empty())
            {
                vector<int> it = q.front();
                q.pop();
                
                int curNode = it[0];
                int d = it[1];
                int color = it[2];
                
                for (auto ngh: adj[curNode])
                {
                    int nghNode = ngh.first;
                    int nghColor = ngh.second;
                        
                    // already visited node or node with same color as parent node    
                    if (vis[nghNode][nghColor] == true or nghColor == color) continue;
                    
                    else if (dist[nghNode] == -1 and !vis[nghNode][nghColor])
                    {
                    	//if dist is -1 then we are definately visiting it for the first time so lets update its value
                        dist[nghNode] = d + 1;
                        vis[nghNode][nghColor] = true;
                        q.push({ nghNode, d + 1, nghColor });
                    }
                    else
                    {
                    	//if the dist[nei.first] != -1 then the shortest distance has already been found and makes no sense to update it again
                        vis[nghNode][nghColor] = true;
                        q.push({ nghNode, d + 1, nghColor });
                    }
                }
            }
            return dist;
        }
};