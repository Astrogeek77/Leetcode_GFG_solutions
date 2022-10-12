class Solution
{
    public:
        vector<vector < int>> intervalIntersection(vector<vector < int>> &a, vector< vector< int>> &b)
        {
            vector<vector<int>> ans;
            int i = 0, j = 0;
            while (i < a.size() and j < b.size())
            {
                int f = max(a[i][0], b[j][0]);
                int s = min(a[i][1], b[j][1]);
              
                if(f <= s)  ans.push_back({f, s});
              
                if(a[i][1] < b[j][1]) i++;
                else j++;
            }
          
          return ans;
        }
};