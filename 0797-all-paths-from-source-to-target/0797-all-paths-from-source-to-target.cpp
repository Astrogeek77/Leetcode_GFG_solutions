class Solution
{
    public:
        vector<vector < int>> allPathsSourceTarget(vector<vector < int>> &G)
        {
            vector<vector < int>> ans;
            queue<vector < int>> q;
            q.push({ 0 });	// starting node of every path
            while (size(q))
            {
                auto path = move(q.front());
                q.pop();
                if (path.back() == size(G) - 1) ans.push_back(move(path));	// found valid path
                else
                    for (auto child: G[path.back()])
                    {
                    	// try every possible next node in path
                        path.push_back(child);
                        q.push(path);	// push path into queue for further exploration
                        path.pop_back();
                    }
            }
            return ans;
        }
};