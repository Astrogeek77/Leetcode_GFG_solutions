class Solution
{
    public:
        int networkDelayTime(vector<vector < int>> &times, int n, int k)
        {
           	// Create Graph
            vector<vector<pair<int, int>>> graph(n + 1);
           	// result vector
            vector<int> ans(n + 1, INT_MAX);

            for (int i = 0; i < times.size(); i++)
            {
               	// nodes are prssent at the first index of every vector in times vector.
                int node = times[i][0];
               	// Populating Graph
                graph[node].push_back({ times[i][1],
                    times[i][2] });
            }

            queue<int> q;	// queue for BFS 
            q.push(k);
            ans[k] = 0;

            while (!q.empty())
            {
                int curr = q.front();
                q.pop();

                for (auto it: graph[curr])
                {
                    int next = it.first;	// Next Node
                    int time = it.second;

                    int arrivalTime = time + ans[curr];
                    if (arrivalTime < ans[next])
                    {
                        ans[next] = arrivalTime;
                        q.push(next);
                    }
                }
            }
            
            int mx = 0;
            for(int i = 1; i <= n; i++){
                if(ans[i] == INT_MAX) return -1;
                mx = max(mx, ans[i]);
            }
            return mx;
        }
};