class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         // taking map as the adjency list
        unordered_map<int, vector<pair<int, int>>> adj;
        int m = flights.size();

        for(int i = 0; i < m; i++)
        {
            // flights -> {from, to, price}
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        // simple queue works because steps can only inc by one per level
        queue<pair<int, pair<int, int>>> q; // {steps, node, distance}
        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        // we will perform dikjakstra in a modified way focusing on stops rather than distance.
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            int stop = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            
            // more stops than allowed
            if(stop > k) break;

            for(auto it: adj[node])
            {
                int adjNode = it.first;
                int edW = it.second;

                // stop <= k beacause dest is counted as stop too for better soltuion.
                if(cost + edW <dist[adjNode] && stop <= k)
                {
                    dist[adjNode] = cost + edW;
                    q.push({stop + 1, {adjNode, dist[adjNode]}});
                }
            }
        }
        // if we can't reach in allowed stops return -1
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};