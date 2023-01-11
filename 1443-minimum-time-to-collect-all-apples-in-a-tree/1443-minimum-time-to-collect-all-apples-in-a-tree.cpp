class Solution 
{
    int helper(vector<int> adj[], vector<bool> &hasApple, 
                int currNode, int parent)
    {
        int time = 0; // time to collect apples from root
        for(int nghNode: adj[currNode])
        {
            // for all neighbours
            // -> check if it is the parent;
            if(nghNode != parent) 
            {
                 // time from children traversal.
                int timeChilds = helper(adj, hasApple, nghNode, currNode);

                if(hasApple[nghNode] == true)
                {
                    time += (2 + timeChilds); // adding 2 because we have to come back too
                    hasApple[currNode] = true;
                }
            }
        }
        // cout << "time: " << time << endl;
        return time;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        // build graph
        vector<int> adj[n];
        // for(vector<int> edge: edges)
        for(int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        
        
        return helper(adj, hasApple, 0, 0);
    }
};