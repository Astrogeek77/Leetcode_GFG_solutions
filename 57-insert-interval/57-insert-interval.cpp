class Solution
{
    public:
        vector<vector < int>> insert(vector<vector < int>> &v, vector< int > &p)
        {
            vector<vector < int>> ans;
            int idx = lower_bound(v.begin(), v.end(), p) - v.begin();
            v.insert(v.begin() + idx, p);

            ans.push_back(v[0]);
            int n = v.size();

            for (int i = 0; i < n; i++)
            {
                if (ans.back()[1] >= v[i][0])
                    ans.back()[1] = max(ans.back()[1], v[i][1]);
                else
                    ans.push_back(v[i]);
            }
            return ans;
        }
};