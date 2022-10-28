class Solution
{
    public:
        vector<vector < int>> kClosest(vector<vector < int>> &points, int k)
        {
            vector<vector < int>> v;
            priority_queue<pair<int, pair<int, int>>> pq;
            for (int i = 0; i < points.size(); i++)
            {
                int sq = points[i][0] * points[i][0] + points[i][1] * points[i][1];
                pq.push({ 
                    sq,
                    {
                        points[i][0],
                        points[i][1]
                    } 
                    });
            }
            
            int n = points.size() - k;

            while (n--) pq.pop();
            
            while (!pq.empty())
            {
                pair<int, pair<int, int>> p = pq.top();
                pq.pop();
                vector<int> ans = { p.second.first, p.second.second };
                v.push_back(ans);
            }

            return v;
        }
};