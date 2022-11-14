class Solution
{
    public:
        int kthSmallest(vector<vector < int>> &matrix, int k)
        {

            int n = matrix.size();
            int m = matrix[0].size();
            
            int lo = matrix[0][0];
            int hi = matrix[n - 1][m - 1];
            int mid, count;
            
            while (lo < hi)
            {
                count = 0;
                mid = lo + (hi - lo) / 2;

                for (int i = 0; i < n; i++)
                {
                    // count element less than mid in a row
                    count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                }

                if (count < k) lo = mid + 1;
                else hi = mid;
            }

            return lo;
        }
};