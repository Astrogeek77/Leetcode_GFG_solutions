class Solution {
public:
    long long ans = 0; int s;
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) 
    {
        vector<vector<int>> graph(roads.size() + 1); 
        s = seats;
        
        // contruct graph from roads.
        for (vector<int>& r: roads) 
        {
            graph[r[0]].push_back(r[1]);
            graph[r[1]].push_back(r[0]);
        }
        dfs(0, 0, graph);
        return ans;
    }
    
    int dfs(int node, int parent, vector<vector<int>>& graph, int people = 1) 
    {
        // for all neighbours ngh
        for (int& ngh: graph[node]) 
        {
            if (ngh == parent) continue;
            people += dfs(ngh, node, graph);
        }
        if (node != 0) ans += (people + s - 1) / s;
        return people;
    }
};