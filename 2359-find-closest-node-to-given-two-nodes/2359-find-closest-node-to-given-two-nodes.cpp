class Solution
{
    public:
    void dfs(int node, int d, vector<int> &e, vector<int> &dist)
    {
        while (node != -1 and dist[node] == -1)
        {
            dist[node] = d++;
            node = e[node];
        }
    }
    
    int closestMeetingNode(vector<int> &e, int node1, int node2)
    {
        int res = -1, min_dist = INT_MAX;
        vector<int> dist1(e.size(), -1), dist2(e.size(), -1);
        
        dfs(node1, 0, e, dist1);
        dfs(node2, 0, e, dist2);
        
        for (int i = 0; i < e.size(); ++i) 
        {
            if (min(dist1[i], dist2[i]) >= 0 and max(dist1[i], dist2[i]) < min_dist)
            {
                min_dist = max(dist1[i], dist2[i]);
                res = i;
            }
        }
        return res;
    }
};