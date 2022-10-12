class Solution
{
    public:
        bool searchMatrix(vector<vector < int>> &matrix, int target)
        {
            int n = matrix.size();
            int m = matrix[0].size();
          
            int lo = 0, hi = m - 1;
            while (lo < n and hi >= 0)
            {
                if (matrix[lo][hi] == target) return true;
                else if (matrix[lo][hi] > target) hi--;
                else lo++;
            }
            return false;
        }
};