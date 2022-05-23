class Solution
{
    public:
        bool canFinish(int n, vector<vector < int>> &pre)
        {
            int m = pre.size();
            vector<int> indegree(n, 0);
            vector<int> topo;
           	//Creating a Graph of N vertices 
            vector<int> adj[n];
            for (int i = 0; i < m; i++)
            {
                adj[pre[i][1]].push_back(pre[i][0]);
            }
           	//Finding Indegree of nodes
            for (int i = 0; i < n; i++)
            {
                for (auto it: adj[i])
                    indegree[it]++;
            }
            queue<int> q;
           	//Push the nodes in the queue which have indgree as zero
            for (int i = 0; i < n; i++)
            {
                if (indegree[i] == 0)
                    q.push(i);
            }
           	//If no node having indegree as zero than we have cycle in the graph, so our queue size will be zero as no nodes has been pushed into the queue
            if (q.size() == 0) return false;
            int count = 0;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                topo.push_back(node);
                count++;
                for (auto it: adj[node])
                {
                    if (indegree[it] != 0)
                    {
                        indegree[it]--;
                        if (indegree[it] == 0)
                            q.push(it);
                    }
                }
            }
           	//if size of topo vector is not equal to number of vertices than the topo sort is not correct/Graph contains a cycle
            return (count == n);
        }
};