class Solution
{
    vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int source)
    {
        vector<int> dist(graph.size(), INT_MAX);
        priority_queue<pair<int, int>, vector< pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({ source, 0 });
        dist[source] = 0;
        
        while (!pq.empty())
        {
            int node = pq.top().first;
            pq.pop();
            
            for (pair<int, int> ngh: graph[node])
            {
                int new_node = ngh.first;
                int d = ngh.second;
                if (dist[new_node] > dist[node] + d)
                {
                    dist[new_node] = dist[node] + d;
                    pq.push({ new_node, dist[new_node] });
                }
            }
        }
        return dist;
    }
    public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2) 
    {
        vector<vector<pair<int, int>>> graph(edges.size());
        
        for(int i = 0; i < edges.size(); i++)
        {
            if(edges[i] == -1) 
                continue;
            
            graph[i].push_back({edges[i], 1});
        }
        
        vector<int> dist1 = dijkstra(graph, node1);
        vector<int> dist2 = dijkstra(graph, node2);
        
        int min_dist = INT_MAX, min_node = -1;
        for(int i = 0; i < dist1.size(); i++)
        {
            if(min_dist > max(dist1[i], dist2[i]))
            {
                min_dist = max(dist1[i], dist2[i]);
                min_node = i;
            }
        }
        
        return min_node;
    }
};