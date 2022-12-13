class Solution
{
    public:
        int minFallingPathSum(vector<vector < int>> &matrix)
        {
            int rows = matrix.size();
            int cols = matrix.size();
            for (int i = 1; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    int rowUp = matrix[i - 1][j];
                    int leftUp = j > 0 ? matrix[i - 1][j - 1] : INT_MAX;
                    int rightUp = j < cols - 1 ? matrix[i - 1][j + 1] : INT_MAX;
                    matrix[i][j] += min(rowUp, min(leftUp, rightUp));
                }
            }
            int answer = INT_MAX;
            for (int j = 0; j < cols; j++)
            {
                answer = min(answer, matrix[rows - 1][j]);
            }
            return answer;
        }
};